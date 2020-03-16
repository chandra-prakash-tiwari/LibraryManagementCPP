#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include<stdlib.h>
#include<iomanip.h>
#include<dos.h>
#include<ctype.h>
#include<conio.h>
#include<iomanip.h>

void mainmenu();
void draw_rectangle(int a, int b, int c, int d);
void draw_line(int a);
/**********************************************/
// LIBRARY CLASS..........
/*********************************************/
class library
{
public:
     char book_id[50];
     char book_name[50];
     char author[50];
     int edition,c;
     int num,a,b,i;

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

	l1:
		b=0;
		gotoxy(37,10);
		cin.ignore();
		cin.getline(book_name,50);
		a=strlen(book_name);
		for(i=0;i<a;i++){
			if((book_name[i]>='A'&&book_name[i]<='Z')||(book_name[i]>='a'&&book_name[i]<='z')||book_name[i]==32)
			b++;
		}
		if(a!=b){
			gotoxy(20,19);
			cout<<"Enter Correct Book Name";
			delay(1000);
			gotoxy(37,10);
			cout<<"                                   ";
			gotoxy(20,19);
			cout<<"            " ;
			goto l1;
		}
	l2:
		b=0;
		gotoxy(37,12);
		cin.getline(author,50);
		a=strlen(author);
		b=a;
		for(i=0;i<a;i++){
		    if(isdigit(author[i]))
			b--;
		}
		if(a!=b){
		    gotoxy(20,19);
		    cout<<"Please Enter correct Author";
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
	cout<<"New Entry Has Been Done";
    }
     void view_book()
    {
	cout<<"\nBook ID: "<<book_id;
	cout<<"\nBook Name: "<<book_name;
	cout<<"\nAuthor's Name: "<<author;
    }
     void modify_book()
    {
    cout<<"\n  Modify the Book Detail:\n\n";
	cout<<"\nBook ID       : "<<book_id;
	cout<<"\n\nBook Name     :\n";
	cout<<"\nAuthor's Name :\n";
	cout<<"\nEdition       :\n";
	cout<<"\nNo.Of Copies  :\n";

	l3:
		b=0;
		gotoxy(17,9);
		cin.ignore();
		cin.getline(book_name,50);
		a=strlen(book_name);
		for(i=0;i<a;i++){
			if((book_name[i]>='A'&&book_name[i]<='Z')||(book_name[i]>='a'&&book_name[i]<='z')||book_name[i]==32)
			b++;
		}
		if(a!=b){
			gotoxy(17,21);
			cout<<"Error";
			delay(1000);
			gotoxy(17,9);
			cout<<"                                             ";
			gotoxy(17,21);
			cout<<"            " ;
			goto l3;
		}
    l4:
	b=0;
	    gotoxy(17,11);
	cin.getline(author,50);
	a=strlen(author);
	    for(i=0;i<a;i++){
		    if((author[i]>='A'&&author[i]<='Z')||(author[i]>='a'&&author[i]<='z')||author[i]==32)
			b++;
	}
	    if(a!=b){
		    gotoxy(17,21);
		    cout<<"Error";
		delay(1000);
		gotoxy(17,11);
		cout<<"                                             ";
		    gotoxy(17,21);
			cout<<"            " ;
			goto l4;
		}
	gotoxy(17,13);
	cin>>edition;
	gotoxy(17,15);
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
    void report()
    {                    cout<<setfill(' ');
	cout<<book_id<<setw(28)<<book_name<<setw(28)<<author<<setw(12)<<edition<<setw(10)<<num<<endl ;
    }
};

/*************************************************/
//MEMBER CLASS......
/************************************************/
class member
{
public:
    char member_id[20];
    char member_name[20];
    char mob[15];
    char stbno[6];
    int token;

    void create_member()
    {
	cout<<"\nEnter The Member ID : ";
	cin>>member_id;
	cout<<"\n\nEnter The Name of The Member : ";
	cin>>member_name;
	cout<<"\n\nEnter the mobile number : ";
	cin>>mob;
	token=0;
	stbno[0]='/0';
	cout<<"\t\t\n\nMember Record Created Successfully...";
    }
    void show_member()
    {
	cout<<"\nMember ID: "<<member_id;
	cout<<"\nMember Name: "<<member_name;
	cout<<"\nMobile number: "<<mob;
	cout<<"\nNo of Book issued: "<<token;
	if(token==1)
	    cout<<"\nBook No "<<stbno;
    }
    void modify_member()
    {
	cout<<"\nID Number: "<<member_id;
	cout<<"\nModify Member Name: ";
	cin.ignore();
	cin.getline(member_name,50);
	cout<<"\nModify Mobile number: ";
	cin.getline(mob,15);
    }
    char* get_member_id()
    {
	return member_id;
    }
    char* retstbno()
    {
	return stbno;
    }
    int rettoken()
    {
	return token;
    }
    void addtoken()
    {
	token=1;
    }
    void resettoken()
    {
	token=0;
    }
    void getstbno(char t[])
    {
	strcpy(stbno,t);
    }
    void report()
    {
	cout<<member_id<<setw(15)<<member_name<<setw(15)<<mob<<setw(15)<<token<<endl;
    }

};

