// CSC-237 Project1
// Student Name: Gilberto Del Busto
// Due Date:
// Description:
  // This program reads a text document, “packs” the ASCII characters
  // from that document into unsigned int variables, and outputs those variables
  // to another text file as integers in HEXADECIMAL format.
  // This program also reverses the process, converting the unsigned int numbers
  // back into a copy of the original text document.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayMenu();
char validateUserInput(char);


int main() {

  bool keepGoing = true;
  char userInput;

  do {
    displayMenu();
    cout << "Enter a single character command (or 'h' for help): ";
    userInput = validateUserInput(userInput);

    if(userInput == 'p') {
      cout << "\nYou selected p \n" << endl;
    } 

    if(userInput == 'u') {
      cout << "\nYou selected u \n" << endl;
    }

    if(userInput == 'h') {
      cout << "\nYou selected h \n" << endl;
    }

    if(userInput == 'q') {
      cout << "\nYou selected q \n" << endl;
      keepGoing = false;
    }

  } while(keepGoing);

  cout << "\nExiting the program." << endl;
  return 0;
}

void displayMenu() {
    cout << "\nSupported commands: \n\n" 
      << "p Pack a text document into unsigned integers. \n"
      << "u Unpack unsigned integers to text \n"
      << "h Output “help” text \n"
      << "q Exit the program. \n"
      << endl;
}

char validateUserInput(char userInput) {
  while(true) {
    if(
      (cin >> userInput) && 
      (userInput == 'p') || 
      (userInput == 'u') || 
      (userInput == 'h') || 
      (userInput == 'q')
      ) {
      return userInput;
    }
    cin.clear();
    cin.ignore(100,'\n');
    cout << "Please only enter p, u, h, or q: ";
  }
  cin.ignore(100,'\n');
}
