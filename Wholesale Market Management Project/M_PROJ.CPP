#include<graphics.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<iostream.h>
#include<process.h>
int y=0,member_in=0,item_no[20],n=0,tot_item=0,item_qty[20];char item_nm[20][20];
float price[20],total=0,discount;
void new_item();
class item;
class member;
void view_opted_item();
void del_item();
void modi_item();
void buy_it();
void bill(int no[20],char nm[][20],int qat[20],float[20],float total);
void admin_page_1();
void user_page_1();
void admin_enter();
void main_page()  ;
void shop_details_2();
void change_all();
void set_it();
void update(int ino,int qty);
void change_all()
{
	for(int i=0;i<n;i++)
	{
	  update(item_no[i],item_qty[i]);
	}
}

class member
{	char phn[20],nm[25],adr[80];
	int mno;
	public:
	member()
	{strcpy(nm,"N/A");
	 strcpy(phn,"N/A");
	 strcpy(adr,"N/A");
	 mno=0;
	}
	void modify()
	{ cleardevice();clrscr();
	  char phn1[20],nm1[25],adr1[80];
	  cout<<"Enter Phone Number (press '0'to retain):\n";gets(phn1);
	  if(strcmp(phn1,"0")!=0)
	   strcpy(phn,phn1);
	  cout<<"Enter Name (press '0' to retain):\n";gets(nm1);
	  if(strcmp(nm1,"0")!=0)
	   strcpy(nm,nm1);
	  cout<<"Enter Address (press '0' to retain):\n";gets(adr1);
	  if(strcmp(adr1,"0")!=0)
	   strcpy(adr,adr1);
	}
	void enter()
	{ clrscr(); cleardevice();
	  cout<<"Enter details....\n";
	  cout<<"Name : ";gets(nm);
	  cout<<"Phone Number : ";gets(phn);
	  cout<<"Address : ";gets(adr);
	  cout<<"m_no : ";cin>>mno;
	}
	void disp()
	{
		gotoxy(1,y);
		cout<<mno;
		gotoxy(10,y);
		cout<<nm;
		gotoxy(30,y);
		cout<<phn;
		gotoxy(43,y);
		cout<<adr;
		y++;
	}
	int getmno()
	{return mno;}
	char* getphn()
	{return phn;}
	char* getnm()
	{return nm;}
	~member()
	{	};

}m;
void new_member()
{       clrscr(); cleardevice();
	ofstream fout;
	fout.open("members.txt",ios::binary|ios::app);
	if(!fout)
		cout<<"Can't open the file..!";
     else{      char ch;
		do
	    {	clrscr();
		cleardevice();
		m.enter();
		fout.write((char*)&m,sizeof(m));
		cout<<"\nEnter more ? (y/n) : ";cin>>ch;
	    }while(ch=='y'||ch=='Y');
	 }
}
void display_member()
{
	clrscr();cleardevice();
	ifstream fin;
	fin.open("members.txt",ios::binary);
	if(!fin)
		cout<<"Error in opening file..!";
	else{   gotoxy(1,1);
		cout<<"M. no.";
		gotoxy(10,1);
		cout<<"Name";
		gotoxy(30,1);
		cout<<"Ph no";
		gotoxy(43,1);
		cout<<"Address";
		fin.seekg(0);
		while(fin.read((char*)&m,sizeof(m)))
		{
			m.disp();
		}
	    }
	    fin.close();
}
void remove_member()
{
	clrscr(); cleardevice();
	int flag=0,mno;
	ifstream fin("members.txt",ios::binary);
	ofstream fout("temp.txt",ios::binary,ios::app);
	cout<<"Enter the MEMBER NO to be deleted : ";cin>>mno;
	if(!fin||!fout)
		cout<<"ERROR OCCURED WHILE OPENING THE FILE !";
	else
	{
		while(fin.read((char*)&m,sizeof(m)))
		{
			if(m.getmno()==mno)
			{
				m.disp();
				flag=1;
				cout<<"You want to delete this member ? (Y/N) :";
				if(getch()=='y'||getch()=='Y')
				continue;
				else if(getch()=='n'||getch()=='N')
				fout.write((char*)&m,sizeof(m));
			}
			else
			fout.write((char*)&m,sizeof(m));
		}


		if(flag==0)
		cout<<"Member not fount..!";
	}
	fin.close();
	fout.close();
	remove("members.txt");
	rename("temp.txt","members.txt");
}
void modi_member()
{       clrscr();cleardevice();
	fstream finout;
	finout.open("members.txt",ios::binary|ios::in|ios::out);
	if(!finout)
		cout<<"Error Occured while opening 'item.txt' !";
	else
	{
		int mno,flag=0;long pos;char ch;
		cout<<"Enter member number that to be modified : ";cin>>mno;
		finout.seekg(0);
		while(finout.read((char*)&m,sizeof(m)))
	    {
		if(m.getmno()==mno)
		{       clrscr();cleardevice();pos=finout.tellp()-sizeof(m);
			gotoxy(1,1);
			cout<<"M. no.";
			gotoxy(10,1);
			cout<<"Name";
			gotoxy(30,1);
			cout<<"Ph no";
			gotoxy(43,1);
			cout<<"Address";
			y=3;
			m.disp();
			cout<<"\n\n\nModify this member..? (y/n) :";
			cin>>ch;cout<<"\n";
			if(ch=='y'||ch=='Y')
			{       clrscr();cleardevice();
				m.modify();
				finout.seekp(pos);
				finout.write((char*)&m,sizeof(m));
				flag=1;
				break;
			}
			else
			{
			cout<<"\n\nOK..We'll modify it later..!";
			break;
			}
		}
	    }
		if(flag==0)
		{ if(ch=='n'||ch=='N')
		    ;
		  else
		    cout<<"\n\nRecord not found";
		}
		else
			cout<<"\n\n\n!..Record modified..!";
	}
	finout.close();
	getch();
}
//######## MEMBER FUNCTIONS AND CLAS DONE
void bill(int no[20],char nm[][20],int qat[20],float[20],float total)
{       clrscr();cleardevice();

	gotoxy(1,1);
	cout<<"Item no.";
	gotoxy(20,1);
	cout<<"Item name";
	gotoxy(45,1);
	cout<<"Quantity";
	gotoxy(69,1);
	cout<<"Price";
	y=3;
	for(int i=0;i<n;i++)
	       {	gotoxy(1,y);
			cout<<no[i];
			gotoxy(20,y);
			cout<<nm[i];
			gotoxy(45,y);
			cout<<qat[i];
			gotoxy(69,y);
			cout<<price[i];
			y++;
	       }
	   gotoxy(5,y+3);
	   cout<<"Total Amount :"<<total;
	   for(i=0;i<n;i++)
	   {tot_item+=qat[i];}
	   if(tot_item>80 && member_in==1)
	   {
		discount=(9*total)/100;
	   }
	   else
	   discount=0;
	   gotoxy(40,y+3);
	   cout<<"Discount Available :"<<discount;
	   gotoxy(5,y+5);
	   cout<<"Final Amount :"<<total-discount;
	   getch();
	   change_all();
}
class item
{
	int i_no,qty;
	char i_nm[20],categ[20],brand[20];
	float price;
	public:
		item()
		{
			i_no=0;
			qty=0;
			strcpy(i_nm,"NULL");
			strcpy(categ,"NULL");
			strcpy(brand,"NULL");
			price=0;

		}

