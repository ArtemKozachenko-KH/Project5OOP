#include <iostream>
using namespace std;

class Fraction
{
	int chis;
	int znam;
public:
	Fraction();
	Fraction(int cs, int zm);
	void PrintFract();
	void SetFract();
	Fraction PlusFract(Fraction& b);
	Fraction MinusFract(Fraction& b);
};

Fraction::Fraction()
{
	chis = 0;
	znam = 1;
}

Fraction::Fraction(int cs, int zm)
{
	chis = cs;
	if (zm != 0)
	{
		znam = zm;
	}
	else
	{
		znam = 1;
	}
}

void Fraction::PrintFract()
{
	cout << chis << "/" << znam << endl;
}

void Fraction::SetFract()
{
	cout << "Enter chislitel: ";
	cin >> chis;
	cout << "\nEnter znamenatel: ";
	cin >> znam;
	while (znam == 0)
	{
		cin >> znam;
		if (znam == 0)
		{
			cout << "Znamenatel ne raven 0"<<endl;
		}
	}

}

Fraction Fraction::PlusFract(Fraction& b)
{
	Fraction result;
	result.chis = chis*b.znam + b.chis*znam;
	result.znam = znam * b.znam;
	return result;
}

Fraction Fraction::MinusFract(Fraction& b)
{
	Fraction result;
	result.chis = chis * b.znam - b.chis * znam;
	result.znam = znam * b.znam;
	return result;
}

int main()
{
	Fraction obj1;
	obj1.SetFract();
	Fraction obj2;
	obj2.SetFract();
	Fraction obj3 = obj1.PlusFract(obj2);
	obj3.PrintFract();
	obj3 = obj1.MinusFract(obj2);
	obj3.PrintFract();

}