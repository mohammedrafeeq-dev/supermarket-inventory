#include "personAccount.h"
#include <iostream>
#include<fstream>
#include <string>
using namespace std;




void personAccount::createAccount(string name, string pass, string RePass, string contactInfo) {
        cout << "Password: ";
        cin >> pass;
        
        while (!setPass) { 
            cout << "Re-Enter Pass: ";
            cin >> RePass;
            if (pass == RePass) {
                setPass = true;
                Username = name;
                Password = pass;
                cout << "A way to contact you Email/Phone number etc...: ";
                cin >> contactInfo;
                ContactInfo = contactInfo;
                break;
            } 
			else {
                cout << "Passwords don't match! Try again." << endl;
            }
        }
    }
void personAccount::saveCInfo() {
        if (setPass) { 
            ofstream file("CostumersInfo.txt", ios::out | ios::app); 
            if (!file.is_open()) {
                cout << "Error opening file." << endl;
                return;
            }
            file << Username << " " << Password << " " << ContactInfo << endl;
            file.close();
        }
        }
