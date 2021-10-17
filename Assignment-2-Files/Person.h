#ifndef Person_h
#define Person_h
#include <iostream>
using namespace std;
class Person{
protected:
  string name;
  int age;
  char gender;
public:
  //default constructor
  Person();
  //parameter constructor
  Person(string, int, char);
  string getname();
  int getAge();
  char getGender();
  //pure virtual function to make class abstract
  virtual void displayInfo() = 0;
};
#endif