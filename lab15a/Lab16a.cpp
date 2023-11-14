
#include <iostream>
#include <iomanip>
#include "ProductionWorker.h"

using namespace std;

void printMenu() {
  cout << "\nSupported Commands: " << endl;
  cout << setw(5) << "" << "c. create a new ProductionWorker object" << endl;
  cout << setw(5) << "" << "h. print help text" << endl;
  cout << setw(5) << "" << "p. print ProductionWorker information" << endl;
  cout << setw(5) << "" << "q. quit (end the program)" << endl;
  cout << endl;
}

int main() {
  char userInput;
  ProductionWorker* worker = nullptr;

  do {
    cout << "\nEnter command (or 'h' for help): ";
    cin >> userInput;

    if(userInput == 'h') {
      printMenu();
    }

    if(userInput == 'c') {
      worker = ProductionWorker::createNewProductionWorker();
      if(worker == nullptr) {
        delete worker;
        worker = ProductionWorker::createNewProductionWorker();
      }
    }

    if(userInput == 'p') {
      worker->printWorkerData();
    }

    if(userInput == 'q') {
      delete worker;
      break;
    }

  } while(true);

  cout << "\nExiting program...";
  return 0;
}