		void enter()
		{
			cout<<"Item number : ";cin>>i_no;
			cout<<"Brand : ";gets(brand);
			cout<<"Item name   : ";gets(i_nm);
			cout<<"Item's Category : ";gets(categ);
			cout<<"Item price : ";cin>>price;
			cout<<"Quantity of Item : ";cin>>qty;
			cout<<"Details are taken..!";
		}
		void display_2_user()
		{
			gotoxy(1,y);
			cout<<i_no;
			gotoxy(20,y);
			cout<<i_nm;
			gotoxy(45,y);
			cout<<price;
			y++;
		}
			void display_2_admin()
		{
			gotoxy(1,y);
			cout<<i_no;
			gotoxy(20,y);
			cout<<i_nm;
			gotoxy(45,y);
			cout<<brand;
			gotoxy(65,y);
			cout<<price;
			gotoxy(75,y);
			cout<<qty;
			y++;
		}
		int getitem()
		{	return i_no;	}
		void modify()
		{       int t_qty;float t_price;
			cout<<"Enter qty (press '0'to retain): ";cin>>t_qty;
			if(t_qty!=0)
				qty=t_qty;
			cout<<"Enter price (press '0' to retain): ";cin>>t_price;
			if(t_price!=0)
				price=t_price;
		}
		char* getnm()
		{
		return i_nm;
		}
		char* getcateg()
		{
		return categ;
		}
		int get_qty()
		{
		return qty;
		}
		void remove_qty(int a)
		{
			qty-=a;
		}
		float getprice()
		{
			return price;
		}
};
void update(int ino,int qty)
{
	item i;
	int flag=1;
	fstream finout;
	finout.open("items.txt",ios::binary|ios::in|ios::out);
	if(!finout)
	cout<<"\nSORRY FILE NOT FOUND";
	else
   {    finout.seekg(0);
	while(!finout.eof()&& flag==1)
	{ finout.read((char*)&i,sizeof(i));
	  if(i.getitem()==ino)
	  {
		i.remove_qty(qty);
		finout.seekp(finout.tellp()-sizeof(i));
		finout.write((char*)&i,sizeof(i));
		flag=0;
		break;
	   }
	}
   }
   finout.close();
}
void new_item()
{
	clrscr();cleardevice();
	item i;char ch;
	ofstream fout;
	fout.open("items.txt",ios::binary|ios::app);
	if(!fout)
		cout<<"Error Occured while opening 'my_members.txt' !";
	else
		{       do
			{       clrscr();
				cleardevice();
				i.enter();
				fout.write((char*)&i,sizeof(i));
				cout<<"\nEnter more ? (y/n) : ";cin>>ch;
			}while(ch=='y'||ch=='Y');
		}
		fout.close();
	admin_page_1();
}

