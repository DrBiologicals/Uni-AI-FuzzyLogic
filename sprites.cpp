#include "sprites.h"


///////////////////////////////////////////////////////////////

float Ball::getX(){
  	 return x;
}
	   
float Ball::getY(){
  	 return y;
}
	
void Ball::setX(float xx){
	x = xx;
}

void Ball::setY(float yy){
   y = yy;
}

void Ball::setAngle(float a){
    if((a >= 0.0f) && (a <= 360.0f)){
	     angle = a;
    }   
}	
   	
float Ball::getAngle(){
    return angle;
}
   
   
	   
float Ball::getRadius(){
	 return radius;
}

void Ball::setRadius(float r){
	 if(r > 0.0f){
	    radius = r;
		 
	 } else {
		 exit(1);
	 }
}

void Ball::setSpeed(float s){
    speed = s;
}   
	   

float Ball::getSpeed(){
    return speed;
}
      
void Ball::move(float robotX, float robotY, float robotAngle, float robotSpeed) {
   	
   float tempX, tempY;
  
  

  
   
   x = (x + (speed * cos(degToRad(angle))));
	y = (y + (speed * sin(degToRad(angle))));
	
	speed = speed * 0.999;
	 
	////////////////////////////////////////////////
	// Collision against the wall.
	//
	
	// Right-most wall
	 if(x > worldBoundary.x2-(radius)){
	   	 x = worldBoundary.x2 - radius; 
		 
		 if(angle > 270.0f && angle < 360.0f){
			angle = 180.0f + (360.0f - angle); 
		 } else {
			 angle = 180.0f - angle;
		 }
		 
		 speed = speed * 0.85f;
	}
	 // Left-most wall   
	 else if(x < worldBoundary.x1+(radius)){
	   	 x = worldBoundary.x1 + radius; 
		 
		 if(angle > 180.0f && angle < 270.0f){
			angle = 270.0f + (270.0f - angle); 
		 } else {
			 angle = 180.0f - angle;
		 }
		speed = speed * 0.85f;
	}
	    
	 // Top-most wall   
	 else if(y < worldBoundary.y2+(radius)){
	   	 y = worldBoundary.y2 + (radius); 
	
		 if(angle > 270.0f && angle < 360.0f){
			angle = 360.0f - angle; 
		 } else {
			 angle = 90.0f + (270.0f - angle);
		 }
		speed = speed * 0.85f;
	}
	 // Bottom wall  
	 else if(y > worldBoundary.y1-(radius)){
	   	 y = worldBoundary.y1 - (radius); 
		 
		 if(angle > 0.0f && angle < 90.0f){
			angle = (360.0f - angle); 
		 } else {
			 angle = (180.0f - angle) + 180.0f;
		 }
		speed = speed * 0.85f; 
	}
	
   ////////////////////////////////////////////////
	// Collision against the robot.
	//	
	
	//distance of ball from the robot
	float temp = sqrt(   pow((x-robotX),2.0f) + pow((y-robotY),2.0f)   );
	
	float robotWidth = 2.5f;
	float kickSpeed;
	float tempAngle;
	float collisionX, collisionY;
	
	////////////////////////////////////////////////////////
	//There's a bug in this section
	//These formulas only work on the 1st Quadrant and 3rd Quadrants
	//
	if(temp < robotWidth + radius){
		temp = robotWidth - temp;
      if(temp < 0.0f) {
			tempAngle = angle;
			temp = radius - temp;
		} else {
			tempAngle = angle + 180.0f;
		}			
		
		temp = fabs(temp);
		
		collisionX = x + (temp * cos(degToRad(tempAngle)));
		collisionY = y + (temp * sin(degToRad(tempAngle)));
		
		x = collisionX + (radius * cos(degToRad(robotAngle)));
      y = collisionY + (radius * cos(degToRad(robotAngle)));		
		
		angle = robotAngle;
		kickSpeed = robotSpeed;
		speed = (kickSpeed +  (speed));  //ballgametest
		
		while(speed > 4.0f){  //modulo effect
			speed = speed - 4.0f;
		}
		
		while(angle > 360.0f){
			angle = angle - 360.0f;
		}
		speed = speed - 0.5;
		
		if(speed < 0.0f ) speed = 0.0f;
	}
	   	
}


