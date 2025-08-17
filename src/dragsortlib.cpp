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
