#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>

int xmax,ymax,i=0,ch,para,j,jump=0,k=0,score=0;
int rectx,jumpline,obsline; //for jump logic
int jumpx1=1000,jumpx2;
int str[100];

void startpage()
{
   cleardevice();
   settextstyle(8,0,2);
   outtextxy(10,20,"1.Name : Kedar Kharde   , Roll No : 29");
   outtextxy(10,60,"2.Name : Parthesh Pawar , Roll No : 47");
   settextstyle(8,0,5);
   outtextxy(250,(ymax/2),"ROAD DASH");
   line(0,(ymax/2)+60,xmax,(ymax/2)+60);

   /*TYRE*/
   setfillstyle(SOLID_FILL,RED);
   circle(30,(ymax/2)-i+40,20);
   circle(90,(ymax/2)+40-i,20);
   floodfill(30,(ymax/2)-i+40,WHITE);
   floodfill(90,(ymax/2)-i+40,WHITE);

   /*CAR BODY*/
   setfillstyle(SOLID_FILL,YELLOW);
   rectangle(0,ymax/2-i,120,(ymax/2)+20-i);
   floodfill(5,(ymax/2)+5,WHITE);

   /*WINDOWS*/
   setfillstyle(SOLID_FILL,GREEN);
   line(60,ymax/2-i,60,(ymax/2)-30-i);
   line(20,(ymax/2)-30-i,100,(ymax/2)-30-i);
   line(20,(ymax/2)-30-i,0,ymax/2-i);
   line(100,(ymax/2)-30-i,120,ymax/2-i);
   floodfill(30,(ymax/2)-5,WHITE);
   floodfill(75,(ymax/2)-15,WHITE);

   delay(5000);
   cleardevice();

}

