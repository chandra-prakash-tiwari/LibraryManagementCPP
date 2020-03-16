#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include<stdlib.h>
#include<iomanip.h>
#include<dos.h>
#include<ctype.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<time.h>

void mainmenu();

void draw_line(int a)
{
	int i;
	textcolor(RED);
	textbackground(WHITE);
	for(i=0;i<a;i++)
	cprintf("%c",196);
	textcolor(WHITE);
	textbackground(BLACK);
}

void draw_rectangle(int a,int b,int c,int d)
{
	int i,j;
	textcolor(RED);
	textbackground(WHITE);
	for(i=a;i<c;i++){
		for(j=b;j<d;j++){
			if(i==a||i==c-1){
				gotoxy(j,i);
				if(j==b&&i==a)
				cprintf("%c",218);
				else if(i==a&&j==d-1)
				cprintf("%c",191);
				else if(i==c-1&&j==b)
				cprintf("%c",192);
				else if(i==c-1&&j==d-1)
				cprintf("%c",217);
				else
				cprintf("%c",196);
			}
			else{
				if(j==b||j==d-1){
				gotoxy(j,i);
				cprintf("%c",179);
				}
			}
		}
	}
	textcolor(WHITE);
	textbackground(BLACK);
}

class library
{
    public:
	char book_id[50];
	char book_name[50];
	char author[50];
	char edition[30];
	int num,a,b,i,c;

	void create_book(int c)
	{
		system("cls");
		draw_rectangle(3,15,22,65);
		gotoxy(20,4);
		cout<<"Enter The New Book Detail";
		gotoxy(16,5);
		draw_line(48);
		gotoxy(20,8);
		cout<<"Book ID       :";
		gotoxy(20,10);
		cout<<"Book Name     :";
		gotoxy(20,12);
		cout<<"Author's Name :";
		gotoxy(20,14);
		cout<<"Edition       :";
		gotoxy(20,16);
		cout<<"No.Of Copies  :";
		itoa(c,book_id,10);
		gotoxy(37,8);
		cout<<book_id;
		textcolor(RED+BLINK);
		textbackground(WHITE);

		l1:
			b=0;
			gotoxy(37,10);
			gets(book_name);
			a=strlen(book_name);
			for(i=0;i<a;i++){
				if((book_name[i]>='A'&&book_name[i]<='Z')||(book_name[i]>='a'&&book_name[i]<='z')||book_name[i]==32)
				b++;
			}
			if(a!=b||b==0){
				gotoxy(20,19);
				cprintf("Enter Correct Book Name");
				delay(1000);
				gotoxy(37,10);
				cout<<"                                   ";
				gotoxy(20,19);
				cout<<"                            " ;
				goto l1;
			}
		l2:
			b=0;
			gotoxy(37,12);
			gets(author);
			a=strlen(author);
			b=a;
			for(i=0;i<a;i++){
				if(isdigit(author[i]))
				b--;
			}
			if(a!=b||a==0){
				gotoxy(20,19);
				cprintf("Please Enter correct Author");
				delay(1000);
				gotoxy(37,12);
				cout<<"                                 ";
				gotoxy(20,19);
				cout<<"                              " ;
				goto l2;
			}
		gotoxy(37,14);
		cin>>edition;
		gotoxy(37,16);
		cin>>num;
		gotoxy(20,18);
		cprintf("New Entry Has Been Done");
		textcolor(WHITE);
		textbackground(BLACK);
	}

