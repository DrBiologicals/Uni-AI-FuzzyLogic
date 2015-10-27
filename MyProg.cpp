///////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//               Authors: Carsten, 11218504, 2013, Course 159.302, Contribution   
//                        
//
//	 	      Program Name:  Fuzzy Logic, Robot soccer
//	 	       Description: Object-oriented version of Space ship simulation
//
//        Run Parameters: 
//
//    Keys for Operation: 
//
//	 		        History:  date of revision
//                         18 April 2013
//                         30 Sept. 2007 
//
//      Start-up code by:    n.h.reyes@massey.ac.nz
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <deque>
#include <set>
#include <vector>

#include "sprites.h" 
#include "graphics.h"
#include "nodes.h"
#include "transform.h"
#include "algorithm.h"
#include "fuzzylogic.h"

using namespace std;

const float radius=0.352;
enum CellType{baricade=0, space=1, fence=2, wood=3, brick=4, paper=5, plastic=6, start=7, goal=8};

/// Global Variables ///////////////////////////////////////////////////////////////////////

float WORLD_MAXX, WORLD_MAXY;
int fieldX1, fieldY1, fieldX2, fieldY2; //playing field boundaries
BoundaryType worldBoundary,deviceBoundary;
char keyPressed[5];

int numOfObstacles;
float gAngleFromObstacle;
Position gObstaclePosition;

int numOfRows=0;
int numOfCols=0;

typedef struct{
	float x, y;
} Coordinate;

vector<vector<int> > displayMap;
deque<Node *> nMap; //nodes map
vector<Coordinate> ballTrails;
vector<Coordinate> robotTrails;

bool DYNAMIC_OBSTACLES_FLAG=false;

fuzzy_system_rec g_fuzzy_system;
fuzzy_system_rec g_fuzzy_system_pursuit_speed;
fuzzy_system_rec g_fuzzy_system_avoidance;
fuzzy_system_rec g_fuzzy_system_avoidance_speed;

float inputValues[MAX_NO_OF_INPUTS];



/// Function Prototypes ////////////////////////////////////////////////////////////////////

void getKey(Robot &robot);
void runGame();
void markCell(Robot robot, int rowIndex, int colIndex, int weight);
void drawGrid(Robot robot);
void drawObstacles(Robot robot);


////////////////////////////////////////////////////////////////////////////////////////////


void getKey(Robot &robot) {
    float tempAngle;
    
    strncpy(keyPressed, "", 5);
	
    if(GetAsyncKeyState(VK_F4) < 0) { 
       robot.setSpeed(0.5);
    } 
  
    if(GetAsyncKeyState(VK_F5) < 0) {
        robot.setSpeed(2.2);
    }
  
    if(GetAsyncKeyState(VK_F6) < 0) {
        robot.setSpeed(3.2);
    }
    
    if(GetAsyncKeyState(VK_F7) < 0) {
        DYNAMIC_OBSTACLES_FLAG = !DYNAMIC_OBSTACLES_FLAG;
        delay(150);
    }
   
	
    if(GetAsyncKeyState(VK_UP) < 0) { 
        if((robot.getSpeed() + 0.05) <= 2.5) {
            robot.setSpeed(robot.getSpeed() + 0.05);
        } else {
            robot.setSpeed(2.5);
        }  
    
        strncpy(keyPressed, "UP", 4);
	 }
		
    if(GetAsyncKeyState(VK_DOWN) < 0) { 
       // if((robot.getSpeed()-0.005) >= 0) {
       //     robot.setSpeed(robot.getSpeed() - 0.005);
       
        if((robot.getSpeed()-0.05) >= 0) {
            robot.setSpeed(robot.getSpeed() - 0.05);
        } else {
            robot.setSpeed(0);
        }  
        
        strncpy(keyPressed, "DOWN", 4);
    }  
  
    if(GetAsyncKeyState(VK_LEFT) < 0) { 
//        tempAngle = robot.getAngle() + 0.7;
        tempAngle = robot.getAngle() + 2.0;
       
        
        if(tempAngle > 360.0){
	        tempAngle = 0.0;
	        robot.setAngle(tempAngle);
           strncpy(keyPressed, "> 360 LEFT", 4);
	     }
	     else{
           robot.setAngle(tempAngle);
           strncpy(keyPressed, "LEFT", 4);
        }  
           
    }
  
    if(GetAsyncKeyState(VK_RIGHT) < 0) { 
//        tempAngle = robot.getAngle() - 0.7;
        tempAngle = robot.getAngle() - 2.0;
        
        if(tempAngle < 0.0) {
	        tempAngle = 360.0;
           robot.setAngle(tempAngle);
           strncpy(keyPressed, "== 0 RIGHT", 5);
        }
        else{
           robot.setAngle(tempAngle);
           strncpy(keyPressed, "RIGHT", 5);
        }
        
    }
}

