#include "ThreadPool.h"
#include <cassert>
#include <stdexcept>
#include "MoveGenerator.h"

// global object
ThreadPool Threads{std::thread::hardware_concurrency()};

// ThreadPool constructor
ThreadPool::ThreadPool(size_t numThreads) {

  if (numThreads <= 0) {

    throw std::invalid_argument{"Must create a positive number of threads"};

  }

  threads.resize(numThreads, nullptr);

  for (size_t id = 0; id < numThreads; ++id) {
    threads[id] = std::make_unique<Thread>(id);
  }

}

// notify all threads to start searching
void ThreadPool::run_threads() {
  for (auto& th : threads) {
    th->start_search();
  }
}

// wait for all threads to finish searching
void ThreadPool::wait_for_threads_finish() {
for (auto& th : threads) {
    th->wait_for_search_finish();
  }
}

void ThreadPool::start_searching(Position& pos) {

  // make sure threads are not searching
  wait_for_threads_finish();

  stop = false;

  // generate moves and distribute them among threads
  int moveCounter = 0;
  for (const auto& move : MoveList::generate_moves(pos)) {

    threads[moveCounter % threads.size()]->baseMoves.emplace_back(move);
    ++moveCounter;

  }

  // initalize threads
  for (auto& th : threads) {

    th->basePosition = pos;
    
  }
  
  // start searching
  run_threads();
}

// allowd for custom amount of threads to be set
void ThreadPool::set_threads(size_t numThreads) {

  // throw if invalid number of threads are entered
  if (numThreads < 0) {
    throw std::invalid_argument{"Cannot set thread count to negative number"};
  }

  // delete all current threads
  threads.clear();

  // create desired amount of threads
  for (size_t id = 0; id < numThreads; ++id) {
    threads.emplace_back(std::make_unique<Thread>(id));
  }
}


Thread* ThreadPool::get_best_thread() {
  // TODO: impl
  return threads.front().get();
}


// Thread constructor
Thread::Thread(size_t id) : thread{std::thread{&idle_loop}}, id{id} {

  wait_for_search_finish(); // make sure thread is sleeping

}

//Thread destuctor
Thread::~Thread() {
  
  assert(!searching); // thread shouldnt be searching, dtors cant throw
  exit = true;
  start_search(); // this will make up anyone in the idle loop then return
  thread.join();

}

void Thread::wait_for_search_finish() {

  std::unique_lock<std::mutex> lock{mutex};
  cv.wait(lock, [this]{return !this->searching;});

}

// set variable to break out of idle loop
void Thread::start_search() {

  std::lock_guard<std::mutex> lock{mutex};
  searching = true;
  cv.notify_one();

}

// halts execution of thread until searching = true
void Thread::idle_loop() {

  while (true) {

    std::unique_lock<std::mutex> lock{mutex};
    searching = false;
    cv.notify_one(); // for search finished
    cv.wait(lock, [this]{return this->searching;});

    if (exit) {
      return;
    }
    
    lock.unlock();

    search();

  }
}

// Thread search is defined in search.cc



