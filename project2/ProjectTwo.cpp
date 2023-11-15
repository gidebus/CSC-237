
#include <iostream>
#include <iomanip>
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
  InventoryItem item;

  cout << "Choose a item Number: ";
  cin >> itemIndex;

  item = inventory[itemIndex];

  if(item.getDescription().empty()) {
    cout << "Error: item is not in use. Select another item." << endl;
    return;
  }

  cout << "How many parts to add? ";
  cin >> additionalParts;
  if (additionalParts < 0 || additionalParts + item.getUnits() > 30) {
    cout << "Error: invalid number of units" << endl;
    return;
  }

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
  cout << "\nItem Num" << setw(15) << "Description" << setw(26) << "Cost" << setw(12) << "Quantity" << endl;
  cout << "--------" << setw(15) << "-----------" << setw(26) << "----" << setw(12) << "--------" << endl;
  for(int i = 0; i < itemCount; i++) {
    // item = inventory[i];
    cout << i << setw(18) << inventory[i].getDescription() << setw(31) << inventory[i].getCost() << setw(12) << inventory[i].getUnits() << endl;
  }
  cout << "\n\n" << itemCount << " records." << endl;
}

void removeParts(InventoryItem inventory[]) {
  int itemIndex;
  int unitsToRemove;
  InventoryItem item;

  cout << "Choose a item Number: ";
  cin >> itemIndex;

  item = inventory[itemIndex];

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

void inputFromFile(int &itemCount, InventoryItem inventory[]) {

}