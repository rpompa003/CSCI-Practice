/***************************************
[Make A Linked List]
Author: [Rafael Pompa]
Date Completed: [3/11/2026]
Description: [implement the logic for the member function declarations for the SList data type]
***************************************/

#include <iostream>
#include <string>
using namespace std;

class SList
{
// Note: Do not modify any code in the private section!
private:
// Node definition
struct Node
{
Node* next;
string data;
Node(string d, Node* n) : data(d), next(n){}
};

// Node pointer to head (front) of list
Node* head_;

public:

// Constructor
// Initializes head to null
SList();

// Ruturn true if the list is empty, otherwise false
bool empty();

// Return the number of nodes in the list
int size();

// Create a new node to contain value and insert
// the node to the front of the list
void pushFront(string value);

// Create a new node to conatin value and insert
// the node to the back of the list
void pushBack(string value);

// Retrieve the node value at the specified list index.
// Note: Your implementation may assume that the value
// passed into the index parameter is within the range
// of the linked list size
string at(int index);

// Remove the head node in the list such that
// the second node in the list should become
// the new head node. Then return the previous
// head node's value.
// Note: Your implementation may assume that the
// size of the linked list is greater than zero
string popFront();

// Remove the node at the specified list index.
// Return true if the node at the specified index
// could be removed, otherwise false
bool removeAt(int index);

// Remove all nodes in the list
void clear();

// Destructor
// Remove any remaining nodes in the list
~SList();
};

// Constructor
SList::SList(){

// I set the head pointer to null so that the list starts empty
head_ = nullptr;

}

// Ruturn true if the list is empty, otherwise false
bool SList::empty(){

// If head_ is null, the list has no nodes
return head_ == nullptr;

}

// Return the number of nodes in the list
int SList::size(){

// Creating a counter variable
int count = 0;

// Added a pointer to walk through the list
Node* iter = head_;

while(iter != nullptr){

count++;

// Moving to the next node in the list
iter = iter->next;

}

return count;
}

// Create a new node to contain value and insert
// the node to the front of the list
void SList::pushFront(string value){

// Create another node whose next pointer points to the current head
Node* newNode = new Node(value, head_);

// Move head_ to the new node so it becomes the first node
head_ = newNode;

}

// Create a new node to conatin value and insert
// the node to the back of the list
void SList::pushBack(string value){

// Creating a new node that will go at the end of the list
Node* newNode = new Node(value, nullptr);

// If the list was empty, this node becomes the head
if(head_ == nullptr)
{
head_ = newNode;
return;
}

// Starting at the head and going to the last node
Node* iter = head_;

while(iter->next != nullptr){

// Move through the list until reaching the last node
iter = iter->next;

}

// Attach the new node to the end of the list
iter->next = newNode;

}

// Retrieve the node value at the specified list index.
string SList::at(int index){

// Starting at the head of the list
Node* iter = head_;

for(int i = 0; i < index; i++){

// Moving through the list until reaching the desired index
iter = iter->next;

}

// Returning the data stored at that node
return iter->data;

}

// Remove the head node in the list
string SList::popFront(){

// Storing the current head node
Node* temp = head_;

// Storing the data from the head node
string value = temp->data;

// Moving the head to the next node in the list
head_ = head_->next;

// Deleting the memory of the old head node
delete temp;

// Returning the value that was removed
return value;

}

// Remove the node at the specified list index.
bool SList::removeAt(int index){

// If the list is empty, nothing can be removed
if(head_ == nullptr)
return false;

// If removing the first node, call popFront
if(index == 0)
{
popFront();
return true;
}

Node* iter = head_;

for(int i = 0; i < index - 1; i++)
{

if(iter->next == nullptr)
return false;

// Moving the pointer to the next node
iter = iter->next;

}

// Node that will be removed
Node* removeNode = iter->next;

if(removeNode == nullptr)
return false;

// Skipping the node we want to delete
iter->next = removeNode->next;

// Deleting the node
delete removeNode;

return true;

}

// Remove all nodes in the list
void SList::clear()
{

while(!empty())
{

// Keep removing the first node until the list is empty
popFront();

}

}

// Destructor
// Remove any remaining nodes in the list
SList::~SList()
{

// Ensuring all memory is freed when the object is destroyed
clear();

}
int main()
{
cout<<"Starting program...\n\n";
{
SList list;
cout<<"The size of the list is: "<<list.size();
cout<<"\n\nPushing strings into the list...\n\n";
list.pushFront("This should end up as index 2 in the list");
list.pushFront("This should end up as index 1 in the list");
list.pushBack("This should end up as index 3 in the list");
list.pushBack("This should end up as index 4 in the list");
list.pushFront("This should end up as index 0 in the list");
cout<<"The size of the list is: "<<list.size();
cout<<"\n\nThe string at index 1 is \""<<list.at(1)<<"\"\n";
cout<<"The string at index 3 is \""<<list.at(3)<<"\"\n";
cout<<"\nClearing the list...\n\n";
list.clear();
cout<<"Pushing four strings into the list...\n\n";
list.pushBack("item 1");
list.pushBack("item 2");
list.pushBack("item 3");
list.pushBack("item 4");
if (list.removeAt(2))
{
cout<<"Successfully removed string at index 2 from list\n";
}
if (list.removeAt(3))
{
cout<<"Successfully removed string at index 3 from list\n";
}
cout<<"\nThe size of the list is: "<<list.size();
cout<<"\n\nItems in the list:\n";
while (!list.empty())
{
cout<<list.popFront()<<endl;
}
}
cout<<"\nExiting program...\n";

return 0;
}