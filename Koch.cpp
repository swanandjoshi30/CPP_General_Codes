/*
Problem Statement: c) Write C++ program to generate fractal patterns by using Koch curves.
Code from Computer Graphics (SPPU - Second Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-se-comp-codes/CG
*/

// BEGINNING OF CODE
#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

void koch(int x1,int y1,int x2,int y2,int it)
{
	float angle = (60*3.14)/180;
	int x3 = (2*x1 + x2)/3;//we divide the line segment in 3 parts which is also called trisection
	int y3 = (2*y1 + y2)/3;
	int x4 = (2*x2 + x1)/3;
	int y4 = (2*y2 + y1)/3;
	int x = x3+ (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
	int y = y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);
	if(it>0)
	{
		koch(x1,y1,x3,y3,it-1);
		koch(x3,y3,x,y,it-1);
		koch(x,y,x4,y4,it-1);
		koch(x4,y4,x2,y2,it-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
	}
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int x1,y1,x2,y2,order;
    cout<<"Enter value of x1: ";
    cin>>x1;
    cout<<"Enter value of y1: ";
    cin>>y1;
    cout<<"Enter value of x2: ";
    cin>>x2;
    cout<<"Enter value of y2: ";
    cin>>y2;
    cout<<"Enter order of curve: ";
    cin>>order;
    koch(x1,y1,x2,y2,order);
    delay(10000);
    return 0;
}
// END OF CODE