	void view_book()
	{
		gotoxy(37,8);
		cout<<setw(10)<<book_id;
		gotoxy(37,10);
		cout<<setw(20)<<book_name;
		gotoxy(37,12);
		cout<<setw(20)<<author;
		gotoxy(37,14);
		cout<<setw(10)<<edition;
		gotoxy(37,16);
		cout<<setw(10)<<num;
	}
	void modify_book()
	{
		l3:
			b=0;
			gotoxy(37,10);
			cin.ignore();
			gets(book_name);
			a=strlen(book_name);
			for(i=0;i<a;i++){
				if((book_name[i]>='A'&&book_name[i]<='Z')||(book_name[i]>='a'&&book_name[i]<='z')||book_name[i]==32)
				b++;
			}
			if(a!=b||b==0){
				gotoxy(20,19);
				cout<<"Enter Correct Book name";
				delay(1000);
				gotoxy(37,10);
				cout<<"                                             ";
				gotoxy(20,19);
				cout<<"                         " ;
			goto l3;
			}
		l4:
			b=0;
			gotoxy(37,12);
			gets(author);
			a=strlen(author);
			for(i=0;i<a;i++){
			    if((author[i]>='A'&&author[i]<='Z')||(author[i]>='a'&&author[i]<='z')||author[i]==32)
				b++;
			}
			if(a!=b||b==0){
				gotoxy(20,19);
				cout<<"Enter Correct Author Name ";
				delay(1000);
				gotoxy(37,12);
				cout<<"                                             ";
				gotoxy(20,19);
				cout<<"                           " ;
				goto l4;
			}
		gotoxy(37,14);
		cin>>edition;
		gotoxy(37,16);
		cin>>num;
	}

	char* getbookid()
	{
		return book_id;
	}

	char* getbooknm()
	{
		return book_name;
	}

	char* getauthor()
	{
		return author;
	}

	void issuedis()
	{
		gotoxy(33,14);
		cout<<book_name;
		gotoxy(33,16);
		cout<<author;
	}

	void report()
	{
		cout<<setw(7)<<book_id<<setw(26)<<book_name<<setw(26)<<author<<setw(12)<<edition<<setw(8)<<num<<endl ;
	}
};
int b,a,i;
class member
{
public:
	char member_id[20];
	char member_name[20];
	char member_add[40];
	char mob[15];
	char stbno[6];
	int token;


	void create_member(int c)
	{
		system("cls");
		itoa(c,member_id,10);
		draw_rectangle(3,15,22,65);
		gotoxy(20,4);
		cout<<"Enter The New Member Detail";
		gotoxy(16,5);
		draw_line(48);
		gotoxy(20,8);
		cout<<"Member ID     : "<<member_id;
		gotoxy(20,10);
		cout<<"Member Name   : ";
		//cin>>member_name;
		gotoxy(20,12);
		cout<<"Mobile Number : ";
		//cin>>mob;
		gotoxy(20,14);
		cout<<"Address       :";

		m1:
			b=0;
			gotoxy(36,10);
			cin.ignore();
			gets(member_name);
			a=strlen(member_name);
			for(i=0;i<a;i++){
				if((member_name[i]>='A'&&member_name[i]<='Z')||(member_name[i]>='a'&&member_name[i]<='z')||member_name[i]==32)
				b++;
			}
			if(a!=b||b==0){
				gotoxy(20,19);
				cout<<"Enter Correct Member Name";
				delay(1000);
				gotoxy(36,10);
				cout<<"                                   ";
				gotoxy(20,19);
				cout<<"                           " ;
				goto m1;
			}
		m2:
			b=0;
			gotoxy(36,12);
			gets(mob);
			if(strlen(mob)==10)
			{
				if(mob[0]=='6'||mob[0]=='7'||mob[0]=='8'||mob[0]=='9')
				b++;
				for(i=1;i<10;i++)
				{
					if(mob[i]=='0'||mob[i]=='1'||mob[i]=='2'||mob[i]=='3'||mob[i]=='4'||mob[i]=='5'||mob[i]=='6'||mob[i]=='7'||mob[i]=='8'||mob[i]=='9')
					b++;
				}
			}
			if(b!=10)
			{
				gotoxy(20,19);
				cout<<"Enter Correct Mobile Number";
				delay(1000);
				gotoxy(36,12);
				cout<<"           	            ";
				gotoxy(20,19);
				cout<<"                             ";
				goto m2;
			}
		gotoxy(36,14);
		gets(member_add);
		token=0;
		stbno[0]='/0';
		gotoxy(20,16);
		cout<<"Member Record Created Successfully...";
	}

    void show_member()
	{
		gotoxy(39,10);
		cout<<setw(25)<<member_name;
		gotoxy(39,12);
		cout<<setw(15)<<mob;
		gotoxy(39,14);
		cout<<setw(25)<<member_add;
		gotoxy(39,16);
		cout<<setw(10)<<token;
	}

