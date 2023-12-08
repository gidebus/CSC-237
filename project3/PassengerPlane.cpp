#include "PassengerPlane.h"
#include <sstream>


// Mutators
void PassengerPlane::setMaxNumberOfPassengers(int passenger) {
  this->maxNumberOfPassengers = passenger;
}

PassengerPlane* PassengerPlane::addNewPassengerPlane() {
  PassengerPlane* newPassengerPlane = new PassengerPlane();
  return newPassengerPlane;
}

// Accessors
int PassengerPlane::getMaxNumberOfPassengers() const {
  return this->maxNumberOfPassengers;
}

string PassengerPlane::getDescription() const {
  stringstream stringBuilder;

  stringBuilder << "ID#: " << getAirplane_ID() << ", " 
  << "Manufacturer: " << getManufacturer() << ", "
  << "Model: " << getModel() << ", "
  << "Year: " << getYearBuilt() << ", "
  << "Hours " << getFlightHours() << ", "
  << "Max Cargo: " << getMaxNumberOfPassengers() << ".";

  return stringBuilder.str();
}