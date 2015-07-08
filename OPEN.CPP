#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<fstream.h>


void highdikhao();


class khiladi1
	{
	public:
		char naam[20];
		long ank;


			khiladi1()
				{
					strcpy(naam,"Akash");
					ank=0;
				}


		  //	void scorestore();
		  //	void atapata();
	}k1;

  void open()
  {
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"c:\\tc\\BGI");
   int y=155,flag=0;
  rectangle(100,100,500,350);
 setcolor(WHITE);
 settextstyle(1,HORIZ_DIR,4);
 outtextxy(140,150,"CHALIYE KHELEN");
 outtextxy(140,200,"SARVADHIK");
 outtextxy(140,250,"AA AB LAUT CHALEN");
 settextstyle(1,HORIZ_DIR,2);
 outtextxy(110,155,">>");

 delay(1000);
// outtextxy(110,205,">>");
// outtextxy(110,255,">>");
 while(flag==0)
	{
		while(kbhit())
			{
				label:
				setcolor(BLACK);
				outtextxy(110,155,">>");
				outtextxy(110,205,">>");
				outtextxy(110,255,">>");

				setcolor(WHITE);
				outtextxy(110,y,">>");
				char ch=getch();

				 // setcolor(BLACK);
				// outtextxy(110,205,">>");
					// outtextxy(110,255,">>");
				if(ch==13)
					  {
						   if(y==155) flag=1;
						   /*
							{
								cleardevice();
								k.ank-=10;
								main();
								  //	goto wahinse;
							} //resume;   */
						   if(y==205)
						   {
								fstream fp;
								fp.open("player.txt",ios::in);
								fp.read((char*)&k1,sizeof(k1));
								highdikhao();
							   //	settextstyle(1,HORIZ_DIR,4);
							   //	gotoxy(20,15);
							   //	cout<<k1.naam<<"\n"<<k1.ank;
								fp.close();

						   }

								//Draw();//shooroo();
						   if(y==255)exit(0);//GameOver();//maardo();
					  }
					  setcolor(0);
		  //						settextstyle(1,HORIZ_DIR,4);
		  //	outtextxy(200,300,Arr);

				if(ch==0)
					  {
						   ch=getch();
					  }
						  //	if(ch==72)CycleUp();
				if(ch==72)
						 {
							if(y==155) {y=255;goto label;}
							if(y==255) {y=205;goto label;}
							if(y==205) {y=155;goto label;}
						 }
						   //	if(ch==80)CycleDown();
				if(ch==80)
					{
						if(y==155) {y=205;goto label;}
						if(y==205) {y=255;goto label;}
						if(y==255) {y=155;goto label;}
						}
			}
  }

// wahinse:
closegraph();

 }



void highdikhao()
	{
		long z=k1.ank;
		char Arr[20];
		int num=0;
		long x=k1.ank;
		z=x;
		if(k1.ank==0)
			{
				strcpy(Arr,"000");
				return;
			}
		while(z!=0)
			{
				z=z/10;
				num++;
			}
		int i=0;
		if(x<100 && x>0)
			{
				i=-1;
				Arr[0]='0';
			}
		Arr[num-i]='\0';
		z=x;
		while(z!=0)
			{
				i++;
				switch(z%10)
					{
						case 0: Arr[num-i]=char(48);break;
						case 1: Arr[num-i]=char(49);break;
						case 2: Arr[num-i]=char(50);break;
						case 3: Arr[num-i]=char(51);break;
						case 4: Arr[num-i]=char(52);break;
						case 5: Arr[num-i]=char(53);break;
						case 6: Arr[num-i]=char(54);break;
						case 7: Arr[num-i]=char(55);break;
						case 8: Arr[num-i]=char(56);break;
						case 9: Arr[num-i]=char(57);break;
					}
				z=z/10;
			}
			setcolor(WHITE);
			settextstyle(1,HORIZ_DIR,4);
			outtextxy(200,25,"SARVADHIK-ANK");
			setcolor(BLACK);
			settextstyle(1,HORIZ_DIR,4);
			outtextxy(140,150,"CHALIYE KHELEN");
			outtextxy(140,200,"SARVADHIK");
			outtextxy(140,250,"AA AB LAUT CHALEN");
			settextstyle(1,HORIZ_DIR,2);
			outtextxy(110,205,">>");
			setcolor(WHITE);
			settextstyle(1,HORIZ_DIR,4);
			outtextxy(180,120,k1.naam);
			outtextxy(200,150,Arr);
			settextstyle(1,HORIZ_DIR,4);
			settextstyle(1,HORIZ_DIR,2);
			outtextxy(150,250,"KRIPYA TANIK PRATIKSHA KAREN!!!");
			delay(5000);
			setcolor(BLACK);
			settextstyle(1,HORIZ_DIR,4);
			outtextxy(180,120,k1.naam);
			outtextxy(200,150,Arr);
			settextstyle(1,HORIZ_DIR,2);

			outtextxy(150,250,"KRIPYA TANIK PRATIKSHA KAREN!!!");
			outtextxy(110,155,">>");
			settextstyle(1,HORIZ_DIR,4);
			outtextxy(200,25,"SARVADHIK-ANK");

			setcolor(WHITE);
			settextstyle(1,HORIZ_DIR,4);
			outtextxy(140,150,"CHALIYE KHELEN");
			outtextxy(140,200,"SARVADHIK");
			outtextxy(140,250,"AA AB LAUT CHALEN");
			settextstyle(1,HORIZ_DIR,2);
			outtextxy(110,205,">>");



	}
