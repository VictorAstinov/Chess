#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <memory>
#include "Position.h"
#include "types.h"
#include "MoveGenerator.h"
#include "Search.h"

class Thread {
  std::thread thread;
  std::mutex mutex;
  std::condition_variable cv;
  size_t id;
  bool searching = true;
  bool exit = false;

  public:
  
  explicit Thread(size_t id);
  virtual ~Thread();

  void search();
  void idle_loop();
  void start_search();
  void wait_for_search_finish();

  Position basePosition;
  std::vector<RootMove> baseMoves;

};

// save this for later
/*
class MainThread : public Thread {

  public:

  void search() override;
};
*/

class ThreadPool {
  std::vector<std::unique_ptr<Thread>> threads;

  public:

  explicit ThreadPool(size_t numThreads);
  virtual ~ThreadPool() = default;

  void run_threads();
  void stop_threads();
  void set_threads(size_t numThreads);
  void wait_for_threads_finish();
  Thread* get_best_thread();
  void start_searching(Position& pos );
  
  std::atomic_bool stop;
};

extern ThreadPool Threads; // global ThreadPool object
#endif