void recordBallTrails(Ball ball){
	
	Coordinate c;
	
	c.x = ball.getX(); 
	c.y = ball.getY();
	
	ballTrails.push_back(c);
	
}


void displayBallTrails(){
	
	for(int i=0; i < ballTrails.size(); i++){
		
		putpixel(xDev(worldBoundary,deviceBoundary,ballTrails[i].x),yDev(worldBoundary,deviceBoundary,ballTrails[i].y), WHITE);
		
	}
	
}

void initWorld(){
	 gAngleFromObstacle=0.0;
    
    //widescreen
    fieldX1 = getmaxx() / 10;
    fieldX2 = getmaxx() - (getmaxx() / 10);
    fieldY1 = getmaxy() / 9;
    fieldY2 = getmaxy() - (getmaxy() / 9);
	
	
	/*
	//square monitor
    fieldX1 = getmaxx() / 8;
    fieldX2 = getmaxx() - (getmaxx() / 8);
    fieldY1 = getmaxy() / 12;
    fieldY2 = getmaxy() - (getmaxy() / 12);
	*/

	/*
//3 vs 3 MIROSOT FIELD    
    worldBoundary.x1 = 0.0;
    worldBoundary.y1 = 150.0;
    worldBoundary.x2 = 180.0;
    worldBoundary.y2 = 0.0;
    */
    
//5 vs 5 MIROSOT FIELD    
    worldBoundary.x1 = 0.0;
    worldBoundary.y1 = 180.0;
    worldBoundary.x2 = 220.0;
    worldBoundary.y2 = 0.0;

    deviceBoundary.x1 = fieldX1;
    deviceBoundary.y1 = fieldY1;
    deviceBoundary.x2 = fieldX2;
    deviceBoundary.y2 = fieldY2;
       
    WORLD_MAXX=worldBoundary.x2-worldBoundary.x1;
    WORLD_MAXY=worldBoundary.y2-worldBoundary.y1;
}


void markCell(Robot robot, int rowIndex, int colIndex, int weight){
	int xInc = int(  ((fieldX2-fieldX1)/WORLD_MAXX) * robot.getWidth());
	int yInc = int(  ((fieldY2-fieldY1)/(WORLD_MAXY)) * robot.getLength());
	
	setbkcolor(BLACK);
	
	if(yInc < 0) {
		yInc = yInc * -1;
	}
	
	if(xInc < 0) {
		xInc = xInc * -1;
	}
	
	
   //setfillstyle(SOLID_FILL, weight);
   
   
	switch(weight){
		//baricade=0, space=1, fence=2, metal=3, brick=4, paper=5, wood=6, start=7, goal=8
		case 0: setfillstyle(SOLID_FILL, DARKGRAY); break;
		case 1: setfillstyle(SOLID_FILL, BLACK); break;
		case 2: setfillstyle(CLOSE_DOT_FILL, DARKGRAY); break;
		case 3: setfillstyle(LTSLASH_FILL, BLUE); break;
		case 4: setfillstyle(SOLID_FILL, BROWN); break;
		case 7: setfillstyle(SOLID_FILL, GREEN); break; //START
		case 8: setfillstyle(SOLID_FILL, RED); break; //GOAL
		//case path: setfillstyle(SOLID_FILL, RED); break; //GOAL
		
	}
	
	
	if((weight != 1) && (weight != 9)){	
     //bar(fieldX1 + (xInc * colIndex)+3, fieldY1 + (yInc * rowIndex)+2, fieldX1 + ((xInc * colIndex) + xInc)-1, fieldY1 + ((yInc * rowIndex) + yInc)-1);
     bar(fieldX1 + (xInc * colIndex)+1, fieldY1 + (yInc * rowIndex), fieldX1 + ((xInc * colIndex) + xInc), fieldY1 + ((yInc * rowIndex) + yInc));
   }
   
   if(weight==7){
	   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	   settextjustify(CENTER_TEXT, CENTER_TEXT);
	   setbkcolor(GREEN);
	   setcolor(WHITE);
	   outtextxy(fieldX1 + (xInc * colIndex) + (xInc/2), fieldY1 + (yInc * rowIndex) + (yInc/2),"S");
	}
   
   if(weight==8){
  	   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
  	   settextjustify(CENTER_TEXT, CENTER_TEXT);
  	   setbkcolor(RED);
	   setcolor(WHITE);
	   outtextxy(fieldX1 + (xInc * colIndex) + (xInc/2), fieldY1 + (yInc * rowIndex) + (yInc/2),"G");
	}

   if(weight == 9){
	   setcolor(YELLOW);
	   circle(fieldX1 + (xInc * colIndex) + (xInc/2), fieldY1 + (yInc * rowIndex) + (yInc/2),3);
	}
	
}


