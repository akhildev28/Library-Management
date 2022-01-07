#include "Book.h"
//#include<windows.h>
using namespace std;
#pragma once


void Book :: add_book()
{
    cout<<"\n\t\tADD NEW BOOK DETAILS...\n";
    cout<<"\t\t-----------------------\n";
    //cout<<"\tEnter book id :\t";
    //cin>>BookNo;
    fflush(stdin);
    cout<<"\tEnter book name :\t";
    gets(BookName);
    fflush(stdin);
    cout<<"\tEnter author's name :\t";
    gets(AuthorName);
    strcpy(Status,"Available");
    strcpy(DateOfIssue,"Not_Issued");
    strcpy(WhoTaken,"-");
    cout<<"\n\n\tBook added successfully..!";
    getch();
}

void Book :: show_book()
{
    cout<<"\n\tBook ID :\t"<<BookNo;
    cout<<"\n\tBook Name :\t";
    cout<<BookName<<endl;
    cout<<"\tAuthor Name :\t";
    cout<<AuthorName<<endl;
    cout<<"\tStatus :\t";
    puts(Status);
}

void Book :: modify_book()
{
    cout<<"\n\tBook ID :\t"<<BookNo<<endl;
    fflush(stdin);
    cout<<"\tUpdate book name :\t";
    gets(BookName);
    fflush(stdin);
    cout<<"\tUpdate author's name of the book :\t";
    gets(AuthorName);
}

char* Book :: retbookno()
{
    return BookNo;
}

void Book :: Display()
{
    cout<<"\t"<<BookNo<<setw(25);
    cout<<BookName<<setw(20);
    cout<<AuthorName<<setw(20);
    cout<<Status<<setw(27);
    cout<<DateOfIssue<<setw(20);
    cout<<WhoTaken<<endl;

}

void Book :: getstsno(char t[])
{
    strcpy(WhoTaken,t);
}