/*TODO; complete lv 2,
text; walls on lv 2, levers, all elv but lv 0*/



/*There is a large marble plinth directly in front of me,
on its flat top is a large grey stone disk resembling a valve,
with indentations that appear as handholds along the edge.
On the corner of the plinth is a curved arrow clearly indicating circular motion.
  Should I turn the wheel?

The disk spins slowly at first then picks up speed,
after a short span of time,
the plinth beneath it dissolves into the surrounding mist
and the disk becomes a falling saucer as it plumets to the ground. */
 
 
 
 #include "gamefunct.h"

// make shure to compile with -lm (to include the math library)!!!


char map0[9][9] =
 {"+-------+",  //0 //2d array defines char[y][x]??
  "|       |",  //1
  "|     E |",  //2
  "|       |",  //3
  "|       |",  //4
  "|       |",  //5
  "|       |",  //6
  "|       |",  //7
  "+-------+"}; //8
// 012345678
char map1[15][9] =
 {"+-------+", //It's true 2d aray is defined char[y][x]!!
  "|       |",
  "|   *   |",
  "|       |",
  "| *   * |",
  "|       |",
  "|   *   |",
  "|       |",
  "|+-+ +-+|",
  " | | | | ",
  " +-+ +-+ ",
  "  |   |  ",
  "  | E |  ",
  "  |   |  ",
  "  +---+  "};

char map2[19][19] =
 {"       +---+       ",
  "       |   |       ",
  "       | E |       ",
  "       |   |       ",
  "       |+-+|       ",
  "     +-+|X|+-+     ",
  "     |  +-+  |     ",
  "+----+       +----+",
  "|   +-+  E  +-+   |",
  "| E |X|     |X| E |",
  "|   +-+     +-+   |",
  "+----+   L   +----+",
  "     |  +-+  |     ",
  "     +-+|X|+-+     ",
  "       |+-+|       ",
  "       |   |       ",
  "       | E |       ",
  "       |   |       ",
  "       +---+       "};


