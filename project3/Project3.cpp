// Name: Gilberto Del Busto
// Due Date: Wednesday December 13th, 2023

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

// function to create a cargo plane
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
  cout << "\nNew Airplane: \n" << newCargoPlane->getDescription() << endl;
}

// function to create a passenger plane
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
  cout << "\nNew Airplane: \n" << newPassengerPlane->getDescription() << endl;
}

// function to add flight hours to an airplane
void flyAirplane(vector<Airplane*>& fleet) {
  int airplaneID, flightDuration;
  Airplane* foundAirplane = nullptr;
  
  cout << "\nWhich airplane do you want to fly?: ";
  cin >> airplaneID;

  for(size_t i = 0; i < fleet.size(); ++i) {
    if(fleet[i]->getAirplane_ID() == airplaneID) {
      foundAirplane = fleet[i];
      break;
    }
  }

  if(foundAirplane != nullptr) {
    cout << "\nLength of flight (hours)?: ";
    cin >> flightDuration;

    cout << "\nChoosing airplane: \n" << foundAirplane->getDescription();
    foundAirplane->setFlightHours(foundAirplane->getFlightHours() + flightDuration);
    cout << "\nFlight complete: \n" << foundAirplane->getDescription();

  } else {
    cout << "\nAirplane " << airplaneID << " not found. " << endl;
  }
}

// function to print all airplanes
void printFleet(vector<Airplane*>& fleet) {
  cout << "\nCurrent fleet contains " << fleet.size() << " airplane(s):" << endl;
  for(size_t i = 0; i < fleet.size(); i++) {
    cout << endl << fleet[i]->getDescription() << endl;
  }
}

// function to remove an airplane
void removeAirplane(vector<Airplane*>& fleet) {
  int airplaneID, locationID;
  Airplane* foundAirplane = nullptr;

  cout << "\nWhich airplane do you want to remove?: ";
  cin >> airplaneID;


  for(size_t i = 0; i < fleet.size(); ++i) {
    if(fleet[i]->getAirplane_ID() == airplaneID) {
      locationID = i;
      foundAirplane = fleet[locationID];
      break;
    }
  }

  if(foundAirplane != nullptr) {
    string removedAirplaneDescription =  foundAirplane->getDescription();

    cout << "\nChoosing airplane: \n" << foundAirplane->getDescription();

    delete foundAirplane;

    fleet.erase(fleet.begin() + locationID);
    cout << "\n Removal complete: \n Airplane " << removedAirplaneDescription << " has been removed.";

  } else {
    cout << "\nAirplane " << airplaneID << " not found. " << endl;
  }
  
}

int main() {
  vector<Airplane*> fleet;
  char userInput;

  do {
    cout << "\n\nEnter command (or 'h' for help): ";
    cin >> userInput;

    if(userInput == 'a') {
      char typeOfAirplane;
      // The airplane object must be called using the new command
      cout << "\nEnter type of airplane (c = cargo, p = passenger): " << endl;
      cin >> typeOfAirplane;
      

      if(typeOfAirplane != 'c' && typeOfAirplane != 'p') {
        cout << "\nSorry. That is not a type of plane." << endl;
      }

      if(typeOfAirplane == 'c') {
        createCargoPlane(fleet);
      };

      if(typeOfAirplane == 'p') {
        createPassengerPlane(fleet);
      };

      cout << "\naddNewAirplane: \nSize of fleet = " << fleet.size() << endl;
    };
    
    if(userInput == 'f') {
      flyAirplane(fleet);
    };

    if(userInput == 'h') {
      printMenu();
    };

    if(userInput == 'i') {
      int newValue;
    };

    if(userInput == 'p') {
      printFleet(fleet);
    };
  
    if(userInput == 'r') {
      removeAirplane(fleet);
    };
    
    if(userInput == 'q') {
      break;
    };

  } while(true);

  cout << "\nExiting program...";
  return 0;
}