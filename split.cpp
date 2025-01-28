/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit  non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype  a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // if list is empty
  if(in == nullptr){
    return;
  }

  Node* current = in; // current position
  in = in->next; // shifts to the next position

  if((current->value) % 2 == 0)
  {
    evens = current;
    evens->next = nullptr;
    split(in, odds, evens->next);
  }
  else
  {
    odds = current;
    odds->next = nullptr;
    split(in, odds->next, evens);
  }

  // recursive call
  // split(in, odds, evens);

}

/* If you needed a helper function, write it here */

// void printList(Node* head)
// {
//   Node* curr = head;
//   (curr != nullptr){
//     cout << curr->value;
//     cout << " -> "; 
//     curr = curr -> next;
//   }
//   cout << "nullptr" << endl;

// }