	void modify_member()
	{
		m3:
			b=0;
			gotoxy(36,10);
			cin.ignore();
			gets(member_name);
			a=strlen(member_name);
			for(i=0;i<a;i++){
				if((member_name[i]>='A'&&member_name[i]<='Z')||(member_name[i]>='a'&&member_name[i]<='z')||member_name[i]==32)
				b++;
			}
			if(a!=b||b==0){
				gotoxy(20,19);
				cout<<"Enter Correct Member Name";
				delay(1000);
				gotoxy(36,10);
				cout<<"                                   ";
				gotoxy(20,19);
				cout<<"                           " ;
				goto m3;
			}
		m4:
			b=0;
			gotoxy(36,12);
			gets(mob);
			if(strlen(mob)==10)
			{
				if(mob[0]=='6'||mob[0]=='7'||mob[0]=='8'||mob[0]=='9')
				b++;
				for(i=1;i<10;i++)
				{
					if(mob[i]=='0'||mob[i]=='1'||mob[i]=='2'||mob[i]=='3'||mob[i]=='4'||mob[i]=='5'||mob[i]=='6'||mob[i]=='7'||mob[i]=='8'||mob[i]=='9')
					b++;
				}
			}
			if(b!=10)
			{
				gotoxy(20,19);
				cout<<"Enter Correct Mobile Number";
				delay(1000);
				gotoxy(36,12);
				cout<<"           	            ";
				gotoxy(20,19);
				cout<<"                             ";
				goto m4;
			}
		gotoxy(36,14);
		gets(member_add);
		gotoxy(20,16);
		cout<<"Member Record Update Successfully...";
	}

	void issue(char a[20]){
		strcpy(stbno,a);
		token=1;
	}

	char* get_member_id()
	{
		return member_id;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{
		token++;
	}

	void resettoken()
	{
		token--;
	}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{
		cout<<setw(7)<<member_id<<setw(20)<<member_name<<setw(15)<<mob<<setw(30)<<member_add<<setw(5)<<token<<endl;
	}

};

class bookiss
{
public:
	char book_id[10];
	char u_id[10];
	char book_name[30];
	char author[30];
	// int day;
	// int month;
	// int year;

