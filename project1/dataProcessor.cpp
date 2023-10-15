// CSC-237 Project1
// Student Name: Gilberto Del Busto
// Due Date: Monday, October 16 at 10:00 p.m.
// Description:
  // This program reads a text document, “packs” the ASCII characters
  // from that document into unsigned int variables, and outputs those variables
  // to another text file as integers in HEXADECIMAL format.
  // This program also reverses the process, converting the unsigned int numbers
  // back into a copy of the original text document.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void displayMenu();
char validateUserInput(char);
void packData(string, string);
void unpackData(string, string);

int main() {
  bool keepGoing = true;
  char userInput;

  string inputFile;
  string packedFile;
  string unpackedFile;

  do {
    displayMenu();
    cout << "Enter a single character command (or 'h' for help): ";
    userInput = validateUserInput(userInput);

    if(userInput == 'p') {
      cout << "\nYou selected p \n" << endl;
      cin.clear();
      cout << "Enter the input filename: ";
      cin >> inputFile;
      cout << "Enter the output filename: ";
      cin >> packedFile;
      packData(inputFile, packedFile);
    } 

    if(userInput == 'u') {
      cout << "\nYou selected u \n" << endl;
      cin.clear();
      cout << "Enter the packed filename: ";
      cin >> packedFile;
      cout << "Enter the unpacked filename: ";
      cin >> unpackedFile;
      unpackData(packedFile, unpackedFile);
    }

    if(userInput == 'h') {
      cout << "\nYou selected h \n" << endl;
    }

    if(userInput == 'q') {
      cout << "\nAre you sure that you want to exit the program? (y or n): ";
      cin >> userInput;
      if(userInput == 'y') {
        keepGoing = false;
      }
    }

  } while(keepGoing);

  cout << "\nExiting the program." << endl;
  return 0;
}

void packData(string inputFile, string packedFile) {
  ifstream inFile(inputFile);
  ofstream outFile(packedFile);
  string data;

  while(getline(inFile, data)) {
    data += "\n";
    int startIndex = 0;
    while(startIndex < data.length()) {
      int endIndex = startIndex + 4;
      if (endIndex > data.length()) {
        endIndex = data.length();
      }
      unsigned int dataPackage = 0;
      for(int i = startIndex; i < endIndex; ++i) {
        dataPackage = (dataPackage << 8) | static_cast<unsigned char>(data[i]);
      }
      outFile << hex << dataPackage << endl;
      startIndex = endIndex;
    }
  }
  inFile.close();
  outFile.close();
}

void unpackData(string packedFile, string unpackedFile) {
  
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
