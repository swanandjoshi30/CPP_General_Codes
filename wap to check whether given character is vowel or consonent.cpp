//wap to check whether given character is vowel or consonent

#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	char ch;
	cout<<"Enter any character ";
	cin>>ch;
	if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
	cout<<ch<<"is vowel";
	else
	cout<<ch<<"is consonent";
	return 0;
	
}