void buy_it()
{
		item i;
		int ino,iqty;ifstream fin;
		fin.open("items.txt",ios::binary);
		cout<<"\n\nItem number : " ;
		cin>>ino;
		cout<<"\nEnter quantity : ";
		cin>>iqty;
		fin.seekg(0);
		while(fin.read((char*)&i,sizeof(i)))
		{
			if(ino==i.getitem())
			{
				if(iqty>i.get_qty())
				cout<<"Not enough quantity...SORRY !";
				else
				{	cout<<"Product Purchased..!";
					char ch;
					item_no[n]=i.getitem();
					strcpy(item_nm[n],i.getnm());
					item_qty[n]=iqty;
					price[n]=iqty*i.getprice();
					total+=price[n];
					i.remove_qty(iqty);
					n++;
					cout<<"Continue Shopping ?(y/n) : ";
					cin>>ch;
					if(ch=='y'||ch=='Y')
					 {  view_opted_item();
						buy_it();
					 }
					else
					      {	bill(item_no,item_nm,item_qty,price,total);
					      main_page();}
				}
			}
		}
}


void view_opted_item()
{
	item i;ifstream fin;clrscr();
	fin.open("items.txt",ios::binary);
	if(!fin)
		cout<<"\nCan't open-up file.!";
	else
	{
		clrscr();
		cleardevice();
		cout<<"Enter '1' to search by category and '2' for name :";
		int a;char type [20];
		cin>>a;
		if(a==1)
			cout<<"Enter Category : ";
		else if(a==2)
			cout<<"Enter Name : ";
		cin>>type;
		clrscr();
		cleardevice();
		y=4;
		fin.seekg(0);
		gotoxy(1,1);
		cout<<"Item no.";
		gotoxy(20,1);
		cout<<"Item name";
		gotoxy(45,1);
		cout<<"Price";
		while(fin.read((char*)&i,sizeof(i)))
		{       if(a==1 && strcmp(type,i.getcateg())==0)
			{
				i.display_2_user() ;
			}
			else if(a==2 && strcmp(type,i.getnm())==0)
			{
				i.display_2_user() ;
			}
		}
}
buy_it();
}

