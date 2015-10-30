#include <MeggyJrSimple.h>

int xdot=0; //player
int ydot=0;

int currentcolor; //color on board

void setup()
{
  MeggyJrSimpleSetup();
}

void loop ()
{
  ClearSlate();
  
  DrawScreen(); //draw path
  
  Song(); //play tones 
  
   if (ReadPx(xdot,ydot)==4) // goal
  {
    Note();
  }
  
  CheckButtonsDown();
  
  if (Button_Up)        
    ydot=ydot+1; //if up pressed, increase y coor by 1 

  if (Button_Down)       
    ydot=ydot-1; //down pressed, decrease y by 1 

  if (Button_Right)       
    xdot=xdot+1; //right pressed, increase x coor by 1 


  if (Button_Left)       
    xdot=xdot-1; //left pressed, decrease x by 
    
  currentcolor=ReadPx(xdot,ydot); //current color = color dot is on
  
  if(ReadPx(xdot,ydot)==0) //start from beginning
  {
    xdot=0;
    ydot=0;
  }
  
  DrawPx(xdot,ydot,7); //draw player
  
  DisplaySlate();
  delay(200);
}

void DrawScreen() //path drawing
{  
 DrawPx(1,1,1);
 DrawPx(2,1,7);
 DrawPx(3,1,1);
 DrawPx(4,1,8);
 DrawPx(5,1,7);
 DrawPx(6,1,8);
 DrawPx(6,2,10);
 DrawPx(6,3,7);
 DrawPx(5,3,10);
 DrawPx(4,3,8);
 DrawPx(3,3,6);
 DrawPx(2,3,7);
 DrawPx(1,3,6);
 DrawPx(1,4,5);
 DrawPx(1,5,7);
 DrawPx(1,6,5);
 DrawPx(2,6,3);
 DrawPx(3,6,7);
 DrawPx(4,6,3);
 DrawPx(4,5,1);
 DrawPx(5,5,4);
}

void Song() //scale matched with colors 
{
  if(currentcolor==1) //red=C
  {
    Tone_Start(ToneC4,500);
  }
  
  if(currentcolor==2) //orange=Cs
  {
    Tone_Start(ToneCs4,500);
  }
  
  if(currentcolor==3) //yellow=D
  {
    Tone_Start(ToneD4,500);
  }
  
  if(ReadPx(xdot,ydot)==13) //dimblue=Ds
  {
    Tone_Start(ToneDs4,500);
  }
  
  if(currentcolor==5) //blue=E
  {
    Tone_Start(ToneE4,500);
  }
  
  if(currentcolor==6) //violet=F
  {
    Tone_Start(ToneF4,500);
  }
  
  if(currentcolor==14) //dim violet=Fs
  {
    Tone_Start(ToneFs4,500);
  }
  
  if(currentcolor==8) //dim red=G
  {
    Tone_Start(ToneG4,500);
  }
  
  if(currentcolor==9) //dim orange=Gs
  {
    Tone_Start(ToneGs4,500);
  }
  
  if(currentcolor==10) //dimyellow=A
  {
    Tone_Start(ToneA4,500);
  }
  
  if(currentcolor==11) //dimgreen=As
  {
    Tone_Start(ToneAs4,500);
  }
  
  if(currentcolor==12) //dim aqua=B
  {
    Tone_Start(ToneB4,500);
  }
}

void Note() // goal image 
{   
    DrawPx(xdot,ydot,0); //ensure that player is not on screen while image appears 
  
    ClearSlate();  
  
    DrawPx(1,1,7); //image drawing
    DrawPx(2,1,7);
    DrawPx(3,1,7);
    DrawPx(1,2,7);
    DrawPx(1,3,7);
    DrawPx(2,2,7);
    DrawPx(2,3,7);
    DrawPx(3,2,7);
    DrawPx(3,3,7);
    DrawPx(3,4,7);
    DrawPx(3,5,7);
    DrawPx(3,6,7);
    DrawPx(3,7,7);
    DrawPx(4,6,7);
    DrawPx(5,5,7);
    
    DisplaySlate();
    delay(1000);
}