void Ball::draw(bool page) {  
	
	setlinestyle(SOLID_LINE, 1, 3);
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   setcolor(RED);
	setfillstyle(SOLID_FILL, YELLOW);     
	
	fillellipse(xDev(worldBoundary,deviceBoundary,x),yDev(worldBoundary,deviceBoundary,y),3, 3);
	
}
///////////////////////////////////////////////////////////////	
float Robot::getX(){
  	 return x;
}
	   
float Robot::getY(){
  	 return y;
}
	
void Robot::setAngle(float a){
    if((a >= 0.0f) && (a <= 360.0f)){
	     angle = a;
    }   
}	
   	
float Robot::getAngle(){
    return angle;
}
   
   
float Robot::getLength(){
    return length;
}
	   
float Robot::getWidth(){
	 return width;
}

void Robot::setSpeed(float s){
    speed = s;
}   
	   

float Robot::getSpeed(){
    return speed;
}
      
void Robot::move() {
   	
   float tempX, tempY;
  
  

  
  
   x = (x + (speed * cos(degToRad(angle))));
	y = (y + (speed * sin(degToRad(angle))));
	 
	 if(x > worldBoundary.x2-(width/2.0f)){
	   	 x = worldBoundary.x2 - width/2.0f; 
	    }
	    
	 if(x < worldBoundary.x1+(width/2.0f)){
	   	 x = worldBoundary.x1 + width/2.0f; 
	    }
	    
	    
	 if(y < worldBoundary.y2+(length/2.0f)){
	   	 y = worldBoundary.y2 + (length/2.0f); 
	    }
	    
	 if(y > worldBoundary.y1-(length/2.0f)){
	   	 y = worldBoundary.y1 - (length/2.0f); 
	    }
	 
	   	
}


void Robot::draw(bool page) {  

	 char msg[256];
	char mx[130], my[80], info[80];
	static int counter;
	float pos[8], front[2];
   int poly[8];
	
	setlinestyle(SOLID_LINE, 1, 3);
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   setcolor(RED);

   front[0] = x + ((width/2.0) * cos(degToRad(angle))); //+135 
   front[1] = y + ((length/2.0) * sin(degToRad(angle))); 

   //bottom right - lightblue
   pos[0] = x + ((width/2.0) * cos(degToRad(angle-45))); //+135 
   pos[1] = y + ((length/2.0) * sin(degToRad(angle-45))); 
   
   //upper right - yellow
   pos[2] = x+((width/2.0) * cos(degToRad(angle+45)));; 
   pos[3] = y +((length/2.0) * sin(degToRad(angle+45)));  
   
   //UPPER left - red
   pos[4] = x+((width/2.0) * cos(degToRad(angle+135)));; //+45
   pos[5] = y +((length/2.0) * sin(degToRad(angle+135)));  
   
   //bottom left - green
   pos[6] = x+((width/2.0) * cos(degToRad(angle-135)));;  
   pos[7] = y +((length/2.0) * sin(degToRad(angle-135)));  

        
   for(int i=0; i < 8; i = i + 2){
	    poly[i] = xDev(worldBoundary,deviceBoundary,pos[i]);
	      poly[i+1] = yDev(worldBoundary,deviceBoundary,pos[i+1]);
	}     
        
   setfillstyle(SOLID_FILL, RED);     
   fillpoly(4,poly);     
   
   setcolor(YELLOW);
   line(xDev(worldBoundary,deviceBoundary,pos[0]),yDev(worldBoundary,deviceBoundary,pos[1]),
        xDev(worldBoundary,deviceBoundary,pos[2]),yDev(worldBoundary,deviceBoundary,pos[3]));

// setcolor(YELLOW);       
   line(xDev(worldBoundary,deviceBoundary,pos[2]),yDev(worldBoundary,deviceBoundary,pos[3]),
        xDev(worldBoundary,deviceBoundary,pos[4]),yDev(worldBoundary,deviceBoundary,pos[5]));
        
// setcolor(WHITE);     
   line(xDev(worldBoundary,deviceBoundary,pos[4]),yDev(worldBoundary,deviceBoundary,pos[5]),
        xDev(worldBoundary,deviceBoundary,pos[6]),yDev(worldBoundary,deviceBoundary,pos[7]));
   
// setcolor(GREEN);
   line(xDev(worldBoundary,deviceBoundary,pos[6]),yDev(worldBoundary,deviceBoundary,pos[7]),
        xDev(worldBoundary,deviceBoundary,pos[0]),yDev(worldBoundary,deviceBoundary,pos[1]));

   setcolor(BROWN);
   circle(xDev(worldBoundary,deviceBoundary,x),yDev(worldBoundary,deviceBoundary,y),2);            
   line(xDev(worldBoundary,deviceBoundary,x),yDev(worldBoundary,deviceBoundary,y),
        xDev(worldBoundary,deviceBoundary,front[0]),yDev(worldBoundary,deviceBoundary,front[1]));

 
   
   setlinestyle(0,1,2);     
   putpixel(xDev(worldBoundary,deviceBoundary,pos[0]),yDev(worldBoundary,deviceBoundary,pos[1]),BLUE);            
   setcolor(LIGHTBLUE);
   circle(xDev(worldBoundary,deviceBoundary,pos[0]),yDev(worldBoundary,deviceBoundary,pos[1]),2);            
 
   setcolor(YELLOW);
   circle(xDev(worldBoundary,deviceBoundary,pos[2]),yDev(worldBoundary,deviceBoundary,pos[3]),2);            


   setcolor(RED);
   circle(xDev(worldBoundary,deviceBoundary,pos[4]),yDev(worldBoundary,deviceBoundary,pos[5]),2);            
   
   setcolor(GREEN);
   circle(xDev(worldBoundary,deviceBoundary,pos[6]),yDev(worldBoundary,deviceBoundary,pos[7]),2);            


   
   /////////////////////////////////////////////////////////////////
   //display object properties
   
// settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   setcolor(WHITE);
   setbkcolor(BLUE);
   
   

   sprintf(msg,"Robot width = %2.1f, x = %3.2f, y = %3.2f, speed = %4.2f, angle = %4.2f",width, x,y, speed, angle);
   
   settextjustify(CENTER_TEXT, TOP_TEXT);              outtextxy(getmaxx() / 2, textheight("H")*3, msg);
   
}





