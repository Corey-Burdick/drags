#include "dragsiolib.hpp"
#include "dragsortlib.hpp"

#include <cstring>

// Drags - Quick and Dirty Random Array Generator and Sorter
// Version 0.1.02 Stable
// 
// Drags will generate an array (std::vector<int>) of numbers.
// The user will be able to use the "-n" option to change the numbers of elements.
// the user can also use different sorting algorithms as defined in "dragsortlib.cpp"

int main(int argc, char* argv[]) {
  
  char version[] = "0.1.02 Stable";
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
              if (argc >= i) {
                mainSize = std::atoi(argv[argc - 1]);
              }
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
            case 'h':
            case 'H':
              printf("Drags Version - %s\n"
              "\n" 
              "Drags generates a list of random numbers, then sort them with different algorithms.\n"
              "\n"
              "-- [OPTIONS] --\n"
              "-h (or)\n"
              "-H   Show help (You are here).\n"
              "-n   Change the number of elements generated and sorted. Follow with a positive number.\n"
              "-t   Activate Timer mode.\n"
              "-v   Activate Verbose mode.\n"
              "\n"
              "-- [SORTING ALGORITHMS] --\n"
              "-b   Bubble Sort (Not recommended)\n"
              "-q   Quick Sort\n"
              "-i   Intro Sort\n", version);
              return 0;
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