	void issue(char *nm, char *bn,char *getbooknm, char *a)
	{
		// day=d;
		// month=m;
		// year=y;
		strcpy(book_id,bn);
		strcpy(u_id,nm);
		strcpy(book_name,getbooknm);
		strcpy(author,a);
	}
	void display(){
		cout<<setw(10)<<book_id<<setw(10)<<u_id<<setw(24)<<book_name<<setw(25)<<author<<endl;//<<day<<"/"<<month<<"/"<<year<<endl;
	}
	char* getbookid(){
		return book_id;
	}
	char* getuid(){
		return u_id;
	}
};

library bk;
fstream fp , fp1,fp2,fp3;
member mb;
bookiss iss;

void Display_Issue_Book(){

	system("cls");
	fp.open("issue.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		mainmenu();
	}
	d1:
	system("cls");
	//c=1;
	cout<<"\n\t\tBook LIST WITH MEMBER DETAIL AND DATE\n";
	cout<<"================================================================================";
	cout<<setw(10)<<"Book ID"<<setw(10)<<"Member ID"<<setw(24)<<"Book Name"<<setw(25)<<"Author"<<setw(10)<<"Date"<<endl;
	cout<<"================================================================================";
	while(fp.read((char*)&iss,sizeof(bookiss))){
		iss.display();
	}
	fp.close();
	getch();

}

void write_book()
{
	char answer;
	int c;
	fp.open("book.dat", ios::out|ios::app);
	fp1.open("book.dat",ios::in);
	c=1;
	while(fp1.read((char*)&bk,sizeof(library)))
	{
		c++;
	}
	bk.create_book(c);
	fp.write((char*)&bk,sizeof(library));
	gotoxy(20,20);
	textcolor(BLACK);
	textbackground(WHITE);
	cout<<"Do you want to add another book(";
	cprintf(" Y / N ");
	cout<<"):";
	a1:
	answer=getch();
	fp.close();
	fp1.close();
	if(answer=='Y'||answer=='y')
	write_book();
	else if(answer=='N'||answer=='n')
	mainmenu();
	else
	goto a1;
}

void display_allbook()
{
	int c;
	fp.open("book.dat" , ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		mainmenu();
	}
	d1:
	system("cls");
	c=1;
	cout<<"\n\t\tBook LIST\n";
	cout<<"================================================================================";
	cout<<setw(7)<<"Book ID"<<setw(26)<<"Book Name"<<setw(26)<<"Author"<<setw(12)<<"Edition"<<setw(8)<<"Copies"<<endl;
	cout<<"================================================================================";
	while(fp.read((char*)&bk,sizeof(library)))
	{
		bk.report();
		c++;
		if(c==20){
			getch();
			goto d1;

		}
	}
	fp.close();
	getch();
	mainmenu();
}

void modify_book()
{
	char n[20];
	int found=0;
	system("cls");
	draw_rectangle(3,15,22,65);
	gotoxy(20,4);
	cout<<"Modify the Book Detail";
	gotoxy(16,5);
	draw_line(48);
	gotoxy(20,8);
	cout<<"Book ID       : ";
	gotoxy(20,10);
	cout<<"Book Name     :";
	gotoxy(20,12);
	cout<<"Author's Name :";
	gotoxy(20,14);
	cout<<"Edition       :";
	gotoxy(20,16);
	cout<<"No.Of Copies  :";
	gotoxy(37,8);
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	textcolor(RED+BLINK);
	textbackground(WHITE);
	while(fp.read((char*)&bk,sizeof(library)) && found==0)
	{
		if(strcmpi(bk.getbookid(),n)==0)
		{
			bk.modify_book();
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(library));
			gotoxy(20,19);
			cprintf("       Record Updated Successfully...    ");
			found=1;
			break;
		}
	}
	fp.close();
	if(found==0)
	{
		gotoxy(20,19);
		cprintf("           Record Not Found...        ");
	}
	textcolor(WHITE);
	textbackground(BLACK);
	getch();
	system("cls");
	mainmenu();
}

void issue_book()
{
	system("cls");
	char mn[20],bn[20];
	int found=0,flag=0,d,m,y;
	time_t T=time(NULL);
	struct tm tm=*localtime(&T);
	d=tm.tm_mday;
	m=tm.tm_mon+1;
	y=tm.tm_year+1900;
	draw_rectangle(3,15,22,65);
	gotoxy(20,4);
	cout<<"Issue Book";
	gotoxy(16,5);
	draw_line(48);
	gotoxy(20,8);
	cout<<"Date      : "<<d<<"/"<<m<<"/"<<y;
	gotoxy(20,10);
	cout<<"Member Id : ";
	gotoxy(20,12);
	cout<<"Book Id   : ";
	gotoxy(20,14);
	cout<<"Book Name : ";
	gotoxy(20,16);
	cout<<"Author    : ";
	gotoxy(33,10);
	cin>>mn;
	fp1.open("member.dat",ios::in|ios::out);
	fp.open("book.dat",ios::in|ios::out);
	textcolor(RED+BLINK);
	textbackground(WHITE);
	while(fp1.read((char*)&mb,sizeof(member)) && found==0)
	{
		if(strcmpi(mb.get_member_id(),mn)==0)
		{
			found=1;
			if(mb.rettoken()<3)
			{
				gotoxy(33,12);
				cin>>bn;
				while(fp.read((char*)&bk,sizeof(library))&& flag==0)
				{
					if(strcmpi(bk.getbookid(),bn)==0&&bk.num>0)
					{
						bk.issuedis();
						fp2.open("issue.dat",ios::out|ios::app);
						flag=1;
						mb.addtoken();
						mb.getstbno(bk.getbookid());
						int pos=-1*sizeof(mb);
						fp1.seekp(pos,ios::cur);
						
						fp1.write((char*)&mb,sizeof(member));
						bk.num--;
						int p=-1*sizeof(bk);
						fp.seekp(p,ios::cur);
						fp.write((char*)&bk,sizeof(library));
						iss.issue(mn,bn,bk.getbooknm(),bk.getauthor());
						fp2.write((char*)&iss,sizeof(bookiss));
						gotoxy(20,19);
						cprintf("       Book issued successfully...       ");
						fp2.close();
					}
				}
				if(flag==0)
				{
					gotoxy(17,19);
					cprintf(" Book Id/Currently Not Available in library...");
				}
			}
			else
			{
				gotoxy(20,19);
				cprintf("    You have exceed your book limit...   ");
			}
		}
	}
	if(found==0)
	{
		gotoxy(20,19);
		cprintf("         Member record not exist...       ");
	}
	fp.close();
	fp1.close();
	getch();
	textcolor(WHITE);
	textbackground(BLACK);
	system("cls");
	mainmenu();
}

