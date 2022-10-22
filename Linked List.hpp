//
//  Linked List.hpp
//  Assignment 3
//
//  Created by jana on 18/10/2022.
//

#ifndef Linked_List_hpp
#define Linked_List_hpp
#include <vector>
#include <iostream>
using namespace std;

#include <stdio.h>


struct node{
    int value=0;
    node *next=NULL;
    int numOfOccurance=0;
};
class LinkedList{
    node *head;
public:
    LinkedList();
    void insert(int data);
    void removeFromEnd();
    void removeFromMiddle(int previousNodeValue);
    void print();
    LinkedList create(vector<int> v);
    int sum();
    node* getHead();
};

#endif /* Linked_List_hpp */
