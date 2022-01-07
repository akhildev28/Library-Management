#include"users.cpp"

using namespace std;

//====== MAIN MENU ========= 
int main()
{
    char password[10]="admin@123";
    char typePassword[10];
    char option;
    do
    {
        system("cls");
        cout<<"\n\n\tLIBRARY MANAGEMENT SYSTEM\n";
        cout<<"\t-------------------------\n";
        cout<<"\n\t\tMAIN MENU\n";
        cout<<"\n\t1. Librarian Menu";
        cout<<"\n\t2. Student Menu";
        cout<<"\n\t3. Close";
        cout<<"\n\n\tSelect Your Option :\t";
        cin>>option;
        switch(option)
        {
            case '1':system("cls");
                    {
                        cout<<"\n\tEnter Password to Continue :\t";
                        cin>>typePassword;
                        if (strcmpi(typePassword,password)==0)
                        {
                            admin_menu();
                        }
                        else
                        {
                            cout<<"\n\tWrong Password..!";
                            getch();
                            break;
                        }
                    }
                    break;
            case '2':system("cls");
                    user_menu();
                    break;
            case '3':exit(0);
                    break;
            default :cout<<"\n\tWrong Choice..!\n";
                    getch();
        }
    }while(option!='3');
    return 0;
}