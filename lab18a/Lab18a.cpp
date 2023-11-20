
#include "IntList.h"

using namespace std;

void printMenu() {
  cout << "\nSupported Commands: " << endl;
  cout << setw(5) << "" << "a. APPEND a value to the list." << endl;
  cout << setw(5) << "" << "c. COUNT the nodes in the list (display LENGTH of the list)." << endl;
  cout << setw(5) << "" << "d. DELETE a value from the list." << endl;
  cout << setw(5) << "" << "i. INSERT a value into the list." << endl;
  cout << setw(5) << "" << "m. display MAXIMUM (largest) value in the list." << endl;
  cout << setw(5) << "" << "p. PRINT the list contents." << endl;
  cout << setw(5) << "" << "h. print this help text." << endl;
  cout << setw(5) << "" << "q. Quit (end the program)" << endl;
  cout << setw(5) << "" << "t. display TOTAL (sum) of all values in the list." << endl;
  cout << endl;
}

int main() {
  char userInput;
  IntList linkedList;

  do {
    cout << "\nEnter command (or 'h' for help): ";
    cin >> userInput;

    if(userInput == 'a') {
      int newValue;

      cout << "Enter number to append into the list: ";
      cin >> newValue;

      linkedList.appendNode(newValue);
    };
    
    if(userInput == 'c') {
      int length = linkedList.length();
      cout << "Total of all list values = " << length << " nodes." << endl;
    };

    if(userInput == 'd') {
      int value;

      cout << "Enter number to delete from the list: ";
      cin >> value;

      linkedList.deleteNode(value);
    };

    if(userInput == 'i') {
      int newValue;

      cout << "Enter number to insert into the list: ";
      cin >> newValue;

      linkedList.insertNode(newValue);
    };
    
    if(userInput == 'm') {
      linkedList.maxValue();
    };

    if(userInput == 'p') {
      linkedList.print();
    };
  
    if(userInput == 'h') {
      printMenu();
    };
    
    if(userInput == 'q') {
      break;
    };

    if(userInput == 't') {
      int total = linkedList.total();
      cout << "Total of all list values = " << total << endl;
    };
    
  } while(true);

  cout << "\nExiting program...";
  return 0;
}
