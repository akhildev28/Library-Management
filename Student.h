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

class Student
{
    public:
        char LibraryId[4];
        char StudentName[30];
        char ClassName[10];
        char department[20];
        char StBookNo[6];
        int token=0;
        

        //Student(char LibraryId[4],char StudentName[20],char ClassName[10],char department[20],char StBookNo[6],int token=0)
        //{};

        void Add_student();
        void show_student();
        void modify_student();
        char* retadmno();
        char* retstbno();
        int rettoken();
        void getstbno(char t[]);
        void report();

        //~Student()
        //{};
};