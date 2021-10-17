#include "Student.h"
#include "Teacher.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

//validation to check file for duplicate name for student or teacher
template<typename T>
bool sameName(vector <T*> &container,string name){
typename vector <T*>::iterator iter;
for(iter=container.begin();iter!=container.end();iter++){
  if((*iter)->getname()==name)return true;
}
return false;
}

void ReadFile(vector <Teacher*> &teachers,vector<Student*>&students){
string name; int age; char gender; int year; string subject; string sub;list  <string> Subjects; string type;
  string stringToInteger;
  string stringToChar;
  string entireSubject;
  stringstream ss;
    list<string>temporaryList;
  ifstream file("2020_teacher_student.txt");
    if(!file){
      cout<<"ERROR: File does not exist"<<endl;
      exit(0);
    }
    while(!file.eof()){
      int c=0;
      getline(file,type,':');
      if(type=="Teacher"){
        getline(file,name,':');
        //if teachers are duplicate we will not enter the repeated value into the vector
        if(sameName(teachers,name)){
          cout<<"ERROR: Teacher "<<name<<" already exists in the record"<<endl;
        }
        else{
        getline(file,stringToInteger,':');
        age=stoi(stringToInteger);
        getline(file, stringToChar,':');
        gender=stringToChar[0];
        getline(file,stringToInteger,':');
        year=stoi(stringToInteger);
        getline(file,entireSubject,'\n');
        stringstream ss(entireSubject);
        while(ss>>sub){
          //if a subject is duplicate we will not add it to the list
            if(find(Subjects.begin(),Subjects.end(),sub)!=Subjects.end()){
                cout<<"ERROR: Teacher "<<name<<" is already teaching "<<sub<<endl;
            }
            else{
                temporaryList.push_back(sub);
                //if subject is already being taught by 3 teachers we will not add it to the list for the 4th teacher
                if(count(temporaryList.begin(),temporaryList.end(),sub)>3)
                    cout<<"ERROR: Teacher "<<name<< " cannot teach "<<sub<<endl;
                else{
                    Subjects.push_back(sub);
                    c++;
                }
            }
        }
          //if teacher has less than 2 or more than 3 subjects we will not add it to the vector
          if(c>3||c<2)cout<<"ERROR: Teacher "<<name<<" cannot be added in the record"<<endl;
          else teachers.push_back(new Teacher(name,age,gender,year,Subjects));
        Subjects.erase(Subjects.begin(),Subjects.end());
        }
        }
      else if(type=="Student"){
        int c1=0;
        getline(file,name,':');
        //if students are duplicate we will not enter the repeated value into the vector
        if(sameName(students,name)){
          cout<<"ERROR: Student "<<name<<" already exists in the record"<<endl;
        }
        else{
        getline(file,stringToInteger,':');
        age=stoi(stringToInteger);
        getline(file, stringToChar,':');
        gender=stringToChar[0];
        getline(file,entireSubject,'\n');
        stringstream ss(entireSubject);
        while(ss>>sub){
          //if a subject is duplicate we will not add it to the list
            if(find(Subjects.begin(),Subjects.end(),sub)!=Subjects.end()){
                cout<<"ERROR: Student "<<name<<" is already enrolled in "<<sub<<endl;
            }
            else{
                Subjects.push_back(sub);
                c1++;
            }
        }
          //if student has less than 3 or more than 5 subjects we ill not add it in the vector
          if(c1>5||c1<3) cout<<"ERROR: Student "<<name<<" cannot be added in the record"<<endl;
          else students.push_back(new Student(name,age,gender,Subjects));
        Subjects.erase(Subjects.begin(),Subjects.end());
      }
      }
    }
}

void AddStudent(vector <Student*> &students){
  string name; int age; char gender; int sub; string subject;list<string>subs;
  bool x;
  cout << "Enter student name: " << endl;
  cin.ignore();
  getline(cin,name);
  //validation to make sure entered name of student does not already exist in the database
  do{
        if(sameName(students, name)){
          cout<<"This student already exists in the Database!"<<endl;
        cout << "Enter student name: " << endl;
        getline(cin,name);}
    }while(sameName(students, name)); 
  if(!sameName(students,name)){
  cout << "Enter age: " << endl;
  cin >> age;
  cout << "Enter gender: " << endl;
  cin >> gender;
  do{
  cout <<"Enter the number of subjects enrolled in: "<<endl;
  cin >> sub;
    if(sub<3||sub>5){
      cout<<"ERROR: Student should be enrolled in minimum 3 and maximum 5 subjects only! "<<endl;
    }
    }while(sub<3||sub>5);
    for(int i=0; i<sub; i++){
      //validation to make sure student in not enrolled in an already enrolled subject
      do{
        x=0;
      cout<<"Enter subject code:"<<endl;
      cin>>subject;
            if(find(subs.begin(),subs.end(),subject)!=subs.end()){
                x=1;
                cout<<"ERROR: Subject has already been added previously"<<endl;
            }
            else {subs.push_back(subject);}
        }while(x==1);
    }
  students.push_back(new Student(name, age, gender,subs));
  }
}

