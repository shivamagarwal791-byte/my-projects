#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>

int readLastData();

 struct Bank
   {
     char name[25];
     char address[35];
     char phoneNo[15];
     int accountNo;
     int balance;

    }det,det2;

  void appendData()
     {
        textcolor(RED);
        cprintf("Enter account Holder name : ");
        Bank det1;
        gets(det1.name);
        Labu:
          cout<<"Phone No   : ";
          cin>>det1.phoneNo;

            if(strlen(det1.phoneNo)!=10)
              {
                clrscr();
               cout<<"Enter account Holder name : "<<det1.name<<endl;

                goto Labu;
              }

          char ans;
          cout<<"Do you want to Add Roll No Y/N : ";
          cin>>ans;

           if(ans=='n'||ans=='N')
            {
             int temp = readLastData();
             det1.accountNo=(temp+1);
             cout<<"Account number : "<<det1.accountNo<<endl;
            }
           else
            {
             cout<<"Enter The Account No : ";
             cin>>det1.accountNo;
            }

        cout<<"Enter balance : ";
        cin>>det1.balance;

          ofstream outfile;  //app
          outfile.open("d://MyFiles//Bankdata.dat",ios::app|ios::binary);
          if(!outfile)
           {
             cout<<"File not Created! ";
             getch();
             return;
           }

        outfile.write( (char*)&det1,sizeof(det1) );
        outfile.close();
      }


  void readData()
    {
       ifstream inFile;
       inFile.open("d://MyFiles//Bankdata.dat",ios::in|ios::binary);
       if( !inFile )
         {
            cout<<"File Not Found ! "<<endl;
            getch();
            return;
         }

        gotoxy(5,2);cout<<"Name";
       //gotoxy(20,2);cout<<"Address";
       gotoxy(20,2);cout<<"Phone No ";
       gotoxy(35,2);cout<<"Account No ";
       gotoxy(50,2);cout<<"Balance";

        int rows=3;
       while ( inFile.read((char*)&det,sizeof(det)) )
          {
        gotoxy(5,rows);cout<<det.name;
       //gotoxy(20,rows);cout<<det.address;
       gotoxy(20,rows);cout<<det.phoneNo;
       gotoxy(35,rows);cout<<det.accountNo;
       gotoxy(50,rows++);cout<<det.balance;
          }
       inFile.close();
    }


  int searchData(int accountNo)
    {
       ifstream inFile;
       inFile.open("d://MyFiles//Bankdata.dat",ios::in|ios::binary);
       if( !inFile )
         {
            cout<<"File Not Found ! "<<endl;
            getch();
            return 0;
         }

       int Loc=-1;

       while ( inFile.read((char*)&det,sizeof(det)) )
          {
            if( det.accountNo==accountNo)
              {
                 cout<<"Account Holder Details "<<endl;
                 cout<<"-----------------------------------"<<endl;
                 cout<<"Name       : "<<det.name<<endl;
                 cout<<"Phone No   : "<<det.phoneNo<<endl;
                 cout<<"Account No : "<<det.accountNo<<endl;
                 cout<<"Balance    : "<<det.balance<<endl;
                 cout<<"-----------------------------------"<<endl;

                 Loc=inFile.tellg();
                 break;
              }
          }

       inFile.close();

       return Loc;

    }


  void deposite(int accountNo)
    {

       int Loc=searchData(accountNo);

       int amt;

       if(Loc!=-1)
         {
           cout<<"Enter The Deposite Amount : ";
           cin>>amt;

           Loc = Loc-sizeof(det);



           ifstream inFile;
           inFile.open("d://MyFiles//BankData.dat",ios::in|ios::binary);
           inFile.seekg(Loc,ios::beg);
           inFile.read( (char*)&det,sizeof(det));
           inFile.close();

           det.balance=det.balance+amt;

           ofstream outFile;      //ate
           outFile.open("d://MyFiles//BankData.dat",ios::ate|ios::binary);
           outFile.seekp(Loc,ios::beg);
           outFile.write((char*)&det,sizeof(det));
           outFile.close();

         }
       else
         {
           cout<<"Not Found ! ";
         }
    }

  void withdraw(int accountNo)
    {
       int Loc=searchData(accountNo);
       int amt;

       if(Loc!=-1)
         {
            cout<<"Enter the Withdraw amount : ";
            cin>>amt;


       ifstream inFile;
       inFile.open("d://MyFiles//BankData.dat",ios::in|ios::binary);
       inFile.seekg(Loc-sizeof(det),ios::beg);
       inFile.read((char*)&det,sizeof(det));
       inFile.close();




        if(det.balance>=amt && det.balance>0)
         {
           det.balance=det.balance-amt;

           ofstream outFile; //ate
           outFile.open("d://MyFiles//BankData.dat",ios::ate|ios::binary);
           outFile.seekp(Loc-sizeof(det),ios::beg);
           outFile.write((char*)&det,sizeof(det));
           outFile.close();
         }

       else
        {
            cout<<"Insufficient Balance";
        }
       }

      else
        {
           cout<<"Invalid Input ! ";
        }
    }

  void closeAcc(int accountNo)
    {
      ifstream inFile;
      ofstream outFile;

      inFile.open("d://MyFiles//BankData.dat",ios::in|ios::binary);
      outFile.open("d://MyFiles//tempi.dat",ios::out|ios::binary);

      if(!inFile)
        {
          cout<<"File not Found! ";
          getch();
          return;
        }

      if(!outFile)
        {
          cout<<"File Not Created! ";
          getch();
          return;
        }

      int check=0;

      while(inFile.read((char*)&det,sizeof(det)))
        {
           if(accountNo==det.accountNo)
             {
               cout<<"Close Account "<<endl;
               cout<<"------------------------------------\n";
               cout<<"Account Holder Name : "<<det.name<<endl;
               cout<<"Closing Balance : "<<det.balance<<endl;
               cout<<"Account No : "<<det.accountNo<<endl;
               cout<<"------------------------------------"<<endl;
               check=1;
             }

           else
             {
               outFile.write((char*)&det,sizeof(det));
             }
        }

      inFile.close();
      outFile.close();

      if(check==1)
        {
           remove("d://MyFiles//BankData.dat");
           rename("d://MyFiles//tempi.dat","d://MyFiles//BankData.dat");

           cout<<"Bank Account Closed SuccessFully";
        }

      else
        {
          cout<<"Account not found ! ";
        }
    }



  void modifyAcc(int accountNo)
    {
      ifstream inFile;
      inFile.open("d://MyFiles//BankData.dat",ios::in|ios::binary);

      if(!inFile)
        {
           cout<<"File not Found";
           getch();
           return;
        }

      int check=0;
      int Loc=-1;

      while(inFile.read((char*)&det,sizeof(det)))
        {
          if(accountNo==det.accountNo)
            {
               cout<<"Update record \n";
               cout<<"---------------------------------------\n";
               cout<<"Name of account Holder : "<<det.name<<endl;
               cout<<"Phone No : "<<det.phoneNo<<endl;
               cout<<"Balance  : "<<det.balance<<endl;
               cout<<"Account No : "<<det.accountNo<<endl;
               cout<<"---------------------------------------\n";
               check=1;

               Loc=inFile.tellg();
               break;
            }
        }
      inFile.close();

      if(check==1)
        {
          int chc;
          textcolor(RED);
          cprintf("WHAT YOU WANT TO UPDATE");
          textcolor(WHITE);
          printf("\n");
          cprintf("-------------------------------------");
          printf("\n");
          textcolor(GREEN);
          cprintf("PRESS 1. FOR NAME");
          printf("\n");
          cprintf("PRESS 2. FOR PHONE NO");
          printf("\n");
          cprintf("PRESS 3. FOR ACCOUNT NO");
          printf("\n");
          cprintf("PRESS 4. FOR BALANCE");
          printf("\n");
          textcolor(WHITE);
          cprintf("-------------------------------------");
          printf("\n");

          cout<<"Enter your Choice : ";
          cin>>chc;

             cout<<endl;
             cout<<"Update Account Holder Details "<<endl;
             cout<<"--------------------------------------"<<endl;
             switch(chc)
              {
               case 1: cout<<"Name       : ";
                       gets(det.name); break;

               case 2: Labu:

                       cout<<"Phone No   : ";
                       cin>>det.phoneNo;

                       if(strlen(det.phoneNo)!=10)
                        {
                         clrscr();
                         cout<<"Enter account Holder name : "<<det.name<<endl;
                         goto Labu;
                        }

                        break;

               case 4:  cout<<"Enter balance : ";
                        cin>>det.balance;break;

               case 3:

                      Lab:
                        cout<<"Enter account number : ";
                        cin>>det.accountNo;

                        ifstream inFile;
                        inFile.open("d://MyFiles//Bankdata.dat",ios::in|ios::binary);

                        int check=0;
                        while( inFile.read((char*)&det2,sizeof(det2)) )
                         {
                           if( det.accountNo==det2.accountNo)
                           {
                          check=1;
                          break;
                           }

                         }

             inFile.close();

             if(check==1)
             {
                clrscr();
                cout<<"Enter account Holder name : "<<det.name<<endl;
                cout<<"Enter Phone number : "<<det.phoneNo<<endl;

                goto Lab;
             }



             }

            cout<<"--------------------------------------"<<endl;

          ofstream outFile;
          outFile.open("d://MyFiles//BankData.dat",ios::ate|ios::binary);
          if(!outFile)
           {
              cout<<"File not Created!";
              getch();
              return;
           }

             outFile.seekp(Loc-sizeof(det),ios::beg);

             outFile.write((char*)&det,sizeof(det));
             outFile.close();
             cout<<"Record Updated SuccessFully ! ";
        }
       else
        {
          cout<<"Record not Found !";
        }
    }

  int readLastData()
    {
      ifstream inFile;
      int LOC;
      inFile.open("d://MyFiles//BankData.dat",ios::in|ios::binary);
      while(inFile.read((char*)&det,sizeof(det)));
      LOC=inFile.tellg();
      inFile.close();

      inFile.open("d://MyFiles//BankData.dat",ios::in|ios::binary);
      inFile.seekg(LOC-sizeof(det));
      inFile.read((char*)&det,sizeof(det));
      inFile.close();
      //cout<<"AccountNo "<<det.accountNo<<endl;
      //cout<<"Location "<<LOC<<endl;

      if(LOC<=0)
       return 10000;
      else
       return det.accountNo;
    }

  void main()
    {

    int choice,accountNo;

      while(1)
       {
        clrscr();
        textcolor(WHITE);
        cprintf("====================================");
         textcolor(RED);
         printf("\n");
        cprintf("       BANK MANAGEMENT SYSTEM ");
         textcolor(WHITE);
         printf("\n");
        cprintf("====================================");
         textcolor(BLUE);
         printf("\n");
        cprintf("           ::MAIN MENU::            \n");
        cout<<"\n";
        textcolor(GREEN);
        cprintf("1. NEW ACCOUNT");
        printf("\n");
        cprintf("2. DEPOSIT AMOUNT");
        printf("\n");
        cprintf("3. WITHDRAW AMOUNT");
        printf("\n");
        cprintf("4. BALANCE ENQUIRY");
        printf("\n");
        cprintf("5. ALL ACCOUNT HOLDER LIST");
        printf("\n");
        cprintf("6. CLOSE AN ACCOUNT");
        printf("\n");
        cprintf("7. MODIFY AN ACCOUNT");
        printf("\n");
        cprintf("8. EXIT");
        printf("\n");
         textcolor(WHITE);
        cprintf("====================================");
        printf("\n");
        cout<<"Enter your Choice : ";
        cin>>choice;
        clrscr();
        switch(choice)
          {
             case 1: appendData();break;
             case 2:  cout<<"Enter The Account No : ";
                      cin>>accountNo;
                          deposite(accountNo);

                      cout<<endl<<endl;
                      searchData(accountNo);

                   break;

             case 3: cout<<"Enter The Account No : ";
                     cin>>accountNo;
                     withdraw(accountNo);

                      cout<<endl<<endl;
                      searchData(accountNo);

                   break;

             case 4: cout<<"Enter The Account No : ";
                      cin>>accountNo;
                     searchData(accountNo);break;
             case 5: readData();break;
             case 6: cout<<"Enter The Account No : ";
                      cin>>accountNo;
                     closeAcc(accountNo);
                     break;
             case 7: cout<<"Enter The Account No : ";
                      cin>>accountNo;
                     modifyAcc(accountNo);break;
             case 8: cout<<"Thank You ! "<<endl;
                     getch();
                     return;
          }

        getch();
        }
      }
