#include "Teacher.h"
Teacher::Teacher(){}
  //parameter constructor
  Teacher::Teacher(string name, int age, char gender, int year_joined, list <string> Subjects_taught) : Person(name, age, gender){
    this->year_joined = year_joined;
    this->Subjects_taught = Subjects_taught;
  }
  //virtul function implemented in child class
  void Teacher::displayInfo(){
    cout << "-----------------" << endl;
      cout << "Name: " << this->name << endl;
      cout << "Age: " << this->age << endl;
      cout << "Gender: " << this->gender << endl;
      cout << "Year Joined: " << this->year_joined << endl;
      list <string>::iterator it;
      cout << "Subjects taught: ";
      for (it = Subjects_taught.begin(); it != Subjects_taught.end(); it++){
        cout << *it << " ";
      }
      cout<<endl;
    cout << "-----------------" << endl;
    }
  int Teacher::getYear(){
      return this->year_joined;
  }
  //functions from interface implemented
  list<string> Teacher::getSubjectsTaught(){
    return this->Subjects_taught;
  }
  void Teacher::addSubjectsTaught(string code){
    this->Subjects_taught.push_back(code);
  }