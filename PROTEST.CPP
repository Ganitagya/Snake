
//ANDE KA FUNDA

#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<fstream.h>
#include"maze.cpp"
#include"open.cpp"
#include"check.cpp"
class khiladi
	{
		char naam[20];
		int ank;
		int rollno;
		friend class saamp;

		public:
			khiladi()
				{
					strcpy(naam,"Akash");
					ank=0;
				}


		  //	void scorestore();
		  //	void atapata();
	}k,a;


class sharir
	{
		int x,y;
		sharir *nxt,*prv;

		friend class saamp;
	};


class saamp
	 {
		sharir *head,*tail;
		sharir X,*temp;

		public:
			saamp()
				{
					 head=tail=NULL;
				}


		//Function List:

	void Draw();
	void shooroo();
	void AddNode(int,int);
	void maardo();
	void saamppaida();
	void andalao();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void Update();
	int khao();
	void atapata();
	int takkar();
	void GameOver();
	void maze();
	void dikhao();
	void infile();
};
void saamp::atapata()
{
	char ch;
		cout<<"\nEnter your name - ";
		cin>>k.naam;
		cout<<"\nEnter Roll NO - ";
		cin>>k.rollno;
		//cin>>k.ank;
		//infile();
}
void saamp::infile()
{
	fstream out;
	khiladi q;
	out.open("player.txt",ios::in);
	//strcpy(a.naam,k.naam);
	//a.ank=k.ank;
	out.read((char*)&q,sizeof(q));
	out.close();
	if(k.ank>q.ank)
	{
		out.open("player.txt",ios::out);
		out.write((char*)&k,sizeof(k));
		out.close();
	}
	out.open("player1.txt",ios::app|ios::binary);
	out.write((char*)&k,sizeof(k));
	out.close();
}



int aclr=5,sclr=5,der=30,andax=-1,anday=-1,l=1;

char sbody[]={'o','\0'};

char Arr[]={"000"};

int main()
	{
		saamp s;
		//check();
		open();
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"c:\\TC\\BGI");
		cleardevice();
		s.Draw();
		return 0;
	}



/*
void khiladi::atapata()
	{
		cleardevice();
		setcolor(RED);
		settextstyle(1,HORIZ_DIR,2);
		outtextxy(100,300,"Enter Name:");
		gettextxy(int left, int top, int right, int bottom, void*destin);


/*
void pause()
{
 int y;
 rectangle(100,100,500,350);
 setcolor(WHITE);
 settextstyle(1,HORIZ_DIR,4);
 outtextxy(140,150,"RESUME");
 outtextxy(140,200,"RESTART");
 outtextxy(140,250,"QUIT");
 settextstyle(1,HORIZ_DIR,2);

 outtextxy(110,155,">>");
 outtextxy(110,205,">>");
 outtextxy(110,255,">>");
 for(;;)
 {
  setcolor(WHITE);
  outtextxy(110,y,">>");
 // setcolor(BLACK);
// outtextxy(110,205,">>");
// outtextxy(110,255,">>");
  while(kbhit())
	{
	 char ch=getch();
	 if(ch==13)
	  {
	   if(y==155) exit(0); //resume;
	   if(y==205) exit(0);//shooroo();
	   if(y==255) exit(0);//maardo();
	  }
	 else
	  {
	   if(ch==80)
	   {
		if(y==155) y=205;
		if(y==205) y=255;
		if(y==255) y=155;
	   }
	   else
		{
		 if(ch==72)
		 {
		  if(y==155) y=255;
		  if(y==255) y=205;
		  if(y==205) y=155;
		 }
		}
	  }
	}


						 getch();  }

 }
*/


void saamp::maze()
	{
		rectangle(20,58,(getmaxx()-25),(getmaxy()-17));
		setcolor(WHITE);
		outtextxy(100,10,"SCORE: ");
		k.ank-=10;
		lev(l);


	}


void saamp::Draw()
	{
//		cleardevice();
//		getch();
	atapata();

		shooroo();
	}


void saamp::shooroo()
	{
		 //	k.atapata();
		/*if(strcmp(k.naam,"")==0) */
		//strcpy(k.naam,"vb");
		  //	k.scorestore();

		cleardevice();
		maze();
		saamppaida();
		andalao();

		MoveLeft();
	}



