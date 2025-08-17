#include "dragsiolib.hpp"

void printIntVector(std::vector<int> inputVector, bool verbose) {
  if (inputVector.size() < 10) {
    verbose = true;
  }

  switch (verbose) {
    
    case true:
      for (int i = 0; i < inputVector.size();) {
        printf("%d", inputVector[i]);
        i++;
        if (i < inputVector.size()) {
          printf(", ");
        } else {
          printf("\n");
        }
      }
      break;

    case false:
      for (int i = 0; i < 10;) {
        printf("%d", inputVector[i]);
        i++;
        if (i < 10) {
          printf(", ");
        } else {
          printf(". . .\n");
        }
      }
    break;
  }

}

std::vector<int> generateRandomVector(int size) {

  std::vector<int> output(size);

  auto now = std::chrono::system_clock::now();
  auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
  unsigned int seed = static_cast<unsigned int>(milliseconds.count());
  srand(seed);
  
  for (int i = 0; i < size; i++) {
    output[i] = rand() % size + 1;
  }

  return output;

}
