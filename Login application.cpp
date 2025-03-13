#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
void login();
void registration ();
void forgot();
void repeat();
void menu();

int main()
{
	int a;
  cout << "\033[1;36m\n\n\n\n \t\t\t\t\t---- Login and Registration System ------\033[0m" << endl;
    cout << "\033[1;36m\n\n\n \t\t\t\t\t Presented to \n\n \t\t\t\t\t Miss HINA TUFAIL\033[0m" << endl;
    cout << "\033[1;36m\n\n\n\t\t\t\t\t Presented by \n\n\t\t\t\t\t  1.USAMA ARHAD \n\n\t\t\t\t\t  2.AMBREEN SHAHZAD \n\n\t\t\t\t\t  3.ALEEHA MALIK\n\n\033[0m" << endl;
   cout<<"\033[1;32m\n\nPress any number to continuo into the program: \033[0m";
   	cin>>a;
   	if(a)
   	{
   		system("cls");
   		
	}
	
	menu();
   
   
   

   
   return 0;
}

void menu()
{
	 //starting
    int c;
    cout<<"\t\t\t________________________________________________________\n\n\n\033[0m";
    cout<<"\t\t\t                   \033[1;46mWelcome to the login Page\033[0m\n\n\n";
    cout<<"\t\t\t___________________          \033[1;46mMENU\033[0m          _____________\n\n\n";
    cout<<"\033[1;36m\t| Press 1 to LOGIN                      |\033[0m"<<endl;
    cout<<"\033[1;36m\t| Press 2 to REGISTER                   |\033[0m"<<endl;
    cout<<"\033[1;36m\t| Press 3 to if you forgot you PASSWORD |\033[0m"<<endl;
    cout<<"\033[1;36m\t| Press 4 to to EXIT                    |\033[0m"<<endl;
    cout<<"\033[1;36m \n\t\t\t Please Enter your choice : \033[0m";
    cin>>c; //choice
    cout<<endl;

    switch(c)
    {
        case 1:
             {
                login();
                break;
             }

        case 2:
             {
                registration();
                break;
             }
        case 3:
             {
                forgot();
                break;
             }
        case 4:
            {
            	 system("cls");
                cout<<"\033[1;33m\n\n\n \t\t\t Thank you! \n\n\n The program has been successfully ended\n\n ";
                cout<<" \033[1;32mDont forget to Appreciate.....\033[0m\n\n";
                break;
            }

        default :
            {
                system("cls");
                cout<<"\033[1;37m\t\t\t Please select from the option above \n"<<endl;
                menu();
                break;
            }


    }
	
}


void login()
{
    int count;
    string userId, password, id,pass;
    system("cls");
    cout<<"\033[1;30m\n\n\n\t\t\t Please enter the user name and password :"<<endl;
    cout<<"\033[1;37m\n\n\n\t\t\t USERNAME: ";
    cin>>userId;
    cout<<"\033[1;37m\n\t\t\t PASSWORD: ";
    cin>>password;

    ifstream f1("record.text");
    while(f1>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }

    }
    f1.close();

    if(count==1)
    {
        cout<<userId<<"\033[1;32m\n Your login is successful \n Thanks for logging in !\n";
        cout<<"\033[1;31m\n\n                     --------Quote of the Day------";
        cout<<"\033[1;36m\n\n\n Nobody will tell you why discipline is so important .\n Discipline is the strongest form of Self-love.\n It is ignoring current pleasure for bigger rewards to come. \n It is loving yourself enough to give yourself everything you have ever wanted.";
        repeat();
	//	main();
    }
    else
    {
        int choose;
      cout<<"\033[1;30m\n LOGIN ERROR \n PLESE CHECK YOUR USERNAME and PASSWORD \n";
     // main();
      cout<<"\033[1;37mEnter you choice\n\n";
      cout<<"\033[1;30m1. do you want to try again "<<endl;
      cout<<"\033[1;30m2. go to main menu\n\n";
       cout<<"\033[1;37mEnter you choice";
       cin>>choose;
      switch(choose)
      {
        case 1:
        {
            system("cls");
            login();
        }

        case 2:
        {
            system("cls");
            menu();
        }

        default:
        { 
            system("cls");
		    cout<<"\033[1;31m\n\n\n \t\t\t you have enter invalid choice...\n\n Returning to the main menu\n";
            menu();
        }
      }

    }
}

void registration()
{
    string ruserid, rpassword,rid,rpass;
    system("cls");
    cout<<"\033[1;36m\t\t\t Enter the Username :";
    cin>>ruserid;
    cout<<" \033[1;36m\t\t\t Enter the password :";
    cin>>rpassword;

    ofstream output("record.text", ios::app);

    output<<ruserid<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\033[1;33m \t\t\t The REGISTRATION has been successful \n";
    repeat();
    
   
}

void forgot()
{
    int option;
    system("cls");
    cout<<"\033[1;31m \n\n\n\n \t\t\t You forgot your Password? No worries \n\n\n";
    cout<<"\033[1;30m Press 1 to search you id by username \n"<<endl;
    cout<<"\033[1;30m Press 2 to go back to the main menu\n"<<endl;
    cout<<"\033[1;33m \t\t\t Enter you choice :";
    cin>>option;

    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserId,sId,spass;
            cout<<"\033[1;37m Enter the user name which you rememebered :";
            cin>>suserId;

            ifstream f2("record.text");
            while(f2>>sId>>spass)
            {
                if(sId==suserId)
                {
                    count=1;
                }
            }
            f2.close();
            if(count==1)
            {
                cout<<"\033[1;32m\n\n your account is found! \n";
                cout<<"\033[1;32m\n\n your password is :"<<spass;
               repeat();
            }
            else
            {
                cout<<"\033[1;31m\n\t Sorry! your account is not found! \n ";
                int choice;
                cout<<"\033[1;30m1. do you want to try again\n";
                cout<<"\033[1;30m 2. Return to th main menu\n\n";
                cout<<"\033[1;37m Enter your choice: ";
                cin>>choice;
                switch(choice)
                {
                	case 1:
                		{
                			system("cls");
                			forgot();
						}
					case 2:
						{
							system("cls");
							menu();
						}
					default:
					{
						system("cls");
						menu();
						
					 } 
				}
            
            }
            break;

        }

        case 2:
        {
            menu();
        }

        default :
        	  system("cls");
             cout<<"\033[1;31m \t\t\t Wrong Choice !Please try again \n "<<endl;
             forgot();
            break;

    }
}
void repeat()
{
	int choice;
        
        cout<<"\033[1;30m\n\n 1. Do you wish  to exit \n";
        cout<<"\033[1;30m 2. Return to main menu";
        cout<<"\033[1;30m\n\n\n Enter the choice (1/2): ";
        cin>>choice;
        switch(choice)
        {
        	case 1:
        		{
        			system("cls");
        			cout<<"\033[1;33m Thank you for using the program ";
        			break;
				}
				
			case 2:
			   {
			   	system("cls");
				menu();
                break;
				}
			default:
					{
						system("cls");
						menu();
                        break;
						}
}
}
						
