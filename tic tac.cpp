#include<iostream.h>
#include<conio.h>
#include<stdio.h>
   int tictac(int mats[3][3])
   { int rows,cols,status=0;
        gotoxy(30,6);
        textcolor(GREEN);
        cprintf("TIC TAC TOE GAME");

       gotoxy(35,9);cout<<(char)mats[0][0];
       gotoxy(40,9);cout<<(char)mats[0][1];
       gotoxy(45,9);cout<<(char)mats[0][2];

       gotoxy(35,11);cout<<(char)mats[1][0];
       gotoxy(40,11);cout<<(char)mats[1][1];
       gotoxy(45,11);cout<<(char)mats[1][2];

       gotoxy(35,13);cout<<(char)mats[2][0];
       gotoxy(40,13);cout<<(char)mats[2][1];
       gotoxy(45,13);cout<<(char)mats[2][2];

   for(rows=7;rows<=15;rows++)
      {
        gotoxy(37,rows);cout<<"|";
        gotoxy(43,rows);cout<<"|";
      }

  for(cols=33;cols<=47;cols++)
  {
     gotoxy(cols,10);cout<<"-";
     gotoxy(cols,12);cout<<"-";
  }
 //code player1
 if(mats[0][0]==mats[0][1] && mats[0][1]==mats[0][2] && mats[0][2]==88)
    {clrscr();
     gotoxy(50,15);
     cout<<"player1 won the match";
     getch();
     status=1;
    }

if(mats[1][0]==mats[1][1] && mats[1][1]==mats[1][2] && mats[1][2]==88)
    {clrscr();
     gotoxy(50,15);
     cout<<"player1 won the match";
     getch();
     status=1;

    }

if(mats[2][0]==mats[2][1] && mats[2][1]==mats[2][2] && mats[2][2]==88)
    {clrscr();
     gotoxy(50,15);
     cout<<"player1 won the match";
     getch();
     status=1;

    }



if(mats[0][0]==mats[1][0] && mats[1][0]==mats[2][0] && mats[2][0]==88)
    {clrscr();
     gotoxy(50,15);
     cout<<"player1 won the match";
     getch();
     status=1;

    }

    if(mats[0][1]==mats[1][1] && mats[1][1]==mats[2][1] && mats[2][1]==88)
    {clrscr();
     gotoxy(50,15);
     cout<<"player1 won the match";
     getch();
     status=1;

    }

    if(mats[0][2]==mats[1][2] && mats[1][2]==mats[2][2] && mats[2][2]==88)
    {clrscr();
     gotoxy(50,15);
     cout<<"player1 won the match";
     getch();
     status=1;

    }


     if(mats[0][0]==mats[1][1] && mats[1][1]==mats[2][2] && mats[2][2]==88)
    {clrscr();
     gotoxy(50,15);
     cout<<"player1 won the match";
     getch();
     status=1;

    }

    if(mats[0][2]==mats[1][1] && mats[1][1]==mats[2][0] && mats[2][0]==88)
    {clrscr();
     gotoxy(50,15);
     cout<<"player1 won the match";
     getch();
     status=1;

    }

//code of player2

if(mats[0][0]==mats[0][1] && mats[0][1]==mats[0][2] && mats[0][2]==48)
    {clrscr();
     gotoxy(50,15);
     cout<<"player2 won the match";
     getch();
     status=2;
    }

if(mats[1][0]==mats[1][1] && mats[1][1]==mats[1][2] && mats[1][2]==48)
    {clrscr();
     gotoxy(50,15);
     cout<<"player2 won the match";
     getch();
     status=2;

    }

if(mats[2][0]==mats[2][1] && mats[2][1]==mats[2][2] && mats[2][2]==48)
    {clrscr();
     gotoxy(50,15);
     cout<<"player2 won the match";
     getch();
     status=2;

    }


if(mats[0][0]==mats[1][0] && mats[1][0]==mats[2][0] && mats[2][0]==48)
    {clrscr();
     gotoxy(50,15);
     cout<<"player2 won the match";
     getch();
     status=2;

    }

    if(mats[0][1]==mats[1][1] && mats[1][1]==mats[2][1] && mats[2][1]==48)
    {clrscr();
     gotoxy(50,15);
     cout<<"player2 won the match";
     getch();
     status=2;

    }

    if(mats[0][2]==mats[1][2] && mats[1][2]==mats[2][2] && mats[2][2]==48)
    {clrscr();
     gotoxy(50,15);
     cout<<"player2 won the match";
     getch();
     status=2;

    }


 if(mats[0][0]==mats[1][1] && mats[1][1]==mats[2][2] && mats[2][2]==48)
    {clrscr();
     gotoxy(50,15);
     cout<<"player2 won the match";
     getch();
     status=2;

    }

    if(mats[0][2]==mats[1][1] && mats[1][1]==mats[2][0] && mats[2][0]==48)
    {clrscr();
     gotoxy(50,15);
     cout<<"player2 won the match";
     getch();
     status=2;
     }
     return status;
     }
   void main()
   {
     int mats[3][3],rows,cols,choice,count,val,times,status;
     val=49;
    for(rows=0;rows<3;rows++)
    {for(cols=0;cols<3;cols++)
      {mats[rows][cols]=val;
      val++;
       }
    }

    for(times=1;times<=5;times++)
    {player1:
     clrscr();
     status=tictac(mats);
     if(status==2)
       return;
       gotoxy(50,17);
     cout<<"enter your choice:";
     cin>>choice;

       if(choice>=1 && choice<=9)
          {
            count=0;
            for (rows=0;rows<3;rows++)
             {
               for(cols=0;cols<3;cols++)
                {
                  if (mats[rows][cols]==(choice+48))
                   {
                     mats[rows][cols]=88;
                   }
                   else
                   {
                   count++;
                   }
                }
             }
            if(count==9)
             {
              clrscr();
              gotoxy(50,12);
              cout<<"already taken!";
              getch();
              goto player1;
              }

          }

          else
           {
             clrscr();
             gotoxy(50,12);
              cout<<"invalid choice!";
              getch();
              goto player1;
           }


           //code for player 2
       player2:
         clrscr();
         status=tictac(mats);
         if(status==1)
          return;

         if(status==0 && times==5)
          {
           clrscr();
           gotoxy(50,12);
           cout<<"match tie";
           getch();
           return;
          }
         gotoxy(50,17);
         cout<<" enter your choice : ";
         cin>>choice;

         if(choice>=1 && choice<=9)
          {
            count=0;
            for (rows=0;rows<3;rows++)
             {
               for(cols=0;cols<3;cols++)
                {
                  if (mats[rows][cols]==(choice+48))
                   {
                     mats[rows][cols]=48;
                   }
                   else
                   {
                   count++;
                   }
                }
             }
            if(count==9)
             {
              clrscr();
              gotoxy(50,12);
              cout<<"already taken";
              getch();
              goto player2;
              }

          }

          else
           {
             clrscr();
             gotoxy(50,12);

             cout<<"invalid choice";
             getch();
             goto player2;
           }

       }

     getch();
   }