//validation to check number of subjects taught by teacher
int checkTeachers(vector<Teacher*>&teachers,string code){
    vector<Teacher*>::iterator iter;
    list<string> l;
    int k=0;
    list<string>::iterator iter2;
    for(iter=teachers.begin();iter!=teachers.end();iter++){
      l=(*iter)->getSubjectsTaught();
      for(iter2=l.begin();iter2!=l.end();iter2++){
        if((*iter2)==code){
          k++; //increment count of teacher by one if subject is taught by the teacher
        }
      }
    }
    //return the number of teachers teaching a subject
  return k;
}

void AddTeacher(vector <Teacher*> &teachers){
    string name; int age; char gender; int year; int sub; string subject; list <string> subs;
      bool x;
      cout << "Enter teacher name: " << endl;
      cin.ignore();
      getline(cin,name);
      //validation to make sure entered name of teacher does not already exist in the database
      do{
        if(sameName(teachers, name))
        {cout<<"This teacher already exists in the Database!"<<endl;
        cout << "Enter teacher name: " << endl;
        getline(cin,name);}
      }while(sameName(teachers, name));
      if(!sameName(teachers,name)){
      cout << "Enter age: " << endl;
      cin >> age;
      cout << "Enter gender: " << endl;
      cin >> gender;
      cout << "Enter Year joined: " << endl;
      cin >> year;
      do{
        cout << "Enter number of subjects taught: " << endl;
        cin >> sub;
        if(sub < 2 || sub > 3){
          cout << "ERROR: Teacher can teach minimum 2 and maximum 3 subjects only!" << endl;
        }
      }while(sub < 2 || sub > 3);
      for(int i = 0; i < sub; i++){
        //validation to check if subject is already taught by 3 teachers and make sure teacher in not teaching an already registered subject
        do{
          x=0;
        cout << "Enter subject code:" << endl;
        cin >> subject;
        if(checkTeachers(teachers, subject)>=3){
                cout<<"ERROR: Cannot add subject, it is already taught by 3 teachers"<<endl;
            }
        else if(find(subs.begin(),subs.end(),subject)!=subs.end()){
                cout<<"ERROR: Subject has already been added previously"<<endl;
            x=1;
            }
        else{
          subs.push_back(subject);
        }
        }while(checkTeachers(teachers, subject)>=3||x==1);
      }
      teachers.push_back(new Teacher(name, age, gender, year, subs));
      }
    }

void displayStudents(vector <Student*> &students){
  for(auto k : students){
    k -> displayInfo();
  }
}

void displayTeachers(vector <Teacher*> &teachers){
  for(auto k : teachers){
    k -> displayInfo();
  }
}

void subjectsTaught(vector <Teacher*> &teachers){
  string fullname;
  cout<<"Enter the full name of teacher to see subjects taught:"<<endl;
  cin.ignore();
  getline(cin,fullname);
  //validation to make sure teacher name entered exists in Database
  do{
        if(!sameName(teachers, fullname)){cout<<"This teacher does not exist in the Database!"<<endl;
        cout << "Enter the full name of teacher to see subjects taught: " << endl;
        getline(cin,fullname);}
      }while(!sameName(teachers, fullname));
  vector<Teacher*>::iterator iter;
  list<string> l;
  bool x = 0;
  for(iter = teachers.begin(); iter != teachers.end(); iter++){
    if((*iter)->getname() == fullname){
      //add the subjects taught by a given teacher in another list
      l = (*iter)->getSubjectsTaught();
     }
    }
    //display the subjects taught by the teacher
      for(auto k:l){
      cout << k << endl;
  }
}

void subjectsEnrolled(vector <Student*> &students){
string fullname;
  cout<<"Enter the full name of student to see subjects enrolled:"<<endl;
  cin.ignore();
  getline(cin,fullname);
  //validation to make sure student name entered exists in Database
  do{
        if(!sameName(students, fullname)){cout<<"ERROR: This student does not exist in the Database!"<<endl;
        cout << "Enter the full name of student to see subjects enrolled: " << endl;
        getline(cin,fullname);}
      }while(!sameName(students, fullname));
  vector<Student*>::iterator iter;
  list<string> l;
  bool x = 0;
  for(iter=students.begin(); iter != students.end(); iter++){
    if((*iter)->getname() == fullname){
      //add the subjects enrolled into by a given student in another list
      l=(*iter)->getSubjectsEnrolled();
     }
    }
    //display the enrolled subjects of the given student
      for(auto k:l){
      cout << k << endl;
    }
}