void showMap(Robot robot){
	
	
	
	//vector<vector<int> >::iterator i, j;
	int cols = displayMap[0].size();
	
	//cout << "Map: rows: " << displayMap.size() << ", cols = " << cols << endl;
	
	for(int i=0; i < displayMap.size();i++){
		 for(int j=0; j < cols;j++){
		    markCell(robot, i, j, displayMap[i][j]);
		    
		    //cout << displayMap[i][j] << ", ";
	    }
	    //cout << endl;
	}
	
}

void loadMap(Robot robot)
{
	cout << "Load map." << endl; 
	string strWeight;
	int weight;
   Node *node;
	int i=0;
	int row, col;
	
	
	ifstream inputstream("soccer.map");
	ifstream tempstream("soccer.map");
	

	if (!inputstream.is_open()){
	   cerr << "Error opening file" << endl;
	   exit(EXIT_FAILURE);
	}
	
		
	row=0;
	
	
	while(tempstream >> strWeight){
	    numOfCols = strWeight.size();	
	    numOfRows++;
	}
	
	cout << "numOfRows = " << numOfRows << ", numOfColumns = " << numOfCols << endl;
	
	
	
	for(int i=0; i < numOfRows;i++){
   	  
   	  displayMap.push_back(vector <int>() );
   }	  
	
	
		
   while(inputstream >> strWeight)
	{
      
      for(col=0; col < numOfCols; col++){
		  weight = strWeight.at(col) - '0';
		   
        displayMap[row].push_back(weight);
		    
		  markCell(robot, row, col, weight);
		  
		  node = new Node(col, row, weight);
  		  		  
		  nMap.push_back(node);
		  
		  
		  i++;
	   }
	   row++;
	   cout << endl;
	}
	
	inputstream.close();
	
	
	cout << "Items read = " << i << endl; 
	cout << "Map size = " << nMap.size() << endl;
	cout << "vector size = " << displayMap.size() << " (rows)." << endl;
	
	
	int Count=i--;


	
}


////////////////////////////////////////////////////////////////////////////////


void drawGrid(Robot robot){
	
	int xInc = int(  ((fieldX2-fieldX1)/WORLD_MAXX) * robot.getWidth());
	int yInc = int(  ((fieldY2-fieldY1)/(WORLD_MAXY)) * robot.getLength());
	
	if(yInc < 0) {
		yInc = yInc * -1;
	}
   setlinestyle(WIDE_DOT_FILL, 1, 1);
   setcolor(DARKGRAY);
   
   //draw vertical bars
   for(int i=fieldX1; i < fieldX2; i += xInc){
	   line(i,fieldY1 ,i,fieldY2);
	}
   
   //draw horizontal bars   
   for(int i=fieldY1; i < fieldY2; i += yInc){
	   line(fieldX1,i,fieldX2,i);
	}
	
	float x1,y1,x2,y2;
	
	
	x1=110.0f;
	y1=90.0f;
	setlinestyle(SOLID_LINE,1,4);
	setcolor(WHITE);
	circle(xDev(worldBoundary,deviceBoundary,x1),yDev(worldBoundary,deviceBoundary,y1),60);
	setlinestyle(SOLID_LINE,1,1);
	
	x1=110.0f;
	x2=110.0f;
	y1=0.0f;
	y2=180.0f;
	setlinestyle(SOLID_LINE,1,4);
	setcolor(WHITE);
	line(xDev(worldBoundary,deviceBoundary,x1),yDev(worldBoundary,deviceBoundary,y1),xDev(worldBoundary,deviceBoundary,x2),yDev(worldBoundary,deviceBoundary,y2));
	setlinestyle(SOLID_LINE,1,1);
	
	
	x1=220.0f-35.0f;
	y1=90.0f;
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,1,3);
	circle(xDev(worldBoundary,deviceBoundary,x1),yDev(worldBoundary,deviceBoundary,y1),40);
	setlinestyle(SOLID_LINE,1,1);
	setcolor(DARKGRAY);
	
	//goal area
	x1= 220.0f-35.0f;
   y1= (180.0f/2.0f)-40.f;
   x2= 220.0f;
   y2=(180.0f/2.0f)+40.f;
	//setbkcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(xDev(worldBoundary,deviceBoundary,x1),yDev(worldBoundary,deviceBoundary,y1),xDev(worldBoundary,deviceBoundary,x2),yDev(worldBoundary,deviceBoundary,y2));
	setcolor(WHITE);
	rectangle(xDev(worldBoundary,deviceBoundary,x1),yDev(worldBoundary,deviceBoundary,y1),xDev(worldBoundary,deviceBoundary,x2),yDev(worldBoundary,deviceBoundary,y2));

	//inner goal
	x1= 220.0f-15.0f;
   y1= (180.0f/2.0f)-25.f;
   x2= 220.0f;
   y2=(180.0f/2.0f)+25.f;
	setcolor(WHITE);
	
	rectangle(xDev(worldBoundary,deviceBoundary,x1),yDev(worldBoundary,deviceBoundary,y1),xDev(worldBoundary,deviceBoundary,x2),yDev(worldBoundary,deviceBoundary,y2));
}