void book_return()
{
	system("cls");
	char mn[20],bn[10];
	int found=0, flag=0, day, fine,count=0,d,m,y;
	time_t T=time(NULL);
	struct tm tm=*localtime(&T);
	d=tm.tm_mday;
	m=tm.tm_mon+1;
	y=tm.tm_year+1900;
	draw_rectangle(3,15,22,65);
	gotoxy(20,4);
	cout<<"Book Returned";
	gotoxy(16,5);
	draw_line(48);
	gotoxy(20,8);
	cout<<"Date      : "<<d<<"/"<<m<<"/"<<y;
	gotoxy(20,10);
	cout<<"Member Id : ";
	gotoxy(20,12);
	cout<<"Book Id   : ";
	gotoxy(33,10);
	cin>>mn;
	gotoxy(33,12);
	cin>>bn;
	textcolor(RED+BLINK);
	textbackground(WHITE);
	fp2.open("issue.dat",ios::in);
	fp3.open("temp.dat",ios::out|ios::app);
	while(fp2.read((char*)&iss,sizeof(bookiss)))
	{
		if(strcmpi(iss.getbookid(),bn)==0&&strcmpi(iss.getuid(),mn)==0&&flag==0)
		{
			flag=1;
			fp.open("book.dat",ios::in|ios::out);
			fp1.open("member.dat",ios::in|ios::out);
			while(fp.read((char*)&bk,sizeof(library)))
			{
				if(strcmpi(bk.getbookid(),bn)==0)
				{
					bk.num++;
					int p=-1*sizeof(bk);
					fp.seekp(p,ios::cur);
					fp.write((char*)&bk,sizeof(library));
				}
			}
			while(fp1.read((char*)&mb,sizeof(member)))
			{
				if(strcmpi(mb.get_member_id(),mn)==0)
				{
					mb.resettoken();
					int pos=-1*sizeof(mb);
					fp1.seekp(pos,ios::cur);
					fp1.write((char*)&mb,sizeof(member));
				}
			}
			found=1;
		}
		else
		{
			fp3.write((char*)&iss,sizeof(bookiss));
		}
	}
	if(found==1)
	{
		gotoxy(20,16);
		cprintf("      Book Returned succefully   ");
		fp.close();
		fp1.close();
		fp2.close();
		fp3.close();
		remove("issue.dat");
		rename("temp.dat","issue.dat");
	}
	else
	{
		fp2.close();
		fp3.close();
		gotoxy(20,16);
		cprintf("     Member can't take This Book     ");
	}
	textcolor(WHITE);
	textbackground(BLACK);
	getch();
	system("cls");
	mainmenu();
}

void write_member()
{
	char answer;
	int c;
	fp1.open("member.dat",ios::out|ios::app);
	fp.open("member.dat",ios::in);
	c=1;
	while(fp.read((char*)&mb,sizeof(member))){
		c++;
	}
	mb.create_member(c);
	fp1.write((char*)&mb,sizeof(member));
	gotoxy(20,18);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	cout<<"Do you want to add another member(";
	cprintf(" Y / N ");
	cout<<") :";
	textcolor(WHITE);
	textbackground(BLACK);
	fp1.close();
	fp.close();
	add1:
	answer=getch();
	if(answer=='y'||answer=='Y')
	write_member();
	else if(answer=='n'||answer=='N')
	mainmenu();
	else
	goto add1;
}

