#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
private:
int aside;
int bside;
int cside;
int b2side;
Triangle (int a, int b, int c, int b2);
Triangle();

public:
void setaside(int);
void setbside(int);
void setcside(int);
void setb2side(int);
int getparameter();
int getarea();
int getscale();
};

Triangle::Triangle (int a, int b, int c, int b2){
  aside = a;
  bside = b;
  cside = c;
  b2side =b2;
}
Triangle::Triangle(){
 aside = 0;
 bside = 0;
 cside = 0;
 b2side = 0;
}
void Triangle::setaside(int a){
 aside = a;
}
void Triangle::setbside(int b){
 bside = b;
}
 void Triangle::setcside(int c){
 cside = c;
}
void Triangle::setb2side(int b2){
 b2side = b2; 
}
int Triangle::getarea(){
 return 0.5*aside*bside;
}
int Triangle::getparameter(){
 return aside+bside+cside;
}
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