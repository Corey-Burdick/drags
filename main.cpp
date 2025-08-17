#include "src/dragsiolib.hpp"

#include <algorithm>

int main(int argc, char* argv[]) {
  
  bool verboseMode = true;
  int mainSize = 20;
  std::vector<int> mainVector = generateRandomVector(mainSize);

  printf("Generated Array: ");
  printIntVector(mainVector, verboseMode);

  std::sort(mainVector.begin(), mainVector.end());

  printf("Sorted Array: ");
  printIntVector(mainVector, verboseMode);

  return 0;

}
