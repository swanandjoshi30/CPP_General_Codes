/*b) Write C++ program to draw the following pattern. Use DDA line and Bresenham's circle drawing algorithm. Apply the concept of encapsulation.*/

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void dda(int x1,int y1,int x2,int y2)
{
	float dx,dy,len,x,y;
	float xic,yic;
	 int i=1;
	
	x=x1;
	y=y1;
	putpixel(x,y,RED);
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
	{
	len=dx;
	}
	else
	{
	len=dy;
	}
	xic=(x2-x1)/len;
	yic=(y2-y1)/len;
	
	
	while(i<=len)
	{
		
		
		putpixel(x,y,RED);
		x=x+xic;
		y=y+yic;
		i++;
		//delay(2000);
	
	}
	
	//closegraph();

}

void bresc(int centx,int centy,int r)
{
	int p,x,y;
	x=0;
	y=r;
	p=3-(2*r);
	do
	{
		putpixel(centx+x,centy-y,1);
		putpixel(centx-x,centy-y,2);
		putpixel(centx-x,centy+y,3);
		putpixel(centx+x,centy+y,4);
		putpixel(centx+y,centy+x,5);
		putpixel(centx+y,centy-x,6);
		putpixel(centx-y,centy+x,7);
		putpixel(centx-y,centy-x,8);
		if(p<0)
		{
			p=p+(4*x)+6;
		}	
		else
		{
			p=p+(4*(x-y)+10);
			y=y-1;		
		}	
		x=x+1;
		
		

	}while(x<y);

	
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);	
	int x1=25,y1=25,x2,y2,x3=350,y3=350,x4,y4;
	int x5,y5,x6,y6,x7,y7,x8,y8;
	int x9,y9,x10,y10,x11,y11,x12,y12;
	int r,D,d;
	
	/*
	cout<<"enter x1";
	cin>>x1;	
	
	cout<<"enter y1";
	cin>>y1;
	cout<<"enter x3";
	cin>>x3;	
	
	cout<<"enter y3";
	cin>>y3;	
	*/

	x2=x3;
	y2=y1;
	x4=x1;
	y4=y3;
	
	
	x5=(x1+x2)/2;
	y5=y1;
	x6=x2;
	y6=(y2+y3)/2;
	x7=(x3+x4)/2;
	y7=y3;
	x8=x1;
	y8=(y1+y4)/2;
	
	x9=(x8+x5)/2;
	y9=(y8+y5)/2;
	x10=(x7+x6)/2;
	y10=(y7+y6)/2;

	x11 = x9;
	x12 = x10;
	y12 = y9;
	y11 = y10;
	D=x2-x1;
	d=y4-y1;
	
	r=(D*d)/(2*sqrt((D*D)+(d*d)));
	
	
	
	dda(x1,y1,x2,y2);
	dda(x2,y2,x3,y3);
	dda(x3,y3,x4,y4);
	dda(x4,y4,x1,y1);
	dda(x5,y5,x6,y6);
	dda(x6,y6,x7,y7);
	dda(x7,y7,x8,y8);
	dda(x8,y8,x5,y5);
	//dda(x12,y12,x10,y10);
	//dda(x10,y10,x11,y11);
	//dda(x11,y11,x9,y9);
	//dda(x12,y12,x9,y9);
	bresc(x5,y6,r);
	delay(1000000);
	closegraph();
}
//25 25 350 350