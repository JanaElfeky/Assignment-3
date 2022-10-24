//
//  main.cpp
//  Assignment 3
//
//  Created by jana on 17/10/2022.
//

#include <iostream>
#include <vector>
#include <iostream>
#include "Linked List.hpp"
using namespace std;

void insertAfter(LinkedList list, int firstValue, int secondValue); //header for insertAfter function

int main(int argc, const char * argv[]) {
    LinkedList list;
    vector<int> userVector;
    int n, userData;
    cout << "please input how many numbers you want to add to the vector" << endl;
    cin >> n; //user inputs how many values he wants to add in the vector
    cout << "please enter the values you want in the vector" << endl;
    for (int i=0;i<n;i++){
        cin >> userData; //user enters each value
        userVector.push_back(userData); //inputting each value in the vector
    }
    
    list=list.create(userVector); //inputting the vector elements in the linked list
    list.print(); //printing the linked list elements before manipulation
    insertAfter(list, 4, 6);
    list.print(); //printing after manipulation
    cout << "the sum of the elements is: " << list.sum() << endl; //output the sum of the values in the linked list
    return 0;
}

void insertAfter(LinkedList list, int firstValue, int secondValue){
    node *newNode = new node; //initializing new node
    newNode->value=secondValue; //making value of new node = value entered by the user
    node* mirror; //initialzing mirror pointer
    mirror=list.getHead(); //making mirror point to first node of the list
    while (mirror->value != firstValue){
        mirror=mirror->next; //incrementing mirror until it points to the node before the one they want to insert
    }
    newNode->next=mirror->next; //making the new node point to the node mirror points at
    mirror->next=newNode; //making mirror point to the new node, so the new node is after the node mirror points to
}
