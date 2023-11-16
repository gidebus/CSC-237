
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "InventoryItem.h"

using namespace std;

void printMenu() {
  cout << "\nSupported Commands: " << endl;
  cout << setw(5) << "" << "a. Add parts:  increase the units value for an existing InventoryItem object" << endl;
  cout << setw(5) << "" << "h. print help text" << endl;
  cout << setw(5) << "" << "i. Input inventory data from a file" << endl;
  cout << setw(5) << "" << "n. create a New inventory Item" << endl;
  cout << setw(5) << "" << "o. Output inventory data to a file" << endl;
  cout << setw(5) << "" << "p. Print inventory list on the screen" << endl;
  cout << setw(5) << "" << "q. Quit (end the program)" << endl;
  cout << setw(5) << "" << "r. Remove parts: reduce the units value for an existing InventoryItem object" << endl;
  cout << endl;
}

// TODO: Pass array by reference
// TODO: Implement try/catch
// TODO: Break into validating functions? Ex. is not negative, etc.

void addParts(InventoryItem inventory[]);
void addItem(int &itemCount, InventoryItem inventory[]);
void printInventory(int &itemCount, InventoryItem inventory[]);
void removeParts(InventoryItem inventory[]);
void inputFromFile(int &itemCount, InventoryItem inventory[]);
void outputFromFile(int &itemCount, InventoryItem inventory[]);
int splitLineToArray(string inputText, string inputDelim, string outputFieldArray[], int maxFields);

int main() {
  char userInput;
  int MAX_ITEMS = 100;
  InventoryItem inventory[MAX_ITEMS];
  int itemCount = 0;

  do {
    cout << "\nEnter command (or 'h' for help): ";
    cin >> userInput;

    if(userInput == 'a') {
      addParts(inventory);
    }

    if(userInput == 'h') {
      printMenu();
    }


    if(userInput == 'i') {
      inputFromFile(itemCount, inventory);
    }

    if(userInput == 'n') {
      addItem(itemCount, inventory);
    }

    if(userInput == 'o') {
      outputFromFile(itemCount, inventory);
    }

    if(userInput == 'p') {
      if(itemCount == 0) {
        cout << "There are no items yet. " << endl;
      }
      printInventory(itemCount, inventory);
    }

    if(userInput == 'r') {
      removeParts(inventory);
    }

    if(userInput == 'q') {
      break;
    }

  } while(true);

  cout << "\nExiting program...";
  return 0;
}

void addParts(InventoryItem inventory[]) {
  int itemIndex;
  int additionalParts;

  cout << "Choose a item Number: ";
  cin >> itemIndex;

  InventoryItem &item = inventory[itemIndex];

  if(item.getDescription().empty()) {
    cout << "Error: item is not in use. Select another item." << endl;
    return;
  }

  do {
    cout << "How many parts to add? ";
    cin >> additionalParts;

    if (additionalParts < 0 || additionalParts + item.getUnits() > 30) {
      cout << "Error: invalid number of units" << endl;
    } else {
      break;
    }
  } while(true);

  item.setUnits(additionalParts + item.getUnits());

}

void addItem(int &itemCount, InventoryItem inventory[]) {
  InventoryItem newItem;
  string newItemDescription;
  double newItemCost;
  int newItemUnits;

  cout << "Enter description for new Item: ";
  cin.ignore();
  getline(cin, newItemDescription);

  cout << "Enter unit cost for new Item: ";
  cin >> newItemCost;

  cout << "Enter initial quantity for the new item: ";
  cin >> newItemUnits;

  inventory[itemCount] = InventoryItem(newItemDescription, newItemCost, newItemUnits);
  itemCount++; // TODO: Account for 0 index initial value
  cout << "Announcing a new inventory Item: " << newItemDescription << endl;
  cout << "We now have " << itemCount << " different inventory item(s) in stock!" << endl;
}

void printInventory(int &itemCount, InventoryItem inventory[]) {
  // InventoryItem item;
  cout << setw(10) << "\nItem Num" << setw(30) << "Description" << setw(10) << "Cost" << setw(10) << "Quantity" << endl;
  cout << setw(10) << "--------" << setw(30) << "-----------" << setw(10) << "----" << setw(10) << "--------" << endl;
  for(int i = 0; i < itemCount; i++) {
    cout << left << setw(10) << i << setw(30) << inventory[i].getDescription() << setw(10) << fixed << setprecision(2) << inventory[i].getCost() << setw(10) << inventory[i].getUnits() << endl;
  }
  cout << "\n\n" << itemCount << " records." << endl;
}

