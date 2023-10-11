#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


void populateIntegerArray(int *arrayPtr, int arraySize);
void displayIntegerArray(int *arrayPtr, int arraySize);
int findMaximumInteger(int *arrayPtr, int arraySize);

int main() {
  int arraySize;

  cout << "\nEnter desired array size: ";
  cin >> arraySize;

  int* arrayPtr = new int[arraySize];

  populateIntegerArray(arrayPtr, arraySize);

  displayIntegerArray(arrayPtr, arraySize);

  int maxValue = findMaximumInteger(arrayPtr, arraySize);
  cout << "\nMaximum Value in the Array: " << dec << maxValue << endl;

  cout << "\nDELETING array at arrayPtr = " << arrayPtr << endl;
  delete[] arrayPtr;

  cout << "\nExit the program." << endl;
  return 0;
}

void populateIntegerArray(int *arrayPtr, int arraySize) {
  cout << "\narrayPtr = " << arrayPtr << endl;
  cout << endl;
  for(int i = 0; i < arraySize; i++) {
    cout << "Enter value for array element " << i << " : ";
    cin >> arrayPtr[i];
  }
}

void displayIntegerArray(int *arrayPtr, int arraySize) {
  cout << endl;
  cout << setfill('0');
  for(int i = 0; i < arraySize; i++) {
    cout << hex << uppercase << setw(16)<< &arrayPtr[i] << ": " 
      << "arrayPtr[" << "] = " << dec << arrayPtr[i] 
      << " (Hex " << hex << setw(8) << arrayPtr[i] << ")" 
      << endl;
  }
  cout << setfill(' '); 
}

int findMaximumInteger(int *arrayPtr, int arraySize) {
  int max = arrayPtr[0];
  for(int i = 1; i < arraySize; i++) {
    if(arrayPtr[i] > max) {
      max = arrayPtr[i];
    }
  }
  return max;
}
