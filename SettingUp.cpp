/***************************************
Setting up
Author: Rafael Pompa
Date Completed: 3/25/2026
Description: This program would print out an itemized receipt form your visit at a diner
***************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include "LinkedList.hpp"
using namespace std;

//class to store item name and price
class InvoiceItem
{
private:
string name;
float price;

public:

//constructor using initialization list
InvoiceItem(string n, float p)
: name(n), price(p) {}

//geting name function
string getName()
{
return name;
}

//getting price function
float getPrice()
{
return price;
}
};

int main()
{
//setting up the linked list
LinkedList<InvoiceItem> list;

//adding items to list
list.pushFront(InvoiceItem("Pot of coffee", 3.29));
list.pushFront(InvoiceItem("Short stack and eggs breakfast", 12.99));
list.pushFront(InvoiceItem("Denver omelet", 15.99));
list.pushFront(InvoiceItem("Country fried steak and eggs breakfast", 16.49));
list.pushFront(InvoiceItem("Two egg, Two bacon breakfast", 10.99));

//printing out the receipt
cout << "Itemized Receipt:\n\n";

//variable for subtotal
float subtotal = 0;

//creating iterator for linked list
LinkedList<InvoiceItem>::Iterator it = list.generateIterator();

//loop to go through the list using iterator
while (it.hasNext())
{
//getting current item pointer
InvoiceItem* item = it.current();

//printing each item out
cout << "$" << item->getPrice()
 << " - " << item->getName() << endl;

//adding up the subtotal
subtotal += item->getPrice();

//moving to next node
it.next();
}

//Setting up the taxrate for california
float taxRate = 0.0725;

//calculating total with tax
float total = subtotal + subtotal * taxRate;

//formatting to 2 decimals
cout << fixed << setprecision(2);

//printing subtotal and total
cout << "\nSub Total: $" << subtotal << endl;
cout << "Total: $" << total << endl;

return 0;
}