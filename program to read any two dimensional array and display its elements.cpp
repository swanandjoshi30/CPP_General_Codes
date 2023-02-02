//program to read any two dimensional array and display its elements

#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a[2][3],i,j;
	cout<<"Enter any matrix ";
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=2;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"The entered matrix is "<<endl;
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=2;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
}
return 0;
}