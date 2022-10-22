//
//  Linked List.cpp
//  Assignment 3
//
//  Created by jana on 18/10/2022.
//

#include "Linked List.hpp"
#include <vector>
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head=NULL; //initializing head pointer
}
node* LinkedList::getHead(){
    return head; //getter for head pointer to be used in insertAfter function
}
void LinkedList::insert(int data){
    node* mirror; //creating mirror pointer
    node *newNode=new node; //initializing temporary node pointer
    newNode->value=data;
    newNode->next=NULL;
    if (head==NULL){ //if list is empty
        head=newNode; //make head pointer point to the new node
    }
    mirror=head; //making mirror pointer point at first node
    while (mirror->next!=NULL){
        mirror=mirror->next; //increment mirror pointer until it points to the last node
    }
    mirror->next=newNode; //making last node point to new node
    newNode->next=NULL; //making new node point to NULL
}
void LinkedList::removeFromEnd(){
    node* mirror; //initializing mirror pointer
    node* mirror2; //initializing another mirror pointer
    mirror=head;
    mirror2=head; //making both pointers point to first node
    while (mirror != NULL){
        mirror2=mirror; //making mirror2 point to the node before mirror
        mirror=mirror->next; //incrementing mirror until it points to NULL
    }
    mirror2->next=NULL; //making mirror2 point to NULL, deleting the last node of the list
}
void LinkedList::removeFromMiddle(int previousNodeValue){
    node* mirror; //initializing mirror pointer
    node* mirror2; //initializing another mirror pointer
    mirror=head;
    mirror2=head; //making both pointers point to first node
    while ((mirror->value) != previousNodeValue){
        mirror2=mirror; //making mirror2 point to the node before mirror
        mirror=mirror->next; //incrementing mirror until it points to the node needed to delete
    }
    mirror2->next=mirror->next; //making mirror2 point to node after mirror, deleting the node mirror is pointing to
}
void LinkedList::print(){
    node* mirror; //initializing mirror pointer
    mirror=head; //making mirror point to first node
    cout << "the elements of the linked list are: " << endl;
    while (mirror!=NULL){
        cout << mirror->value << endl; //output value by value
        mirror=mirror->next; //incrementing mirror till it points to NULL
    }
}
int LinkedList::sum(){
    node* mirror; //initializing mirror pointer
    mirror=head; //making mirror point to first node
    int sum=0; //initializing sum with 0
    while (mirror!=NULL){
        sum+=mirror->value; //adding each value in the list to sum
        mirror=mirror->next; //incrementing mirror till it points to NULL
    }
    return sum; //returning sum
}
LinkedList LinkedList::create(vector<int> v){
    LinkedList list; //initializing new LinkedList object
    
    vector<int>::iterator iter; //initializing iterator for the vector
    sort(v.begin(),v.end()); //sorting the vector ascendingly
    iter=unique(v.begin(), v.end()); //using unique function to remove all duplicates from the vector
    v.resize(distance(v.begin(), iter)); //resizing the vector to only include the non-duplicate integers
    for (int i=0;i<v.size();i++)
        list.insert(v[i]);
    
    /*node* mirror=head;
    node* mirror2=head;
    
    for (int i=0;i<v.size();i++)
        list.insert(v[i]);
    
    while (mirror!=NULL){
        mirror2=mirror;
        mirror=mirror->next;
        if (mirror->value == mirror2->value){
            list.removeFromMiddle(mirror2->value);
            mirror2->numOfOccurance++;
        }
    }*/
    return list; //returning the list
}
