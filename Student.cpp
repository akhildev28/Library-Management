#include "Student.h"
using namespace std;
#pragma once

void Student :: Add_student()
{
    system("cls");
    cout<<"\n\t\tNEW STUDENT ENTRY...\n";
    cout<<"\t\t--------------------\n";
    //cout<<"\tEnter the admission no. :\t";
    //cin>>LibraryId;
    fflush(stdin);
    cout<<"\tEnter the student name :\t";
    gets(StudentName);
    fflush(stdin);
    cout<<"\tEnter class of the student :\t";
    cin>>ClassName;
    fflush(stdin);
    cout<<"\tEnter department of the student :\t";
    cin>>department;

    token=0;
    StBookNo[0]='/0';
    cout<<"\n\n\tNew Student added successfully..!\n";
    getch();
}

void Student :: show_student()
{
    cout<<"\n\tAdmission no. :\t"<<LibraryId<<endl;
    cout<<"\tStudent Name :\t";
    cout<<StudentName<<endl;
    cout<<"\tNumber of Book issued :\t"<<token;
    if(token==1 || token==2)
        cout<<"\n\tBook ID :\t"<<StBookNo;
}

void Student :: modify_student()
{
    cout<<"\n\tAdmission no. : "<<LibraryId<<endl;
    fflush(stdin);
    cout<<"\tUpdate student name :\t";
    gets(StudentName);
    cout<<"\tUpdate Class :\t";
    cin>>ClassName;
    cout<<"\tUpdate Department :\t";
    cin>>department;
}

char* Student :: retadmno()
{
    return LibraryId;
}

char* Student :: retstbno()
{
    return StBookNo;
}

int Student :: rettoken()
{
    return token;
}

void Student :: getstbno(char t[])
{
    strcpy(StBookNo,t);
}

void Student :: report()
{
    cout<<"\t"<<LibraryId<<setw(18);
    cout<<StudentName<<setw(20);
    cout<<ClassName<<setw(15);
    cout<<department<<setw(20);
    cout<<token<<endl;
}