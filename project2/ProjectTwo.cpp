
#include <iostream>
#include <iomanip>

using namespace std;

void printMenu() {
  cout << "\nSupported Commands: " << endl;
  cout << setw(5) << "" << "a. Add parts:  increase the units value for an existing InventoryItem object" << endl;
  cout << setw(5) << "" << "h. print help text" << endl;
  cout << setw(5) << "" << "i. Input inventory data from a file" << endl;
  cout << setw(5) << "" << "n. create a New inventory Item" << endl;
  cout << setw(5) << "" << "o. Output inventory data to a file" << endl;
  cout << setw(5) << "" << "p. Print inventory list on the screen" << endl;
  cout << setw(5) << "" << "q. Quit (end the program)" << endl;
  cout << setw(5) << "" << "r. Remove parts: reduce the units value for an existing InventoryItem object" << endl;
  cout << endl;
}

int main() {
  char userInput;

  do {
    cout << "\nEnter command (or 'h' for help): ";
    cin >> userInput;

    if(userInput == 'h') {
      printMenu();
    }

    if(userInput == 'q') {
      break;
    }

  } while(true);

  cout << "\nExiting program...";
  return 0;
}