void drawObstacles(Robot robot){
	for(int i = 0;i < nMap.size(); i++){
		
		Node *n;
		n = nMap.at(i);
			
		markCell(robot, n->getY(),n->getX(),n->getWeight());
		//cout << "map(" << n->getX() << ", " << n->getY() << ")= " << n->getWeight() <<  endl;
	}
}

void drawPanel(){
	    setbkcolor(BLACK);
       setfillstyle(SOLID_FILL, BLUE);
       bar(0, 0, getmaxx(), getmaxy()); //draw main panel
       
       setfillstyle(SOLID_FILL, BLACK);
       bar(fieldX1, fieldY1, fieldX2, fieldY2); //draw playing field
       
       //draw borders around the field
       setcolor(WHITE);
       line(fieldX1, fieldY1, fieldX2, fieldY1);
       line(fieldX1, fieldY1, fieldX1, fieldY2);
       
       setcolor(DARKGRAY);
       line(fieldX1, fieldY2, fieldX2, fieldY2);
       line(fieldX2, fieldY1, fieldX2, fieldY2);
       
       setbkcolor(BLUE);
       
       settextjustify(CENTER_TEXT,CENTER_TEXT);
       settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
       setcolor(DARKGRAY);
       outtextxy(getmaxx() / 2, textheight("H"), "RobotSoccer Simulation by C.Scholz (11218504)");
       
}

int findNearestObstacle(Robot robot, Obstacle *obs){
	    
	double minDistance=99999.0;
   double tempDistance=99999.0;
   float x,y;
	    
	x=robot.getX();
   y=robot.getY();
   
   int i=0, index=0;
   
   minDistance=99999;
   
   for(i=0; i < numOfObstacles; i++){
	    //obs[i].draw(page);
	       
	    tempDistance=  sqrt( double((x-obs[i].getX())*(x-obs[i].getX()) ) + ( (y-obs[i].getY())*(y-obs[i].getY()) ));
	    if(tempDistance < minDistance) {
	      minDistance = tempDistance;
	      index = i;
	   }   
	}
	return index;
	
}

float calcAngleFromTarget(Robot robot, float tX, float tY, Position &pos){
   float A1, A2;
   float newAngleFromTarget;
	float angleFromTarget, otherAngleFromTarget=0.0f;
	
	float thetaTarget=0.0f;
	
	float newX, newY=0.0f;
	char msg[100];
	char quadrant[50];
	char position[30];
	
	Position targetPos;
	
	newX = tX - robot.getX();

	
	newY = tY - robot.getY(); //we are using the world representation here
	
	
	
	if(newX < 0.0f && newY > 0.0f){
	
		strcpy(quadrant,"2ND Quadrant");
		
	} else if(newX < 0.0f && newY < 0.0f){
	  
		strcpy(quadrant,"3RD Quadrant");
	  
	} else if(newX > 0.0f && newY < 0.0f){
		
		strcpy(quadrant,"4TH Quadrant");

	} else {

		strcpy(quadrant,"1ST Quadrant");
	}
	
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   setcolor(WHITE);
   setbkcolor(BLUE);
   settextjustify(LEFT_TEXT, TOP_TEXT); 

   outtextxy(fieldX2 + (textwidth("W")*1), textheight("H")*21, "<<TARGET INFO.>>");
	sprintf(msg,"x: %3.2f", tX);

   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*23, msg);


	sprintf(msg,"y: %3.2f", tY);

   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*24, msg);

	    
   outtextxy(fieldX2+textwidth("W"), textheight("H")*26, quadrant);
		
	
	
	thetaTarget = fabs(atan(newY/newX));
	
	if(newX < 0.0f && newY > 0.0f){
	
		thetaTarget = M_PI - thetaTarget;
		
	} else if(newX < 0.0f && newY < 0.0f){
	  
	   thetaTarget = M_PI + thetaTarget;
	  
	} else if(newX > 0.0f && newY < 0.0f){
		
		thetaTarget = 2*M_PI - thetaTarget;
	}
	
	
	angleFromTarget = robot.getAngle() - (thetaTarget * 180.0f / M_PI);
    otherAngleFromTarget = 360.0f - angleFromTarget;	
	
