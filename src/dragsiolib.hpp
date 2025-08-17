#ifndef DRAGSIOLIB_HEADER
#define DRAGSIOLIB_HEADER

#include <stdio.h>
#include <vector>
#include <chrono>
#include <random>

class Timer {
public:
  
  Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

  void reset() {
    start_time = std::chrono::high_resolution_clock::now();
  }

  long long elapsed_milliseconds() const {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    return duration.count();
  }

private:

  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

};

void printIntVector(std::vector<int> inputVector, bool verbose);
std::vector<int> generateRandomVector(int size);

#endif // DRAGSIOLIB_HEADER
