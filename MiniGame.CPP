


#include<stdio.h>
#include<conio.h>
  void drawRectangle()
    {
       int line , num ;
       for(line=1;line<=26;line++)
         {
            for(num=1;num<=95;num++)
               {
                 if(line==1||line==26)
                  printf("-");
                 else if(num==1||num==95)
                  printf("|");
                 else
                  printf(" ");

               }
             printf("\n");
         }

      gotoxy(65,26);
      printf("[ Developed By : shivam ]");
    }
  int pats(int mat[3][3])
    {
        int status=0;

        int rows,cols;
        drawRectangle();

        textcolor(GREEN);
        gotoxy(29,4);
        cprintf("TIC TAC TOE GAME");



        gotoxy(30,9);printf("%c",mat[0][0]);
        gotoxy(36,9);printf("%c",mat[0][1]);
        gotoxy(42,9);printf("%c",mat[0][2]);

        gotoxy(30,11);printf("%c",mat[1][0]);
        gotoxy(36,11);printf("%c",mat[1][1]);
        gotoxy(42,11);printf("%c",mat[1][2]);

        gotoxy(30,13);printf("%c",mat[2][0]);
        gotoxy(36,13);printf("%c",mat[2][1]);
        gotoxy(42,13);printf("%c",mat[2][2]);


        for(cols=25;cols<=47;cols++)
           {
             gotoxy(cols,10);printf("-");
             gotoxy(cols,12);printf("-");
           }

        for(rows=7;rows<=15;rows++)
           {
             gotoxy(33,rows); printf("|");
             gotoxy(39,rows); printf("|");

           }

      // Winning Condition For Player 1
      // Horizontal
       if( mat[0][0]==mat[0][1] && mat[0][1]==mat[0][2] && mat[0][2]==88 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 1 Won The Match ! ");
            getch();
            status=1;
          }
       if( mat[1][0]==mat[1][1] && mat[1][1]==mat[1][2] && mat[1][2]==88 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 1 Won The Match ! ");
            getch();
            status=1;
          }
       if( mat[2][0]==mat[2][1] && mat[2][1]==mat[2][2] && mat[2][2]==88 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 1 Won The Match ! ");
            getch();
            status=1;
          }

      // Vertical Condition
       if( mat[0][0]==mat[1][0] && mat[1][0]==mat[2][0] && mat[2][0]==88 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 1 Won The Match ! ");
            getch();
            status=1;
          }

       if( mat[0][1]==mat[1][1] && mat[1][1]==mat[2][1] && mat[2][1]==88 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 1 Won The Match ! ");
            getch();
            status=1;
          }
       if( mat[0][2]==mat[1][2] && mat[1][2]==mat[2][2] && mat[2][2]==88 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 1 Won The Match ! ");
            getch();
            status=1;
          }

      // Diagonal Condtion
       if( mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2] && mat[2][2]==88 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 1 Won The Match ! ");
            getch();
            status=1;
          }
       if( mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0] && mat[2][0]==88 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 1 Won The Match ! ");
            getch();
            status=1;
          }

      // Winning Condition For Player 2
      // Horizontal
       if( mat[0][0]==mat[0][1] && mat[0][1]==mat[0][2] && mat[0][2]==48 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 2 Won The Match ! ");
            getch();
            status=2;
          }
       if( mat[1][0]==mat[1][1] && mat[1][1]==mat[1][2] && mat[1][2]==48 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 2 Won The Match ! ");
            getch();
            status=2;
          }
       if( mat[2][0]==mat[2][1] && mat[2][1]==mat[2][2] && mat[2][2]==48 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 2 Won The Match ! ");
            getch();
            status=2;
          }

      // Vertical Condition
       if( mat[0][0]==mat[1][0] && mat[1][0]==mat[2][0] && mat[2][0]==48 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 2 Won The Match ! ");
            getch();
            status=2;
          }

       if( mat[0][1]==mat[1][1] && mat[1][1]==mat[2][1] && mat[2][1]==48 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 2 Won The Match ! ");
            getch();
            status=2;
          }
       if( mat[0][2]==mat[1][2] && mat[1][2]==mat[2][2] && mat[2][2]==48 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 2 Won The Match ! ");
            getch();
            status=2;
          }

      // Diagonal Condtion
       if( mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2] && mat[2][2]==48 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 2 Won The Match ! ");
            getch();
            status=2;
          }
       if( mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0] && mat[2][0]==48 )
          {
            clrscr();
            gotoxy(28,12);printf("Player 2 Won The Match ! ");
            getch();
            status=2;
          }

          return status;

    }

  void main()
    {
       int mat[3][3],rows,cols,val,status;
       int times,choice;
       int count;


       // Initialize The Value of Matrices
       val=49;
       for(rows=0;rows<3;rows++)
          {
            for(cols=0;cols<3;cols++)
              {
                 mat[rows][cols]=val;
                 val++;
              }
          }



     for(times=1;times<=5;times++)
       {
           // Code For Player 1

           Player1:
           clrscr();
           status=pats(mat);
           if(status==2)
             return;
           gotoxy(22,20);
           printf("Player 1 Enter Your Choice : ");
           scanf("%d",&choice);

           if(choice>=1 && choice<=9 )
             {    //  Begin of If
               count=0;

               for(rows=0;rows<3;rows++)
                 {
                   for(cols=0;cols<3;cols++)
                     {
                        if( mat[rows][cols]==(choice+48))
                          {
                             mat[rows][cols]=88;
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
                gotoxy(30,12);
                printf("Already Taken ! ");
                getch();
                goto Player1;
                }

             } //End of If
           else
             {
                clrscr();
                gotoxy(30,12);
                printf("Invalid Choice ");
                getch();
                goto Player1;
             }


           // Code For Player 2

           Player2:
           clrscr();
           status=pats(mat);
           if(status==1)
              return;

           if(status==0 && times==5)
             {
                 clrscr();
                gotoxy(30,12);
                printf("Match Tie ! ");
                getch();
                return;

             }

           gotoxy(22,20);
           printf("Player 2 Enter Your Choice : ");
           scanf("%d",&choice);

           if(choice>=1 && choice<=9 )
             {
               count=0;

               for(rows=0;rows<3;rows++)
                 {
                   for(cols=0;cols<3;cols++)
                     {
                        if( mat[rows][cols]==(choice+48))
                          {
                             mat[rows][cols]=48;
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
                gotoxy(30,12);
                printf("Already Taken ! ");
                getch();
                goto Player2;
                }

             }
           else
             {
                clrscr();
                gotoxy(30,12);
                printf("Invalid Choice ");
                getch();
                goto Player2;
             }


       } // End of For Loop - Times


    }



