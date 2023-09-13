#include <iostream>
#include <iomanip>

using namespace std;

int calculateMilesTraveled(int odometerAtOrigin, int odometerAtDestination) {
  int milesTraveled = odometerAtOrigin - odometerAtDestination;
  return milesTraveled;
}

float calculateMilesPerGallon(float milesTraveled, float gallonsPurchased) {
  float milesPerGallon = milesTraveled / gallonsPurchased;
  return milesPerGallon;
}

int validateInitialOdometerInput(int initialOdometer) {
  while(true) {
    if (
      (cin >> initialOdometer) && 
      (initialOdometer == static_cast<int>(initialOdometer)) && 
      (initialOdometer >= 0)
    ) {
      cin.ignore(100,'\n');
      return initialOdometer;
    }
    cin.clear();
    cin.ignore(100,'\n');
    cout << "Please enter a positive integer: ";
  }
}

int validateLatestOdometerInput(int initialOdometer, int finalOdometer) {
  while(true) {
    if (cin >> finalOdometer && finalOdometer > initialOdometer) {
      cin.ignore(100, '\n');
      return finalOdometer;
    }
    cin.clear();
    cin.ignore(100,'\n');
    cout << "Please enter a positive integer greater than previous odometer: ";
  }
}

float validateGallonsPurchased(float gallonsPurchased) {
  while(true) {
    if(cin >> gallonsPurchased && gallonsPurchased > 0) {
      return gallonsPurchased;
    }
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Please enter a positive decimal number greater than 0: ";
  }
}

int main() {
  int odometerAtPreviousFillUp, odometerAtLatestFillUp;
  float milesTraveled, gallonsPurchasedAtLatestFillUp, milesPerGallon;

  cout << "Enter Odometer at PREVIOUS fill-up: ";
  odometerAtPreviousFillUp = validateInitialOdometerInput(odometerAtPreviousFillUp);


  cout << "Enter Odometer at LATEST fill-up: ";
  odometerAtLatestFillUp = validateLatestOdometerInput(odometerAtPreviousFillUp, odometerAtLatestFillUp);


  milesTraveled = calculateMilesTraveled(odometerAtLatestFillUp, odometerAtPreviousFillUp);
  cout << "Distanced traveled was " << fixed << setprecision(1) << milesTraveled << " miles." << endl;

  cout << "Enter gallons purchased at LATEST fill-up: ";
  gallonsPurchasedAtLatestFillUp = validateGallonsPurchased(gallonsPurchasedAtLatestFillUp);


  milesPerGallon = calculateMilesPerGallon(milesTraveled, gallonsPurchasedAtLatestFillUp);
  cout << "Your fuel economy is: " << fixed << setprecision(1) << milesPerGallon << " MPG." << endl;

  return 0;
}