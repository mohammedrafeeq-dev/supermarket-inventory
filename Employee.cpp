#include "Employee.h"
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;


void Employee::EmpCheckin(string name)
		{
			ofstream file("Employees_Attendance.txt" , ios::out | ios::app);
			if(!file.is_open()){
				cout << "Error opening file." << endl;
                return;
			}
			time_t tt;
            struct tm * ti ;
            time(&tt);
            ti = localtime(&tt);
			file<<name<<": "<<"Check in at>>"<<asctime(ti);
			file.close();
		}
void Employee::EmpCheckout()
		{
			ofstream file("Employees_Attendance.txt" , ios::out | ios::app);
			if(!file.is_open()){
				cout << "Error opening file." << endl;
                return;
			}
			time_t tt;
            struct tm * ti ;
            time(&tt);
            ti = localtime(&tt);
			file<<"       Check out at>>"<<asctime(ti);
			file<<"_______________________________________________________________"<<endl;
			file.close();
		}
void Employee::Displayatt()
		{
			ifstream file("Employees_Attendance.txt");
			if(!file.is_open()){
				cout << "Error opening file." << endl;
                return;
			}
			string line;
			while(getline(file , line))
			{
				cout<<line<<endl;
			}
			file.close();
		}
void Employee::creatEAccount(string name, string pass, string RePass, string contactInfo , string role) {
        cout << "Password: ";
		cin >> pass;
        while (!setPass) { 
            cout << "Re-Enter Pass: ";
            cin >> RePass;
            if (pass == RePass) {
                setPass = true;
                Username = name;
                Password = pass;
                cout<<"Role: ";
                cin >> role;
                cout << "Contact Info Email/Phone number etc...: ";
                cin >> contactInfo;
                ContactInfo = contactInfo;
                EmployeeRole = role;
                break;
            } 
			else {
                cout << "Passwords don't match! Try again." << endl;
            }
        }
    }
void Employee::saveEInfo() {
        if (setPass) { 
            ofstream file("EmployeesInfo.txt", ios::out | ios::app); 
            if (!file.is_open()) {
                cout << "Error opening file." << endl;
                return;
            }
            file << Username << " " << Password << " " <<EmployeeRole<<" "<< ContactInfo << endl;
            file.close();
        }
        }
void Employee::searchEAccount(string S_Username) {
		string line;
		ifstream inputFile("EmployeesInfo.txt");
		if (!inputFile.is_open()) 
		{
            cout << "Error opening input file." << endl;
            return;
        }
        bool found = false;
        while (getline(inputFile, line)) 
		{
            if (line.find(S_Username) != string::npos) 
			{
                found = true;
                cout << "Account found:" << endl;
                cout << line << endl;
                break;
            }
        }
        if(!found)
		{
			cout<<"\nAccount not Found!";
		}
        inputFile.close();
	}
void Employee::removeEAccount(string CancelACC) {
        string line;
        ifstream inputFile("EmployeesInfo.txt");
        ofstream tempFile("temp.txt", ios::out | ios::trunc);
        
        if (!inputFile.is_open()) {
            cout << "Error opening input file." << endl;
            return;
        }
        
        if (!tempFile.is_open()) {
            cout << "Error creating temporary file." << endl;
            inputFile.close();
            return;
        }
        
        bool found = false;
        
        while (getline(inputFile, line)) {
            if (line.find(CancelACC) != string::npos) {
                found = true;
                cout << "Account '" << CancelACC << "' found and removed." << endl;
            } else {
                tempFile << line << endl; 
            }
        }
        
        inputFile.close();
        tempFile.close();
        
        if (!found) {
            cout << "Account '" << CancelACC << "' not found." << endl;
        } else {
            
            remove("EmployeesInfo.txt"); 
            rename("temp.txt", "EmployeesInfo.txt"); 
        }
    }
void Employee::updateEAccount(string U_name)
	{
		string line;
        ifstream inputFile("EmployeesInfo.txt");
        ofstream tempFile("temp.txt", ios::out | ios::trunc);
        
        if (!inputFile.is_open()) {
            cout << "Error opening input file." << endl;
            return;
        }
        
        if (!tempFile.is_open()) {
            cout << "Error creating temporary file." << endl;
            inputFile.close();
            return;
        }
        
        bool found = false;
        
        while (getline(inputFile, line)) {
            
            if (line.find(U_name) != string::npos) {
                found = true;
            } else {
                tempFile << line << endl; 
            }
        }
        inputFile.close();
        tempFile.close();
        
        if (!found) {
            cout << "Account '" << U_name << "' not found." << endl;
        } else {
            
            remove("EmployeesInfo.txt"); 
            rename("temp.txt", "EmployeesInfo.txt"); 
        }
    }
		
