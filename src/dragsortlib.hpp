#ifndef DRAGSORTLIB_HEADER
#define DRAGSORTLIB_HEADER

#include <stdint.h>
#include <vector>
#include <algorithm>

enum sortMode : uint8_t {
  none = 0,
  bubble = 1,
  quick = 2,
  intro = 3
};

void bubbleSort(std::vector<int>& inputArray);
void quickSort(std::vector<int> &inputArray, int start, int end);
int partition(std::vector<int> &inputArray, int start, int end);


#endif // DRAGSORTLIB_HEADER
