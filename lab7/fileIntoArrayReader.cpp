
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int getHighest(int array[], int size) {
  int highest = array[0];
  for(int i = 1; i < size; i++) {
    if(array[i] > highest) {
      highest = array[i];
    }
  }
  return highest;
}

int getLowest(int array[], int size) {
  int lowest = array[0];
  for(int i = 1; i < size; i++) {
    if(array[i] < lowest) {
      lowest = array[i];
    }
  }
  return lowest;
}

int getSum(int array[], int size) {
  int sum = 0;
  for(int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

double getAverage(int array[], int size) {
  int sum = getSum(array, size);
  double average = static_cast<double>(sum) / size;
  return average;
}

bool readFile(string fileName, int array[], int& count) {
  ifstream inFile(fileName);

  if(!inFile) {
    return false;
  }

  int num;

  while(inFile >> num) {
    array[count] = num;
    count++;
  }

  inFile.close();
  return true;
}

int main() {
  const int ARRAY_SIZE = 100;
  int numbers[ARRAY_SIZE];
  int count = 0;
  string inputFileName;
  int lowest, highest, sum;
  double average;

  cout << "Enter name of input file with the extension. Ex fileName.txt: ";
  getline(cin, inputFileName);
  cout << " \n You selected " << inputFileName << endl;

  // Read File
  if(!readFile(inputFileName, numbers, count)) {
    cout << "Error: Could not open file or does not exist." << endl;
    exit(0);
  }

  // Main Ouput
  cout << count << " numbers read from input file." << endl;

  highest = getHighest(numbers, count);
  cout << "The highest value is " << highest << endl;
  
  lowest = getLowest(numbers, count);
  cout << "The lowest value is " << lowest << endl;

  sum = sum = getSum(numbers, count);
  cout << "The sum of the numbers is " << sum << endl;

  average = getAverage(numbers, count);
  cout << "The average of the numbers is " << average << endl;
}