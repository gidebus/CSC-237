// Specification file for the IntList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include <iostream>
#include <iomanip>

class IntList
{
  private:
    // Declare a structure for the list
    struct ListNode
    {
        int value;           // The value in this node
        struct ListNode *next;  // To point to the next node
        ListNode(int value) : value(value), next(nullptr) {};
    }; 

    ListNode *head;            // List head pointer

  public:
    // Constructor
    IntList() : head(nullptr) {};
        
    // Destructor
    ~IntList();
        
    // Linked list operations
    void appendNode(int); // Adds a node to the back
    void insertNode(int); // Adds a node keeping the order
    void deleteNode(int); // Deletes node with the matching value
    void maxValue(); // Displays the highest data value in the list
    void print(); // Outputs the values for all the node to the terminal
    int length(); // Outputs how many nodes are in the list
    int total(); // Returns the sum of all the values in the list

    ListNode* getHead();
    void recursivePrint(ListNode*);
    void recursiveBackwardsPrint(ListNode*);
    int recursiveCount(ListNode*);
    int recursiveSum(ListNode*);
    int recursivelyFindLargestValue(ListNode*);
};

#endif