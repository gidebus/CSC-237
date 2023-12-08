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

void createCargoPlane(vector<Airplane*>& fleet) {
  string manufacturer, model;
  int year, flightHours, maxCargoWeight;

  cout << "\nEnter name of manufacturer: ";
  cin >> manufacturer;

  cout << "\nEnter model: ";
  cin >> model;

  cout << "\nEnter year built: ";
  cin >> year;

  cout << "\nEnter flight hours: ";
  cin >> flightHours;

  cout << "\nEnter maximum cargo weight: ";
  cin >> maxCargoWeight;

  CargoPlane* newCargoPlane = new CargoPlane(manufacturer, model, year, flightHours, maxCargoWeight);
  fleet.push_back(newCargoPlane);
  cout << "\nNew Airplane: " << newCargoPlane->getDescription();
}

void createPassengerPlane(vector<Airplane*>& fleet) {
  string manufacturer, model;
  int year, flightHours, maxNumberOfPassengers;

  cout << "\nEnter name of manufacturer: ";
  cin >> manufacturer;

  cout << "\nEnter model: ";
  cin >> model;

  cout << "\nEnter year built: ";
  cin >> year;

  cout << "\nEnter flight hours: ";
  cin >> flightHours;

  cout << "\nEnter maximum Passenger count: ";
  cin >> maxNumberOfPassengers;

  PassengerPlane* newPassengerPlane = new PassengerPlane(manufacturer, model, year, flightHours, maxNumberOfPassengers);
  fleet.push_back(newPassengerPlane);
  cout << "\nNew Airplane: " << newPassengerPlane->getDescription();
}

int main() {
  vector<Airplane*> fleet; // Becomes the argument for each function
  char userInput;

  do {
    cout << "\n\nEnter command (or 'h' for help): ";
    cin >> userInput;

    if(userInput == 'a') {
      char typeOfAirplane;
      // The airplane object must be called using the new command
      cout << "Enter type of airplane (c = cargo, p = passenger): " << endl;
      cin >> typeOfAirplane;

      if(typeOfAirplane != 'c' || typeOfAirplane != 'p') {
        cout << "\nSorry. That is not a type of plane." << endl;
      }

      if(typeOfAirplane == 'c') {
        createCargoPlane(fleet);
      };

      if(typeOfAirplane == 'p') {
        createPassengerPlane(fleet);
      };

      cout << "\naddNewAirplane: Size of fleet = " << fleet.size() << endl;
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