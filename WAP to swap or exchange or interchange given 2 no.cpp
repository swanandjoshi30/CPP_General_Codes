//write a program to swap/exchange/interchange given 2 numbers

#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a,b,temp;
	cout<<"Enter value of a and b ";
	cin>>a>>b;
	temp=a;
	a=b;
	b=temp;
	cout<<"After swapping a ="<<a<<endl<<"b ="<<b;
	return 0;
}