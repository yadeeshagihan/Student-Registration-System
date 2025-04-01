#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
using namespace std;

class Student{
	private:
		string fname, lname, regno, course, email, ccode;
		char cname[30],ch;
		int a;
	public:
		void menu();
		void insert();
		void display();
		void add();
		void show();
};
void Student::menu(){
	menustart:
	int choice;
	char x;
	system("cls");
	cout << "\tWELCOME TO THE STUDENT REGISTRATION SYSTEM" << endl;
	cout << "\nMENU\n";
	cout << "\nEnter your position:\n";
	cout << "1 - Student\n2 - Academic\n3 - Management staff\n4 - Admin\n---------------------\n5 - Exit\n" << endl;
	cout << "Choose from the above: ";
	cin >> choice;

	switch(choice){
	case 1:
		insert();
		break;
    case 2:
    case 3:
        display();
		break;
    case 4:
        add();
        break;
    case 5:
        exit(0);
	default:
		cout << "\nInvalid ! Please Try Again.\n" << endl;
	}

	getch();
	goto menustart;
}

void Student::insert(){
	system("cls");
	fstream file;
	cout << "\nEnter your details to register for course" << endl;
	cout << "Enter first name: ";
    cin >> fname;
    cout << "Enter last name: ";
    cin >> lname;
    cout << "Enter Registration number: ";
    cin >> regno;
	cout << "Enter Email: ";
	cin >> email;
    cout << "\nSelect the course that you want:\n";
    show();
    cout << "Enter the course code that you choose from the above: ";
    cin >> course;

    cout << "\nYour registration was successful !\n";

    file.open("Records.txt", ios::app | ios::out);
    file << fname <<"\t\t" << lname << "\t\t" << regno << "\t\t" << email << "\t\t" << course << endl;
    file.close();
}

void Student::display(){
    system("cls");
    fstream file;
    cout << "\nRegistered Students:" << endl;
    file.open("Records.txt",ios::in);
    file >> fname >> lname >> regno >> email >> course;
    cout << "First name\t\tLast name\t\tReg No\t\tEmail\t\t\t\t\tCourse" << endl;
    while(!file.eof()){
        cout << fname << "\t\t\t" << lname << "  \t\t" << regno << "\t\t" << email << "  \t\t" << course << endl;
        file >> fname >> lname >> regno >> email >> course;
    }
    file.close();
}

void Student::add(){
    system("cls");
    fstream file;
    cout << "1 - Add a course\n2 - Add an account\n3 - Available courses" << endl;
    cout << "Choose from the above: ";
    cin >> a;
    if(a==1){
        cout << "\nEnter the course code: ";
        cin >> ccode;
        cin.ignore();
        cout << "Enter the course name: ";
        gets(cname);

        cout << "\nYou have successfully added a new course !" << endl;
        file.open("Addco.txt",ios::app | ios::out);
        file << ccode << cname << endl;
        file.close();
    }
    else if(a==2){
        insert();
    }
    else if(a==3){
        show();
    }
    else{
        cout << "\nInvalid ! Please Try Again." << endl;
    }
}

void Student::show(){
    system("cls");
    fstream file;

    cout << "Available Courses:" << endl;
    cout << "ICT1407 - Database Management System\nICT1306 - Object Oriented Programming\nICT1308 - Operating System\nICT1305 - Data Structures";
    file.open("Addco.txt",ios::in);
    file >> ccode >> cname;
    cout << "\n";
    cout << ccode << " " << cname ;

    while(file>>noskipws>>ch){
        cout << ch;
    }
    file.close();
    cout << endl;
}

int main(){
	Student s1;
	s1.menu();
	return 0;
}

