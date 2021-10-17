#pragma once
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
namespace Assignment1 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	class Person {
	protected:
		string name;
		int age;
		char gender;
	public:
		//default constructor
		Person() {
			this->name = " ";
			this->age = 0;
			this->gender = ' ';
		}
		//paramenter constructor
		Person(string name, int age, char gender) {
			this->name = name;
			this->age = age;
			this->gender = gender;
		}
		//pure virtual function to make class abstract
		virtual void displayInfo() = 0;
	};
	class Teacher : public Person {
	private:
		int year_joined;
		list <string> Subjects_taught;
	public:
		Teacher() {}
		//paramenter constructor
		Teacher(string name, int age, char gender, int year_joined, list <string> Subjects_taught) : Person(name, age, gender) {
			this->year_joined = year_joined;
			this->Subjects_taught = Subjects_taught;
		}
		//virtul function implemented in child class
		void displayInfo() {
			string s1(1, this->gender);
			string s = "Name:" + this->name + '\n';

			s = s + "Age:" + to_string(this->age) + '\n';
			s = s + "Gender:" + s1 + '\n';
			s = s + "Year Joined:" + to_string(year_joined) + '\n';
			list <string>::iterator it;
			s = s + "Subjects Taught:" + '\n';
			for (it = Subjects_taught.begin(); it != Subjects_taught.end(); it++) {
				s = s + *it + " ";
			}
			s = s + '\n';
			const char* c_res = s.c_str();
			String^ S = gcnew String(c_res);
			MessageBox::Show(S);
		}
		string getname() {
			return this->name;
		}
		int getAge() {
			return this->age;
		}
		char getGender() {
			return this->gender;
		}
		int getYear() {
			return this->year_joined;
		}
		list<string> getSubjects() {
			return this->Subjects_taught;
		}
		void setSubjects(string code) {
			this->Subjects_taught.push_back(code);
		}
	};

	class Student : public Person {
	private:
		list <string> Subjects_enrolled;
	public:
		Student() {}
		//paramenter constructor
		Student(string name, int age, char gender, list <string> Subjects_enrolled) : Person(name, age, gender) {
			this->Subjects_enrolled = Subjects_enrolled;
		}
		//virtul function implemented in child class
		void displayInfo() {
			string s1(1, this->gender);
			string s = "Name:" + this->name + '\n';

			s = s + "Age:" + to_string(this->age) + '\n';
			s = s + "Gender:" + s1 + '\n';
			list <string>::iterator it;
			s = s + "Subjects Taught:" + '\n';
			for (it = Subjects_enrolled.begin(); it != Subjects_enrolled.end(); it++) {
				s = s + *it + " ";
			}
			s = s + '\n';
			const char* c_res = s.c_str();
			String^ S = gcnew String(c_res);
			MessageBox::Show(S);
		}
		string getname() {
			return this->name;
		}
		int getAge() {
			return this->age;
		}
		char getGender() {
			return this->gender;
		}
		list<string> getSubjects() {
			return this->Subjects_enrolled;
		}
		void setSubjects(string code) {
			this->Subjects_enrolled.push_back(code);
		}
	};
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::TextBox^ textbox1;
	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->textbox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(304, 331);
			this->button1->Margin = System::Windows::Forms::Padding(7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(399, 123);
			this->button1->TabIndex = 0;
			this->button1->Text = L"List Students";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(240, 42);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1204, 55);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Welcome to Student and Teacher Database System";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1064, 331);
			this->button2->Margin = System::Windows::Forms::Padding(7);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(399, 123);
			this->button2->TabIndex = 2;
			this->button2->Text = L"List Teachers";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1064, 511);
			this->button3->Margin = System::Windows::Forms::Padding(7);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(411, 127);
			this->button3->TabIndex = 3;
			this->button3->Text = L"List Subject taught by Teacher";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(304, 511);
			this->button4->Margin = System::Windows::Forms::Padding(7);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(399, 127);
			this->button4->TabIndex = 4;
			this->button4->Text = L"List Subject enrolled by Student";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(304, 164);
			this->button5->Margin = System::Windows::Forms::Padding(7);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(399, 118);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Add Student";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(1064, 154);
			this->button6->Margin = System::Windows::Forms::Padding(7);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(399, 118);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Add Teacher";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(304, 680);
			this->button7->Margin = System::Windows::Forms::Padding(7);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(399, 127);
			this->button7->TabIndex = 7;
			this->button7->Text = L"List Student taught by Teacher";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(1064, 680);
			this->button8->Margin = System::Windows::Forms::Padding(7);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(411, 127);
			this->button8->TabIndex = 8;
			this->button8->Text = L"List Student enrolled in Subject";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(304, 858);
			this->button9->Margin = System::Windows::Forms::Padding(7);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(399, 130);
			this->button9->TabIndex = 9;
			this->button9->Text = L"Add Subject to student";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(1064, 858);
			this->button10->Margin = System::Windows::Forms::Padding(7);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(411, 130);
			this->button10->TabIndex = 10;
			this->button10->Text = L"Add subject to Teacher";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(788, 1018);
			this->button11->Margin = System::Windows::Forms::Padding(7);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(223, 113);
			this->button11->TabIndex = 11;
			this->button11->Text = L"Save file";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// textbox1
			// 
			this->textbox1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->textbox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textbox1->ForeColor = System::Drawing::Color::Black;
			this->textbox1->Location = System::Drawing::Point(1719, 202);
			this->textbox1->Name = L"textbox1";
			this->textbox1->ReadOnly = false;
			this->textbox1->Size = System::Drawing::Size(300, 44);
			this->textbox1->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(1773, 110);
			this->label3->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label3->Name = L"label3";
			this->label3->Padding = System::Windows::Forms::Padding(21);
			this->label3->Size = System::Drawing::Size(197, 79);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Add Input";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(19, 37);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2299, 1184);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textbox1);
			this->Margin = System::Windows::Forms::Padding(7);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		//validation to check file for duplicate name for student or teacher
		template<typename T>
		bool sameName(vector <T*>& container, string name) {
			typename vector <T*>::iterator iter;
			for (iter = container.begin(); iter != container.end(); iter++) {
				if ((*iter)->getname() == name)return true;
			}
			return false;
		}
		void ReadFile(vector <Teacher*>& teachers, vector<Student*>& students) {
			string name; int age; char gender; int year; string subject; string sub; list  <string> Subjects; string type;
			string stringToInteger;
			string stringToChar;
			string entireSubject;
			stringstream ss;
			list<string>temporaryList;
			ifstream file("Text.txt");
			if (!file) {
				string sa = "ERROR:File does not exist";
				sa=sa + '\n';
				const char* c_res = sa.c_str();
				String^ S = gcnew String(c_res);
				MessageBox::Show(S);
				exit(0);
			}
			while (!file.eof()) {
				int c = 0;
				getline(file, type, ':');
				if (type == "Teacher") {
					getline(file, name, ':');
					//if teachers are duplicate we will not enter the repeated value into the vector
					if (sameName(teachers, name)) {
						string sa = "ERROR: Teacher"+name+" already exists in the record"+'\n';
						const char* c_res = sa.c_str();
						String^ S = gcnew String(c_res);
						MessageBox::Show(S);
					}
					else {
						getline(file, stringToInteger, ':');
						age = stoi(stringToInteger);
						getline(file, stringToChar, ':');
						gender = stringToChar[0];
						getline(file, stringToInteger, ':');
						year = stoi(stringToInteger);
						getline(file, entireSubject, '\n');
						stringstream ss(entireSubject);
						while (ss >> sub) {
							//if a subject is duplicate we will not add it to the list
							if (find(Subjects.begin(), Subjects.end(), sub) != Subjects.end()) {
								string sa = "ERROR: Teacher " + name + " is already teaching subject " + sub + '\n';
								const char* c_res = sa.c_str();
								String^ S = gcnew String(c_res);
								MessageBox::Show(S);
							}
							else {
								temporaryList.push_back(sub);
								//if subject is already being taught by 3 teachers we will not add it to the list for the 4th teacher
								if (count(temporaryList.begin(), temporaryList.end(), sub) > 3) {
									string sa = "ERROR:Teacher " + name + " cannot teach " + sub + '\n';
									const char* c_res = sa.c_str();
									String^ S = gcnew String(c_res);
									MessageBox::Show(S);
								}
						
								else {
									Subjects.push_back(sub);
									c++;
								}
							}
						}
						//if teacher has less than 2 or more than 3 subjects we will not add it to the vector
						if (c > 3 || c < 2) {
							string sa = "ERROR:Teacher " + name + " cannot be added in the record " + '\n';
							const char* c_res = sa.c_str();
							String^ S = gcnew String(c_res);
							MessageBox::Show(S);
						}
						else teachers.push_back(new Teacher(name, age, gender, year, Subjects));
						Subjects.erase(Subjects.begin(), Subjects.end());
					}
				}
				else if (type == "Student") {
					int c1 = 0;
					getline(file, name, ':');
					//if students are duplicate we will not enter the repeated value into the vector
					if (sameName(students, name)) {
						string sa = "ERROR: Student" + name + " already exists in the record" + '\n';
						const char* c_res = sa.c_str();
						String^ S = gcnew String(c_res);
						MessageBox::Show(S);
					}
					else {
						getline(file, stringToInteger, ':');
						age = stoi(stringToInteger);
						getline(file, stringToChar, ':');
						gender = stringToChar[0];
						getline(file, entireSubject, '\n');
						stringstream ss(entireSubject);
						while (ss >> sub) {
							//if a subject is duplicate we will not add it to the list
							if (find(Subjects.begin(), Subjects.end(), sub) != Subjects.end()) {
								string sa = "ERROR: Student " + name + " is already enrolled in subject " + sub + '\n';
								const char* c_res = sa.c_str();
								String^ S = gcnew String(c_res);
								MessageBox::Show(S);
							}
							else {
								Subjects.push_back(sub);
								c1++;
							}
						}
						//if student has less than 3 or more than 5 subjects we ill not add it in the vector
						if (c1 > 5 || c1 < 3) {
							string sa = "ERROR:Student " + name + " cannot be added in the record " + '\n';
							const char* c_res = sa.c_str();
							String^ S = gcnew String(c_res);
							MessageBox::Show(S);
						}
						else students.push_back(new Student(name, age, gender, Subjects));
						Subjects.erase(Subjects.begin(), Subjects.end());
					}
				}
			}
		}
		void displayStudents(vector <Student*>& students) {
			for (auto k : students) {
				k->displayInfo();
			}
		}
		void displayTeachers(vector <Teacher*>& teachers) {
			for (auto k : teachers) {
				k->displayInfo();
			}
		}

#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		vector<Student*>students;
		vector<Teacher*>teachers;
		ReadFile(teachers, students);
		displayStudents(students);
	}
		   private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			   vector<Student*>students;
			   vector<Teacher*>teachers;
			   ReadFile(teachers, students);
			   displayTeachers(teachers);
		   }
	private: System::Void textbox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
};