//	cout << "\nrobotAngle = " << robot.getAngle() << ", thetaTarget=" << (thetaTarget * 180 / M_PI) << ", orig. angleFromTarget = " << angleFromTarget;
	
	A1 = fabs(angleFromTarget);
 
	
	
	A2 = 360.0f - A1;
	
	if(angleFromTarget > 0.0f){
		
		if(A1 <= A2){
			
			targetPos = RIGHT_SIDE;
			newAngleFromTarget = A1;
			
		} else {
			
			targetPos = LEFT_SIDE;
			newAngleFromTarget = A2;
		}
		
		
	} else {
		
		if(A1 <= A2){
			
			targetPos = LEFT_SIDE;
			newAngleFromTarget = A1;
			
		} else {
			
			targetPos = RIGHT_SIDE;
			newAngleFromTarget = A2;
		}
		
		
	}

   gObstaclePosition = targetPos;
   gAngleFromObstacle = newAngleFromTarget;	

//------------------------------------------------------

	

   
   if(targetPos == LEFT_SIDE){
		newAngleFromTarget = -newAngleFromTarget;
   	strcpy(position, "LEFT");
   } else {
   	strcpy(position, "RIGHT");
   }	

	sprintf(msg,"angle: %3.2f", newAngleFromTarget);
   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*28, msg);
	
	
	sprintf(msg,"position: %s", position);
   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*29, msg);
	
	pos = targetPos;
	return newAngleFromTarget;
}



float calcAngleFromObstacle(Robot robot, Obstacle obs, Position &pos){
   float A1, A2;
   float newAngleFromObstacle;
	float angleFromObstacle, otherAngleFromObstacle=0.0f;
	
	float thetaObs=0.0f;
	
	float newX, newY=0.0f;
	char msg[100];
	char quadrant[50];
	char position[30];
	
	Position obsPos;
	
	newX = obs.getX() - robot.getX();
//	newY = robot.getY() - obs.getY();
	
	newY = obs.getY() - robot.getY(); //we are using the world representation here
	
	
	
	if(newX < 0.0f && newY > 0.0f){
	
		strcpy(quadrant,"2ND Quadrant");
		
	} else if(newX < 0.0f && newY < 0.0f){
	  
		strcpy(quadrant,"3RD Quadrant");
	  
	} else if(newX > 0.0f && newY < 0.0f){
		
		strcpy(quadrant,"4TH Quadrant");

	} else {

		strcpy(quadrant,"1ST Quadrant");
	}
	
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   setcolor(WHITE);
   setbkcolor(BLUE);

   outtextxy(fieldX2 + (textwidth("W")*10), textheight("H")*8, "<<OBSTACLE INFO.>>");
	sprintf(msg,"x: %3.2f", obs.getX());

   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*10, msg);


	sprintf(msg,"y: %3.2f", obs.getY());

   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*11, msg);

	    
   outtextxy(fieldX2+textwidth("W"), textheight("H")*13, quadrant);
		
	
	
	thetaObs = fabs(atan(newY/newX));
	
	if(newX < 0.0f && newY > 0.0f){
	
		thetaObs = M_PI - thetaObs;
		
	} else if(newX < 0.0f && newY < 0.0f){
	  
	   thetaObs = M_PI + thetaObs;
	  
	} else if(newX > 0.0f && newY < 0.0f){
		
		thetaObs = 2*M_PI - thetaObs;
	}
	
	
	angleFromObstacle = robot.getAngle() - (thetaObs * 180.0f / M_PI);
   otherAngleFromObstacle = 360.0f - angleFromObstacle;	
	
