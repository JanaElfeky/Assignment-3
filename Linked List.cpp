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
    mirror=NULL;
    mirror2=NULL;
}
node* LinkedList::getHead(){
    return head; //getter for head pointer to be used in insertAfter function
}
void LinkedList::insert(node* &Head,int data){
    node *newNode=new node; //initializing temporary node pointer
    newNode->value=data;
    newNode->next=NULL;
    if (Head==NULL){ //if list is empty
        Head=newNode; //make head pointer point to the new node
    }
    mirror=Head; //making mirror pointer point at first node
    while (mirror->next!=NULL){
        mirror=mirror->next; //increment mirror pointer until it points to the last node
    }
    mirror->next=newNode; //making last node point to new node
}
void LinkedList::removeFromEnd(){
    mirror=head;
    mirror2=head; //making both pointers point to first node
    while (mirror != NULL){
        mirror2=mirror; //making mirror2 point to the node before mirror
        mirror=mirror->next; //incrementing mirror until it points to NULL
    }
    mirror2->next=NULL; //making mirror2 point to NULL, deleting the last node of the list
}
void LinkedList::removeFromMiddle(int previousNodeValue){
    mirror=head;
    mirror2=head; //making both pointers point to first node
    while ((mirror->value) != previousNodeValue){
        mirror2=mirror; //making mirror2 point to the node before mirror
        mirror=mirror->next; //incrementing mirror until it points to the node needed to delete
    }
    mirror2->next=mirror->next; //making mirror2 point to node after mirror, deleting the node mirror is pointing to
}
void LinkedList::print(){
    mirror=head; //making mirror point to first node
    cout << "the elements of the linked list are: " << endl;
    while (mirror!=NULL){
        cout << mirror->value << endl; //output value by value
        mirror=mirror->next; //incrementing mirror till it points to NULL
    }
}
int LinkedList::sum(){
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
    
    LinkedList list; //initializing new LinkedList object
    list.insert(head, v[0]); //inserting first vector element in list
    mirror=head; //making mirror point to head
        for (int i=1;i<v.size();i++){ //checking if each vector element has duplicates by traversing the whole linked list
            if (mirror->value==v[i]){
                mirror->numOfOccurance++;
            }
            else{
                list.insert(head,v[i]);
            }
            mirror=mirror->next;
            
        }
        return list; //returning the list

}
