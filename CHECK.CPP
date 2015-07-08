#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void check()
{
 void go();
 void blast();
 void entry();
 int gmode,gdrive=DETECT;
 detectgraph(&gdrive,&gmode) ;
 initgraph(&gdrive,&gmode,"..//bgi");
 go();
 blast();
 entry();
 getch();
 closegraph();
}


void go()
{
	   void blast();
	int k=130,l=268,m=10;
	///// pump
	rectangle(30,200,40,275);
	ellipse(78,270,180,0,30,10);
	ellipse(78,268,180,0,30,10);
	rectangle(20,274,50,275);
	rectangle(30,200,40,275);
	rectangle(40,270,48,272);

	bar(18,180,52,183);

	bar(32,183,38,275);
	fillellipse(120,268,10,2);
	setcolor(YELLOW);


	settextstyle(7,0,2);
	outtextxy(120,240,"PRESS ANY KEY !!!");
	getch();
	setcolor(BLACK);
	outtextxy(120,240,"PRESS ANY KEY !!!");

	settextstyle(7,0,5);
	setcolor(YELLOW);
	outtextxy(200,10,"LOADING !!!");
	for( k=130,l=268,m=10;k<300,l>160,m<120;k+=5,m+=4,l-=2)
	{
	for(int i=0;i<=50;i++)
	{

		setcolor(BLACK);
		setfillstyle(1,WHITE);
		bar(18,180-i,52,183-i);
		bar(32,183-i,38,275);
		delay(5);
		if(i!=50)
		{

			setfillstyle(1,0);
			bar(18,180-i,52,183-i);
		}

	}
	for( i=0;i<=50;i++)
	{

		setcolor(BLACK);
		setfillstyle(1,WHITE);
		bar(18,130+i,52,133+i);
		bar(32,133+i,38,225);
		delay(1);
		if(i!=50)
		{

			setfillstyle(1,0);
			bar(18,130+i,52,133+i);

		}
	}
	setcolor(WHITE);
	fillellipse(k,l,m,m);
	}
	blast();
}
void blast()
{
	 setcolor(RED);
	 setfillstyle(1,RED);
	 sector(240,220,20,100,70,90);
	 sector(200,120,300,350,80,80);
	 sector(250,90,280,320,80,70);
	 sector(330,110,200,270,80,60);
	 sector(370,170,150,190,80,50);
	 sector(330,220,100,160,80,60);
	 //delay(100);
	  setcolor(YELLOW);
	 setfillstyle(1,YELLOW);

	 sector(240,320,20,100,70,90);
	 sector(200,220,300,350,80,80);
	 sector(250,190,280,320,80,70);
	 sector(330,210,200,270,80,60);
	 sector(370,270,150,190,80,50);
	 sector(330,320,100,160,80,60);
	  setcolor(1);
	 setfillstyle(1,1);

	 sector(170,320,20,100,70,90);
	 sector(130,220,300,350,80,80);
	 sector(180,190,280,320,80,70);
	 sector(260,210,200,270,80,60);
	 sector(300,270,150,190,80,50);
	 sector(260,320,100,160,80,60);
	 delay(10);


	 setcolor(0);
	 setfillstyle(1,0);
	 sector(240,220,20,100,70,90);
	 sector(200,120,300,350,80,80);
	 sector(250,90,280,320,80,70);
	 sector(330,110,200,270,80,60);
	 sector(370,170,150,190,80,50);
	 sector(330,220,100,160,80,60);
	 sector(240,320,20,100,70,90);
	 sector(200,220,300,350,80,80);
	 sector(250,190,280,320,80,70);
	 sector(330,210,200,270,80,60);
	 sector(370,270,150,190,80,50);
	 sector(330,320,100,160,80,60);
	 sector(170,320,20,100,70,90);
	 sector(130,220,300,350,80,80);
	 sector(180,190,280,320,80,70);
	 sector(260,210,200,270,80,60);
	 sector(300,270,150,190,80,50);
	 sector(260,320,100,160,80,60);
	 delay(100);

	setcolor(0);
	setfillstyle(1,0);
	bar(0,0,500,500);
}

void entry()
{
 setcolor(RED);
 settextstyle(7,HORIZ_DIR,6);
 outtextxy(100,50,"We Present to you...");
 delay(1000);
 outtextxy(100,340,"ANDE KA FUNDA");
 //delay(2000);
 setcolor(WHITE);
 setfillstyle(1,WHITE);
  fillellipse(getmaxx()/2,getmaxy()/2,50,70);
  setcolor(BLACK);
  setlinestyle(SOLID_LINE,1,3);
  delay(1000);
  line(270,210,getmaxx()/2,getmaxy()/2);
  delay(1000);
  //line(300,250,330,230);
  //delay(1000);
  line(getmaxx()/2,getmaxy()/2,370,210);
  delay(1000);
  int y=getmaxy()/2;
	while(y+50>0)
	{
		int x1,y1,x=getmaxx()/2;
		y1=y;
		y-=100;
		delay(100);
		setcolor(BLACK);
		setfillstyle(1,BLACK);
		sector(x,y1,160,20,50,70);
		setcolor(WHITE);
		setfillstyle(1,WHITE);
		sector(x,y,150,30,30,50);
	}
	delay(1000);
	cleardevice();
	 settextstyle(1,HORIZ_DIR,2);
	 setcolor(YELLOW);
	 outtextxy(250,180,"By TEAM 1983PSG");
	 setcolor(RED);
 outtextxy(250,200,"2103 - AKASH MAHAPATRA");
 outtextxy(250,220,"2108 - VIJAY BANG");
 outtextxy(250,240,"2118 - PRASHIK GADGE");
 outtextxy(250,260,"2119 - GAURAV MISHRA");
 }

