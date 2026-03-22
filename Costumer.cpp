#include "Costumer.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void Costumer::searchCAccount(string S_Username) {
		string line;
		ifstream inputFile("CostumersInfo.txt");
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
void Costumer::removeCAccount(string CancelACC) {
        string line;
        ifstream inputFile("CostumersInfo.txt");
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
            
            remove("CostumersInfo.txt"); 
            rename("temp.txt", "CostumersInfo.txt"); 
        }
    }
void Costumer::updateCAccount(string U_name)
	{
		string line;
        ifstream inputFile("CostumersInfo.txt");
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
            
            remove("CostumersInfo.txt"); 
            rename("temp.txt", "CostumersInfo.txt"); 
        }
    }