//	cout << "\nrobotAngle = " << robot.getAngle() << ", thetaObs=" << (thetaObs * 180 / M_PI) << ", orig. anglefromObstacle = " << angleFromObstacle;
	
	A1 = fabs(angleFromObstacle);
 
	
	
	A2 = 360.0f - A1;
	
	if(angleFromObstacle > 0.0f){
		
		if(A1 <= A2){
			
			obsPos = RIGHT_SIDE;
			newAngleFromObstacle = A1;
			
		} else {
			
			obsPos = LEFT_SIDE;
			newAngleFromObstacle = A2;
		}
		
		
	} else {
		
		if(A1 <= A2){
			
			obsPos = LEFT_SIDE;
			newAngleFromObstacle = A1;
			
		} else {
			
			obsPos = RIGHT_SIDE;
			newAngleFromObstacle = A2;
		}
		
		
	}

   gObstaclePosition = obsPos;
   gAngleFromObstacle = newAngleFromObstacle;	

//------------------------------------------------------

   if(obsPos == LEFT_SIDE){
		newAngleFromObstacle = -newAngleFromObstacle;
   	strcpy(position, "LEFT");
   } else {
   	strcpy(position, "RIGHT");
   }	
	
	sprintf(msg,"angle: %3.2f", newAngleFromObstacle);
   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*15, msg);

	sprintf(msg,"position: %s", position);
   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*16, msg);
	
	pos = obsPos;
	return newAngleFromObstacle;
}

float calcDistanceFromTarget(Robot robot, float worldGx, float worldGy){

	char msg[100];
   float d;
	
   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   setcolor(WHITE);
   setbkcolor(BLUE);
   settextjustify(LEFT_TEXT, TOP_TEXT); 

	
	
   d = sqrt(pow(worldGx - robot.getX(), 2) + pow(worldGy - robot.getY(), 2));

	sprintf(msg,"distance: %3.2f", d);
   settextjustify(LEFT_TEXT, TOP_TEXT);       
   outtextxy(fieldX2+textwidth("W"), textheight("H")*30, msg);

   
	return d;
}