    /* GLOBAL DECLARATION*/
/*********************************************/
library bk;
fstream fp , fp1;
member mb;
/************************************************/

void write_book()
{
    char answer='n';
    int c;
    fp.open("book.dat", ios::out|ios::app);
    fp1.open("book.dat",ios::in);
    do
    {
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
	cin>>answer;
    }while(answer == 'y'|| answer == 'y');
    fp.close();
    fp1.close();
    mainmenu();
}

void display_allbook()
{
    fp.open("book.dat" , ios::in);
    if(!fp)
    {
	cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
	mainmenu();
    }
    cout<<"\n\t\tBook LIST\n";
    cout<<"================================================================================";
    cout<<"Book ID"<<setw(22)<<"Book Name"<<setw(28)<<"Author"<<setw(12)<<"Edition"<<setw(10)<<"Copies"<<endl;
    cout<<"================================================================================";
    while(fp.read((char*)&bk,sizeof(library)))
    {
	bk.report();
    }
    fp.close();
    system("pause");
    mainmenu();
}

void display_a_book_by_id()
{
    int found=0;
    char id[20];
    system("cls");
    cout<<"\n\n\tPlease Enter The book ID:  ";
    cin>>id;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(library)))
    {

	if(strcmpi(bk.getbookid(),id)==0)
	{
	    bk.view_book();
	    found=1;
	    //cout<<"\n\n\nPress any key to continue"<<endl;
	}
    }
    fp.close();
    if(found==0)
       cout<<"BOOK NOT FOUND"<<endl;
    system("PAUSE");
    system("cls");
    mainmenu();
}

void display_a_book_by_name()
{
    system("cls");
    int found=0;
    char nm[20];
    system("cls");
    cout<<"\n\n\tPlease Enter name of the book:  ";
    cin>>nm;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(library)))
    {

	if(strcmpi(bk.getbooknm(),nm)==0)
	{
	    bk.view_book();
	    found=1;
	    //cout<<"\n\n\nPress any key to continue"<<endl;
	}
    }
    fp.close();
    if(found==0)
       cout<<"BOOK NOT FOUND"<<endl;
    system("PAUSE");
    system("cls");
    mainmenu();
}

void issue_book()
{
    system("cls");
    char mn[20],bn[20];
    int found=0,flag=0;
    cout<<"\t\t\nBOOK ISSUE";
    cout<<"\n\n\tEnter member's ID number: ";
    cin>>mn;
    fp1.open("member.dat",ios::in|ios::out);
    fp.open("book.dat",ios::in|ios::out);
    while(fp1.read((char*)&mb,sizeof(member)) && found==0)
    {
	if(strcmpi(mb.get_member_id(),mn)==0)
	{
	    found=1;
	    if(mb.rettoken()==0)
	    {
		cout<<"\n\n\tEnter book ID: ";
		cin>>bn;
		while(fp.read((char*)&bk,sizeof(library))&& flag==0)
		{
		    if(strcmpi(bk.getbookid(),bn)==0)
		    {
			bk.view_book();
			flag=1;
			mb.addtoken();
			mb.getstbno(bk.getbookid());
			int pos=-1*sizeof(mb);
			fp1.seekp(pos,ios::cur);
			fp1.write((char*)&mb,sizeof(member));
			bk.num--;
			cout<<"\n\n\t Book issued successfully...";
		    }
		}
		if(flag==0)
		    cout<<"Book number does not exist";
	    }
	    else
		cout<<"You have not returned the last book ";
	}
    }
    if(found==0)
	cout<<"Member record not exist...";
    fp.close();
    fp1.close();
    system("pause");
    system("cls");
    mainmenu();
}

void book_return()
{
    system("cls");
    char mn[20],bn[20];
    int found=0, flag=0, day, fine;
    cout<<"\t\tRETURN BOOKS\n";
    cout<<"\n\n\tEnter The member’s ID Number: ";
    cin>>mn;
    fp1.open("member.dat",ios::in|ios::out);
    fp.open("book.dat",ios::in|ios::out);
    while(fp1.read((char*)&mb,sizeof(member)) && found==0)
    {
	if(strcmpi(mb.get_member_id(),mn)==0)
	{
	    found=1;
	    if(mb.rettoken()==1)
	    {
		while(fp.read((char*)&bk,sizeof(library))&& flag==0)
		{
		    if(strcmpi(bk.getbookid(),mb.retstbno())==0)
		    {
			bk.view_book();
			flag=1;
			cout<<"\n\nBook returned in no. of days";
			cin>>day;
			if(day>15)
			{
			    fine=(day-15)*5;
			    cout<<"\n\n No. of days exceeds so, you have to pay a fine of  "<<fine<<" Rs.";
			}
			mb.resettoken();
			int pos=-1*sizeof(mb);
			fp1.seekp(pos,ios::cur);
			fp1.write((char*)&mb,sizeof(member));
			bk.num++;
			cout<<"\n\n\t Book returned successfully...";
		    }
		}
		if(flag==0)
			cout<<"Book number does not exist";
	    }
	    else
		cout<<"No book is issued..please check!!";
	}
    }
    if(found==0)
	cout<<"Member's record not exist...";
    fp.close();
    fp1.close();
    system("pause");
    mainmenu();
}

