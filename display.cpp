#include "Student.cpp"
#include "Book.cpp"

#pragma once
using namespace std;

fstream fileObj,fileObj1;// creating 2 file object  
Book bk; // creating an object of Book class
Student st; // creating an object of Student class


//======== Function to search and view the details of specific book ======================
void display_showBook(char n[])
{
    cout<<"\n\t\tBOOK DETAILS";
    cout<<"\n\t\t------------\n";
    int flag=0;
    fileObj.open("book.dat",ios::in);
    // iterating through each file object
    while(fileObj.read((char*)&bk,sizeof(Book)))
    {
        //comparing the each bk's with given book number 'n'
        if(strcmpi(bk.retbookno(),n)==0)
        {
            //if found the same book no , then showing the details of the specific book 
            bk.show_book();
            flag=1;
        }
    }
    fileObj.close();
    if(flag==0)
        cout<<"\n\tBook does not exist..!";
    getch();
}


//======== Function to search and view the details of specific student ======================
void display_showStudent(char n[])
{
    cout<<"\n\t\tSTUDENT DETAILS\n";
    int flag=0;
    fileObj.open("student.dat",ios::in);
    while(fileObj.read((char*)&st,sizeof(Student)))
    {
        if((strcmpi(st.retadmno(),n)==0))
        {
            st.show_student();
            flag=1;
        }
    }
    
    fileObj.close();
    if(flag==0)
            cout<<"\n\nStudent does not exist";
    getch();
}

//======== Function to display all student details ======== 
void display_allStudent()
{
    system("cls");
    fileObj.open("student.dat",ios::in);
    if(!fileObj)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
    cout<<"\n\n\t\t\t\tSTUDENT DETAILS\n";
    cout<<"\t\t\t\t---------------\n";
    cout<<"==============================================================================================\n";
    cout<<"   "<<"Library Id."<<setw(15)<<"Name"<<setw(20)<<"Class"<<setw(18)<<"Department"<<setw(23)<<"Book Taken\n";
    cout<<"==============================================================================================\n";

    while(fileObj.read((char*)&st,sizeof(Student)))
    {
        st.report();
    }
         
    fileObj.close();
    getch();
}

//======== Function to display all book details in the library ============
void display_allBooks()
{
    system("cls");
    fileObj.open("book.dat",ios::in|ios::binary);
    if(!fileObj)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }

    cout<<"\n\n\t\t\t\t\t\tBOOK DETAILS\n";
    cout<<"\t\t\t\t\t\t------------\n";
    cout<<"=========================================================================================================================================\n";
    cout<<"  "<<"Book Number"<<setw(24)<<"Book Name"<<setw(19)<<"Author"<<setw(19)<<"Status"<<setw(28)<<"Date Of Issue"<<setw(25)<<"Who Taken \n";
    cout<<"=========================================================================================================================================\n";

    while(fileObj.read((char*)&bk,sizeof(Book)))
    {
        bk.Display();
    }
    fileObj.close();
    getch();
}
