#include "users.h"
#include "Commonfunctions.cpp"
#pragma once
using namespace std;





//====== ADMIN MENU ===== call all basics functions of admin(librarian).
  void admin_menu()
{
    system("cls");
    char option;
    cout<<"\n\t\tLIBRARIAN MENU\n";
    cout<<"\n\t1. Student Management";
    cout<<"\n\t2. Book Management";
    cout<<"\n\t3. Logout";
    cout<<"\n\n\tSelect Your Option :\t";
    cin>>option;
    switch (option)
    {
        case '1':{system("cls");
                char option1;
                cout<<"\n\t\tSTUDENT MANAGEMENT\n";
                cout<<"\n\t1. Add new student details";
                cout<<"\n\t2. View all students details";
                cout<<"\n\t3. Display specific student details";
                cout<<"\n\t4. Update student details";
                cout<<"\n\t5. Remove a student";
                cout<<"\n\t6. Go Back";
                cout<<"\n\n\tSelect Your Option :\t";
                cin>>option1;
                switch(option1)
                {
                    case '1':system("cls");
                            write_student();
                            break;
                    case '2':system("cls");
                            display_allStudent();
                            break;
                    case '3':{system("cls");
                            char num[6];
                            cout<<"\n\n\tEnter Admission No. to search student :\t";                    
                            cin>>num;
                            display_showStudent(num);}
                            break;
                    case '4':system("cls");
                            modify_student_file();
                            break;
                    case '5':system("cls");
                            delete_student();
                            break;
                    case '6':system("cls");
                            admin_menu();
                            break;
                    default :cout<<"\n\tWrong Choice..!\n";
                            getch();
                }}
                break;
        case '2':{system("cls");
                char option1;
                cout<<"\n\t\tBOOK MANAGEMENT\n";
                cout<<"\n\t1. Add new book details";
                cout<<"\n\t2. View all books details";
                cout<<"\n\t3. Display specific book details";
                cout<<"\n\t4. Update book details";
                cout<<"\n\t5. Remove a book";
                cout<<"\n\t6. Go Back";
                cout<<"\n\n\tSelect Your Option :\t";
                cin>>option1;
                switch(option1)
                {
                    case '1':system("cls");
                            write_book();
                            break;
                    case '2':system("cls");
                            display_allBooks();
                            break;
                    case '3':{system("cls");
                            char num[6];
                            cout<<"\n\n\tEnter the book No. to serach specific book :\t";
                            cin>>num;
                            display_showBook(num);}
                            break;
                    case '4':system("cls");
                            modify_book_file();
                            break;
                    case '5':system("cls");
                            delete_book();
                            break;
                    case '6':system("cls");
                            admin_menu();
                            break;
                    default :cout<<"\n\tWrong Choice..!\n";
                            getch();
                }}
                break;
        case '3':return;
                break;
        default :"\n\n\tWrong choice..!\n";
                getch();
    }
    admin_menu();
}

//====== USER MENU ===== call all basics functions of user(Student).
void user_menu()
{
    system("cls");
    char option;
    cout<<"\n\t\tSTUDENT MENU\n";
    cout<<"\n\t1. View all book details";
    cout<<"\n\t2. Take a book";
    cout<<"\n\t3. Return the taken book";
    cout<<"\n\t4. Logout";
    cout<<"\n\n\tSelect Your Option :\t";
    cin>>option;
    switch (option)
    {
        case '1':system("cls");
                display_allBooks();
                break;
        case '2':system("cls");
                book_issue();
                break;
        case '3':system("cls");
                book_deposit();
                break;
        case '4':system("cls");
                return;
                break;
        default :cout<<"\n\tWrong Choice..!\n";
                getch();
    }
    user_menu();
}