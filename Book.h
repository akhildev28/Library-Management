#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>
using namespace std;


class Book
{
    public:
        char BookName[30];
        char BookNo[6];
        char AuthorName[30];
        char Status[10];
        char DateOfIssue[30];
        char WhoTaken[30];

       // Book(char BookNo[6],char BookName[50],char AuthorName[20],char Status[10],char DateOfIssue[15])
        //{};

        void add_book();
        void show_book();
        void modify_book();
        char* retbookno();
        void Display();
        void getstsno(char t[]);

        //~Book()
        //{};
};