#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
class khiladi3 {
public:
   char name[20];
   int score;
   int rollno;
   khiladi3()
   {
	  strcpy(name,"*****");
	  rollno=0;
   }
   int getdata();
   void putdata();
};
class hashtable {
   int hash[15][3];
   public:
   void init();
   int insert(int,int);
   int search(int);
   void insertr(int);
   void display();
   void putdata(int);
};
int khiladi3::getdata()
{
  cout<<"\n Enter the name:";
  cin>>name;
  cout<<"\n Enter the rollno:";
  cin>>rollno;
  return rollno;
}
void khiladi3::putdata()
{
   cout<<"\n Name:"<<name;
   cout<<"\n rollno:"<<rollno;
   cout<<"\n score:"<<score;
}
void hashtable::putdata(int x)
{
	cout<<"Roll No - "<<hash[x][0];
	cout<<"Score - "<<hash[x][2];
}
void hashtable::init()
{
   int i,j;
   for(i=0;i<15;i++)
   {
	  hash[i][0]=0;
	  hash[i][1]=-1;
	  hash[i][2]=0;
   }
}

int hashtable::insert(int x,int score)
{
   int temp;
   int loc;
   loc=x%15;
   if(hash[loc][0]==0)
   {
	hash[loc][0]=x;
	hash[loc][2]=score;
   }
   else{
   while(hash[loc][1]!=-1){
   loc=hash[loc][1];
   }
   temp=loc;
   while(hash[loc][0]!=0){
   loc=(loc+1)%15;
   }
   hash[loc][0]=x;
   hash[temp][1]=loc;
   hash[loc][2]=score;
   }
   return loc;
}
void hashtable::display()
{
   int i,j;
   cout<<"\n"<<"   Value"<<"   Chain\n";
   for(i=0;i<15;i++)
   {
	  for(j=0;j<2;j++)
	  {
	  //if(hash[i][0]!=0)
	 cout<<"      "<<hash[i][j];
	  }
	  cout<<endl;
   }
}
int hashtable::search(int x)
{
   int loc;
   int cnt=1;
   loc=x%15;
   while(hash[loc][0]!=x && cnt<15)
   {
	  loc=hash[loc][1];
	  cnt++;
   }
   if(x==hash[loc][0]) {
   cout<<"\n Element found";
   cout<<"\n Number of comparisons:"<<cnt;
   return loc;
   }
   else {
   cout<<"\n Element not found";
   return -1;
   }
}
int main()
{
   int choice,data,i;
   char ans;
   khiladi3 e,p[15];
   hashtable h;
   int rollno,loc[20],loc1;
   fstream iofile;
   //clrscr();
   iofile.open("player1.txt",ios::in|ios::out,ios::binary);
   h.init();
   do {
   cout<<"\n 1.Insert\n 2.Search\n 3.Display";
   cin>>choice;
   switch(choice)
   {
	  case 1:
	  /*rollno=e.getdata();
	  loc1=h.insert(rollno);
	  iofile.seekg(loc1*sizeof(e),ios::beg);
	  iofile.write((char*)&e,sizeof(e)); */
	  break;

	  case 2:
	  cout<<"\n Enter the rollno number to be searched:";
	  cin>>rollno;
	  loc1=h.search(rollno);
	  iofile.clear();
	  if(loc1!=-1){
	  //iofile.seekg(2*loc1*sizeof(e),ios::beg);
	  //iofile.read((char*)&e,sizeof(e));
	  h.putdata(loc1);
	  }
	  /*if(loc1!=-1)
	  {
	  p[loc1].putdata
	  break;*/
	  break;
	  case 3:
	  iofile.seekg(0,ios::beg);
	  int i=0;
	  while(!iofile.eof()){
	  iofile.read((char*)&e,sizeof(e));
	  cout<<"\n";
	  if(!iofile.eof()&&i%1==0)
	  {
		e.putdata();
		loc1=h.insert(e.rollno,e.score);
		/*strcpy(p[n].name,e.name);
		p[n].rollno=e.rollno;
		n++;*/
	  }
	  i++;
	  }
	  getch();
	  h.display();
	  break;
	  default:
	  cout<<"\n Wrong choice:";
   }
   cout<<"\n Do you want to continue:";
   cin>>ans;
   }while(ans=='y' || ans=='Y');
   iofile.close();
   getch();
   return 0;
}