int main(void)
{
printf(	
   "\n   I am now awake,\n"
   "I know this because when my eyes where closed "
   "I saw nothing but black darkness,\n"
   "and now that my eyes are open I see nothing...\n"
   "...but white fog.\n\n"

   "   I get up,\n"
   "I feel sturdy ground beneath my feet,\n"
   "but an infernal abyss inside my mind.\n");
   while(loop==1)
   {
      
      if(z == 0)
      {
         /*-input,cls&roommsg-*/
         
         takeinp();
         int i; for(i=0; i != 60; i++) printf("\n"); // clear screen
         rmsg("type w a s or d to move.\n");
         
         /*-walls&objects-*/
         
         room(0,8,0,8,
         "   I see a great white wall forever rising to infinity...\n"
         "...How bland.");
         
         elev(6,2,4,13,1,
         "   An elegant glass box materializes out of the mist,\n"
         "it has a height twice its length and width,\n"
         ">>I wonder if I should go inside, Yes or No : ",
         "I decide not to enter the box.");
         
         /*switches&effects*/
         
         lvr(0,2,6,"I have found a lever. Do I pull it? ",
         "",
         "I have already pulled this lever.");
         
         /*-map&coordinates-*/
         
         showmap(9,9,2,map0);
         printf("%i,%i,%i\n",x,y,z);
      
      }
      if(z == 1)
      {
         /*-input,cls&roommsg-*/
         
         takeinp();
         int i; for(i=0; i != 60; i++) printf("\n"); // clear screen
         rmsg(
         "   I step into the elevator and the machine begins to hum\n" 
         "as the doors close behind me.\n"
         "I notice the elevator has no buttons inside as it starts to move.\n"
         "The elevator continues for a time.\n\n"

         "   The doors open with a hiss.\n"
         "I step outside and look at the space where I have been deposited,\n"
         "The white mist is still there, but I can see the ceiling now.\n" 
         "There is a three dimensional network of pipes on the aforementioned ceiling.\n");
         
         /*-walls&objects-*/

         char wall[] =
         {"   I see a network of pipes barring my way in that direction,\n"
          "some of the tubes rising to the ceiling are warm "
          "and others are very cold."};
         char pillar[] =
         {"   There is an unstable pillar before me.\n"
          "It reminds me of the foundation to all logic and reason."};
         
         block(2,2,11,14,wall);
         block(6,6,11,14,wall);
         block(3,5,14,14,wall);
         block(1,3,8, 10,"you hit a tube");
         block(5,7,8, 10,"you hit a tube");
         block(0,0,0, 8 ,wall);
         block(8,8,0, 8 ,wall);
         block(0,8,0, 0 ,wall);
         block(4,4,6, 6 ,pillar);
         block(6,6,4, 4 ,pillar);
         block(4,4,2, 2 ,pillar);
         block(2,2,4, 4 ,pillar);
         
         elev(4,12,6,3,0,"I see an elevator, enter? ","I don\'t enter.");

         /*switches&effects*/
         
         if(sw[0])
         {
	        map1[4][4]='E';elev(4,4,9,9,2,
            "I see an elevator, enter? ",
            "I don\'t enter.");
         }
         else 
         {
		    msg(4,4,4,4,
            "   My foot scrapes against a rough spot on the ground,\n"
            "I look down and see a complex geometric design,\n"
            "surrounded by an inscription:\n\n"
         
            "      2,6,0");
         }

         /*-map&coordinates-*/

         showmap(15,9,2,map1);
         printf("%i,%i,%i\n",x,y,z);
      
      }
      if( z== 2)
      {
	      /*-input,cls&roommsg-*/
	      takeinp();
         int i; for(i=0; i != 60; i++) printf("\n"); // clear screen
         rmsg(
         "A voice echoes throught the room;\n\n"

         "\"Welcome to the Infinite Cube,\n"
         "The Cube is a prototype in alternate-reality technology.\n"
		 "You may ask how we know this space is a cube if it is, as has been previously stated, infinite.\n"
		 "Don\'t.\n\n"
         "It consists of several levels,\n"
         "designed to test your mental abilities,\n"
         "which are being enhanced by experiments in the real world.\n"
         "You are perfectly safe...\n\n" 
         "... as far as we know.\"");
         
         /*-walls&objects-*/
         char cube[]=
         {"   You see a large cube.\n"
          "It is inscribed with strange symbols.\n"
          "They seem to indicate the turning of a lever...\n"
          "...this is giving me second thoughts about turning that lever."};
                  
         block(4 ,6 ,8 ,10,cube);
         block(8 ,10,4 ,6 ,cube);
         block(12,14,8 ,10,cube);
         
         char wall[]=
         {""};
         
         block(7 ,11,0 ,0, wall);
         block(5 ,7 ,0 ,5 ,wall);
         block(0 ,5, 5, 7 ,wall);
         block(0 ,0 ,7 ,11,wall);
         block(0 ,5 ,11,13,wall);
         block(5 ,7 ,13,18,wall);
         block(7 ,11,18,18,wall);
         block(11,13,13,18,wall);
         block(13,18,11,13,wall);
         block(18,18,7 ,11,wall);
         block(13,19,5 ,7 ,wall);
         block(11,13,0 ,5 ,wall);

         //...cont. in book
         
         /*switches&effects*/
         lvr(1,9,11,"I see a lever, do I pull it? ",
         "",
         "I already pulled the lever");
         
         if(sw[1])
         {
	        map2[13][9]=' ';
	        msg(8 ,10,12,14,
	        "I see the cube around me,\n"
	        "but I can't touch it.");
		 }
         else
         {block(8 ,10,12,14,cube);}
         
         /*-map&coordinates-*/
         showmap(19,19,4,map2);
         printf("%i,%i,%i\n",x,y,z);
         
	  }
   
   
   }
  return 0 ;
}

 /*-input,cls&roommsg-*/
 /*-walls&objects-*/
 /*switches&effects*/
 /*-map&coordinates-*/