void removeParts(InventoryItem inventory[]) {
  int itemIndex;
  int unitsToRemove;

  cout << "Choose a item Number: ";
  cin >> itemIndex;

    InventoryItem& item = inventory[itemIndex];

  if(item.getDescription().empty()) {
    cout << "Error: item is not in use. Select another item." << endl;
    return;
  }

  cout << "How many parts to remove? ";
  cin >> unitsToRemove;
  if (unitsToRemove < 0 || unitsToRemove > item.getUnits()) {
    cout << "Error: Invalid number of units" << endl;
    return;
  }

  item.setUnits(item.getUnits() - unitsToRemove);

}

int splitLineToArray(string inputText, string inputDelim,
	string outputFieldArray[], int maxFields)
{
	//	Local Variables:
	int nextFieldPosition = 0;		//	Start position of data field.
	int foundPosition;				//  Position where delimiter was found,
	int fieldCount = 0;		        //  Number of data fields found so far,
	bool endOfLine = false;			//	Flag -- end of input line detected,
	string dataField;				//  Copy of the data field.

	while (!endOfLine)
	{
		foundPosition = inputText.find(inputDelim, nextFieldPosition);
		if (foundPosition == string::npos)
		{
			// (Here if the string 'find' function reached the end of the input string.)
			endOfLine = true;
			foundPosition = inputText.length();

			if (foundPosition > nextFieldPosition)
			{
				dataField = inputText.substr(nextFieldPosition,
					foundPosition - nextFieldPosition);
				fieldCount++;
			}
		}
		else
		{
			// (Here if 'inputDelim' was found in the input string.)
			// Copy the data field contents from the input string to the
			// 'dataField' local variable.
			dataField = inputText.substr(nextFieldPosition, foundPosition - nextFieldPosition);
			fieldCount++;

			// Adjust 'nextFieldPosition' as preparation for finding NEXT delimiter.
			nextFieldPosition = foundPosition + 1;
		}

		if (fieldCount > 0)
		{
			if (fieldCount > maxFields)
			{
				cout << "ERROR at line __LINE__: too many input fields, fieldCount="
					<< fieldCount << endl;
			}
			else
			{
				outputFieldArray[fieldCount - 1] = dataField;
			}
		}
	} // (end while)


	return fieldCount;
} // (end function splitLineToArray )

void inputFromFile(int &itemCount, InventoryItem inventory[]) {
  string fileName;
  ifstream inputFile;

  cout << "Enter name of input file: ";
  cin >> fileName;
  int itemsAdded = 0;
  string data;

  inputFile.open(fileName);

  if(!inputFile.is_open()) {
    cout << "Error: File cannot be open or does not exist" << endl;
    return;
  }

  while(getline(inputFile, data)) {
    string productDetails[4];
    splitLineToArray(data, "|", productDetails, 4);
    if(itemCount < 100) {
      inventory[itemCount] = InventoryItem(productDetails[1], stod(productDetails[2]), stoi(productDetails[3]));
      itemCount++;
      itemsAdded++;
    } else {
      cout << "Error: Cannot add more items, inventory is full" << endl;
      break;
    }
  }


  cout << itemsAdded << " records loaded to array." << endl;
  inputFile.close();

}

void outputFromFile(int &itemCount, InventoryItem inventory[]) {
  string fileName;
  int itemsAdded;
  ofstream outputFile;
  
  cout << "Enter name of output file: ";
  cin >> fileName;

  outputFile.open(fileName);

  if(!outputFile.is_open()) {
    cout << "Error: File cannot be open or does not exist" << endl;
    return;
  }

  for(int i = 0; i < itemCount; i++) {
    outputFile << i << " | " 
    << inventory[i].getDescription() << " | " 
    << fixed << setprecision(2) << inventory[i].getCost() << " | " 
    << inventory[i].getUnits() << endl;
    itemsAdded++;
  }

  cout << itemsAdded << " records written to file." << endl;
  outputFile.close();
}