void modify_book()
{
    char n[20];
    int found=0;
    cout<<"\n\n\tMODIFY BOOK";
    cout<<"\n\n\tEnter The book ID: ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(library)) && found==0)
    {
	if(strcmpi(bk.getbookid(),n)==0)
	{
	  //  bk.view_book();
	    cout<<"\nEnter The New Details of book"<<endl;
	    bk.modify_book();
	    int pos=-1*sizeof(bk);
	    fp.seekp(pos,ios::cur);
	    fp.write((char*)&bk,sizeof(library));
	    cout<<"\n\n\t Record Updated Successfully...";
	    found=1;
	}
    }
    fp.close();
    if(found==0)
	cout<<"\n\n Record Not Found ";
    system("pause");
    mainmenu();
}

void write_member()
{
    char answer='n';
    fp1.open("member.dat",ios::out|ios::app);
    do
    {
       mb.create_member();
       fp1.write((char*)&mb,sizeof(member));
       cout<<"\n\t\t Do you want to add another member(y/n):";
       cin>>answer;
    }while(answer == 'y'|| answer == 'y');
    fp1.close();
    mainmenu();
}

void display_all_members()
{
    fp1.open("member.dat",ios::in);
    if(!fp1)
    {
	cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
	return;
    }
    cout<<"\n\n\t\tMEMBERS LIST\n\n";
    cout<<"==================================================================================\n";
    cout<<"MEMBER ID"<<setw(15)<<"Name"<<setw(15)<<"Mobile no"<<setw(15)<<"Book Issued\n";
    cout<<"==================================================================================\n";
    while(fp1.read((char*)&mb,sizeof(member)))
    {
	mb.report();
    }
    fp1.close();
    system("pause");
    mainmenu();
}

void mainmenu()
{
	int i;
	system("cls");
	char option;
	draw_rectangle(7,20,18,60);
	gotoxy(35,8);
	cout<<"  MAIN MENU\n";
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
			draw_rectangle(3,20,22,60);
			gotoxy(35,4);
			cout<<" OPTION:";
			gotoxy(21,5);
			draw_line(38);
			gotoxy(32,8);
			cout<<"1. Search Catalogue";
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
			option=getch();
			system("cls");
			switch(option){
				    case '1':
				    cout<<"\n\t\t\t 1.Search By Book Id:";
				    cout<<"\n\t\t\t 2.Search By Book Name:";
				    cout<<"\n\t\t\t Option : ";
				    option=getch();
				    switch(option){
					case '1':
						display_a_book_by_id();
						break;
					case '2':
						display_a_book_by_name();
						break;
				    }

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
				    cout<<"\n\t\t\t Modify books:";
				    modify_book();
				    break;
			}
			break;
	  case '2':
		draw_rectangle(3,20,22,60);
		gotoxy(35,4);
		cout<<"OPTION";
		gotoxy(21,5);
		draw_line(38);
		gotoxy(32,9);
		cout<<"1. Search Catalogue";
		gotoxy(32,11);
		cout<<"2 .Register New Member";
		gotoxy(32,13);
		cout<<"3. View Member Details";
		gotoxy(32,15);
		cout<<"4. Modify Member Details";
		gotoxy(32,17);
		cout<<"5. Delete Member";
		gotoxy(32,19);
		option=getch();
		system("cls");
		switch(option)
		{
		    case '1':  char id[20];
			cout<<"\n\n\tWork in progress................ ";
			     cin>>id;
			    // display_a_book(id);
			     break;

		    case '2':
			    cout<<"\n\t\t\t Register New Member:";
			    write_member();
			    break;

		    case '3':
			    cout<<"\n\t\t\t View Member Details:";
			    display_all_members();
			    break;

		    case '4':
			    cout<<"\n\t\t\tWork in progress................";
			   //  modify_member();
			    break;

		    case '5':
			    cout<<"\n\t\t\tWork in progress................";
			    // delete_member();
			    break;
		    }
			break;

	  case '3': exit(0);
		  break;
	  default:mainmenu();

    }
}

void draw_rectangle(int a,int b,int c,int d){
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
			cprintf("%c",179);    }
		}
	}
	}
	textcolor(WHITE);
	textbackground(BLACK);
}

void draw_line(int a){
	int i;
	textcolor(RED);
	textbackground(WHITE);
	for(i=0;i<a;i++){
		cprintf("%c",196);
	}
	textcolor(WHITE);
	textbackground(BLACK);
}

/******************************************************/
/****************PASSWORD SECTION**********************/
/******************************************************/
void password()
{
	char c,pass[10],a[10]="12345";
	int i;
	clrscr();
	draw_rectangle(9,21,16,60);
	gotoxy(23,11);
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
		gotoxy(20,18);
		cout<<"Wrong Password please try again....!!!!!!!\n\n";
		getch();
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
