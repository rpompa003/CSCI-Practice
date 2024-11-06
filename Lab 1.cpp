//,ade by rafael pompa
// made on 11/5
//this program is used to write to a text file and put 10 random numbers between 50 and 100.

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<cmath>
using namespace std;

void intro(){
  cout<<"this program will read from the file and adds up all of the numbers."<<endl;
  cout<<"Then the program should print all the numbers and display the total of the numbers added together."<<endl;
  cout<<" "<<endl;
}

int main() { 
  int max = 50;
  int RandomNumber =0;
  int valueArray[10];
  int total =0;

intro();

ifstream infile ("math.txt");
srand(time(0));
  for (int i = 0;i<10;i++){
  valueArray[i]= RandomNumber = rand()%max +50;
  }
  for (int i = 0;i<10;i++){
  cout<<valueArray[i];
  }

while (infile >> RandomNumber) {
        total += RandomNumber;
    cout<< total;
}

}
