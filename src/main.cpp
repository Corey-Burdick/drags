#include "dragsiolib.hpp"
#include "dragsortlib.hpp"

int main(int argc, char* argv[]) {
  
  uint8_t sorter = sortMode::quick;
  bool timerMode = true;
  bool verboseMode = false;
  int mainSize = 20000;

  Timer my_Timer;
  std::vector<int> mainVector = generateRandomVector(mainSize);

  if (timerMode) printf("Time to Generate: %lldms\n", my_Timer.elapsed_milliseconds());
  printf("Generated Array: ");
  printIntVector(mainVector, verboseMode);
  printf("\n");

  if (timerMode) my_Timer.reset();

  switch (sorter) {
    case sortMode::bubble:
      bubbleSort(mainVector);
      printf("Sorting using bubble sort.\n");
      break;
    case sortMode::quick:
      quickSort(mainVector, 0, mainVector.size() - 1);
      printf("Sorting using quick sort.\n");
      break;
    default:
      printf("Invalid Sort Mode. Closing...\n");
      return 1;
  }


  if (timerMode) printf("Time to Sort: %lldms\n", my_Timer.elapsed_milliseconds());

  printf("Sorted Array: ");
  printIntVector(mainVector, verboseMode);

  return 0;

}
