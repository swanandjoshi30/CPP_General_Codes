//program to display multiplication table of given number

#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int n,i;
	cout<<"Enter n ";
	cin>>n;
	i=1;
	while(i<=10)
	{
		cout<<n*i<<endl;
		i++;
	}
	return 0;
}