void runGame() {
   static BOOL page;
   bool ANIMATE_MOUSE_FLAG=true;
   float minDistance=0.0;
   float tempDistance=0.0;
   float x,y;
   
   int gX=0, gY=0; //Target in device coordinates
   float worldGx, worldGy; //Target in world coordinates
  
   
   int index;
   
   float newAngle=0.0;
   float angleFromObstacle;
   float angleFromTarget;
   float distanceFromObstacle;
   float distanceFromTarget;
   
   char msg[100];
   float tempAngle=0.0f;
   float fuzzyAngle=0.0f;
   float fuzzySpeed=0.0f;
   static int mouseRadius;
   
   Robot robot(110,90,45.0,0);
	Ball ball(130,100,285.0f,1.0f);
	Obstacle *obs;
	
	Position obstaclePosition;
	Position targetPosition;
	
	
	srand(time(NULL));  // Seed the random number generator
			
   initWorld();
   //loadMap(robot); //load map of bricks
   
	numOfObstacles=10;
	
	obs = new Obstacle[numOfObstacles];
	
	//initial goal position = center of screen
	gX = getmaxx()/2;
	gY = getmaxy()/2;
	
	//worldGx = float(((gX-fieldX1) * 180.0f) / abs(fieldX2-fieldX1));
   //worldGy = worldBoundary.y1-(float(((gY-fieldY1) * 150.0f) / abs(fieldY2-fieldY1)));  
	
	worldGx = float(((gX-fieldX1) * 220.0f) / abs(fieldX2-fieldX1));
   worldGy = worldBoundary.y1-(float(((gY-fieldY1) * 180.0f) / abs(fieldY2-fieldY1)));  

	worldGx = ball.getX();
	worldGy = ball.getY();
	
	//initialise obstacles with random x & y-coordinates, angle and speed
	for(int i=0; i < numOfObstacles; i++){
		obs[i].initialise(rand() % 180, rand() % 180, float(rand() % 360), float((rand() % 100) *0.004) );
	}
	   
	//********************************************
	//initialise the Fuzzy System here
	initFuzzySystemTargetAngle(&g_fuzzy_system);
	initFuzzySystemTargetPursuitSpeed(&g_fuzzy_system_pursuit_speed);
	initFuzzySystemAvoidanceAngle(&g_fuzzy_system_avoidance);
	initFuzzySystemAvoidanceSpeed(&g_fuzzy_system_avoidance_speed);
	
	//********************************************   
	   
	// keep running the program until the ESC key is pressed   
	while((GetAsyncKeyState(VK_ESCAPE)) == 0 ) {
       setactivepage(page);
       cleardevice();
       drawPanel(); //should be used with loadMap!
       drawGrid(robot);
       //drawObstacles(robot); //display brick obstacles, this should be used with loadMap!
       
       
       if(DYNAMIC_OBSTACLES_FLAG){
   
          //-------------------------------------------------------------------
          //Randomize obstacle movements 
          for(int i=0; i < numOfObstacles; i++){
   	       
   	       if((rand() % 100) > 50){
   	         tempAngle = float(   obs[i].getAngle() - float(rand() % 20) );
   	       } else {
   		      tempAngle = float(   obs[i].getAngle() + float(rand() % 20) );
   		    }
   	       
   	       if(tempAngle > 360.0){
   		       tempAngle = 360.0f;  //fmod - modify this one - napoleon
   		    } else if(tempAngle < 0.0f){
   			    tempAngle = 0.0f;
   			 }
   		    
   	       obs[i].setAngle(tempAngle);
   	       obs[i].move();
   	    }
          //-------------------------------------------------------------------
       }
         
	    index = findNearestObstacle(robot, obs);
	    
	    //draw all obstacles
	    for(int i=0; i < numOfObstacles; i++){
	       obs[i].draw(page);	       
	    }
		
		
		 //indicate distance of robot from nearest obstacle
       setcolor(YELLOW);
       line(xDev(worldBoundary,deviceBoundary,robot.getX()),yDev(worldBoundary,deviceBoundary,robot.getY()), 
            xDev(worldBoundary,deviceBoundary,obs[index].getX()), yDev(worldBoundary,deviceBoundary,obs[index].getY()));
              
       
       //***********************************************************************************
       //Collect inputs (i.e. angles and distances)
       
       angleFromObstacle = calcAngleFromObstacle(robot, obs[index], obstaclePosition);
       distanceFromObstacle = sqrt(pow(obs[index].getX() - robot.getX(), 2) + pow(obs[index].getY() - robot.getY(), 2));
     
       //note:  the angle should be calculated based on the world coordinates of the target (worldGx, worldGy)
       angleFromTarget = calcAngleFromTarget(robot, worldGx, worldGy, targetPosition);
       distanceFromTarget = calcDistanceFromTarget(robot, worldGx, worldGy);//sqrt(pow(worldGx - robot.getX(), 2) + pow(worldGy - robot.getY(), 2));
       
       //***********************************************************************************
              
       
       getKey(robot);  //get key strokes
       	    
	    
	    
	    //************************************************************************************************************
       // Add Intelligence for robot navigation heree

       
       //--- TARGET PURSUIT -----------------------------------------
       
       inputValues[in_angle] = angleFromTarget;
       inputValues[in_distance] = distanceFromTarget;
       fuzzyAngle = fuzzy_system(inputValues, g_fuzzy_system);
		 fuzzySpeed = fuzzy_system(inputValues, g_fuzzy_system_pursuit_speed);
       
       newAngle = robot.getAngle() + fuzzyAngle;
       
       //make sure that the angle is positive [0, 360]
       if(newAngle < 0.0f){
	       newAngle = 360.0f + newAngle;
	    }
	    
	    if(newAngle > 360.0f) {
		    newAngle = newAngle - 360.0f;
		 }
		 

		 //------------------------------------------------------------
       
       
       
       
       //--- OBSTACLE AVOIDANCE -----------------------------------------------------------------------------------
       //
		 float obstacleAvoidanceDist = 17.0f;
       if(DYNAMIC_OBSTACLES_FLAG || fuzzySpeed > 0.5f){
			 obstacleAvoidanceDist = 30.0f;
		 }
		 //change the conditional statement to improve performance
       if((distanceFromObstacle < obstacleAvoidanceDist) && (obstaclePosition == targetPosition)){
      
          inputValues[in_angle] = angleFromObstacle;
          inputValues[in_distance] = distanceFromObstacle;
          fuzzyAngle = fuzzy_system(inputValues, g_fuzzy_system_avoidance);
          fuzzySpeed = fuzzy_system(inputValues, g_fuzzy_system_avoidance_speed);
         
             
          newAngle = robot.getAngle() + fuzzyAngle;
          
          //make sure that the angle is positive [0, 360]
          if(newAngle < 0.0f){
   	       newAngle = 360.0f + newAngle;
   	    }
   	    
   	    if(newAngle > 360.0f) {
   		    newAngle = newAngle - 360.0f;
   		 }
   	
   	 }	
		
  	    //************************************************************************************************************
  	    
  	    
  	    //Apply calculated steering angles and speed

		 robot.setAngle(newAngle); 
       robot.setSpeed(fuzzySpeed);
       robot.move();   //Update Object's (x, y) position and (angle) orientation	
       robot.draw(page);     //Display Object
       
       	if(robotTrails.size() > 250){
		     robotTrails.clear();
			}
			
			if(ballTrails.size() > 350){
					  ballTrails.clear();
			}
			ball.move(robot.getX(), robot.getY(), robot.getAngle(),robot.getSpeed());
			ball.draw(page);
				 
			
			worldGx = ball.getX();
			worldGy = ball.getY();

			if(robot.getSpeed() < 0.4){
				if(worldGx > 218.0f){
					if(robot.getAngle() < 90.0f){
						ball.move(robot.getX(), robot.getY(), (robot.getAngle()+90.0f),robot.getSpeed());
					}else{
						ball.move(robot.getX(), robot.getY(), (robot.getAngle()-90.0f),robot.getSpeed());
					}
				}
				if(worldGx < 3.0f){
					if(robot.getAngle() < 90.0f){
						ball.move(robot.getX(), robot.getY(), (robot.getAngle()-90.0f),robot.getSpeed());
					}else{
						ball.move(robot.getX(), robot.getY(), (robot.getAngle()+90.0f),robot.getSpeed());
					}
				}
				if(worldGy > 177.0f){
					if(robot.getAngle() < 180.0f){
						ball.move(robot.getX(), robot.getY(), (robot.getAngle()+90.0f),robot.getSpeed());
					}else{
						ball.move(robot.getX(), robot.getY(), (robot.getAngle()-90.0f),robot.getSpeed());
					}
				}
				if(worldGy < 2.0f){
					if(robot.getAngle() < 180.0f){
						ball.move(robot.getX(), robot.getY(), (robot.getAngle()-90.0f),robot.getSpeed());
					}else{
						ball.move(robot.getX(), robot.getY(), (robot.getAngle()+90.0f),robot.getSpeed());
					}
				}
			}


		 if(mousedown()){
          //------------------------------------------------------	       
	       
	       if(!ANIMATE_MOUSE_FLAG) {
		       ANIMATE_MOUSE_FLAG=true;
		    }
		    
	       line(0, mousecurrenty(), getmaxx(), mousecurrenty());
          line(mousecurrentx(), 0, mousecurrentx(), getmaxy());
          //delay(100);
	       
	       gX = mousecurrentx();
  	       gY = mousecurrenty();
  	       
  	       //worldGx = float(((gX-fieldX1) * 180.0f) / abs(fieldX2-fieldX1));
          //worldGy = worldBoundary.y1-(float(((gY-fieldY1) * 150.0f) / abs(fieldY2-fieldY1)));  
			 
			 worldGx = float(((gX-fieldX1) * 220.0f) / abs(fieldX2-fieldX1));
          worldGy = worldBoundary.y1-(float(((gY-fieldY1) * 180.0f) / abs(fieldY2-fieldY1)));  

          ball.setX(worldGx);
			 ball.setY(worldGy);
			 
          //------------------------------------------------------
       }

	    //---------------------------------------------------------
	    // mark goal
	    //	    
	    setcolor(RED);
	    circle(gX, gY, 20);
	    line(gX,gY-20,gX,gY+20);
	    line(gX-20,gY,gX+20,gY);
	    //---------------------------------------------------------
	    
	    setcolor(GREEN);
       line(xDev(worldBoundary,deviceBoundary,robot.getX()),yDev(worldBoundary,deviceBoundary,robot.getY()), 
            gX, gY);

	    //------------------------------------------------------------------
	    // special effect to display concentric circles locating the target
	    //
	    if(ANIMATE_MOUSE_FLAG){
	         setcolor(YELLOW);
	         
	         if(mouseRadius < 80) {
		         mouseRadius += 3;
		      }
	         circle(gX, gY, mouseRadius);
	         		      
		      if(mouseRadius >= 80) {
			      ANIMATE_MOUSE_FLAG=false;
			      mouseRadius=0;
			   }
		      
	       }
  	    //------------------------------------------------------------------    
	    setvisualpage(page);
       page = !page;  //switch to another page

   }	
   
   
   //********************************************
   // free fuzzy rules
	free_fuzzy_rules(&g_fuzzy_system);
   free_fuzzy_rules(&g_fuzzy_system_pursuit_speed);
	free_fuzzy_rules(&g_fuzzy_system_avoidance);
   free_fuzzy_rules(&g_fuzzy_system_avoidance_speed);
   //********************************************
   
   delete [] obs;
	
   
}



////////////////////////////////////////////////////////////////////////////////////

int main(void) {
	
	int graphDriver = 0,graphMode = 0;
   
 	initgraph(&graphDriver, &graphMode, "", 1280, 1024); // Start Window
	testFunction();
   try{
     runGame();
   }

   catch(...){
    	cout << "Exception caught!\n";
   }
	testFunction();
	return 0;
} 

