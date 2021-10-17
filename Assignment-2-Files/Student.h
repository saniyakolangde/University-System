#ifndef Student_h
#define Student_h
#include "Person.h"
#include "EnrolledInterface.h"
#include <list>
//Child Class
class Student : public Person, public EnrolledInterface{
private:
  list <string> Subjects_enrolled;
public:
Student();
  //parameter constructor
  Student(string name, int age, char gender, list <string> Subjects_enrolled);
  //virtul function implemented in child class
  void displayInfo();
  //functions from interface implemented
  list<string> getSubjectsEnrolled();
  void addSubjectsEnrolled(string code);
};
#endif