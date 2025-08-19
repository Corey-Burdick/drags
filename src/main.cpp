#include "dragsiolib.hpp"
#include "dragsortlib.hpp"

#include <cstring>

int main(int argc, char* argv[]) {
  
  uint8_t sorter = sortMode::none;
  bool timerMode = false;
  bool verboseMode = false;
  int mainSize = 10;

  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-') {
        for (int j = 1; j < strlen(argv[i]); j++) {
          switch (argv[i][j]) {
            case 'n':
              mainSize = std::atoi(argv[i + 1]);
              if (mainSize <= 0) {
                printf("Drags only allows the use of strings that are a positive integer\n");
                return 0;
              }
              break;
            case 't':
              timerMode = true;
              break;
            case 'v':
              verboseMode = true;
              break;
            case 'b':
              sorter = sortMode::bubble;
              break;
            case 'q':
              sorter = sortMode::quick;
              break;
            case 'i':
              sorter = sortMode::intro;
              break;
            default:
              printf("Not a valid option.\n");
              break;
          }
        }
      }
    }
  }

  Timer my_Timer;
  std::vector<int> mainVector = generateRandomVector(mainSize);

  long long genTime = my_Timer.elapsed_milliseconds();
  printf("Generated Array: ");
  printIntVector(mainVector, verboseMode);
  if (timerMode) printf("Time to Generate: %lldms\n", genTime);
  printf("\n");

  my_Timer.reset();

  switch (sorter) {
    case sortMode::none:
      printf("No sort chosen. Closing...\n");
      return 0;
    case sortMode::bubble:
      bubbleSort(mainVector);
      printf("Sorting using bubble sort.\n");
      break;
    case sortMode::quick:
      quickSort(mainVector);
      printf("Sorting using quick sort.\n");
      break;
    case sortMode::intro:
      std::sort(mainVector.begin(), mainVector.end());
      printf("Sorting using intro sort.\n");
      break;
    default:
      printf("Invalid Sort Mode. Closing...\n");
      return 1;
  }


  long long sortTime = my_Timer.elapsed_milliseconds();
  printf("Sorted Array: ");
  printIntVector(mainVector, verboseMode);
  if (timerMode) printf("Time to Sort: %lldms\n", sortTime);

  return 0;

}