////////////////////////////////////////////////////////////////////////////////////////////

  

void Obstacle::initialise(int sx, int sy, float a, float s){
    x = sx; //sprite's x-coordinate 
    y = sy; //sprite's y-coordinate
    angle = a; //in degrees
    speed = s;
 
    t = clock() + 10;
	}
		
void Obstacle::setAngle(float a){
   if((a >= 0) && (a <= 360)){
	    angle = a;
   }   
}	
	
float Obstacle::getX(){
  	return x;
}
	   
float Obstacle::getY(){
 	return y;
}
	
float Obstacle::getAngle(){
   return angle;
}

void Obstacle::setSpeed(float s){
   speed = s;
}   

float Obstacle::getSpeed(){
   return speed;
}

void Obstacle::move() {
	
    float tempX, tempY;




    x = (x + (speed * cos(degToRad(angle))));
	 y = (y + (speed * sin(degToRad(angle))));
	 
	 if(x > worldBoundary.x2-(width/2.0f)){
	   	 x = worldBoundary.x2 - width/2.0f; 
	    }
	    
	 if(x < worldBoundary.x1+(width/2.0f)){
	   	 x = worldBoundary.x1 + width/2.0f; 
	    }
	    
	    
	 if(y < worldBoundary.y2+(length/2.0f)){
	   	 y = worldBoundary.y2 + (length/2.0f); 
	    }
	    
	 if(y > worldBoundary.y1-(length/2.0f)){
	   	 y = worldBoundary.y1 - (length/2.0f); 
	    }
	 
	   	
}


