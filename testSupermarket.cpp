#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<ctime>
#include"Inventory.h"
#include "personAccount.h"
#include "Employee.h"
#include "SalesTransaction.h"
#include "Costumer.h"
using namespace std;

int main() {
	SalesTransaction Sales;
	personAccount account; 
	Costumer costumer;
	Employee employee;
	Inventory inventory;
	cout<<"Are you: \n1: Employee \n2: Costumer \n3: Manager \n>>";
	int openChoice;
	cin>>openChoice;
	switch(openChoice)
	{
		case 1:
		{
			bool found = false;
			string LogUser , LogPass;
			cout<<"Check in: "<<endl;
			while(found == false)
			{
		    cout << "Username: ";
            cin >> LogUser;
            cout << "Password: ";
            cin >> LogPass;
            ifstream CostumersFile("EmployeesInfo.txt"); 
            if (!CostumersFile.is_open()) {
               cout << "Error opening input file." << endl;
               return 1; 
               }
            string S_user, S_pass, S_role , S_contact;
            while (CostumersFile >> S_user >> S_pass >> S_role >> S_contact) {
                if (LogUser == S_user && LogPass == S_pass) {
                    found = true;
                    cout << "Login successful! \n__________________________________ " << endl;
                    break; 
                 }
            }
                   if (!found) {
                         cout << "Wrong Username/Password! \n__________________________________" << endl;
                         }
                    CostumersFile.close();
                }
    if(found == true)
    {
    employee.EmpCheckin(LogUser);
    fstream InvenFile;
    int choice;
    while(choice != 5)
    {
    cout<<"\n1: Add Product"<<"\t\t2: Remove Product"<<"\n3: Search for Product"<<"\t4: Update Product Information"<<"\n5: Check out"<<"\n>>";
    cin>>choice;
    switch(choice)
    {
    	case 1:
		{
			string name , type , expDate;
			int Quantity;
			double Prize;
			cout<<"Enter the product Information"<<endl;
			cout<<"Name: "; cin>>name;
			cout<<"Type: "; cin>>type;
			cout<<"Quantity: "; cin>>Quantity;
			cout<<"Prize: "; cin>>Prize;
			cout<<"Expiration Date: "; cin>>expDate;
			Product producti(name , type , Quantity , Prize , expDate);
			inventory.addProduct(producti , InvenFile);
			cout<<"<Product added to the Inventory Successfully>";
			break;
		}
		case 2:
		{
			string prod;
			cout<<"Enter the name of the Product you want to remove from the Inventory\n>>";
			cin>>prod;
			inventory.removeProduct(prod);
			break;
		}
		case 3:
		{
			string S_prod;
			cout<<"Enter the name of the Product you are looking for in the Inventory\n>>";
			cin>>S_prod;
			inventory.searchProduct(S_prod);
			break;
		}
		case 4:
		{
			string U_name;
			cout<<"Enter the name of the Product: ";cin>>U_name;
			inventory.searchProduct(U_name);
			inventory.updateProduct(U_name);
			string name , type , expDate;
			int Quantity;
			double Prize;
			cout<<"Enter the new Info: =>"<<endl;
			cout<<"Name: "; cin>>name;
			cout<<"Type: "; cin>>type;
			cout<<"Quantity: "; cin>>Quantity;
			cout<<"Prize: "; cin>>Prize;
			cout<<"Expiration Date: "; cin>>expDate;
			Product producti(name , type , Quantity , Prize , expDate);
			inventory.addProduct(producti , InvenFile);
			cout<<"<Product Updated Successfully>";
			break;
		}
		case 5:
		{
			employee.EmpCheckout();
			break;
		}
		default :
		{
			cout<<"Wrong Input!";
			break;
		}
	}
}
			break;
		}
	}
	    case 2:
		{
			fstream CostumersFile("CostumersInfo.txt");
			cout<<"1: Log In    2: Sign Up \n>>";
			int open2Cchoice;
			cin>>open2Cchoice;
			bool Cosloging = false;
			string LogUser, LogPass;
			if(open2Cchoice == 1)
			{
                cout << "Username: ";
                cin >> LogUser;
                cout << "Password: ";
                cin >> LogPass;
                ifstream CostumersFile("CostumersInfo.txt"); 
               if (!CostumersFile.is_open()) {
               cout << "Error opening input file." << endl;
               return 1; 
               }
               string S_user, S_pass, S_contact;
               bool found = false;
               while (CostumersFile >> S_user >> S_pass >> S_contact) {
                   if (LogUser == S_user && LogPass == S_pass) {
                        Cosloging = true;
                        found = true;
                        cout << "Login successful! \n__________________________________ " << endl;
                        break; 
                        }
                        }
                   if (!found) {
                         cout << "Wrong Username/Password! \n__________________________________" << endl;
                         }
                    CostumersFile.close();
                    
			}
			else if(open2Cchoice == 2)
			{
				cout << "Please Enter your Information: " << endl;
                cout << "Username: ";
                cin >> LogUser;
				string pass, RePass, contactInfo;
				account.createAccount(LogUser, pass, RePass, contactInfo);
				if (account.setPass) {
					account.saveCInfo();
                      cout << "Account created successfully!" << endl;
                      } else {
                           cout << "Account creation failed." << endl;
                             }                     
			}
			if(account.setPass || Cosloging)
			{
				Inventory inventory;
				string productName ;
				int quantity;
				inventory.DisplayInfo();
				cout<<"__________________________________\n";
				cout<<"Enter the name of the product you want to buy then type 'Cout' to pay off :) "<<endl;
				  while (true) {
                      cout << "\n>> ";
                      cin >> productName;
                      if (productName == "Cout") {
                         Sales.Checkout();
						 Sales.PurchaseHistory(LogUser);         
                         remove("ShoppingCart.txt");
                         break;  
                      }
					  else if(productName == "remove"){
					  	cout<<"Enter the name of the product you want to remove from your cart \n>>";
					  	string Remove;
					  	cin>>Remove;
					  	Sales.removefromCart(Remove);
					  } 
					  else {
                         cout << ">> Quantity: ";
                         cin >> quantity;
                         Sales.addToCart(productName, quantity);
                         cout<<"type 'remove' if you want to remove something from your cart :)"<<endl;
                      }
                  }
			}
			break;
		}
	    case 3:
		{
			string Accesscode = "MU2005FAI2024";
			string QAcode;
			cout<<"Access code: "; cin>>QAcode;
			while(Accesscode != QAcode )
			{
				cout<<"Wrong code!"<<endl;
				cout<<"Type 'E'/'e' if you want to exit program"<<endl;
				cout<<"Access code: "; cin>>QAcode;
				if(QAcode == "E" || QAcode == "e"){
					return 0;
				}
			}
			if(Accesscode == QAcode)
			{
				cout<<"1: Employees Management \n2: Costumers Management \n>>";
				int ManageChoice;
				cin>>ManageChoice;
				if(ManageChoice == 1){
					cout<<"1: Search for Account     2: Update Account \n3: Remove Account         4: Creat Account \n5: Employees Attendas \n>>";
					int ManageEchoice;
					cin>>ManageEchoice;
					switch(ManageEchoice)
					{
						case 1:
						{
							string searchUser;
							cout<<"Username: "; cin>>searchUser;
							employee.searchEAccount(searchUser);
							break;
						}
						case 2: 
						{
							string UpdateEAccount;
							cout<<"Username: "; cin>>UpdateEAccount;
							employee.searchEAccount(UpdateEAccount);
							employee.updateEAccount(UpdateEAccount);
							cout<<"Enter the new Info: "<<endl;
							string name, pass, RePass, contactInfo , role;
							cout<<"Username: ";
							cin>>name;
							employee.creatEAccount(name, pass, RePass, role, contactInfo);
			            	if (employee.setPass) {
							    employee.saveEInfo(); 
                                cout << "Account Updated successfully!" << endl;
                                } else {
                                    cout << "Account Update failed." << endl;
                                }                     
							break;
						}
						case 3:
	                	{
			                string remove;
		                	cout<<"Username: "; cin>>remove;
			                employee.removeEAccount(remove);
			                break;
		                }
		                case 4:
						{
							cout << "Enter the Employee's Information': " << endl;
							string  name , pass, RePass,role, contactInfo;
                            cout << "Username: ";
                            cin >> name;
				            employee.creatEAccount(name, pass, RePass , role, contactInfo);
				            if (employee.setPass) {
					             employee.saveEInfo();
                                 cout << "Account created successfully!" << endl;
                            } 
					        else {
                                cout << "Account creation failed." << endl;
                            }          
							break;
						}
						case 5:
						{
							employee.Displayatt();
							break;
						}
						default:
						{
							cout<<"Wrong input"<<endl;
							break;
						}
					}
				}
				else if(ManageChoice == 2){
					cout<<"1: Search for Account     2: Update Account \n3: Remove Account         4: Purchase History \n>>";
					int ManageCchoice;
					cin>>ManageCchoice;
					switch(ManageCchoice)
					{
						case 1:
						{
							string searchUser;
							cout<<"Username: "; cin>>searchUser;
							costumer.searchCAccount(searchUser);
							break;
						}
						case 2: 
						{
							string UpdateCAccount;
							cout<<"Username: "; cin>>UpdateCAccount;
							costumer.searchCAccount(UpdateCAccount);
							costumer.updateCAccount(UpdateCAccount);
							cout<<"Enter the new Info: "<<endl;
							string name, pass, RePass, contactInfo;
							cout<<"Username: ";
							cin>>name;
							account.createAccount(name, pass, RePass, contactInfo);
			            	if (account.setPass) {
							    account.saveCInfo(); 
                                cout << "Account Updated successfully!" << endl;
                                } else {
                                    cout << "Account Update failed." << endl;
                                }                     
							break;
						}
						case 3:
	                	{
			                string remove;
		                	cout<<"Username: "; cin>>remove;
			                costumer.removeCAccount(remove);
			                break;
		                }
						case 4:
						{
							Sales.DisplayHistory();
							break;
								}
						default:
						{
							cout<<"Wrong Input!"<<endl;
							break;
						}		
					}
				}
				else{
					cout<<"Wrong input"<<endl;
				}
			}
			
			break;
		}
		default :
		{
			cout<<"Wrong Input!";
			break;
		}
	}
    
return 0;
}


