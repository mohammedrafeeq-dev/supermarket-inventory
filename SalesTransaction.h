#include<string>
using namespace std;


class SalesTransaction
{
	public:
		
	void addToCart(const string& productName, int quantity); 
	void removefromCart(string Cancelprod);
    void Checkout();
    void PurchaseHistory(string name);
	void DisplayHistory ();
}; 