void del_item()
{
	clrscr(); cleardevice();
	item i;int flag=0,code;
	ifstream fin("items.txt",ios::binary);
	ofstream fout("temp.txt",ios::binary);
	cout<<"Enter the ITEM CODE to be deleted : ";cin>>code;
	clrscr(); cleardevice();
	if(!fin||!fout)
		cout<<"ERROR OCCURED WHILE OPENING THE FILE !";
	else
	{      gotoxy(1,1);
	cout<<"Item no.";
	gotoxy(20,1);
	cout<<"Item name";
	gotoxy(45,1);
	cout<<"Brand";
	gotoxy(65,1);
	cout<<"Price";
	gotoxy(75,1);
	cout<<"Qty";
	y=3;
		while(fin.read((char*)&i,sizeof(i)))
		{
			if(i.getitem()==code)
			{
				i.display_2_admin();
				flag=1;
				char ch;
				cout<<"\n\n\nYou want to delete this ITEM ? (Y/N) :";
				cin>>ch;
				if(ch=='y'||ch=='Y')
				continue;
				else if(ch=='n'||ch=='N')
				fout.write((char*)&i,sizeof(i));
			}
			else
			fout.write((char*)&i,sizeof(i));
		}


		if(flag==0)
		cout<<"Item not found..!";
	}
	fin.close();
	fout.close();
	remove("items.txt");
	rename("temp.txt","items.txt");
	admin_page_1();
}
void modi_item()
{       clrscr();cleardevice();
	item i;
	fstream finout;
	finout.open("items.txt",ios::binary|ios::in|ios::out);
	if(!finout)
		cout<<"Error Occured while opening 'item.txt' !";
	else
	{
		int ino,flag=0;long pos;char ch;
		cout<<"Enter Item number that to be modified : ";cin>>ino;
		finout.seekg(0);
		while(finout.read((char*)&i,sizeof(i)))
	    {
		if(i.getitem()==ino)
		{       clrscr();cleardevice();pos=finout.tellp()-sizeof(i);
			gotoxy(1,1);
			cout<<"Item no.";
			gotoxy(20,1);
			cout<<"Item name";
			gotoxy(45,1);
			cout<<"Brand";
			gotoxy(65,1);
			cout<<"Price";
			gotoxy(75,1);
			cout<<"qty";
		       y=3;i.display_2_admin();
			cout<<"\n\n\nModify this item..? (y/n) :";
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
				i.modify();
				finout.seekp(pos);
				finout.write((char*)&i,sizeof(i));
				flag=1;
				break;
			}
			else
			{
			cout<<"\n\nOK..We'll modify it later..!";
			break;
			}
		}
	    }
		if(flag==0)
		{ if(ch=='n'||ch=='N')
		    ;
		  else
		    cout<<"\n\nRecord not found";
		}
		else
			cout<<"\n\n\n!..Record modified..!";
	}
	finout.close();
	getch();
	admin_page_1();
}
void user_login()
{
	char nm[20],pn[20];
	set_it();int flag=0;
	setcolor(BLACK);
	rectangle(250,108,400,128);
	rectangle(250,172,400,192);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(251,110,BLACK);
	floodfill(251,174,BLACK);
	setcolor(RED);
	settextstyle(11,0,4);
	outtextxy(140,116,"Enter Name : ") ;
	outtextxy(170,178,"Ph. NO :     ");
	outtextxy(420,116,"<--") ;
	gotoxy(33,8);
	gets(nm);
	outtextxy(420,178,"<--") ;
	gotoxy(33,12);
	gets(pn);
	ifstream fin;
	fin.open("members.txt",ios::binary);
	if(!fin)
	   cout<<"Error In opening file";
	else
	  {
	    fin.seekg(0);
	    while(fin.read((char*)&m,sizeof(m)))
	    {
	      if((strcmp(pn,m.getphn())==0) && (strcmp(nm,m.getnm())==0))
	      {
	      flag=1;
	      setcolor(GREEN);
	      outtextxy(200,330,"..WELCOME..");
	      delay(2000);
	      break;
	      }
	    }
	  }
	  fin.close();
	  if(flag==1)
	    {view_opted_item();
	      member_in=1;
	     }
	  else{ setcolor(RED);
		outtextxy(200,330,"..Wrong Details...");
		delay(2000);
		user_page_1();
	      }
}

 void admin_enter()
 {      set_it();
	char u_nm[20],pass[20];
	settextstyle(1,0,2);
	setcolor(RED);
	outtextxy(260,40,"SIGN - IN") ;
	setcolor(BLACK);
	rectangle(220,158,370,178);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(230,170,BLACK);
	settextstyle(11,0,3);
	outtextxy(135,164,"USERNAME : ");
	outtextxy(135,212,"PASSWORD : ");
	rectangle(220,206,380,226);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(230,210,BLACK);
	setcolor(RED);
	outtextxy(380,164,"<---");
	gotoxy(30,11);
	gets(u_nm);
	outtextxy(400,212,"<---");
	gotoxy(30,14);
	int i=0;  char ch;
	while(1)
	{
		ch=getch();
		if(ch==13)
			{
				pass[i]='\0';
				break;
			}
		else if(ch==8)
			{
				if(i>0)
				{
					i--;
					cout<<"\b \b";
				}
			}
		else if(ch==9|| ch==32)
			continue;
		else
		{
			pass[i]=ch;
			i++;
			cout<<"*";
		}
	}
	if(strcmp(pass,"hardik007")==0 && strcmp(u_nm,"hardik_14")==0)
		{
			setcolor(GREEN);
			outtextxy(230,320,"Welcome Mr. Admin");
			delay(2500);
			admin_page_1();
		 }

	 else	{
			setcolor(RED);
			outtextxy(230,320,"Invalid Details");
			delay(2500);main_page();
		}

 }

 void set_it()
 {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	setcolor(GREEN);
	rectangle(80,40,530,350);
	rectangle(75,35,535,355);
	setfillstyle(SOLID_FILL,9);
	floodfill(0,0,GREEN);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(200,200,GREEN);
	setcolor(GREEN);
	settextstyle(11,0,0);
 }


