#include "personAccount.h"
#include<string>
using namespace std;

class Employee : public personAccount
{
	private:
		string EmployeeRole;
	public:
	void EmpCheckin(string name);
	void EmpCheckout();
	void Displayatt();
	void creatEAccount(string name, string pass, string RePass, string contactInfo , string role);
    void saveEInfo();
    void searchEAccount(string S_Username);
	void removeEAccount(string CancelACC);
    void updateEAccount(string U_name);
		
};