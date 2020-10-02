#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void breline(int,int,int,int);
int main()
{
	int gd=DETECT,gm;
	int x1,y1,xn,yn;
	initgraph(&gd,&gm,"");
	printf("enter the starting co-ordinates:");
	scanf("%d%d",&x1,&y1);
	printf("enter the end co-ordinates:");
	scanf("%d%d",&xn,&yn);
	breline(x1,y1,xn,yn);
	return 0;
	closegraph();
}

void breline(int x1,int y1,int xn,int yn)
{
	int dx,dy,ds,dt,di;
	dx=xn-x1;
	dy=yn-y1;
	di=2*dy-dx;
	ds=2*dy;
	dt=2*(dy-dx);
	putpixel(x1,y1,RED);
	while(x1<xn)
	{
		x1++;
		if(di<0)
		{
			di=di+ds;
		}
		else
		{
			y1++;
			di=di+dt;
		}
		putpixel(x1,y1,RED);
		delay(5);
	}
}