void shop_details_1()
{
	set_it();
	outtextxy(90,70,"1. You can use the 'ADMIN PORTAL' only if you have");
	outtextxy(120,85,"user_name and password.")  ;
	outtextxy(90,105,"2. To enter shop you would be having three options :");
	setcolor(BLUE);
	outtextxy(120,130,"->  Enter As MEMBER")  ;
	setcolor(BLUE);
	outtextxy(120,150,"->  Be a MEMBER")  ;
	setcolor(BLUE);
	outtextxy(120,170,"->  Enter as GUEST")  ;
	setcolor(GREEN);
	outtextxy(90,215,"3.If you choose first method,only if you are  our member.");
	outtextxy(120,230,"Discount on purchase of products having final quantity ");
	outtextxy(120,245,"(sum of all qty) GREATER than 80 of 9% .");
	outtextxy(90,265,"4. By chosing second option you can create your account");
	outtextxy(120,280,"and enjoy your 9% discount that has been mentioned");
	outtextxy(120,295,"in above step.");
	setcolor(BLACK);
	outtextxy(90,420,"[  ]");
	setcolor(WHITE);
	outtextxy(90,420,"     TO GO TO NEXT PAGE.");
	setcolor(RED)               ;
	outtextxy(103,420,"n");
	setcolor(BLACK);
	outtextxy(350,420,"[    ]");
	setcolor(WHITE);
	outtextxy(350,420,"        TO GO TO HOME PAGE.");
	setcolor(RED)               ;
	outtextxy(358,420,"bksp");
	char ch=getch();
	if(ch=='n'||ch=='N')
		shop_details_2();
	else if(ch==8)
		main_page();
	else
		shop_details_1();
}



void shop_details_2()
{
	set_it();
	outtextxy(90,70,"5. By using third method, you can buy products");
	outtextxy(110,90,"without any discounts.");
	outtextxy(90,120,"6. You have to enter the category code first and then ");
	outtextxy(110,140,"the list of products of that category. Enter the ");
	outtextxy(110,160,"product code of required item and qty. Then chose");
	outtextxy(110,180,"'ADD TO BUCKET' or 'PAY NOW'.");
	setcolor(BLUE);
	outtextxy(110,180,"'ADD TO BUCKET'    'PAY NOW'.");
	setcolor(RED);
	outtextxy(90,300,"Thank you for your patience.")  ;
	setcolor(BLACK);
	outtextxy(90,420,"[  ]");
	setcolor(WHITE);
	outtextxy(90,420,"     TO GO TO HOME PAGE.");
	setcolor(RED)               ;
	outtextxy(103,420,"h");
	setcolor(BLACK);
	outtextxy(350,420,"[    ]");
	setcolor(WHITE);
	outtextxy(350,420,"        TO GO TO PREVIOUS PAGE.");
	setcolor(RED)               ;
	outtextxy(358,420,"bksp");
	char c=getch();
	if(c==8||c==8 )
		shop_details_1();
	else if(c=='h')
		main_page();
	else
		shop_details_2();

}


