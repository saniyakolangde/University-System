#ifndef Teacher_h
#define Teacher_h
#include "Person.h"
#include "TaughtInterface.h"
#include <list>
//Child class
class Teacher : public Person, public TaughtInterface{
private:
  int year_joined;
  list <string> Subjects_taught;
public:
Teacher();
  //parameter constructor
  Teacher(string name, int age, char gender, int year_joined, list <string> Subjects_taught);
  //virtul function implemented in child class
  void displayInfo();
  int getYear();
  //functions from interface implemented
  list<string> getSubjectsTaught();
  void addSubjectsTaught(string code);
};
#endif