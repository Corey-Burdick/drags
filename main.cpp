#include <stdio.h>

#include "src/dragsiolib.hpp"


int main(int argc, char* argv[]) {
  
  bool verboseMode = true;
  int mainSize = 20;
  std::vector<int> mainVector = generateRandomVector(mainSize);

  printf("Generated Array: ");
  printIntVector(mainVector, verboseMode);

  
  return 0;

}