void main_page()
{
	cleardevice();
	setcolor(GREEN);
	rectangle(80,40,530,350);
	rectangle(75,35,535,355);
	setcolor(GREEN);
	rectangle(260,20,350,50);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(300,30,GREEN);
	floodfill(300,37,GREEN);
	floodfill(300,42,GREEN);
	setfillstyle(SOLID_FILL,9);
	floodfill(0,0,GREEN);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(200,200,GREEN);
	setcolor(BLACK);
	settextstyle(11,0,0);
	outtextxy(281,33,"WELCOME");
	setcolor(BLACK);
	outtextxy(210,100,"1. ADMIN PORTAL");
	setcolor(BLACK);
	outtextxy(210,130,"2. USER PORTAL");
	setcolor(BLACK);
	outtextxy(210,160,"3. ABOUT THE SHOP");
	outtextxy(210,190,"4. EXIT THE SHOP");
	setcolor(RED);
	outtextxy(290,340,"TIP:Read about the shop first.");
	setcolor(BLACK);
	outtextxy(170,228,"Enter Choice(1,2,3,4) : ");
	gotoxy(45,15); int c;
	cin>>c;
	if(c==3)
		shop_details_1();
	else if(c==1)
		admin_enter();
	else if(c==2)
		user_page_1();
	else if(c==4)
		exit(0);
	else
		main_page();
}
void beginning_graphics()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	settextstyle(1,0,4);

       for(int i=1;i<=(getmaxx()/2)-80;i++)
	{
		cleardevice();
		circle(getmaxx()/2,getmaxy()/2+20,-60+i);
		setcolor(CYAN);
		circle(getmaxx()/2,getmaxy()/2+20,-80+i);
		setcolor(RED);
		circle(getmaxx()/2,getmaxy()/2+20,-100+i);
		setcolor(RED);
		outtextxy(0+i,200,"WHOLESALE")   ;
		setcolor(CYAN);
		outtextxy(510-i,240,"MARKET")   ;
		setcolor(GREEN);
		outtextxy(225,520-i,"MANAGEMENT");
		delay(4);
	}
	settextstyle(0,0,1);
	setcolor(CYAN);
	delay(1000);
	outtextxy(238,5,"St. Anne's School");
	delay(1000);
	setcolor(YELLOW);
	outtextxy(458,25,"Submitted By : ");
	outtextxy(458,45,"Hardik Pachory");
	delay(1000);
	setcolor(YELLOW);
	outtextxy(3,25,"Under Guidance of :");
	outtextxy(3,45,"Mrs. Archana Agarwal");
	delay(2000);
	setcolor(GREEN);
	outtextxy(218,450,"<<PRESS ANY KEY TO CONTINUE>>");
	getch();
	cleardevice();
	main_page();
}
void user_page_1()
 {
	set_it();
	int i;
	settextstyle(1,0,2);
	setcolor(RED);
	outtextxy(260,50,"...User...");
	setcolor(GREEN);
	settextstyle(11,0,0);
	outtextxy( 140,130,"1. Enter As MEMBER");
	outtextxy( 140,160,"2. Be a MEMBER");
	outtextxy( 140,190,"3. Enter As GUEST");
	outtextxy( 140,220,"4. Exit");
	setcolor(BLACK);
	outtextxy( 167,261,"Enter choice(1,2,3,4) : ");
	gotoxy(45,17);cin>>i;
	switch(i)
	{
	case 1: clrscr();cleardevice();
		user_login();
		break;
	case 2: clrscr();cleardevice();
		new_member();
		break;
	case 3: cleardevice();clrscr();
		view_opted_item();
		break;
	}

	main_page();
 }
void admin_page_1()
 {
	set_it();
	int ch;
	settextstyle(1,0,2);
	setcolor(5);
	outtextxy(260,50,"...Admin...");
	setcolor(GREEN);
	settextstyle(11,0,0);
	outtextxy( 140,140,"1. Add an Item");
	outtextxy( 140,170,"2. Remove an Item");
	outtextxy( 140,200,"3. Modify an Item");
	outtextxy( 140,230,"4. Remove a Member");
	outtextxy( 140,260,"5. Change Details of a Member");
	outtextxy( 140,290,"6. GO BACK !");
	setcolor(BLACK);
	outtextxy( 170,325,"Enter choice (1,2,3,4,5,6) : ");
	gotoxy(49,21);
	cin>>ch;
	switch(ch)
	{
		case 1:new_item();
			break;
		case 2:del_item();
			break;
		case 3: modi_item();
			break;
		case 4:remove_member();
			break;
		case 5:modi_member();
			break;
		case 6: main_page();
			break;
	}
	//main_page();
 }





void main()
{       int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	 main_page();
}
