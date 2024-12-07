//made by rafael pompa
//12/6
//this program is made to show appropriate get/set methods. 

#include <iostream>
#include <cmath>
using namespace std;
//setting up private classes 
class Triangle{
private:
int aside;
int bside;
int cside;
int b2side;//setting up private classes with triangle variable
Triangle (int a, int b, int c, int b2);
Triangle();

//setting up public classes 
public:
void setaside(int);
void setbside(int);
void setcside(int);
void setb2side(int); //setting up public classes with int 
int getparameter();
int getarea();
int getscale();
};

//giving each variable a short version of name
Triangle::Triangle (int a, int b, int c, int b2){
  aside = a;
  bside = b;
  cside = c;
  b2side =b2;
}
//Giving each variable a number holder 
Triangle::Triangle(){
 aside = 0;
 bside = 0;
 cside = 0;
 b2side = 0;
}
//Setting variable aside to a 
void Triangle::setaside(int a){
 aside = a;
}
//Setting variable bside to b
void Triangle::setbside(int b){
 bside = b;
}
//Setting variable cside to c
 void Triangle::setcside(int c){
 cside = c;
}
//Setting variable b2side to b2
void Triangle::setb2side(int b2){
 b2side = b2; 
}
//how to calculate area of triangle 
int Triangle::getarea(){
 return 0.5*aside*bside;
}
//how to calculate parameter of triangle 
int Triangle::getparameter(){
 return aside+bside+cside;
}
//how to calculate scale of two triangles 
int Triangle::getscale(){
 return bside/b2side;
}

int main() {
int aside =1;
int bside =1;
int cside =2;
int b2side;

cout<<"enter a number for side a of the triangle :"<<endl;
cin>>aside;

cout<<"enter a number for side b of the triangle :"<<endl;
cin>>bside;

cout<<"enter a number for side c of the triangle :"<<endl;
cin>>cside;

cout<<"enter a number for side B2 for the second triangle :"<<endl;
cin>>b2side;
return 0;
}
