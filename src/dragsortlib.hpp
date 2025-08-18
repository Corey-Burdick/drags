#ifndef DRAGSORTLIB_HEADER
#define DRAGSORTLIB_HEADER

#include <vector>

void bubbleSort(std::vector<int>& inputArray);
void quickSort(std::vector<int> &inputArray, int start, int end);
int partition(std::vector<int> &inputArray, int start, int end);


#endif // DRAGSORTLIB_HEADER