void saamp::saamppaida()
	{
		head=&X;
		tail=&X;
		X.x=450;
		X.y=400;
		for(int i=0;i<=10;i++)
			AddNode(450+i,400);
	}


void saamp::AddNode(int a,int b)
	{
		temp=new sharir;
		temp->x=a;
		temp->y=b;
		temp->prv=tail;
		tail->nxt=temp;
		tail=temp;
		tail->nxt=NULL;
	}


void saamp::andalao()
	{
	int xmax,ymax;
		xmax=getmaxx();
		ymax=getmaxy();

		if(k.ank==0)
			{
				setcolor(WHITE);
				outtextxy(150,10,Arr);
			}
		setcolor(0);
		outtextxy(150,10,Arr);
		circle(andax,anday,2);
		setfillstyle(SOLID_FILL,0);
		floodfill(andax,anday,0);
		setcolor(2);

		k.ank+=10;
		if(k.ank==100*l)
		{
			l++;
			der=der-5;
			shooroo();
		}
		randomize();
		aclr=rand()%15;
		while(aclr==0)
			{                               //not black
				randomize();
				aclr=rand()%15;
			}

		wapas:
		andax=rand()%(getmaxx());
		anday=rand()%(getmaxy());
		if(andax<30 || andax>(getmaxx()-30)) andax=getmaxx()/2;     //between vertical border
		if(anday<66 || anday>(getmaxy()-30)) anday=getmaxy()/2;     //between horizontal border
		if(l==2)
			if(andax>=xmax/2-152&&anday>=ymax/2-35&&andax<=xmax/2+152&&anday<=ymax/2+30)
		   goto wapas;
		if(l==3)
		{
			if(andax>=195&&anday>=97&&andax<=405&&anday<=153)
			{
				goto wapas;
			}
			if(andax>=345&&anday>=197&&andax<=405&&anday<=403)
			{
				goto wapas;
			}
			if(andax>=195&&anday>=97&&andax<=255&&anday<=303)
			{
				goto wapas;
			}
			if(andax>=195&&anday>=347&&andax<=405&&anday<=403)
			{
				goto wapas;
			}

		}

		setcolor(aclr);
		circle(andax,anday,2);
		setfillstyle(SOLID_FILL,aclr);
		floodfill(andax,anday,aclr);
		dikhao();
		setcolor(WHITE);
		outtextxy(150,10,Arr);
}


void saamp::MoveLeft()
	{
		for(;;)
			{

				if(head->x<=21){GameOver();}          //left border
				head->x = head->x -5;
				Update();
				setcolor(sclr);
				outtextxy(head->x,head->y,sbody);

				setcolor(0);
				outtextxy(tail->x,tail->y,sbody);

				if(takkar()){GameOver();}

				if (khao())
					andalao();
				delay(der);
				if (kbhit())
					{
						char ch=getch();
						if(ch==0)  ch=getch();
						if(ch==32)
							{
								while(ch==32)
									{
										if (kbhit())
											ch=getch();
									}
							}
						if(ch==72) MoveUp();
							if(ch==80) MoveDown();
					}
			}
	}

void saamp::MoveRight()
	{
		for(;;)
			{
				if(head->x>=615){GameOver();}              //right border
				head->x=head->x+5;
				Update();
				setcolor(sclr);
				outtextxy(head->x,head->y,sbody);
				delay(der);
				setcolor(0);
				outtextxy(tail->x,tail->y,sbody);
				if(takkar())
					GameOver();
				if (khao())
					andalao();
				while (kbhit())
					{
						char ch=getch();
						if(ch==0)  ch=getch();
						if(ch==32)
							{
								while(ch==32)
									{
										if (kbhit())  ch=getch();
									}
							}
						if(ch==72) MoveUp();
						if(ch==80) MoveDown();
					}
			}
	}


void saamp::MoveUp()
	{
		for(;;)
			{
				if(head->y<=60) GameOver();
				head->y = head->y -5;
				Update();
				setcolor(sclr);
				outtextxy(head->x,head->y,sbody);
				delay(der);
				setcolor(0);
				outtextxy(tail->x,tail->y,sbody);
				if (khao()) andalao();
				if(takkar()) GameOver();
				if (kbhit())
					{
						char ch=getch();
						if(ch==0) ch=getch();
						if(ch==32)
							{
								while(ch==32)
									{
										if (kbhit()) ch=getch();
									}
							}
						if(ch==75) MoveLeft();
						if(ch==77) MoveRight();
					}
			}
	}


