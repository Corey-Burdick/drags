#include "dragsiolib.hpp"
#include "dragsortlib.hpp"

#include <algorithm>

int main(int argc, char* argv[]) {
  
  bool verboseMode = true;
  int mainSize = 20;
  std::vector<int> mainVector = generateRandomVector(mainSize);

  printf("Generated Array: ");
  printIntVector(mainVector, verboseMode);

  bubbleSort(mainVector);

  printf("Sorted Array: ");
  printIntVector(mainVector, verboseMode);

  return 0;

}
