#ifndef PERSON_ACCOUNT_H // Include guard start
#define PERSON_ACCOUNT_H

#include <string>
using namespace std;

class personAccount {
public:
    string Username, Password, ContactInfo;
    bool setPass; // Moved inside private to encapsulate data

public:
    personAccount() : setPass(false) {} // Constructor definition corrected
    void createAccount(string name, string pass, string RePass, string contactInfo);
    void saveCInfo();
};

#endif
