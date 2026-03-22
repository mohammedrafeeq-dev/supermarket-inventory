#include<string>
using namespace std;

class Product {
public:
    string name, type, ExpDate;
    int Quantity;
    double Prize;
    
    Product(string N, string T, int quan, double prize, string expDate);
    void getInfo();
};

class Inventory {
public:
	void DisplayInfo();
    void addProduct(Product product, fstream& file);
    void removeProduct(string Cancelprod);
	void searchProduct(string searchProd);
    void updateProduct(string U_name);
};