void display_all_members()
{
	int a;
	fp1.open("member.dat",ios::in);
	if(!fp1)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		return;
	}
    d1:
	system("cls");
	a=1;
	cout<<"\t\tMEMBERS LIST\n";
	cout<<"===============================================================================\n";
	cout<<setw(7)<<"MEMBER ID"<<setw(19)<<"Name"<<setw(13)<<"Mobile no"<<setw(26)<<"MEMBER ADDRESS"<<setw(12)<<"Book Issued"<<endl;
	cout<<"===============================================================================\n";
	while(fp1.read((char*)&mb,sizeof(member)))
	{
		mb.report();
		a++;
		if(a==20){
			textcolor(BLACK+BLINK);
			textbackground(WHITE);
			cprintf("Please any key to continue....");
			getch();
			textcolor(WHITE);
			textbackground(BLACK);
			goto d1;
		}
	}
	fp1.close();
	getch();
	mainmenu();
}

void modify_member()
{
	char n[20];
	int found=0;
	system("cls");
	draw_rectangle(3,15,22,65);
	gotoxy(20,4);
	cout<<"Modify the Member Detail";
	gotoxy(16,5);
	draw_line(48);
	gotoxy(20,8);
	cout<<"Member ID     : ";
	gotoxy(20,10);
	cout<<"Member Name   :";
	gotoxy(20,12);
	cout<<"Mobile Number :";
	gotoxy(20,14);
	cout<<"Address       :";
	gotoxy(37,8);
	cin>>n;
	fp.open("member.dat",ios::in|ios::out);
	textcolor(RED+BLINK);
	textbackground(WHITE);
	while(fp.read((char*)&mb,sizeof(member)) && found==0)
	{
		if(strcmpi(mb.get_member_id(),n)==0)
		{
			mb.modify_member();
			int pos=-1*sizeof(mb);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&mb,sizeof(member));
			gotoxy(20,19);
			cprintf("       Record Updated Successfully...    ");
			found=1;
			break;
		}
	}
	fp.close();
	if(found==0)
	{
		gotoxy(20,19);
		cprintf("           Record Not Found...        ");
	}
	textcolor(WHITE);
	textbackground(BLACK);
	getch();
	system("cls");
	mainmenu();
}

void display_a_book_by_name()
{
	int found=0;
	char nm[20];
	system("cls");
	draw_rectangle(3,15,22,65);
	gotoxy(20,4);
	cout<<"Please Enter name of the book  ";
	gotoxy(16,5);
	draw_line(48);
	gotoxy(20,8);
	cout<<"Book ID       : ";
	gotoxy(20,10);
	cout<<"Book Name     : ";
	gotoxy(20,12);
	cout<<"Author's Name :";
	gotoxy(20,14);
	cout<<"Edition       :";
	gotoxy(20,16);
	cout<<"No.Of Copies  :";
	gotoxy(16,17);
	cout<<"(Present in library at present)";
	gotoxy(39,10);
	cin>>nm;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(library)))
	{
		if(strcmpi(bk.getbooknm(),nm)==0)
		{
			bk.view_book();
			found=1;
			getch();
		}
	}
	fp.close();
	if(found==0){
		system("cls");
		gotoxy(35,13);
		textcolor(RED+BLINK);
		textbackground(WHITE);
		cprintf(" Book Has not found ");
		textcolor(WHITE);
		textbackground(BLACK);
		getch();
	}
    system("cls");
    mainmenu();
}

