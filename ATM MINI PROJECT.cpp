#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

/* ATM machine with following details
  1. Check Balance
  2. Cash Withdraw
  3. User Details
  4. Update Mobile no.
  
*/


class ATM
{
	private:
		long long int account_no,mobile_no;
		string Name;
		int pin;
		double balance;
		
	public:
		void setdata(long long int,long long int,string,int, double);
		
		bool check_details(long long int,int);
		void get_balance();
		void cash_withdraw(double);
		void user_details();
		void update_mobile(long long int,long long int);		
};


void ATM::setdata(long long int account_no,long long int mobile_no,string name,int pin,double balance)
{
	this->account_no=account_no;
	this->mobile_no=mobile_no;
	this->Name=name;
	this->pin=pin;
	this->balance=balance;
	
	cout<<endl<<endl;
};

bool ATM::check_details(long long int account_no, int pin)
{
	if(account_no==this->account_no  && pin==this->pin)
	{
		cout<<endl<<endl;
		return true;
	}
	else
	{
		cout<<endl<<endl;
		return false;
	}
};

void ATM::get_balance()
{
	cout<<"Balance = "<<balance<<endl;
	cout<<endl<<endl;
}; 

void ATM::cash_withdraw(double balance)
{
	if(balance<=0 || balance>this->balance)
	{
		cout<<"Incorrect input OR Insufficient Balance"<<endl;
		cout<<endl<<endl;
		return ;
	}
	cout<<"Please collect your cash\n";
	this->balance=this->balance-balance;
	cout<<"Your Remaining balance = "<<this->balance<<endl;
	cout<<endl<<endl;
};

void ATM::user_details()
{
	cout<<"Name = "<<Name<<endl;
	cout<<"Account no. = "<<account_no<<endl;
	cout<<"Balance = "<<balance<<endl;
	cout<<"Mobile no. = "<<mobile_no<<endl;
	cout<<endl<<endl;
};

void ATM::update_mobile(long long int mobile_old,long long int mobile_new)
{
	if(mobile_old != mobile_no)
	{
		cout<<"MisMatch of Old Mobile no. \n Mobile No. updation FAILED\n";
		cout<<endl<<endl;
		return ;
	}
	
	mobile_no=mobile_new;
	cout<<"Mobile No. Updated Successfully\n Your new mobile no is "<<mobile_no<<endl;
	cout<<endl<<endl;
};


int main()
{
	ATM p1;
	long long int ac_no;
	int pin;
	p1.setdata(123456789,9000900099,"Nokom Konyak",0000,80500);
	
	cout<<"*************Welcome to ATM***************\n\n";
	cout<<"Please enter your Account Number :  ";
	cin>> ac_no;
	cout<<"Please enter your pin :  ";
	cin>> pin;
	
	if(!p1.check_details(ac_no,pin))
	{
		cout<<"Incorrect details";
		return 0;
	}
	
	while(1)
	{
		system("cls");
		int choice;
		long long int bal,old_mob,new_mob;
		cout<<"Please Enter Your Choice: \n1.Check Balance\n2.Cash Withdraw\n3.User Details\n4.Update Mobile Number\n5.exit\n\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				system("cls");
				p1.get_balance();
				_getch();
				break;
			
			case 2:
				system("cls");
				cout<<"Please enter the amount :  ";
				cin>>bal;
				p1.cash_withdraw(bal);
				_getch();
				break;
				
			case 3:
				system("cls");
				p1.user_details();
				_getch();
				break;
				
			case 4:
				system("cls");
				cout<<"Please enter old mobile no :  ";
				cin>>old_mob;
				cout<<"Please enter new mobile no :  ";
				cin>>new_mob;
				p1.update_mobile(old_mob,new_mob);
				_getch();
				break;
				
			case 5:
				exit(0);
				
			default:
				system("cls");
				cout<<"Please enter correct choice\n";
				cout<<endl<<endl;
		}
	}
	
	return 0;
}

