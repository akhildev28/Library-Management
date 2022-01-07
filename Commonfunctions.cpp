#include "Commonfunctions.h"
#include "Student.cpp"
#include "Book.cpp"
#include "display.cpp"
#pragma once
using namespace std;


//=========This Function Copy TODAYS DATE to given parameter ======
void TodayDate(char Date[]) 
{
    char s[20];
    time_t t = time(0);
    strftime(s, 20, "%m/%d/%Y", localtime(&t));
    strcpy(Date,s);
}  

//=== Function to write the newly added book details in to the file =========
void write_book()
{
    char ch;
    do
    {
        system("cls");
        fileObj.open("book.dat",ios::out|ios::app);
        fstream getid;
        getid.open("book.dat",ios::binary|ios::in);
        while (!getid.eof())
        {
            if (getid.read((char*)&bk,sizeof(Book)))
            {
                int bookid = stoi(bk.BookNo);
                bookid++;
                std::sprintf(bk.BookNo, "%d", bookid);
            }
        }
        bk.add_book();
        fileObj.write((char*)&bk,sizeof(Book));
        getid.close();
        fileObj.close();
        cout<<"\n\n\tDo you want to add more books..(y/n)??\t";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}

//=== Function to write the newly added student details in to the file ========= 
void write_student()
{
    char ch;
    do
    {
        system("cls");
        fileObj.open("student.dat",ios::out|ios::app);
        fstream getid;
        getid.open("student.dat",ios::binary|ios::in);
        while (!getid.eof())
        {
            if (getid.read((char*)&st,sizeof(Student)))
            {
                int studid = stoi(st.LibraryId);
                studid++;
                std::sprintf(st.LibraryId, "%d", studid);
            }
        }
        st.Add_student();
        fileObj.write((char*)&st,sizeof(Student));
        getid.close();
        fileObj.close();
        cout<<"\n\tDo you want to add more students....(y/n)??\t";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}


//======= Function for update the details of specific book ==========
void modify_book_file()
{
    system("cls");
    char n[6];
    int found=0;
    cout<<"\n\n\t\tUPDATE BOOK DETAILS";
    cout<<"\n\t\t-------------------";
    cout<<"\n\n\tEnter book ID for update the book details :\t";
    cin>>n;
    fileObj.open("book.dat",ios::in|ios::out);
    while(fileObj.read((char*)&bk,sizeof(Book)) && found==0)
    {
        if(strcmpi(bk.retbookno(),n)==0)
        {
            bk.show_book();
            cout<<"\n\tEnter new details of the book :\t"<<endl;
            bk.modify_book();
            /*The seekp(pos) method of ostream in C++ is used to set the position of the pointer
             in the output sequence with the specified position. 
             This method takes the new position  and returns this ostream instance with the position 
             set to the specified new position.*/
            int pos=-1*sizeof(bk);
            fileObj.seekp(pos,ios::cur);
            fileObj.write((char*)&bk,sizeof(Book));
            cout<<"\n\n\tBook details updated successfully..!";
            found=1;
        }
    }
    fileObj.close();
    if(found==0)
        cout<<"\n\n\tBook doesnot exist..!";
    getch();
}

//======= Function for update the details of specific student ==========
void modify_student_file()
{
    char n[6];
    int found=0;
    system("cls");
    cout<<"\n\n\t\tUPDATE STUDENT DETAILS\n";
    cout<<"\t\t----------------------\n";
    cout<<"\n\tEnter the admission no. of the student :\t";
    cin>>n;
    fileObj.open("student.dat",ios::in|ios::out);
    while(fileObj.read((char*)&st,sizeof(Student)) && found==0)
    {
        if(strcmpi(st.retadmno(),n)==0)
        {
            st.show_student();
            cout<<"\n\n\t\tEnter new details of the student :"<<endl;
            st.modify_student();
            int pos=-1*sizeof(st);
            fileObj.seekp(pos,ios::cur);
            fileObj.write((char*)&st,sizeof(Student));
            cout<<"\n\n\tDetails updated successfully..!";
            found=1;
        }
    }
    
    fileObj.close();
    if(found==0)
        cout<<"\n\n\tStudent doesnot exist..!";
    getch();
}

//======== Function to delete a student details ========
void delete_student()
{
    system("cls");
    char n[6],ch;
    int flag=0;    
    cout<<"\n\n\t\tREMOVE STUDENT";
    cout<<"\n\t\t--------------\n";
    cout<<"\n\n\tEnter the admission no. of the student you want to remove :\t";
    cin>>n;
    fileObj.open("student.dat",ios::in|ios::out);
    fstream fileObj2;
    fileObj2.open("Temp.dat",ios::out);
    fileObj.seekg(0,ios::beg);
    while(fileObj.read((char*)&st,sizeof(Student)))
    {
        // write all data to temp.dat except the matching condtion
        //ie,student details with the with given admission no/library id  is excluded 
        if(strcmpi(st.retadmno(),n)!=0)
        {
            fileObj2.write((char*)&st,sizeof(Student));
        }
        else
        {
            st.show_student();
            flag=1;
        }
    }
    fileObj2.close();
    fileObj.close();
    // deleting the 'student.dat' and renaming the updated list to 'student.dat'
    if(flag==1)
    {
        cout<<"\n\n\tDo you want to remove this student..(y/n)??\t";
        cin>>ch;
        if(ch=='y'|| ch=='Y')
        {
            remove("student.dat");
            rename("Temp.dat","student.dat");
            cout<<"\n\n\tStudent removed successfully..!";
            getch();
        }
    }
    else
    {
        remove("Temp.dat");
        cout<<"\n\n\tStudent doesnot exist..!";
        getch();
    }
}

//======== Function to delete a book details =============
void delete_book()
{
    system("cls");
    char n[6],ch;
    int flag=0;
    cout<<"\n\n\t\tREMOVE BOOK";
    cout<<"\n\t\t-----------";
    cout<<"\n\n\tEnter the Book ID to delete the specific book :\t";
    cin>>n;
    fileObj.open("book.dat",ios::in|ios::out);
    fstream fileObj2;
    fileObj2.open("Temp.dat",ios::out);
    fileObj.seekg(0,ios::beg);
    while(fileObj.read((char*)&bk,sizeof(Book)))
    {
        // write all data to temp.dat except the matching condtion
        //ie,Book details with the with given Book no.  is excluded 
        if(strcmpi(bk.retbookno(),n)!=0)  
        {
            fileObj2.write((char*)&bk,sizeof(Book));
        }
        else
        {
            bk.show_book();
            flag=1;
        }
    }   
    fileObj2.close();
    fileObj.close();
        // deleting the 'book.dat' and renaming the updated list to 'book.dat'
    if(flag==1)
    {
        cout<<"\n\n\tDo you want to remove this book..(y/n)??\t";
        cin>>ch;
        if(ch=='y'|| ch=='Y')
        {
            remove("book.dat");
            rename("Temp.dat","book.dat");
            cout<<"\n\n\tBook removed successfully..!";
            getch();
        }
    }
    else
    {
        remove("Temp.dat");
        cout<<"\n\n\tBook doesnot exist..!";
        getch();
    }
}
    


//======= Function for the student to take books from library ===========
void book_issue()
{
    system("cls");
    char StudentNumber[6],BookNumber[6]; // Temporay variable to store LibrarayId(Ad.Number) and Book number
    int found=0,flag=0;
    cout<<"\n\n\t\tTAKE YOUR BOOK HERE";
    cout<<"\n\n\tEnter the student's admission no. :\t";
    cin>>StudentNumber;
    fileObj.open("student.dat",ios::in|ios::out);
    fileObj1.open("book.dat",ios::in|ios::out);
    // Iterating through Student Details
    while(fileObj.read((char*)&st,sizeof(Student)) && found==0)
    {
        //Checkimg For Exact student
        if(strcmpi(st.retadmno(),StudentNumber)==0)
        {
            found=1;
            if(st.rettoken()==0||st.rettoken()==1)//checking the student is eligible to to take book
            {
                cout<<"\n\n\tEnter the book ID :\t";
                cin>>BookNumber;
                // Iterating through Book list
                while(fileObj1.read((char*)&bk,sizeof(Book))&& flag==0)
                {
                    //Checking For Exact Book
                    if(strcmpi(bk.retbookno(),BookNumber)==0 && strcmpi(bk.Status,"Available")==0)
                    {
                        // Displaying Exact Book
                        bk.show_book();

                        flag=1;

                        // Issues the book 
                        //st.addtoken(st.token);
                        st.token++;

                        //Changing status of book
                        strcpy(bk.Status,"Issued");


                        // getsbno (Book Number) Function copy the given book number to Student Book Number
                        st.getstbno(bk.retbookno());

                        //getstsno(Student) function copy the given student number to whotaken the book 
                        bk.getstsno(st.retadmno());


                        //Changing IsuueOfDate 
                        TodayDate(bk.DateOfIssue);

                        //Modification to Student file
                        int pos=-1*sizeof(st);
                        fileObj.seekp(pos,ios::cur);
                        fileObj.write((char*)&st,sizeof(Student));

                        
                        // Modification to Book file after changing status
                        int pos2=-1*sizeof(bk);
                        fileObj1.seekp(pos2,ios::cur);
                        fileObj1.write((char*)&bk,sizeof(Book));
                        cout<<"\n\n\t Book issued successfully..!\n";
                    }
                }
                if(flag==0)
                {
                    cout<<"Book ID does not exist or Issued to Someone else";
                }
            }
            else
            {
                cout<<"\n\n\tYou have not returned the taken books..!";
            }
        }
    }
    if(found==0)
    {
        cout<<"\n\n\tStudent record not exist..!";
    }
    fileObj.close();
    fileObj1.close();
    getch(); 

}


//======= Function for the student to return the taken book to the library ================ 
void book_deposit() 
{
    char StudentNumber[6],BookNumber[6],TempNo[6];// Temporay variable to store LibrarayId(Ad.Number) and Book number
    int found=0,flag=0;
    system("cls");
    cout<<"\n\n\t\tRETURN THE TAKEN BOOK HERE";
    cout<<"\n\n\tEnter The student admission no. :\t";
    cin>>StudentNumber;
    fileObj.open("student.dat",ios::in|ios::out);
    fileObj1.open("book.dat",ios::in|ios::out);
    // Iterating through Student Details
    while(fileObj.read((char*)&st,sizeof(Student)) && found==0)
    {
        if(strcmpi(st.retadmno(),StudentNumber)==0)
        {
            found=1;
            // checking token , ie  is the Student have taken any book 
            // if token is 1/2 then one/two book is remaining 
            if(st.rettoken()==1||st.rettoken()==2)
            {
                cout<<"\tEnter Book ID for return :\t";
                cin>>TempNo;
                // Iterating through Book list 
                while(fileObj1.read((char*)&bk,sizeof(Book))&& flag==0)
                {
                    //Checkimg For Exact Book number
                    if(strcmpi(bk.retbookno(),TempNo)==0 && strcmpi(bk.Status,"Issued")==0  && strcmpi(bk.WhoTaken,StudentNumber)==0 )
                    {
                        //need to change so many details
                        bk.show_book();
                        flag=1;
                        // resting the token
                        //st.resettoken(st.token);
                        st.token--; // returning of book noted
                        //Changing Book Status
                        strcpy(bk.Status,"Available");
                        strcpy(bk.WhoTaken,"-");
                        // Changing Issue of Date 
                        strcpy(bk.DateOfIssue,"Not Issued");
                        //change to student file
                        int pos=-1*sizeof(st);
                        fileObj.seekp(pos,ios::cur);
                        fileObj.write((char*)&st,sizeof(Student));
                        // Modification to Book file
                        int pos2=-1*sizeof(bk);
                        fileObj1.seekp(pos2,ios::cur);
                        fileObj1.write((char*)&bk,sizeof(Book));
                        cout<<"\n\n\tBook deposited successfully..!";
                    }
                }
            }
            if(flag==0)
            {
                cout<<"\n\tBook id does not exist or Book is not issued..!\n";
            }
        }
    }
    if(found==0)
        cout<<"\n\n\tStudent doesnot exist..!\n";
    fileObj.close();
    fileObj1.close();
    getch();
}

