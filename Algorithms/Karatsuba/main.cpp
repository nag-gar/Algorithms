#include <iostream>
#include <cstdlib>
#include <sstream>
#include <math.h>

using namespace std;

int size (int x)
{
	stringstream ss;
	ss << x;
	string n1 = ss.str();
	
	return n1.size();
}

string intToString (int x)
{
	stringstream ss;
	ss << x;
	string n1 = ss.str();
	
	return n1;
}

int stringToInt (string x)
{
	int numb;
	istringstream (x) >> numb;
	return numb;
}

int max (int x , int y)
{
	if (x > y)
		return x;
	else
		return y;
}

int * divide (int x , int y)
{
	int * data = new int [5];
	
	string num1 = intToString (x);
	string num2 = intToString (y);
	
	if (num1.size() > num2.size())
	{
		while (num2.size() != num1.size())
			num2 = "0" + num2;
	}
	
	else
	{
		while (num1.size() != num2.size())
			num1 = "0" + num1;
	}
	
	int div = num1.size() / 2;
	string part1 = num1.substr(0 , div);
	string part2 = num1.substr(div , num1.size() - div);
	
	string part3 = num2.substr(0 , div);
	string part4 = num2.substr(div , num2.size() - div);
	
	data[0] = stringToInt (part1);
	data[1] = stringToInt (part2);
	data[2] = stringToInt (part3);
	data[3] = stringToInt (part4);
	data[4] = num1 .size() - div;
	
	return data;
}

int karatsuba (int num1 , int num2)
{
	if (num1 < 10 || num2 <10)
		return num1 * num2;
	
	int result = 0;
	
	int * data = divide (num1 , num2);
	int a = data[0];
	int b = data[1];
	int c = data[2];
	int d = data[3];
	int m = data[4];
	//cout << a << " " << b<<endl;
	//cout << c << " " << d<<endl;
	//cout<<endl<<endl;
	int z2 = karatsuba(a , c);
	int z0 = karatsuba(b , d);
	int z1 = karatsuba((a + b) , (c + d));
	z1 = z1 - z2 - z0;
	result = (z2 * pow(10 , m * 2)) + (z1 * pow(10 , m)) + z0;
	//cout << "z2 is = "<<z2<<endl<<endl;
	//cout << "z0 is = "<<z0<<endl<<endl;
	//cout << "z1 is = "<<z1<<endl<<endl;
	//cout << "Result is = "<<result<<endl<<endl;
	return result;
}

int main()
{
	int res = karatsuba(12345,6789);
	cout<<res<<endl;
	system("PAUSE");
	return 0;
}
