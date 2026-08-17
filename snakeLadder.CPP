


#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

 void pats(int mats[10][10],int choice,int choice2)
  {
    int rows,cols;
    int r=5,c,z,p=5;
    int code=83,code2=88;

    for(rows=0;rows<10;rows++)
     {
       if(rows%2==0)
         c=15;
       else
         c=60;

     /*  if(rows%2==0)
         z=15;
       else
         z=60;  */

        for(cols=0;cols<10;cols++)
          {
             gotoxy(c,r);
             if(mats[rows][cols]==choice)
               {
                 gotoxy(c,r);
                 textcolor(RED);
                 cprintf("%c",code);
                // gotoxy(z,p);
                // textcolor(BLUE);
                // cprintf("%c",code2);
               }

              if(mats[rows][cols]==choice2)
               {
                 gotoxy(z,p);
                 textcolor(BLUE);
                 cprintf("%c",code2);
               }

             else
               {
                 cout<<mats[rows][cols];
               }
                if(rows%2==0)
                  c+=5;
                else
                  c-=5;
          }
         r+=2;
     }
          for(r=4;r<=24;r+=2)
            {
            for(c=12;c<=64;c++)
             {
               textcolor(WHITE);
               gotoxy(c,r);
               cprintf("-");
             }
         }

       for(c=13;c<=65;c=c+5)
        {
         for(r=4;r<25;r++)
          {
           gotoxy(c,r);
           textcolor(WHITE);
           cprintf("|");
          }
       }

  }

 void main()
  {
     int mats[10][10],rows,cols;
     int val=100,val2;

     for(rows=0;rows<10;rows++)
        {
          for(cols=0;cols<10;cols++)
            {
              mats[rows][cols]=val--;
            }
        }



         int choice=-1;
         int choice2=-1;

         randomize();

         while(1)
          {
            pats(mats,choice,choice2);
             cout<<endl;


             val=rand()%6+1;

             if(choice==-1)
                {
                  choice=val;
                }
              if(choice==7)
               {
                 gotoxy(23,22);
                 cprintf("%c",83);
                 choice=25;
               }
              if(choice==35)
               {
                 gotoxy(33,14);
                 cprintf("%c",83);
                 choice=67;
               }
               if(choice==20)
               {
                 gotoxy(63,12);
                 cprintf("%c",83);
                 choice=70;
               }
               if(choice==90)
               {
                 gotoxy(58,24);
                 cprintf("%c",83);
                 choice=9;
               }
               if(choice>=100)
                {
                  clrscr();
                  textcolor(RED);
                  gotoxy(35,15);
                  cprintf("YOU WON !");
                  getch();
                  return;
                }
             else
                {
                  choice=choice+val;
                }
                cout<<"Player 1 :"<<val<<endl;


                //player 2

             val2=rand()%6+1;

             if(choice2==-1)
                {
                  choice2=val2;
                }
              if(choice2==7)
               {
                 gotoxy(23,22);
                 cprintf("%c",88);
                 choice2=25;
               }
              if(choice2==35)
               {
                 gotoxy(33,14);
                 cprintf("%c",88);
                 choice2=67;
               }
               if(choice2==20)
               {
                 gotoxy(63,12);
                 cprintf("%c",88);
                 choice2=70;
               }
               if(choice2==90)
               {
                 gotoxy(58,24);
                 cprintf("%c",88);
                 choice2=9;
               }
               if(choice2>=100)
                {
                  clrscr();
                  textcolor(RED);
                  gotoxy(35,15);
                  cprintf("YOU WON !");
                  getch();
                  return;
                }
             else
                {
                  choice2=choice2+val2;
                }
                cout<<"\nPlayer 2 :"<<val2;



               getch();
               clrscr();
          }
  }