void studentTaughtByTeacher(vector <Student*> &students,vector <Teacher*> &teachers){
string fullname;
bool x=0;
cout<<"Enter the full name of teacher to see students taught:"<<endl;
cin.ignore();
getline(cin,fullname);
//validation to make sure teacher name entered exists in Database
do{
        if(!sameName(teachers, fullname)){cout<<"This teacher does not exist in the Database!"<<endl;
        cout << "Enter the full name of teacher to see subjects taught: " << endl;
        getline(cin,fullname);}
      }while(!sameName(teachers, fullname));
list<string>l;
list<string>l2;
list<string>l3;
list<string>::iterator le;
list<string>::iterator le2;
vector<Student*>::iterator iter;
vector<Teacher*>::iterator iter2;

  for(iter2=teachers.begin();iter2!=teachers.end();iter2++){
    if((*iter2)->getname()==fullname){
      x=1;
      //add subjects taught by a given teacher in another list
      l=(*iter2)->getSubjectsTaught();
     }
  }
    if(x==1){
      for(iter=students.begin();iter!=students.end();iter++){
        //add subjects enrolled in by a student in another list
        l2=(*iter)->getSubjectsEnrolled();
        //compare the subjects enrolled of all students and subjects taught by the given teacher
        for(le2=l2.begin();le2!=l2.end();le2++){
          le=find(l.begin(),l.end(),(*le2));
          if(le!=l.end()){
            //add the name of student taught by the given teacher in another list
            l3.push_back((*iter)->getname());
          }
        }
      }
      l3.sort();
      l3.unique();
      //display the students taught by a given teacher
      for(auto k:l3){
        {
        cout << k << endl;
        }
      }
    }
}

void studentsEnrolledInSubject(vector <Student*> &students){
  bool x=0;
  string code;
  do{
  cout<<"Enter the code of the subject to see students enrolled:"<<endl;
  cin.ignore();
  cin>>code;
  vector<Student*>::iterator iter;
  list<string>::iterator iter2;
  list<string> s;
  list<string> s2;
  for(iter=students.begin();iter!=students.end();iter++){
    s=(*iter)->getSubjectsEnrolled();
    //check whether the student is enrolled in the given subject
    iter2=find(s.begin(),s.end(),code);
    if(iter2!=s.end()){
      x=1;
      //add the name of the student in another list if enrolled in the given subject
      s2.push_back((*iter)->getname());
    }
  }
  if(x==0){
    cout<<"ERROR: No student is enrolled in the given subject"<<endl;
  }
  else{
    //display students enrolled in a given subject
    for(auto k:s2){
      cout << k << endl;
    }
  }
  }while(x==0);
}

void addSubjectToEnrolledStudent(vector <Student*> &students){
  string fullname;
  string code;
  bool y;
  cout<<"Enter the full name of the student to add subject:"<<endl;
  cin.ignore();
  getline(cin,fullname);
  //validation to make sure student name entered exists in Database
  do{
        if(!sameName(students, fullname)){cout<<"ERROR: This student does not exist in the Database!"<<endl;
        cout << "Enter the full name of the student to add subject: " << endl;
        getline(cin,fullname);}
    }while(!sameName(students, fullname));
  vector<Student*>::iterator iter;
  list<string>l;
  list<string>::iterator iter2;
  list<string> s;
do{
  y=0;
  for(iter=students.begin();iter!=students.end();iter++){
    if((*iter)->getname()==fullname){
      s=(*iter)->getSubjectsEnrolled();
      //validation to make sure student with 5 subjects doesnt get enrolled in another subject
      if(s.size()>=5){
        cout<<"ERROR: Cannot add another subject, student is already enrolled in 5 subjects"<<endl;
      }
    else{
      cout<<"Enter the code for the subject:"<<endl;
      cin>>code;
      //validation to check if student is already enrolled in requested subject
      iter2=find(s.begin(),s.end(),code);
        if(iter2!=s.end()){
        y=1;
        cout<< "ERROR: Student is already enrolled in this subject" << endl;
        break;
      }
  }
  //add a new enrolled subject for the given student if the student is not already enrolled in that subject 
    if(y==0){
      (*iter)->addSubjectsEnrolled(code);
    }
    }
  }
}while(y==1);
}

