#include <iostream>

using namespace std;

int calculateMilesTraveled(int odometerAtOrigin, int odometerAtDestination) {
  int milesTraveled = odometerAtOrigin - odometerAtDestination;
  return milesTraveled;
}

float calculateMilesPerGallon(float milesTraveled, float gallonsPurchased) {
  float milesPerGallon = milesTraveled / gallonsPurchased;
  return milesPerGallon;
}

int main() {
  int odometerAtPreviousFillUp, odometerAtLatestFillUp;
  float milesTraveled, gallonsPurchasedAtLatestFillUp, milesPerGallon;

  cout << "Enter Odometer at PREVIOUS fill-up: ";
  cin >> odometerAtPreviousFillUp;

  cout << "Enter Odometer at LATEST fill-up: ";
  cin >> odometerAtLatestFillUp;

  milesTraveled = calculateMilesTraveled(odometerAtLatestFillUp, odometerAtPreviousFillUp);
  cout << "Distanced traveled is was " << milesTraveled << endl;

  cout << "Enter gallons purchased at LATEST fill-up: ";
  cin >> gallonsPurchasedAtLatestFillUp;

  milesPerGallon = calculateMilesPerGallon(milesTraveled ,gallonsPurchasedAtLatestFillUp);
  cout << "Your fuel economy is: " << milesPerGallon << endl;

  return 0;
}