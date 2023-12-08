#include "Airplane.h"
#include "CargoPlane.h"
#include "PassengerPlane.h"

using namespace std;

void printMenu() {
  cout << "\nSupported Commands: " << endl;
  cout << setw(5) << "" << "a. ADD a new airplane to the fleet." << endl;
  cout << setw(5) << "" << "f. FLY a plane in the fleet." << endl;
  cout << setw(5) << "" << "h. print HELP text." << endl;
  cout << setw(5) << "" << "p. PRINT current fleet information." << endl;
  cout << setw(5) << "" << "q. Quit (end the program)" << endl;
  cout << setw(5) << "" << "r. REMOVE airplane from the fleet" << endl;
  cout << endl;
}

int main() {
  vector<Airplane*> fleet; // Becomes the argument for each function
  char userInput;

  do {
    cout << "\nEnter command (or 'h' for help): ";
    cin >> userInput;

    if(userInput == 'a') {
      // The airplane object must be called using the new command
      cout << "You chose A" << endl;
    };
    
    if(userInput == 'f') {
      cout << "You chose F" << endl;
    };

    if(userInput == 'h') {
      printMenu();
    };

    if(userInput == 'i') {
      int newValue;
    };

    if(userInput == 'p') {
      cout << "You chose P" << endl;
    };
  
    if(userInput == 'r') {
      cout << "You chose R" << endl;
    };
    
    if(userInput == 'q') {
      break;
    };

  } while(true);

  cout << "\nExiting program...";
  return 0;
}