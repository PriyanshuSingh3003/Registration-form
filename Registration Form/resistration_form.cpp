
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
void login();
void registration();
void forgot ();

int main(){
    int command;
    cout<<"\t\t\t________________________________________________________________________\n\n\n";
    cout<<"\t\t\t                         Welcome to login page                          \n\n\n";
    cout<<"\t\t\t____________________________     MENU     ______________________________\n\n";
    cout<<"                                                                              \n\n";
    cout<<"\t| Press 1 to LOGIN                |"<<endl;
    cout<<"\t| Press 2 to REGISTER             |"<<endl;
    cout<<"\t| Press 3 to FORGOT               |"<<endl;
    cout<<"\t| Press 4 to EXIT                 |"<<endl;
    cout<<"\n\t\t\t Please enter your choice : ";
    cin>>command;
    cout<< endl;

    switch(command){
        case 1:
        login();
        break;

        case 2:
        registration();
        break;

        case 3:
        forgot();
        break;

        case 4:
        cout<<"\t\t\t Thankyou! \n\n";
        break;

        default:
        system("cls");
        cout<<"\t\t\t please select an option given above \n"<<endl;
        main();

    }
}

  void login() {
    int count;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t please enter the username and password: "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;
    ifstream input("record.txt");
    while(input>>id>>pass){
        if(id==userId && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<userId<<"\n Your login is successfull \n Thanks for login in! \n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password \n";
        main();

    }

}
void registration(){
    string ruserId, rpassword, eid, rpass;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;
    ofstream f1("record.txt", ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registeration is Successfull ! \n";
    main();

}
void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No Worries \n";
    cout<<"Press 1 for search your Id by username"<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cout<<" enter your choice : ";
    cin>>option;
    switch (option){
        case 1 :
        {
            int count =0;
            string suserId,spass, sId;
            cout<<"\n\t\t\t Enter the user name which you remembered : ";
            cin>> suserId;
            ifstream f2("records.txt");
            while(f2>>sId>>spass){
                if(sId==suserId){
                    count =1;

                }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your password is : "<<spass;
                main();
            }
            else{
                cout<<"\n\t Sorry! Your account is not found! \n";
                main();
            }
            break;

        }
        case 2 :
        {
           main();
        }
        default:
        cout<<"\t\t\t Worng choice! Please try again"<<endl;
        forgot();
    }
}