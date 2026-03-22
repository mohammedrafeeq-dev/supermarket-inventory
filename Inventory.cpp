#include"Inventory.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


    
Product::Product(string N, string T, int quan, double prize, string expDate) {
        name = N;
        type = T;
        Quantity = quan;
        Prize = prize;
        ExpDate = expDate;
    }
    
void Product::getInfo() {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Quantity: " << Quantity << endl;
        cout << "Prize: " << Prize << endl;
        cout << "Expiration Date: " << ExpDate << endl;
    }



void Inventory::DisplayInfo(){
		ifstream DisFile("Inventory.txt");
				if(!DisFile.is_open())
				{
					cout<<"Faild to open this file!";
					return ;
				}
				string line;
				while(getline(DisFile , line))
				{
					cout<<line<<endl;
				}
				DisFile.close();
	}
void Inventory::addProduct(Product product, fstream& file) {
        file.open("Inventory.txt", ios::out | ios::app);
        if (!file.is_open()) {
            cout << "Error opening file." << endl;
            return;
        }
        file << product.name<<" "<<product.type<<" "<<product.Quantity<<" "<<product.Prize<<"$ "<<product.ExpDate<<endl;
        file.close();
    }
    
void Inventory::removeProduct(string Cancelprod) {
        string line;
        ifstream inputFile("Inventory.txt");
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
            
            if (line.find(Cancelprod) != string::npos) {
                found = true;
                cout << "Product '" << Cancelprod << "' found and removed." << endl;
            } else {
                tempFile << line << endl; 
            }
        }
        
        inputFile.close();
        tempFile.close();
        
        if (!found) {
            cout << "Product '" << Cancelprod << "' not found in inventory." << endl;
        } else {
            
            remove("Inventory.txt"); 
            rename("temp.txt", "Inventory.txt"); 
        }
    	
	}
void Inventory::searchProduct(string searchProd) {
		string line;
		ifstream inputFile("Inventory.txt");
		if (!inputFile.is_open()) 
		{
            cout << "Error opening input file." << endl;
            return;
        }
        bool found = false;
        while (getline(inputFile, line)) 
		{
            if (line.find(searchProd) != string::npos) 
			{
                found = true;
                cout << "Product found:" << endl;
                cout << line << endl;
                break;
            }
        }
        if(!found)
		{
			cout<<"\nProduct not Found!";
		}
        inputFile.close();
	}
	
void Inventory::updateProduct(string U_name)
	{
		string line;
        ifstream inputFile("Inventory.txt");
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
            cout << "Product '" << U_name << "' not found in inventory." << endl;
        } else {
            
            remove("Inventory.txt"); 
            rename("temp.txt", "Inventory.txt"); 
        }
    	
	}