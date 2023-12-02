
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
  cout << setw(5) << "" << "r. RECURSIVELY print the contents of the list" << endl;
  cout << setw(5) << "" << "b. Recursively print the contents of the list BACKWARDS" << endl;
  cout << setw(5) << "" << "n. recursively count the NUMBER of nodes in the list" << endl;
  cout << setw(5) << "" << "s. recursively calculate the SUM of all values in list" << endl;
  cout << setw(5) << "" << "l. recursively calculate the LARGEST of all values in list" << endl;
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

    if(userInput == 'r') {
      cout << "Recursive print of list, head=" << linkedList.getHead() << endl;
      linkedList.recursivePrint(linkedList.getHead());
    }
  
    if(userInput == 'b') {
      cout << "BACKWARDS recursive print of list, head=" << linkedList.getHead() << endl;
      linkedList.recursiveBackwardsPrint(linkedList.getHead());
    }
  
    if(userInput == 'n') {
      cout << "Number of nodes in the list =" << linkedList.recursiveCount(linkedList.getHead()) << endl;
    }
  
    if(userInput == 's') {
      cout << "The sum of all data values is " << linkedList.recursiveSum(linkedList.getHead()) << endl;
    }
  
    if(userInput == 'l') {
      cout << "LARGEST data value = " << linkedList.recursivelyFindLargestValue(linkedList.getHead()) << endl;
    }

  } while(true);

  cout << "\nExiting program...";
  return 0;
}
