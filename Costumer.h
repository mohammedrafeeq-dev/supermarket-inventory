#include "personAccount.h"
#include<string>
using namespace std;

class Costumer : public personAccount
{
public:
    void searchCAccount(string S_Username);
	void removeCAccount(string CancelACC);
    void updateCAccount(string U_name);
};