void addSubjectToTeacher(vector <Teacher*> &teachers){
  string fullname;
  string code;
  bool y;
  cout<<"Enter the full name of the teacher to add subject:"<<endl;
  cin.ignore();
  getline(cin,fullname);
  //validation to make sure teacher name entered exists in Database
      do{
        if(!sameName(teachers, fullname)){cout<<"This teacher does not exist in the Database!"<<endl;
        cout << "Enter the full name of teacher to see subjects taught: " << endl;
        getline(cin,fullname);}
      }while(!sameName(teachers, fullname));
  vector<Teacher*>::iterator iter;
  list<string>::iterator l;
  list<string>::iterator iter2;
  list<string> s;
do{
y=0;
  for(iter=teachers.begin();iter!=teachers.end();iter++){
    if((*iter)->getname()==fullname){
      s=(*iter)->getSubjectsTaught();
      //validation to make sure teacher teaching 3 subjects don't get registered for teaching another subject
      if(s.size()>=3){
        cout<<"ERROR: Cannot add another subject, teacher is already teaching 3 subjects"<<endl;
      }
    else{
      cout<<"Enter the code for the subject:"<<endl;
      cin>>code;
      //validation to check if teacher is already teaching requested subject
        iter2=find(s.begin(),s.end(),code);
        if(iter2!=s.end()){
          y=1;
          cout<< "ERROR: Teacher is already teaching this subject" << endl;
          break;
        }
        //validation to check whether the subject request is not already taught by three teachers
        if(checkTeachers(teachers, code)>=3){
            cout<<"ERROR: Cannot add subject, it is already taught by 3 teachers"<<endl;
            break;
        }
    }
      if(y==0){
        (*iter)->addSubjectsTaught(code);
      }
    }
  }
}while(y==1||checkTeachers(teachers,code)>=3);
}

//function to write all updated vectors to the file with the delimiter
void saveFile(vector <Teacher*> &teachers, vector <Student*> &students ){
  ofstream myfile ("2020_teacher_student.txt");
  if (myfile.is_open()){
    //write teachers from vector to file
    vector <Teacher*>::iterator it;
    list<string> t;
    for(it = teachers.begin(); it != teachers.end(); it++){
      t=(*it)->getSubjectsTaught();
      myfile << "Teacher:" << (*it)->getname() << ':' << (*it)->getAge() << ':' << (*it)->getGender() << ':' << (*it)->getYear() << ':';
      for(auto k:t){
        myfile << k << " ";
      }
      myfile << '\n';
    }
    //write students from vector to file
    vector <Student*>::iterator it2;
    list<string> s;
    for(it2 = students.begin(); it2 != students.end(); it2++){
      s=(*it2)->getSubjectsEnrolled();
      myfile << "Student:" << (*it2)->getname() << ':' << (*it2)->getAge() << ':' << (*it2)->getGender() << ':';
      for(auto k:s){
        myfile << k << " ";
      }
      myfile << '\n';
    }
    myfile.close();
    }
    else cout << "Unable to open file!";
}

int main() {
  //create vectors and read the file to be proccessed later
  vector <Teacher*> teachers;
  vector <Student*> students;
  ReadFile(teachers,students);
    int opt;
    string option;
    do{
      cout << "-------------------------------------" << endl;
      cout << "Student & Teacher Database System" << endl;
      cout << "1. View list of all Students" << endl;
      cout << "2. View list of all Teachers" << endl;
      cout << "3. Add a student" << endl;
      cout << "4. Add a teacher" << endl;
      cout << "5. View list of subjects enrolled in by a student" << endl;
      cout<<"6. View list of students taught by a teacher" << endl;
      cout << "7. View list of subjects taught by a teacher" << endl;
      cout << "8. View list of students enrolled in a subject" << endl;
      cout << "9. Add subject to a student" << endl;
      cout << "10. Add subject to a teacher" << endl;
      cout << "11. Save and exit program" << endl;
      cout << "-------------------------------------" << endl;
      do {
        cout << "Enter option you want to execute: " << endl;
        cin>>opt;
        //validation to make sure sure enters right option
        if((opt<1)||(opt>11)){
        cout<<"Invalid Option!" <<endl;
        }
      }while ((opt<1)||(opt>11));
      //switch case will allow different function to be called
      switch(opt){
      case 1:
        displayStudents(students);
        break;
      case 2:
        displayTeachers(teachers);
        break;
      case 3:
        AddStudent(students);
        break;
      case 4:
        AddTeacher(teachers);
        break;
      case 5:
        subjectsEnrolled(students);
        break;
      case 6:
        studentTaughtByTeacher(students,teachers);
        break;
      case 7:
        subjectsTaught(teachers);
        break;
      case 8:
        studentsEnrolledInSubject(students);
        break;
      case 9:
        addSubjectToEnrolledStudent(students);
        break;
      case 10:
        addSubjectToTeacher(teachers);
        break;
      case 11:
        saveFile(teachers,students);
        cout << "Thank you for using our program :D" << endl;
        break;
      }
    }while((opt!=11));
    //program will run until user chooses to quit
    return 0;
}