int car()
{
  settextstyle(0,0,2);
  for(j=0;j<xmax;j++)
  {
     if(kbhit())
     {
	  ch=getch();
	  if(ch==' ')
	  {
	   jump=1;
	  }
     else if(ch=='x')
	  {
	  return 2;
	  }
     }

      outtextxy(0,30,"Enter X to Quit");
      outtextxy(0,50,"Enter space to Jump");
      sprintf(str,"Score: %d",score);
      outtextxy(0,70,str);
      rectx=xmax-200-j;  // x coordinate of obstacle
      line(0,(ymax/2)+60,xmax,(ymax/2)+60);  //Road
      /*OBSTACLE*/
      setfillstyle(SOLID_FILL,BROWN);
      rectangle(rectx,(ymax/2)+40,(xmax-200)+30-j,(ymax/2)+60);
      floodfill(rectx+10,(ymax/2)+50,WHITE);

      obsline=(ymax/2)+40;  //comparing for jump, top side of obstacle

     if(jump==1)
     {
      i=60;   //Jump by translating in Y direction
     }
     else
     {
      i=0;
     }

     jumpline=(ymax/2)+60-i; //comparing to obsline for successful jump

     if(rectx>=120 && rectx<=130) //if jump when obstacle is in given range its successfull jump
     {
	if(rectx==120 && jumpline>obsline)   //For unsuccessful jump
	{
	  return 3;
	}

	if(jumpline<obsline)      //For successful jump
	{
	     while(rectx!=10)     //Till obstacle is overcome
	     {
		  if(rectx==15)   //score increment as obstacle is overcame
		  {
		    k=0;
		    score++;
		    i=0;
		    return 0;
		  }
	    //getting x-coordinates before jump
	    jumpx1=xmax-200-j;
	    jumpx2=(xmax-200)+30-j; // only x coordinate of obstacle changes when jump

	      line(0,(ymax/2)+60,xmax,(ymax/2)+60); //Road
	       /*TYRE*/
	       setfillstyle(SOLID_FILL,RED);
	       circle(30,(ymax/2)-i+40,20);
	       circle(90,(ymax/2)+40-i,20);

	       floodfill(30,(ymax/2)-20,WHITE);
	       floodfill(90,(ymax/2)-20,WHITE);
	      /*CAR BODY*/
	      setfillstyle(SOLID_FILL,YELLOW);
	      rectangle(0,ymax/2-i,120,(ymax/2)+20-i);

	      floodfill(5,(ymax/2)-i+15,WHITE);
	     /*WINDOWS*/
	     setfillstyle(SOLID_FILL,GREEN);
	     line(60,ymax/2-i,60,(ymax/2)-30-i);
	     line(20,(ymax/2)-30-i,100,(ymax/2)-30-i);
	     line(20,(ymax/2)-30-i,0,ymax/2-i);
	     line(100,(ymax/2)-30-i,120,ymax/2-i);

	     floodfill(30,(ymax/2)-70,WHITE);
	     floodfill(75,(ymax/2)-70,WHITE);
	     /*OBSTACLE*/
	     setfillstyle(SOLID_FILL,BROWN);
	     rectangle(jumpx1-k,(ymax/2)+40,jumpx2-k,(ymax/2)+60);

	     floodfill(rectx+10,(ymax/2)+50,WHITE);
	     /*text*/
	     outtextxy(0,30,"Enter X to Quit");
	     outtextxy(0,50,"Enter space to Jump");
	     sprintf(str,"Score: %d",score);
	     outtextxy(0,70,str);
	     k++;
	     rectx--;      //continued after successful jump
	     delay(10);
	     cleardevice();
	   }

	}
    }
	      /*TYRE*/
	       setfillstyle(SOLID_FILL,RED);
	       circle(30,(ymax/2)-i+40,20);
	       circle(90,(ymax/2)+40-i,20);
	      if(i==60)  //If jump then filling coordinates also changes
	      {
		  floodfill(30,(ymax/2)-20,WHITE);
		  floodfill(90,(ymax/2)-20,WHITE);
	      }
	      else
	      {
		 floodfill(30,(ymax/2)-i+40,WHITE);
		 floodfill(90,(ymax/2)-i+40,WHITE);
	      }

	      /*CAR BODY*/
	      setfillstyle(SOLID_FILL,YELLOW);
	      rectangle(0,ymax/2-i,120,(ymax/2)+20-i);
	      if(i==60)
	      {
		floodfill(5,(ymax/2)-i+15,WHITE);
	      }
	      else
	      {
		 floodfill(5,(ymax/2)+5,WHITE);
	      }

	     /*WINDOWS*/
	     setfillstyle(SOLID_FILL,GREEN);
	     line(60,ymax/2-i,60,(ymax/2)-30-i);
	     line(20,(ymax/2)-30-i,100,(ymax/2)-30-i);

	     line(20,(ymax/2)-30-i,0,ymax/2-i);
	     line(100,(ymax/2)-30-i,120,ymax/2-i);
	     if(i==60)
	     {
	     floodfill(30,(ymax/2)-70,WHITE);
	     floodfill(75,(ymax/2)-70,WHITE);
	     }
	     else
	     {
	      floodfill(30,(ymax/2)-5,WHITE);
	      floodfill(75,(ymax/2)-15,WHITE);
	     }

	    if(i==60)  //Resetting jumpline , jump and i
	    {
		jumpline=(ymax/2)+40;
		i=0;
		jump=0;
	    }

	   delay(25);
	   cleardevice();
  }
	  return 0;   //returns 0 so countinue in while loop
}

void main()
{

/* request auto detection*/
 int gdriver= DETECT , gmode , errorcode;

 /* intialize local variables and graphics*/
 initgraph(&gdriver , &gmode ,"C:\\TURBOC3\\BGI");
 /* read result of intialization*/
 errorcode=graphresult();

 /* an error has occured*/
 if(errorcode!=grOk)
 {printf("Graphics error: %s",grapherrormsg(errorcode));
  printf("Enter any key to halt:");
  getch();
  exit(1);
 }

  xmax=getmaxx();
  ymax=getmaxy();
  startpage();  //starting page

 while(1)
 {
      para=car();
      if(para==2) //Quit page
      {
      settextstyle(8,0,5);
      setcolor(YELLOW);
      outtextxy(300,200,"End");
      delay(1000);
      cleardevice();
      break;
      }

      else if(para==3) //Game over page
      {
      cleardevice();
      settextstyle(8,0,2);
      setcolor(RED);
      outtextxy(290,200,"GAME OVER");
      setcolor(YELLOW);
      outtextxy(300,250,str);
      delay(10000);
      cleardevice();
      break;
      }
 }
 closegraph();
}
