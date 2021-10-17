#include "Student.h"
Student::Student(){}
  //parameter constructor
  Student::Student(string name, int age, char gender, list <string> Subjects_enrolled) : Person(name, age, gender){
    this->Subjects_enrolled = Subjects_enrolled;
  }
  //virtul function implemented in child class
  void Student::displayInfo(){
    cout << "-----------------" << endl;
      cout << "Name: " << this->name << endl;
      cout << "Age: " << this->age << endl;
      cout << "Gender: " << this->gender << endl;
      list <string>::iterator it;
      cout<<"Subjects enrolled in: ";
      for (it = Subjects_enrolled.begin(); it != Subjects_enrolled.end(); it++){
        cout<< *it << " ";
      }
      cout<<endl;
    cout << "-----------------" << endl;
    }
  //functions from interface implemented
  list<string> Student::getSubjectsEnrolled(){
    return this->Subjects_enrolled;
  }
  void Student::addSubjectsEnrolled(string code){
    this->Subjects_enrolled.push_back(code);
  }