#include "SalesTransaction.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<ctime>
using namespace std;



void SalesTransaction::addToCart(const string& productName, int quantity) {
        ifstream inputFile("Inventory.txt");
        ofstream tempFile("ShoppingCart.txt", ios::out | ios::app);
        if (!inputFile.is_open()) {
            cout << "Error: Unable to open Inventory.txt" << endl;
            return;
        }
        if (!tempFile.is_open()) {
            cout << "Error: Unable to open ShoppingCart.txt" << endl;
            inputFile.close();
            return;
        }
        bool found = false;
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            string name, type, exp;
            int inventoryQuantity;
            double price;

        if (ss >> name >> type >> inventoryQuantity >> price >> exp) {
            if (name == productName) {
                if (quantity > inventoryQuantity) {
                    cout << "Insufficient quantity in inventory for '" << productName << "'" << endl;
                    inputFile.close();
                    tempFile.close();
                    return;
                }
                tempFile << name << " " << quantity << " " << price << endl;
                cout << "Added " << quantity << " units of '" << productName << "' to your Shopping Cart :)" << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "Product '" << productName << "' not found in inventory." << endl;
    }

    inputFile.close();
    tempFile.close();
}

void SalesTransaction::removefromCart(string Cancelprod){
			 string line;
        ifstream inputFile("ShoppingCart.txt");
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
            cout << "Product '" << Cancelprod << "' not found in Cart." << endl;
        } else {
            
            remove("ShoppingCart.txt"); 
            rename("temp.txt", "ShoppingCart.txt"); 
        }
		}
		
void SalesTransaction::Checkout() {
            ifstream file("ShoppingCart.txt");
            if (!file.is_open()) {
                cout << "Failed to open ShoppingCart.txt" << endl;
                return;
            }   
            string name;
            int quantity;
            double price;
            double total = 0.0;
            bool calculated = false;
    while (file >> name >> quantity >> price) {
        double itemTotal = quantity * price;
        total += itemTotal;
        calculated = true;
    }
    file.close();
    if (calculated) {
        cout << "Total cost of items in the shopping cart: $" << total << endl;
    } else {
        cout << "No items found in the shopping cart." << endl;
    }
}

void SalesTransaction::PurchaseHistory(string name){
	    ifstream inputFile("ShoppingCart.txt");
        ofstream File("PurchaseHistory.txt", ios::out | ios::app);
        if (!inputFile.is_open()) {
            cout << "Error: Unable to open ShoppingCart" << endl;
            return;
        }
        if (!File.is_open()) {
            cout << "Error: Unable to open PurchaseHistory" << endl;
            inputFile.close();
            return;
        }
        string line;
        File<<name<<": ";
        while (getline(inputFile, line)) {
            File<<line<<" ";
        }
        time_t tt;
        struct tm * ti ;
        time(&tt);
        ti = localtime(&tt);
        File<<"Date and Time: "<<asctime(ti);
    inputFile.close();
    File.close();
		
	}
	
void SalesTransaction::DisplayHistory ()
	{
		ifstream file("PurchaseHistory.txt");
		if (!file.is_open()) {
            cout << "Error: Unable to open PurchaseHistory" << endl;
            file.close();
            return;
        }
        string line;
        while(getline(file , line))
		{
			cout<<line<<endl;
		}
		file.close();
	}