void display_a_book_by_id()
{
	int found=0;
	char id[20];
	system("cls");
	draw_rectangle(3,15,22,65);
	gotoxy(20,4);
	cout<<"Please Enter The book ID  ";
	gotoxy(16,5);
	draw_line(48);
	gotoxy(20,8);
	cout<<"Book ID       : ";
	gotoxy(20,10);
	cout<<"Book Name     :";
	gotoxy(20,12);
	cout<<"Author's Name :";
	gotoxy(20,14);
	cout<<"Edition       :";
	gotoxy(20,16);
	cout<<"No.Of Copies  :";
	gotoxy(16,17);
	cout<<"(Present in library at present)" ;
	gotoxy(37,8);
	cin>>id;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(library)))
	{
		if(strcmpi(bk.getbookid(),id)==0)
		{
			bk.view_book();
			getch();
			found=1;
		}
	}
	fp.close();
	if(found==0){
		system("cls");
		gotoxy(35,13);
		textcolor(RED+BLINK);
		textbackground(WHITE);
		cprintf(" Book Has not found ");
		textcolor(WHITE);
		textbackground(BLACK);
		getch();
	}
	system("cls");
	mainmenu();
}

void display_a_member()
{
	int found=0;
	char nm[20];
	system("cls");
	draw_rectangle(3,15,22,65);
	gotoxy(20,4);
	cout<<"Please Enter Member ID  ";
	gotoxy(16,5);
	draw_line(48);
	gotoxy(20,8);
	cout<<"Member ID        : ";
	gotoxy(20,10);
	cout<<"Member Name      : ";
	gotoxy(20,12);
	cout<<"Mobile Number    :";
	gotoxy(20,14);
	cout<<"Address          :";
	gotoxy(20,16);
	cout<<"No of Book Issue :";
	gotoxy(39,8);
	cin>>nm;
	fp.open("member.dat",ios::in);
	while(fp.read((char*)&mb,sizeof(member)))
	{
		if(strcmpi(mb.get_member_id(),nm)==0)
		{
			mb.show_member();
			getch();
			found=1;
		}
	}
	fp.close();
	if(found==0){
		system("cls");
		gotoxy(35,13);
		textcolor(RED+BLINK);
		textbackground(WHITE);
		cprintf(" Member Has not found ");
		textcolor(WHITE);
		textbackground(BLACK);
		getch();
	}
    system("cls");
    mainmenu();
}

void menu1(){
	char option;
	system("cls");
	draw_rectangle(3,20,24,65);
	gotoxy(35,4);
	cout<<" OPTION:";
	gotoxy(21,6);
	draw_line(43);
	gotoxy(32,8);
	cout<<"1. Search Book ";
	gotoxy(32,10);
	cout<<"2. Add Books";
	gotoxy(32,12);
	cout<<"3. View BookList";
	gotoxy(32,14);
	cout<<"4. Issue Book";
	gotoxy(32,16);
	cout<<"5. Return Book";
	gotoxy(32,18);
	cout<<"6. Modify Book Details";
	gotoxy(32,20);
	cout<<"7. Display All Issued Book";
	option=getch();
	switch(option){
		case '1':
			m1:
			textcolor(BLACK+BLINK);
			textbackground(GREEN);
			gotoxy(50,8);
			cprintf("1. Book Id  ");
			delay(300);
			textbackground(RED);
			gotoxy(50,9);
			cprintf("2. Book Name");
			delay(300);
			textbackground(CYAN);
			gotoxy(50,10);
			cprintf("3. Main Menu");
			option=getch();
			textcolor(WHITE);
			textbackground(BLACK);
			switch(option){
				case '1':
					display_a_book_by_id();
					break;
				case '2':
					display_a_book_by_name();
					break;
				case '3':
					mainmenu();
					break;
				default:
					goto m1;
			}
			break;
		case '2':
			cout<<"\n\t\t\t Add Books:"<<endl;
			write_book();
			break;

		case '3':
			display_allbook();
			break;

		case '4':
			cout<<"\n\t\t\t Issue book:";
			issue_book();
			break;

		case '5':
			cout<<"\n\t\t\t Return book:";
			book_return();
			break;

		case '6':
			modify_book();
			break;

		case '7':
			Display_Issue_Book();
			break;
		default:
			menu1();
	}
	mainmenu();
}

