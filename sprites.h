#ifndef __SPRITES_H__
#define __SPRITES_H__

#include <stddef.h>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <math.h>

#include "graphics.h"
#include "transform.h"

extern BoundaryType worldBoundary,deviceBoundary;
extern char keyPressed[5];

enum Position {LEFT_SIDE, RIGHT_SIDE};

//class Robot; //forward declare
//class Obstacle;


class Robot{
	
	public:
	
      Robot(int sx = 50, int sy = 100, float a = 45.0f, float s = 1.5f){
      	x = sx; //sprite's x-coordinate 
         y = sy; //sprite's y-coordinate
         angle = a; //in degrees
         speed = s;
    
         length=7.5; //cm.
         width=7.5; //cm.
      }
         	
   	float getX();
	   
	   float getY();
	   void setAngle(float a);
   	float getAngle();
      float getLength();
      float getWidth();
      void setSpeed(float s);
      float getSpeed();
      void move();
      void draw(bool page);
   

	protected:
            float x, y;
            float length;
            float width;
            float angle;
            float realAngle;
            float speed;
};
////////////////////////////////////////////////////////////////////////////////////////////

class Ball{
	
	public:
	
      Ball(int sx = 50, int sy = 100, float a = 45.0f, float s = 1.5f){
      	x = sx; //sprite's x-coordinate 
         y = sy; //sprite's y-coordinate
         angle = a; //in degrees
         speed = s;
    
         radius=2.5; //cm.
         
      }
         	
   	float getX();
	   float getY();
		void setX(float xx);
		void setY(float yy);
	   void setAngle(float a);
   	float getAngle();
      float getRadius();
		void setRadius(float r);
      void setSpeed(float s);
      float getSpeed();
      void move(float robotX, float robotY, float robotAngle, float robotSpeed);
      void draw(bool page);
   

	protected:
            float x, y;
            float radius;
            float angle;
            float realAngle;
            float speed;
};


////////////////////////////////////////////////////////////////////////////////////////////

class Obstacle{
	
	public:
	

	   Obstacle(int sx=50, int sy=100, float a=45.0, float s=1.5){
   		x = sx; //sprite's x-coordinate 
         y = sy; //sprite's y-coordinate
         angle = a; //in degrees
         speed = s;
    
         length=7.5; //cm.
         width=7.5;  //cm.
   	}
   	
   	

     void initialise(int sx, int sy, float a, float s);
   		
      void setAngle(float a);
   	
   	float getX();
	   
	   float getY();
   	
   	float getAngle();
   
      void setSpeed(float s);
   	   
      
      float getSpeed();
      
      void move();
   
   
      void draw(bool page);
   

	   protected:
            float x, y;
            float length;
            float width;
            float angle;
            float speed;
            clock_t t;        
	
};


#endif
