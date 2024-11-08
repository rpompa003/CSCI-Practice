// Made by Rafael Pompa
// Made on 11/5
// This program writes 10 random numbers between 50 and 100 to a text file,
// reads them back, and displays the total.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void intro() {
    cout << "This program will read from the file and add up all of the numbers." << endl;
    cout << "Then the program will print all the numbers and display the total." << endl;
    cout << " " << endl;
}

int main() { 
    int max = 50;
    int RandomNumber = 0;
    int valueArray[10];
    int total = 0;

    intro();

    // Open file for writing
    ofstream outfile("histo.txt");
    srand(time(0));

    // Write 10 random numbers to file
    for (int i = 0; i < 10; i++) {
        valueArray[i] = rand() % max + 50;
        outfile << valueArray[i] << " "; // Add space between numbers for readability
    }
    outfile.close();

    // Open file for reading and calculate total
    ifstream infile("histo.txt");
    cout << "Numbers in the file:" << endl;
    while (infile >> RandomNumber) {
        cout << RandomNumber << " "; // Print each number
        total += RandomNumber;
    }
    infile.close();

    cout << endl << "Total of numbers: " << total << endl;

    return 0;
}
