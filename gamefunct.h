 #include <stdio.h> // input/output, duh!
 #include <termios.h> // for 'getch'.
 #include <unistd.h>
 #include <math.h> // for sqrt in showmap


char inp ;                                  //  //==||
int loop=1,                                //  //   ||
    x  = 4,                               //  //    \/
    y  = 4,                              //  //
    py = 4,                             //  //______
    px = 4,                            //   \______ global variable(s)
    z  = 0,                           //
showmsg= 1;
int sw[5]={0,0,0,0,0};

int getch(void) // code snippet from kermie3 @ cprogramming.com
{
  struct termios oldt,
                 newt;
  int            ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}
void takeinp(void)
{

     // scanf( "%s", &inp ) ;		/* scan input onto &inp */

      py=y;  //previous x and y
      px=x;

      inp = getch(); //scan input onto &inp

      if     ( inp == 'w' )--y;
      else if( inp == 'a' )--x;
      else if( inp == 's' )++y;
      else if( inp == 'd' )++x;
      else if( inp == 'Q' )loop = 0;
}
void showmap(int w, int h, int dis, char map[w][h]) 
// h,w/ x,y placements confuse me, best not meddled with ;)
// h should be w and visaversa
{
   int hp,wp; //variables to show position in map.

   for   (wp = 0; wp < w; wp++)
   {
   	  for(hp = 0; hp < h; hp++)
   	  {
   	     int rdis =(hp-x)*(hp-x) + (wp -y)*(wp-y);

   	     if(wp == y && hp==x){             //print the player pos.
   	     	printf("A ");}                //\_____________________
   	     else if( sqrt(rdis) <= dis){
   	        printf("%c ",map[wp][hp]);} //==\/--------------------
   	     else{
		    printf("  ");}
      }
      printf("\n");
   }
}
void block(int lx, int rx, int ty, int by, char msg[])
{
   if( x >= lx && x <= rx && y >= ty && y <= by )
   {y=py; x=px; printf("%s\n\a",msg);}
}
void room (int lx, int rx, int ty, int by, char msg[])
{
   if( x <= lx || x >= rx || y <= ty || y >= by )
   {y=py; x=px; printf("%s\n\a",msg);}
}
void msg  (int lx, int rx, int ty, int by, char msg[])
{
   if( x >= lx && x <= rx && y >= ty && y <= by )
   {printf("%s\n\a",msg);}
}
void rmsg(char msg[])
{
	if(showmsg==1)
	{printf("%s",msg); showmsg=0;}
}
void elev (int lx, int ly, int tx, int ty, int tz, char msg[], char msgn[])
{
   if( x == lx && y == ly )
   {
      printf("%s", msg  ) ;
      scanf ("%s", &inp ) ;		/* scan input onto &inp */

      if(inp == 'y')
      {y=ty ; x=tx ; z=tz ; showmsg=1; }
      else {printf("%s\n", msgn); x=px; y=py; takeinp();}
   }
}
void lvr(int s, int lx, int ly, char msg0[], char msgy[], char msg1[])
{
   if( x == lx && y == ly )
   {
	   if(sw[s])
       {printf("%s",msg1);}
       else
       {
	       printf("%s",msg0);
           scanf ("%s",&inp);
           if(inp=='y')
           {sw[s]=1;printf("\a%s", msgy);takeinp();}
           else
           {takeinp();}
       }
   }
}
