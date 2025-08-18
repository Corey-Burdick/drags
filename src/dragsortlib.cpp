#include "dragsortlib.hpp"

void bubbleSort(std::vector<int>& inputArray) {
  
  if (inputArray.size() <= 1) {
    return;
  }

  for (int i = 0; i < inputArray.size(); i++) {
    for (int j = i + 1; j < inputArray.size(); j++) {
      if (inputArray[i] > inputArray[j]) {
        int temp = inputArray[j];
        inputArray[j] = inputArray[i];
        inputArray[i] = temp;
      }
    }
  }

}

void quickSort(std::vector<int> &inputArray) {
  m_QuickSort(inputArray, 0, inputArray.size() - 1);
}

void m_QuickSort(std::vector<int> &inputArray, int start, int end) {
  
  if (end <= start) return;

  int pivot = partition(inputArray, start, end);
  m_QuickSort(inputArray, start, pivot - 1);
  m_QuickSort(inputArray, pivot + 1, end);

}

int partition(std::vector<int> &inputArray, int start, int end) {
  
  int pivot = inputArray[end];
  int i = start - 1;
  int temp;
  int j = start;
  for (; j <= end - 1; j++) {
    if (inputArray[j] < pivot) {
      i++;
      temp = inputArray[i];
      inputArray[i] = inputArray[j];
      inputArray[j] = temp;
    }
  }

  i++;

  temp = inputArray[j];
  inputArray[i] = inputArray[end];
  inputArray[end] = temp;

  return i;

}
