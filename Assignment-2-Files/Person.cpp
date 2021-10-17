#include "Person.h"
//default constructor
Person::Person(){
    this->name = " ";
    this->age = 0;
    this->gender = ' ';
}
  //parameter constructor
  Person::Person(string name, int age, char gender){
      this->name=name;
      this->age=age;
      this->gender=gender;
  }
    string Person::getname(){
    return this->name;
  }
  int Person::getAge(){
    return this->age;
  }
  char Person::getGender(){
    return this->gender;
  }