void menu2(){
	char option;
	system("cls");
	draw_rectangle(3,20,22,65);
	gotoxy(40,4);
	cout<<"OPTION";
	gotoxy(21,5);
	draw_line(43);
	gotoxy(32,8);
	cout<<"1. Search Member";
	gotoxy(32,10);
	cout<<"2 .Register New Member";
	gotoxy(32,12);
	cout<<"3. View Member Details";
	gotoxy(32,14);
	cout<<"4. Modify Member Details";
	option=getch();
	system("cls");
	switch(option)
	{
		case '1':
			display_a_member();
			break;
		case '2':
			write_member();
			break;
		case '3':
			display_all_members();
			break;
		case '4':
			modify_member();
			break;
		default:
			menu2();
	}
	mainmenu();
}

void mainmenu()
{
	int i;
	system("cls");
	char option;
	draw_rectangle(7,20,18,60);
	gotoxy(35,8);
	cout<<setiosflags(ios::left)<<setw(10)<<"  MAIN MENU";
	gotoxy(21,9);
	draw_line(38);
	gotoxy(35,11);
	cout<<" 1. Books";
	gotoxy(35,13);
	cout<<" 2. Members";
	gotoxy(35,15);
	cout<<" 3. Exit";
	option=getch();
	system("cls");
	switch(option)
	{
		case '1':
			menu1();
			break;
		case '2':
			menu2();
			break;
		case '3':
			exit(0);
			break;
		default:
			mainmenu();
	}
}

void password()
{
	char c,pass[10],a[10]="12345";
	int i;
	clrscr();
	draw_rectangle(7,18,18,64);
	gotoxy(23,10);
	cout<<" Welcome ABC have a nice day!!!!";
	gotoxy(25,13);
	cout<<"Please Enter Password :";
	gotoxy(49,13);
	i=0;
	textcolor(RED+BLINK);
	textbackground(WHITE);
	while(i<10){
		pass[i]=getch();
		c=pass[i];
		if(c==13)break;
		else
		cprintf("*");
		i++;
	}
	pass[i]='\0';
	textcolor(WHITE);
	textbackground(BLACK);
	if(strcmp(pass,a)==0)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		gotoxy(20,15);
		textcolor(RED+BLINK);
		textbackground(WHITE);
		cprintf("Wrong Password please try again....!!!!!!!");
		getch();
		textcolor(WHITE);
		textbackground(BLACK);
		password();
	}
}

int main()
{
    textcolor(WHITE);
    clrscr();
    cout<<"      **        ********  *******   *******    ******   *******   **    **      ";
    cout<<"      **        ********  ********  ********  ********  ********  **    **      ";
    cout<<"      **           **     **    **  **    **  **    **  **    **  **    **      ";
    cout<<"      **           **     ********  *******   ********  *******   ********      ";
    cout<<"      **           **     **    **  **   ***  **    **  **   ***        **      ";
    cout<<"      ********  ********  ********  **    **  **    **  **    **  ********      ";
    cout<<"      ********  ********  *******   **    **  **    **  **    **  *******       "<<endl;
    delay(300);
    cout<<" *****   *****  **   **  *****  ******* *******  *****  ******* **   ** ********";
    cout<<"******* ******* **   ** ******* ******* ******* ******* ******* **   ** ********";
    cout<<"** * ** **   ** * *  ** **   ** **      **      ** * ** **      ***  **    **   ";
    cout<<"** * ** ******* ** * ** ******* **      ******* ** * ** ******* ** * **    **   ";
    cout<<"**   ** **   ** **  *** **   ** **  *** **      **   ** **      **  ***    **   ";
    cout<<"**   ** **   ** **   ** **   ** ******* ******* **   ** ******* **   **    **   ";
    cout<<"**   ** **   ** **   ** **   ** ******* ******* **   ** ******* **   **    **   "<<endl;
    delay(300);
    cout<<"          ********  **    **  ********  ********  ********   ******             ";
    cout<<"          ********  **    **  ********  ********  ********  ********            ";
    cout<<"          **        **    **  **           **     **        ** ** **            ";
    cout<<"          ********  ********  ********     **     ********  ** ** **            ";
    cout<<"                **        **        **     **     **        **    **            ";
    cout<<"          ********  ********  ********     **     ********  **    **            ";
    cout<<"          ********  *******   ********     **     ********  **    **            ";    
    getch();
    password();
    return 0;
}
