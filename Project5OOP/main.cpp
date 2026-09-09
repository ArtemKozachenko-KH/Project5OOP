#include <iostream>
using namespace std;
#include <string>

class Bankomat
{
	int BankId;
	int MinCashOut;
	int MaxCashOut;
	int BankBalance;
public:
	Bankomat();
	Bankomat(int bid, int min, int max, int bbal);
	void InitBankomat();
	void CheckBankomat();
	void CashIn();
	void CashOut();
	void CheckBankBal();
	string BalToStr();
};

Bankomat::Bankomat()
{
	BankId = 0;
	MinCashOut = 0;
	MaxCashOut = 0;
	BankBalance = 0;
}

Bankomat::Bankomat(int bid, int min, int max, int bbal)
{
	if (bid > 0)
	{
		BankId = bid;
		MinCashOut = min;
		if (max > min)
		{
			MaxCashOut = max;
		}
		else
		{
			MaxCashOut = min;
		}
		BankBalance = bbal;
	}
}

void Bankomat::InitBankomat()
{
	cout << "\n\t|----------Initialization Bankomat----------|"<<endl
		<< "Enter Bankomat id -> ";
	cin >> BankId;
	cout<< "Enter Minimal Cash Out amount -> ";
	cin >> MinCashOut;
	cout << "Enter Maximum Cash Out amount -> ";
	cin >> MaxCashOut;
	cout << "Enter Bankomat balance -> ";
	cin >> BankBalance;
	while (BankId < 0 || MinCashOut <= 0 || MinCashOut % 10 != 0 || MaxCashOut % 10 != 0 || MaxCashOut <= 0 || MaxCashOut < MinCashOut || BankBalance < 0 || BankBalance % 10 != 0)
	{
		if (BankId < 0)
		{
			cout<< "\t!!!!!Bankomat id can't be negative!!!!! \nEnter Bankomat id -> ";
			cin >> BankId;
		}
		if (MinCashOut <= 0 || MinCashOut % 10 != 0)
		{
			cout << "\t!!!!!Bankomat Minimal Cash Out amount must be more than 0 and multiple of 10!!!!!. \nEnter Minimal Cash Out amount -> ";
			cin >> MinCashOut;
		}
		if (MaxCashOut <= 0 || MaxCashOut % 10 != 0 || MaxCashOut<MinCashOut)
		{
			cout << "\t!!!!!Bankomat Maximum Cash Out amount must be more than 0 and Minimal Cash Out and multiple of 10!!!!!. \nEnter Maximum Cash Out amount -> ";
			cin >> MaxCashOut;
		}
		if (BankBalance < 0 || BankBalance % 10 != 0)
		{
			cout << "\t!!!!!Bankomat Balance can't be negative and must be a multiple of 10!!!!!. \nEnter Bankomat balance -> ";
			cin >> BankBalance;
		}
	}
	cout << endl;
}

void Bankomat::CheckBankomat()
{
	cout << "\n\t|----------SHOW BANKOMAT INFO----------|" << endl
 		<< "BankId: " <<BankId<< endl
		<< "Minimal Cash out: " <<MinCashOut<< endl
		<< "Maximum Cash out: " <<MaxCashOut<< endl
		<< "Bankomat balance: " <<BankBalance<< endl;
}

void Bankomat::CashIn()
{
	int sum;
	cout << "\n\t|----------BANKOMAT CASH IN----------|"<<"\nEnter sum that you want cash In -> ";
	cin >> sum;
	while (sum < 10 || sum % 10 != 0)
	{
		cout << "\t!!!!!Sum can't be negative and must be a multiple of 10!!!!!. \nEnter sum that you want cash In -> ";
		cin >> sum;
	}
	BankBalance += sum;
	cout << "\tCash in was successful\n";
}

void Bankomat::CashOut()
{
	int sum;
	cout << "\n\t|----------BANKOMAT CASH OUT----------|" << "\nEnter sum that you want cash out -> ";
	cin >> sum;
	while (sum < 10 || sum % 10 != 0 || sum<MinCashOut || sum>MaxCashOut || sum>BankBalance)
	{
		if (sum < 10 || sum % 10 != 0)
		{
			cout << "\t!!!!!Sum can't be negative and must be a multiple of 10!!!!!. \nEnter sum that you want cash out -> ";
			cin >> sum;
		}
		else if (sum < MinCashOut)
		{
			cout << "\t!!!!!Sum must be more than Minimal Cash out -> " << MinCashOut <<" UAH . !!!!!" <<"\nEnter sum that you want cash out -> ";
			cin >> sum;
		}
		else if (sum > MaxCashOut)
		{
			cout << "\t!!!!!Sum must be less than Maximum Cash out -> " << MaxCashOut << " UAH . !!!!!" << "\nEnter sum that you want cash out -> ";
			cin >> sum;
		}
		else
		{
			cout << "\t!!!!!Bankomat doesn't have enough money. Available balance -> " << BankBalance << " UAH . !!!!!" << "\nEnter sum that you want cash out -> ";
			cin >> sum;
		}
	}
	BankBalance -= sum;
	cout << "\tCash out was successful\n";
}

void Bankomat::CheckBankBal()
{
	cout << "\n\t|----------SHOW BANKOMAT BALANCE----------|" << endl
		<< "\tBankomat balance: " << BankBalance << endl;
}

string Bankomat::BalToStr()
{
	string balance = to_string(BankBalance);
	return balance;
}

int main()
{
	Bankomat ban1;
	ban1.InitBankomat();
	ban1.CheckBankomat();
	ban1.CashIn();
	ban1.CheckBankBal();
	ban1.CashOut();
	ban1.CheckBankBal();
	cout <<"\n\t String balance ->"<< ban1.BalToStr();
}
