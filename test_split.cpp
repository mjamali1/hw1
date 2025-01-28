/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

// #include <cstddef>

#include "split.h"

int main(int argc, char* argv[])
{

  // cout << "got here" << endl;

  Node in1 = Node (1, nullptr);
  Node in2 = Node (2, nullptr);
  Node in3 = Node (3, nullptr);
  Node in4 = Node (4, nullptr);
  Node in5 = Node (5, nullptr);

  in1.next = &in2;
  in2.next = &in3;
  in3.next = &in4;
  in4.next = &in5;

  // initialize odds / evens list
  Node* odds = nullptr;
  Node* evens = nullptr;

  // cout << "original list: ";
  // // printList(&in1);
  // cout << endl;
  
  // if(in1.value == 1){
  //   split(in1, odds, evens);
  // }
  split(in1.next, odds, evens);
  
  // cout << "odd list: ";
  // printList(odds);
  // cout << endl;
  // cout << "evens list: ";
  // printList(evens);
  // cout << endl;

  // printList(&in1);


  return 0;
}


