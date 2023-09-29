
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

int validateUserInput(int userInput) {
  while(true) {
    if(cin >> userInput) {
      return userInput;
    }
    cin.clear();
    cin.ignore(100,'\n');
    cout << "Please enter only integers: ";
  }
  cin.ignore(100,'\n');
}

int main() {
  const int SECONDS_PER_DAY = 86400; // Seconds in a day
  const int SECONDS_PER_HOUR = 3600; // Seconds in an hour
  const int SECONDS_PER_MINUTE = 60; // Seconds in a minute

  int totalSeconds; // To hold a number of seconds (entered by user)
  int days, hours, minutes, seconds; 
  int remainder_seconds_in_day, remainder_seconds_in_hour, remainder_seconds_in_minute;
  
  while(true) {
    cout << "Enter a number of seconds (or negative number to EXIT): ";
    totalSeconds = validateUserInput(totalSeconds);
    cout << "Total seconds = " << totalSeconds << ": \t";

    if(totalSeconds <= 0) {
      break;
    }

    days = totalSeconds / SECONDS_PER_DAY;
    remainder_seconds_in_day = totalSeconds % SECONDS_PER_DAY;
    
    if(days > 0) {
      cout << "Days = " << days << "\t";
    }

    hours = remainder_seconds_in_day / SECONDS_PER_HOUR;
    remainder_seconds_in_hour = remainder_seconds_in_day % SECONDS_PER_HOUR;
    
    if(hours > 0) {
      cout << "Hours = " << hours << "\t";
    }

    minutes = remainder_seconds_in_hour / SECONDS_PER_MINUTE;
    seconds = remainder_seconds_in_hour % SECONDS_PER_MINUTE;
   
    if(minutes > 0) {
      cout << "Minutes = " << minutes << "\t";
    }

    if(seconds > 0) {
      cout << "Seconds = " << seconds << "\t";
    }

    cout << endl;
  }

  return 0;
}
