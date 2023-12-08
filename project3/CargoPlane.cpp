#include "CargoPlane.h"
#include <sstream>

// Mutators
void CargoPlane::setMaxCargoWeight(int s) {
  this->maxCargoWeight = s;
}

CargoPlane* CargoPlane::addNewCargoPlane() {
  CargoPlane* newCargoPlane = new CargoPlane();
  return newCargoPlane;
}

// Accessors
int CargoPlane::getMaxCargoWeight() const {
  return this->maxCargoWeight;
}

string CargoPlane::getDescription() const {
    stringstream stringBuilder;

    stringBuilder << "ID#: " << getAirplane_ID() << ", " 
    << "Manufacturer: " << getManufacturer() << ", "
    << "Model: " << getModel() << ", "
    << "Year: " << getYearBuilt() << ", "
    << "Hours " << getFlightHours() << ", "
    << "Max Cargo: " << getMaxCargoWeight() << ".";

    return stringBuilder.str();
}