#include "IntList.h"
#include <iostream>
#include <iomanip>

using namespace std;

IntList::~IntList() {
  while(head != nullptr) {
    ListNode* tempNode = head;
    head = head->next;
    delete tempNode;
  }
}

void IntList::appendNode(int value) {
  ListNode* newNode = new ListNode(value);

  if(head == nullptr) {
    head = newNode;
    return;
  }

  ListNode* tempNode = head;
  while(tempNode->next != nullptr) {
    tempNode = tempNode->next;
  }
  tempNode->next = newNode;
}

void IntList::insertNode(int value) {
  ListNode* newNode = new ListNode(value);

  if(head == nullptr || head->value > newNode->value) {
    newNode->next = head;
    head = newNode;
    return;
  }

  ListNode* tempNode = head;
  while(head->next != nullptr && head->next->value < newNode->value) {
    tempNode = tempNode->next;
  }
  newNode->next = tempNode->next;
  tempNode->next = newNode;
}

void IntList::deleteNode(int value) {
  ListNode* currentNode = head;
  ListNode* previousNode = nullptr;

  if(currentNode != nullptr && currentNode->value == value) {
    head = currentNode->next;
    delete currentNode;
    return;
  }

  while(currentNode != nullptr && currentNode->value != value) {
    previousNode = currentNode;
    currentNode = currentNode->next;

    if(currentNode == nullptr) {
      return;
    }

    previousNode->next = currentNode->next;
    delete currentNode;
  }
}

void IntList::maxValue() {
  ListNode* currentNode = head;

  if(currentNode == nullptr) {
    cout << "List is empty." << endl;
    return;
  }

  int currentMax = currentNode->value;
  ListNode* nextNode = currentNode->next;
  while(nextNode != nullptr) {
    if(nextNode->value > currentMax) {
      currentMax = nextNode->value;
    }
    nextNode = nextNode->next;
    cout << "Maximum value in list = " << currentMax << endl;
  }
}

void IntList::print() {
  ListNode* currentNode = head;

  if(currentNode == nullptr) {
    cout << "List is empty." << endl;
    return;
  }

  cout << "head=" << currentNode << endl;
  while(currentNode != nullptr) {
    cout << currentNode << ": value= " << currentNode->value << " next= " << currentNode->next << endl;
    currentNode = currentNode->next;
  }
  cout << endl;
}

int IntList::length() {
  int nodeCount = 0;
  ListNode* currentNode = head;

  while(currentNode != nullptr) {
    nodeCount++;
    currentNode = currentNode->next;
  }
  
  return nodeCount;
}

int IntList::total() {
  int currentTotal = 0;
  ListNode* currentNode = head;

  while(currentNode != nullptr) {
    currentTotal += currentNode->value;
    currentNode = currentNode->next;
  }

  return currentTotal;
}