void saamp::MoveDown()
	{
		for(;;)
			{
				if(head->y>=452) GameOver();
				head->y = head->y +5;
				Update();
				setcolor(sclr);
				outtextxy(head->x,head->y,sbody);
				delay(der);
				setcolor(0);
				outtextxy(tail->x,tail->y,sbody);
				if (khao()) andalao();
				if(takkar()) GameOver();
				if (kbhit())
					{
						char ch=getch();
						if(ch==0) ch=getch();
						if(ch==32)
							{
								while(ch==32)
									{
										if (kbhit())
										ch=getch();
									}
							}
						if(ch==75) MoveLeft();
						if(ch==77) MoveRight();
					}
			}
	}


void saamp::Update()
	{
		sharir *s=tail;
		for(;;)
			{
				s->x=s->prv->x;
				s->y=s->prv->y;
				s=s->prv;
				if(s==head) break;
			}
		setcolor(0);
		outtextxy(tail->x,tail->y,sbody);
	}


int saamp::khao()
	{
		if ((head->x>=andax-6 && head->x<=andax+6) && (head->y>=anday-6 && head->y<=anday+6))
			{
				sclr=aclr;
				AddNode(tail->x,tail->y);
				AddNode(tail->x,tail->y);
				AddNode(tail->x,tail->y);
				AddNode(tail->x,tail->y);
				AddNode(tail->x,tail->y);

				return 1;
			}
		else
			return 0;
	}

void saamp::dikhao()
	{
		long z=k.ank;
		int num=0;
		long x=k.ank;
		z=x;
		if(k.ank==0)
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
	}


int saamp::takkar()
	{
		int flag=0,xmax,ymax;
		xmax=getmaxx();
		ymax=getmaxy();
		sharir *temp=head->nxt->nxt;
		while(temp->nxt!=NULL)
			{
				if (temp->y==head->y)
					{
						if (temp->x==head->x)
							{
								flag=1;
								break;
							}
					}
				temp=temp->nxt;
			}
		if(((head->x<25 || head->x>=getmaxx()-35) || (head->y<=60 || head->y>=460)) || flag==1)
			return 1;
		if(l==2)
		{
			if(head->x>=xmax/2-152&&head->y>=ymax/2-31&&head->x<=xmax/2+152&&head->y<=ymax/2+26)
			{
				return 1;
			}
		}
		if(l==3)
		{
			if(head->x>=195&&head->y>=97&&head->x<=405&&head->y<=153)
			{
				return 1;
			}
			if(head->x>=345&&head->y>=197&&head->x<=405&&head->y<=403)
			{
				return 1;
			}
			if(head->x>=195&&head->y>=97&&head->x<=255&&head->y<=303)
			{
				return 1;
			}
			if(head->x>=195&&head->y>=347&&head->x<=405&&head->y<=403)
			{
				return 1;
			}

		}

		return 0;
	}

void saamp::GameOver()
	{
		maardo();
		infile();
		cleardevice();
		exit(0);
	}


void saamp::maardo()
	{
		sharir *tmp=head;
		int SIZE=0,CLR=0;
		while(SIZE<15)
			{
				setcolor(CLR);
				settextstyle(1,HORIZ_DIR,SIZE);
				outtextxy(tmp->x,tmp->y,"OUCH");
				SIZE++;
				CLR++;
				delay(90);
			}
	}

	/*

void scorestore()
	{
		  //	khiladi Z;
		ifstream pehela;
		ofstream naya;

		naya.open("temp.dat",ios::binary);
		naya.close();

		naya.open("temp.dat",ios::binary|ios::app);

		pehela.open("Scores.dat",ios::binary);

		pehela.seekg(0,ios::end);              //goto EOF

		long eofp=pehela.tellg() - sizeof(khiladi);

		pehela.seekg(0);

		while(pehela.tellg()<=eofp)
			{
				pehela.read((char *)&a , sizeof(khiladi));
				if(strcmp(k.naam,a.naam)==0) pehela.read((char *)&a , sizeof(khiladi));
				else
					naya.write((char *)&a,sizeof(khiladi));
			}
		pehela.close();
		naya.close();
		remove("Scores.dat");
		rename("temp.dat" , "Scores.dat");
	}
	  */