void Obstacle::draw(bool page) {  

	  char msg[256];
	 char mx[80], my[80], info[80];
	 static int counter;
	
	 setlinestyle(SOLID_LINE, 1, 2);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);

    float pos[8], front[2];
    int poly[8];
   
    setcolor(DARKGRAY);
   
   
   
    front[0] = x + ((width/2.0) * cos(degToRad(angle))); //+135 
    front[1] = y + ((length/2.0) * sin(degToRad(angle))); 
   
   
    //bottom right - lightblue
   
    pos[0] = x + ((width/2.0) * cos(degToRad(angle-45))); //+135 
    pos[1] = y + ((length/2.0) * sin(degToRad(angle-45))); 
   
    //upper right - yellow
    pos[2] = x+((width/2.0) * cos(degToRad(angle+45)));; 
    pos[3] = y +((length/2.0) * sin(degToRad(angle+45)));  
   
    //UPPER left - red
    pos[4] = x+((width/2.0) * cos(degToRad(angle+135)));; //+45
    pos[5] = y +((length/2.0) * sin(degToRad(angle+135)));  
   
    //bottom left - green
    pos[6] = x+((width/2.0) * cos(degToRad(angle-135)));;  
    pos[7] = y +((length/2.0) * sin(degToRad(angle-135)));  
   
   
    for(int i=0; i < 8; i = i + 2){
        poly[i] = xDev(worldBoundary,deviceBoundary,pos[i]);
        poly[i+1] = yDev(worldBoundary,deviceBoundary,pos[i+1]);
    } 
   
    setfillstyle(SOLID_FILL, DARKGRAY);     
    fillpoly(4,poly); 
       
   
    setcolor(WHITE);
    line(xDev(worldBoundary,deviceBoundary,pos[0]),yDev(worldBoundary,deviceBoundary,pos[1]),
         xDev(worldBoundary,deviceBoundary,pos[2]),yDev(worldBoundary,deviceBoundary,pos[3]));
   
    //setcolor(YELLOW);       
    line(xDev(worldBoundary,deviceBoundary,pos[2]),yDev(worldBoundary,deviceBoundary,pos[3]),
         xDev(worldBoundary,deviceBoundary,pos[4]),yDev(worldBoundary,deviceBoundary,pos[5]));
       
    //setcolor(WHITE);     
    line(xDev(worldBoundary,deviceBoundary,pos[4]),yDev(worldBoundary,deviceBoundary,pos[5]),
         xDev(worldBoundary,deviceBoundary,pos[6]),yDev(worldBoundary,deviceBoundary,pos[7]));
   
    //setcolor(GREEN);
    line(xDev(worldBoundary,deviceBoundary,pos[6]),yDev(worldBoundary,deviceBoundary,pos[7]),
         xDev(worldBoundary,deviceBoundary,pos[0]),yDev(worldBoundary,deviceBoundary,pos[1]));
   
   
     setcolor(BROWN);
     circle(xDev(worldBoundary,deviceBoundary,x),yDev(worldBoundary,deviceBoundary,y),2);            
     line(xDev(worldBoundary,deviceBoundary,x),yDev(worldBoundary,deviceBoundary,y),
          xDev(worldBoundary,deviceBoundary,front[0]),yDev(worldBoundary,deviceBoundary,front[1]));
   
   
   
     setlinestyle(0,1,2);     
     putpixel(xDev(worldBoundary,deviceBoundary,pos[0]),yDev(worldBoundary,deviceBoundary,pos[1]),BLUE);            
     setcolor(LIGHTBLUE);
     circle(xDev(worldBoundary,deviceBoundary,pos[0]),yDev(worldBoundary,deviceBoundary,pos[1]),2);            
   
     setcolor(YELLOW);
     circle(xDev(worldBoundary,deviceBoundary,pos[2]),yDev(worldBoundary,deviceBoundary,pos[3]),2);            
   
     setcolor(RED);
     circle(xDev(worldBoundary,deviceBoundary,pos[4]),yDev(worldBoundary,deviceBoundary,pos[5]),2);            
   
     setcolor(GREEN);
     circle(xDev(worldBoundary,deviceBoundary,pos[6]),yDev(worldBoundary,deviceBoundary,pos[7]),2);            
   

/////////////////////////////////////////////////////////////////
//display object properties
//       
//       settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
//       setcolor(WHITE);
//       setbkcolor(BLUE);
//       sprintf(msg,"x = %3.2f, y = %3.2f, speed = %4.2f, angle = %4.2f",x,y, speed, angle);

//       outtextxy(getmaxx() / 2, textheight("H")*3, msg);

}


