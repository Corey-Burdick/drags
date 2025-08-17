#include "dragsiolib.hpp"
#include "dragsortlib.hpp"

int main(int argc, char* argv[]) {
  
  bool timerMode = true;
  bool verboseMode = true;
  int mainSize = 20;

  Timer my_Timer;
  std::vector<int> mainVector = generateRandomVector(mainSize);

  if (timerMode) printf("Time to Generate: %lldms\n", my_Timer.elapsed_milliseconds());
  printf("Generated Array: ");
  printIntVector(mainVector, verboseMode);
  printf("\n");

  if (timerMode) my_Timer.reset();
  bubbleSort(mainVector);

  if (timerMode) printf("Time to Sort: %lldms\n", my_Timer.elapsed_milliseconds());
  printf("Sorted Array: ");
  printIntVector(mainVector, verboseMode);

  return 0;

}
