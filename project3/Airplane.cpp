#include "Airplane.h"
#include <sstream>

int Airplane::last_airplane_ID_issued = 0;
// Constructor
Airplane::Airplane() {
  airplane_ID = ++last_airplane_ID_issued;
  manufacturer = "";
  model = "";
  yearBuilt = 0;
  flightHours = 0;
}

Airplane::Airplane(string manufacturer, string model,int year, int hours) {
  airplane_ID = ++last_airplane_ID_issued;
  this->manufacturer = manufacturer;
  this->model = model;
  this->yearBuilt = year;
  this->flightHours = hours;
}

// Accessors
string Airplane::getManufacturer() const {
  return manufacturer;
}

string Airplane::getModel() const {
  return model;
}

int Airplane::getAirplane_ID() const {
  return airplane_ID;
}

int Airplane::getYearBuilt() const {
  return yearBuilt;
}

int Airplane::getFlightHours() const {
  return flightHours;
}

int Airplane::get_last_airplane_ID_issued() {
  return last_airplane_ID_issued;
}

string Airplane::getDescription() const {
  stringstream stringBuilder;

  stringBuilder << "ID#: " << this->airplane_ID << ", " 
  << "Manufacturer: " << this->manufacturer << ", "
  << "Model: " << this->model << ", "
  << "Year: " << this->yearBuilt << ", "
  << "Hours " << this->flightHours << ", ";

  return stringBuilder.str();
}

// Mutators
void Airplane::setManufacturer(string company) {
  this->manufacturer = company;
}

void Airplane::setModel(string name) {
  this->model = name;
}

void Airplane::setYearBuilt(int year) {
  this->yearBuilt = year;
}

void Airplane::setFlightHours(int hours) {
  this->flightHours = hours;
}