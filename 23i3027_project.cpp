//Aqsa Khurram 23i-3027
#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath>
#include <fstream>
#include <cstdio> 
#include <cstring>
using namespace std;
int t[51]={0,0},t1[51]={0,0},t2[51]={0,0},t3[51]={ 0,0 }, t4[51]={0,0},t5[51]={0,0},t6[51]={0,0},coordx[51]={10,113,213,313,413,520,620}, coordy[51]={800,710,600,520,390,280,185,85}, players=0, randno,i, score[6]={0,0},check=0, troops1=0,troops2=0,troops3=0,troops4=0, troops5=0,troops6=0,l=0,winner[6]={0}, wincheck=0,s=0,fight=0, mov=0, p1occ=0,p2occ=0,p3occ=0,p4occ=0,p5occ=0,p6occ=0,f=0, greatest=0,chec=0,che=0,tr1=0,tr2=0,tr3=0,tr4=0,tr5=0,tr6=0,c=100,selectedterritory=0,selte=0,troop=0,g=0,r=1,terrcheck=0;
bool dice=100;
string player[6]={ "", ""},playerscol[6];
void winnerDecider();
void winnerCheck();
void colorSelector();
void territoryDecider(float X, float Y);
void extraTroops();
void occTerrChecker(float X,float Y);
void moveTerrCheck(float X,float Y);
void moveTerr(float X, float Y);
void attackTerr(float X, float Y);
void defendTerr(float X, float Y);
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void GameDisplay(){
	int j=1;
	glClearColor(0.96/*Red Component*/, 0.96,	//148.0/255/*Green Component*/,
			0.86/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	for (int l=0; l<6; l++){			// TO CHECK FOR ANY DECLARED WINNER
		if (winner[l]!=0)
			wincheck+=1;}
	if (wincheck==0){				//TO CHECK IF USER HAS NOT ASKED IN MENU TO DECLARE THE WINNER
	DrawSquare( 3 , 730,100,colors[LIGHT_CORAL]); 	// TO DISPLAY THE BOARD
	DrawSquare( 103 , 730 ,100,colors[ROYAL_BLUE]); 
	DrawSquare( 203 , 730 ,100,colors[LIGHT_CORAL]); 
	DrawSquare( 303 , 730 ,100,colors[ROYAL_BLUE]); 
	DrawSquare( 403 , 730 ,100,colors[LIGHT_CORAL]); 
	DrawSquare( 3 ,630,100,colors[ROYAL_BLUE]); 
	DrawSquare( 103 , 630 ,100,colors[LIGHT_CORAL]); 
	DrawSquare( 203 , 630 ,100,colors[ROYAL_BLUE]); 
	DrawSquare( 303 , 630 ,100,colors[LIGHT_CORAL]); 
	DrawSquare( 403 , 630 ,100,colors[ROYAL_BLUE]); 
	DrawSquare( 3 , 530,100,colors[LIGHT_CORAL]); 
	DrawSquare( 103 , 530 ,100,colors[ROYAL_BLUE]); 
	DrawSquare( 203 , 530 ,100,colors[LIGHT_CORAL]); 
	DrawSquare( 303 , 530 ,100,colors[ROYAL_BLUE]); 
	DrawSquare( 403 , 530 ,100,colors[LIGHT_CORAL]); 
	DrawSquare( 3 ,430,100,colors[ROYAL_BLUE]); 
	DrawSquare( 103 , 430 ,100,colors[LIGHT_CORAL]); 
	DrawSquare( 203 , 430 ,100,colors[ROYAL_BLUE]); 
	DrawSquare( 303 , 430 ,100,colors[LIGHT_CORAL]); 
	DrawSquare( 403 , 430 ,100,colors[ROYAL_BLUE]); 
	
	DrawSquare( 510 , 300,100,colors[FOREST_GREEN]); 
	DrawSquare( 510 ,200,100,colors[DARK_SLATE_GRAY]);  
	DrawSquare( 510, 100,100,colors[FOREST_GREEN]); 
	DrawSquare( 510,0,100,colors[DARK_SLATE_GRAY]);
	
	DrawSquare( 3 , 300,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 103 , 300 ,100,colors[CHOCOLATE]); 
	DrawSquare( 203 , 300 ,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 303 , 300 ,100,colors[CHOCOLATE]); 
	DrawSquare( 403 , 300 ,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 3 ,200,100,colors[CHOCOLATE]); 
	DrawSquare( 103 , 200 ,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 203 , 200 ,100,colors[CHOCOLATE]); 
	DrawSquare( 303 , 200 ,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 403 , 200 ,100,colors[CHOCOLATE]); 
	DrawSquare( 3 , 100,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 103 , 100 ,100,colors[CHOCOLATE]); 
	DrawSquare( 203 , 100 ,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 303 , 100 ,100,colors[CHOCOLATE]); 
	DrawSquare( 403 , 100 ,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 3,0,100,colors[CHOCOLATE]); 
	DrawSquare( 103 , 0 ,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 203 , 0 ,100,colors[CHOCOLATE]); 
	DrawSquare( 303 , 0 ,100,colors[BLANCHED_ALMOND]); 
	DrawSquare( 403 , 0 ,100,colors[CHOCOLATE]);

	DrawSquare( 510 , 730,100,colors[DARK_GRAY]); 
	DrawSquare( 610 , 730 ,100,colors[VIOLET]);
	DrawSquare( 510,630,100,colors[VIOLET]); 
	DrawSquare( 610 , 630 ,100,colors[DARK_GRAY]);
	DrawSquare( 510, 530,100,colors[DARK_GRAY]); 
	DrawSquare( 610 , 530 ,100,colors[VIOLET]); 
	DrawSquare( 510,430,100,colors[VIOLET]); 
	DrawLine( 710, 850 ,  710 , 0 , 10 , colors[BLACK] );
	DrawString( 900, 800, "MENU", colors[BLACK]);
	DrawLine( 710, 795 ,  1200 , 795 , 4 , colors[BLACK] );
	fstream obj;
	string str;
	obj.open("highscores.txt", ios::in);			// TO DISPLAY HIGHSCORES 	
    	int yOffset = 710;
    	while (getline(obj, str)) {
        DrawString(730, yOffset, str, colors[BLACK]);
        yOffset -= 40;
        }
	obj.close();
	string str1[6];
	if (t[51]!=1)						//TO TELL WHICH ROUND IS CURRENTLY BEING PLAYED
	DrawString(730, 760, "Round 1", colors[BLACK]);		// ROUND 1 IS TO SIMPLY OCCUPY TERRITORIES
	else DrawString(730, 760, "Round 2", colors[BLACK]);	// ROUNFD 2 IS TO ATTACK OR MOVE
	for (int l=0; l<players; l++){
		str1[l]=player[l];}				// TO TELL WHICH PLAYER'S TURN IS IT
	
	if (randno==1)
    		DrawString( 730, 470, str1[0].append("'s turn"), colors[BLACK]);
    	if (randno==2)
    		DrawString( 730, 470,str1[1].append("'s turn"), colors[BLACK]);
	if (randno==3)
    		DrawString( 730, 470, str1[2].append("'s turn"), colors[BLACK]);
    	if (randno==4)
    		DrawString( 730, 470,str1[3].append("'s turn"), colors[BLACK]);
    	if (randno==5)
    		DrawString( 730, 470,str1[4].append("'s turn"), colors[BLACK]);
    	if (randno==6)
    		DrawString( 730, 470,str1[5].append("'s turn"), colors[BLACK]);
    	
    	if (t[51]==1&&fight==0&&mov==0){
    		if (randno==1)
    			DrawString( 730, 430, str1[0].append("Place your troops"), colors[BLACK]);
    		if (randno==2)
    			DrawString( 730, 430,str1[1].append("Place your troops"), colors[BLACK]);
		if (randno==3)
    			DrawString( 730, 430, str1[2].append("Place your troops"), colors[BLACK]);
    		if (randno==4)
    			DrawString( 730, 430,str1[3].append("Place your troops"), colors[BLACK]);
    		if (randno==5)
    			DrawString( 730, 430,str1[4].append("Place your troops"), colors[BLACK]);
    		if (randno==6)
    			DrawString( 730, 430,str1[5].append("Place your troops"), colors[BLACK]);}
    	
    	if (t[51]==1&&fight==1&&mov==1){
    		DrawString( 730, 430,"Press right key to attack", colors[BLACK]);
    		DrawString( 730, 390,"Press left key to Move", colors[BLACK]);
    		DrawString( 730, 350,"Press down key to Skip", colors[BLACK]);}
    	if (fight==2){
    		DrawString( 730, 430,"Select your attacking territory and number of troops", colors[BLACK]);
    		DrawString( 730, 390,"1", colors[BLACK]);
    		DrawString( 780, 390,"2", colors[BLACK]);
    		DrawString( 830, 390,"3", colors[BLACK]);
    		DrawString( 880, 390,"4", colors[BLACK]);}
    	if (fight==3){
    		DrawString( 730, 430,"Select ememy's territory you'd attack.", colors[BLACK]);}
    	if (mov==2){
    		DrawString( 730, 430,"Select your moving territory and number of troops", colors[BLACK]);
    		DrawString( 730, 390,"1", colors[BLACK]);
    		DrawString( 780, 390,"2", colors[BLACK]);
    		DrawString( 830, 390,"3", colors[BLACK]);
    		DrawString( 880, 390,"4", colors[BLACK]);}
    		
    		
    	if (mov==3){
    		DrawString( 730, 430,"Select YOUR territory you'd move.", colors[BLACK]);}
    	if (s==1){
    		obj.open("leaderboard.txt", ios::in);			// TO DISPLAY THE LEADERBOARD
    		int yOffset = 310;
    		DrawString(730, 460, "Leaderboard", colors[BLACK]);
    		while (getline(obj, str)) {
        	DrawString(730, yOffset, str, colors[BLACK]);
		yOffset -= 40;
        }
	obj.close();
	}
	for (int i=0; i<51; i++){				// FOR THE COLOR OF EACH PLAYER'S TROOPS PLACEMENT
		if ((i>=0&&i<=4)||i==40||i==41)
			j=0;
		else if ((i>=5&&i<=9)||i==43||i==42)
			j=1;
		else if ((i>=10&&i<=14)||i==45||i==44)
			j=2;
		else if ((i>=15&&i<=19)||i==46)
			j=3;
		else if ((i>=20&&i<=24)||i==47)
			j=4;
		else if ((i>=25&&i<=29)||i==48)
			j=5;
		else if ((i>=30&&i<=34)||i==49)
			j=6;
		else if ((i>=35&&i<=39)||i==50)
			j=7;
		
		if (i==0||i==5||i==10||i==15||i==20||i==25||i==30||i==35)
			l=0;
		else if (i==1||i==6||i==11||i==16||i==21||i==26||i==31||i==36)
			l=1;
		else if (i==2||i==7||i==12||i==17||i==22||i==27||i==32||i==37)
			l=2;
		else if (i==3||i==8||i==13||i==18||i==23||i==28||i==33||i==38)
			l=3;	
		else if (i==4||i==9||i==14||i==19||i==24||i==29||i==34||i==39)
			l=4;
		else if (i==40||i==42||i==44||i==46||i==47||i==48||i==49||i==50)
			l=5;
		else if (i==41||i==43||i==45)
			l=6;
		
		
		if (t1[i]>=1){
			if (playerscol[0]=="red"){
				for (int z=0;z<t1[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[RED]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[RED]);}}
			else if (playerscol[0]=="black"){
				for (int z=0;z<t1[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[BLACK]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[BLACK]);}}
			else if (playerscol[0]=="yellow"){
				for (int z=0;z<t1[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE]);}}
			else if (playerscol[0]=="green"){
				for (int z=0;z<t1[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[GREEN]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[GREEN]);}}
			else if (playerscol[0]=="purple"){
				for (int z=0;z<t1[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[DARK_MAGENTA]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[DARK_MAGENTA]);}}
			else if (playerscol[0]=="orange"){
				for (int z=0;z<t1[i];z++){
				DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE_RED]);
				DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE_RED]);}}}
		else if (t2[i]>=1){
			if (playerscol[1]=="red"){
				for (int z=0;z<t2[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[RED]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[RED]);}}
			else if (playerscol[1]=="black"){
				for (int z=0;z<t2[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[BLACK]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[BLACK]);}}
			else if (playerscol[1]=="yellow"){
				for (int z=0;z<t2[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE]);}}
			else if (playerscol[1]=="green"){
				for (int z=0;z<t2[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[GREEN]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[GREEN]);}}
			else if (playerscol[1]=="purple"){
				for (int z=0;z<t2[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[DARK_MAGENTA]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[DARK_MAGENTA]);}}
			else if (playerscol[1]=="orange"){
				for (int z=0;z<t2[i];z++){
				DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE_RED]);
				DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE_RED]);}}}
		else if (t3[i]>=1){
			if (playerscol[2]=="red"){
				for (int z=0;z<t3[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[RED]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[RED]);}}
			else if (playerscol[2]=="black"){
				for (int z=0;z<t3[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[BLACK]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[BLACK]);}}
			else if (playerscol[2]=="yellow"){
				for (int z=0;z<t3[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE]);}}
			else if (playerscol[2]=="green"){
				for (int z=0;z<t3[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[GREEN]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[GREEN]);}}
			else if (playerscol[2]=="purple"){
				for (int z=0;z<t3[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[DARK_MAGENTA]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[DARK_MAGENTA]);}}
			else if (playerscol[2]=="orange"){
				for (int z=0;z<t3[i];z++){
				DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE_RED]);
				DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE_RED]);}}}
		else if (t4[i]>=1){
			if (playerscol[3]=="red"){
				for (int z=0;z<t4[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[RED]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[RED]);}}
			else if (playerscol[3]=="black"){
				for (int z=0;z<t4[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[BLACK]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[BLACK]);}}
			else if (playerscol[3]=="yellow"){
				for (int z=0;z<t4[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE]);}}
			else if (playerscol[3]=="green"){
				for (int z=0;z<t4[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[GREEN]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[GREEN]);}}
			else if (playerscol[3]=="purple"){
				for (int z=0;z<t4[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[DARK_MAGENTA]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[DARK_MAGENTA]);}}
			else if (playerscol[3]=="orange"){
				for (int z=0;z<t4[i];z++){
				DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE_RED]);
				DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE_RED]);}}}
		else if (t5[i]>=1){
			if (playerscol[4]=="red"){
				for (int z=0;z<t5[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[RED]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[RED]);}}
			else if (playerscol[4]=="black"){
				for (int z=0;z<t5[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[BLACK]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[BLACK]);}}
			else if (playerscol[4]=="yellow"){
				for (int z=0;z<t5[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE]);}}
			else if (playerscol[4]=="green"){
				for (int z=0;z<t5[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[GREEN]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[GREEN]);}}
			else if (playerscol[4]=="purple"){
				for (int z=0;z<t5[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[DARK_MAGENTA]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[DARK_MAGENTA]);}}
			else if (playerscol[4]=="orange"){
				for (int z=0;z<t5[i];z++){
				DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE_RED]);
				DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE_RED]);}}}
		else if (t6[i]>=1){
			if (playerscol[5]=="red"){
				for (int z=0;z<t6[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[RED]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[RED]);}}
			else if (playerscol[5]=="black"){
				for (int z=0;z<t6[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[BLACK]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[BLACK]);}}
			else if (playerscol[5]=="yellow"){
				for (int z=0;z<t6[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE]);}}
			else if (playerscol[5]=="green"){
				for (int z=0;z<t6[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[GREEN]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[GREEN]);}}
			else if (playerscol[5]=="purple"){
				for (int z=0;z<t6[i];z++){
					DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[DARK_MAGENTA]);
					DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[DARK_MAGENTA]);}}
			else if (playerscol[5]=="orange"){
				for (int z=0;z<t6[i];z++){
				DrawLine(coordx[l]+(7*z),coordy[j],coordx[l]+(7*z),(coordy[j]-15), 5,colors[ORANGE_RED]);
				DrawCircle(coordx[l]+(7*z), coordy[j], 5,colors[ORANGE_RED]);}}}
		if ((i>=0&&i<=4)||i==26||i==27)
		j=1;}}
	else{								// IF USER CLICKS DECLARE WINNER IN MENU
		if (winner[0]==1)
		DrawString(430, 430, "Player 1 won the game",colors[BLACK]);
		else if (winner[1]==1)
		DrawString(430, 430, "Player 2 won the game",colors[BLACK]);
		else if (winner[2]==1)
		DrawString(430, 430, "Player 3 won the game",colors[BLACK]);
		else if (winner[3]==1)
		DrawString(430, 430, "Player 4 won the game",colors[BLACK]);
		else if (winner[4]==1)
		DrawString(430, 430, "Player 5 won the game",colors[BLACK]);
		else if (winner[5]==1)
		DrawString(430, 430, "Player 6 won the game",colors[BLACK]);}
		
		glutSwapBuffers(); // do not modify this line..
}
void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		mov=2;}
	else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		fight=2;
		cout << fight << " ";}
	else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		c+=1;
		if (c>4){
			c=4;}
}
	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	fight=1;
	mov=1;}
glutPostRedisplay();}
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if (key == 'b' || key == 'B') //Key for placing the bomb
			{cout << "b pressed" << endl;
}
	glutPostRedisplay();
}

void Timer(int m) {
glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y) {
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

void menuCallback(int value) {
    switch (value) {			// MENU FOR CHOICES OF USER
        case 1:
            exit(0);
            break;
        case 2:
        	winnerDecider();
        	break;
        case 3:
		s=1;
		break;
        case 4:
        	s=0;
        	break;
	case 5:
		break;}
	
    }
void createmenu() {					// FUNCTION TO CREATE MENU
    	glutCreateMenu(menuCallback);
	glutAddMenuEntry("Exit", 1);
	glutAddMenuEntry("Declare winner right now", 2);
	glutAddMenuEntry("Leaderboard", 3);
	glutAddMenuEntry("Exit Leaderboard", 4);
    	glutAddMenuEntry("Close", 5);

	glutAttachMenu(GLUT_RIGHT_BUTTON); // You can change GLUT_RIGHT_BUTTON to the desired mouse button
}
void MouseClicked(int button, int state, int x, int y) {
    int width = 1200;
    int height = 840,ch=players;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { 
        winnerCheck();
        float X = static_cast<float>(x) / width;		// TO TAKE A CHECK OF WHICH TERRITORY USER WANTS TO OCCUPY
        float Y = 1.0 - static_cast<float>(y) / height; 
        cout << X*width << " " << Y*height << endl;
        if (dice==0)
		dice=100;
       if (i==0)
       i=players;
       for (int l=0; l<51; l++){
		if (t[l]==1)
		check+=1;}
	
	if (check==51){
		t[51]=1;}
       if (t[51]!=1){
        if (randno%i==0)
        	randno=rand()%players+1;
        cout << "Player " << randno << "'s turn:";
        territoryDecider(X,Y);
	ch+=1;
        i+=1;}
        for (int l=0; l<players; l++){
		score[l]=0;}
        for (int l=0; l<51; l++){
        	if (t1[l]>=1)
        	score[0]+=1;
        	if (t2[l]>=1)
        	score[1]+=1;
        	if (t3[l]>=1)
        	score[2]+=1;
        	if (t4[l]>=1)
        	score[3]+=1;
        	if (t5[l]>=1)
        	score[4]+=1;
        	if (t6[l]>=1)
        	score[5]+=1;}
        
        
        fstream obj;
	obj.open("highscores.txt", ios::out);			// TO WRITE THE HIGHSCORES IN HIGHSCORE FILE
	for (int l=0; l<players; l++){
	obj<<player[l]<< "_____" << score[l] << endl;}
	obj.close();
	int h=0;
	for (int l=0; l<51; l++){
		if(t[l]==1)
			h+=1;}
	if (h==51)
		t[51]=1;
	if (t[51]==1&&f==0){
	
		if(t[51]==1){
		extraTroops();}
		f+=1;}
	
	if (t[51]==1){
		if (randno%i==0)
        		randno=(rand()%players)+1;
		if (che==0){
			for (int l=0; l<players; l++){
				if (score[l]>greatest)
					greatest=l;}
			randno=greatest+1;
			che+=1;}
		
        	if (fight==0&&mov==0){
        		occTerrChecker(X,Y);}
        	if (fight==3){
         		defendTerr(X,Y);
         		if (randno>players)
         			randno=1;
         			r =0;}
        	if (fight==2){
         		if (r ==0){
         		if (X >= 789.0 / width && X <= 801.0 / width &&
           		Y >= 465.0 / height && Y <= 480.0 / height) {
            			troop=1;
            			r =1; }
            		if (X >= 841.0 / width && X <= 856.0 / width &&
           		Y >= 465.0 / height && Y <= 480.0 / height) {
            			troop=2; 
            			r =1;}
            		if (X >= 893.0 / width && X <= 911.0 / width &&
           		Y >= 465.0 / height && Y <= 480.0 / height) {
            			troop=3; 
            			r =1;}
            		if (X >= 951.0 / width && X <= 963.0 / width &&
           		Y >= 465.0 / height && Y <= 480.0 / height) {
            			troop=4; 
            			r =1;}}
            		if (r ==1){
            			attackTerr(X,Y);}
            		if (r ==2){
            			fight=3;}}
         	if (mov==3){
         		moveTerr(X,Y);
         		if (randno>players)
         			randno=1;
         			g=0;}
         	if (mov==2){
         		if (g==0){
         		if (X >= 789.0 / width && X <= 801.0 / width &&
           		Y >= 465.0 / height && Y <= 480.0 / height) {
            			troop=1;
            			g=1; }
            		if (X >= 841.0 / width && X <= 856.0 / width &&
           		Y >= 465.0 / height && Y <= 480.0 / height) {
            			troop=2; 
            			g=1;}
            		if (X >= 893.0 / width && X <= 911.0 / width &&
           		Y >= 465.0 / height && Y <= 480.0 / height) {
            			troop=3; 
            			g=1;}
            		if (X >= 951.0 / width && X <= 963.0 / width &&
           		Y >= 465.0 / height && Y <= 480.0 / height) {
            			troop=4; 
            			g=1;}}
            		if (g==1)
            			moveTerrCheck(X,Y);
            		if (g==2)
            			mov=3;}}
         	
    glutPostRedisplay();
}}

int main(int argc, char*argv[]) {
	int width = 1200, height = 840; 
	 InitRandomizer(); // seed the randno number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	createmenu();
	do {cout << "Enter the number of players:";
	cin >> players;} while (players<2||players>6);
	randno=players;
	if (players==2){
		troops1=40;
		troops2=40;}
	if (players==3){
		troops1=35;
		troops2=35;
		troops3=35;}
	if (players==4){
		troops1=30;
		troops2=30;
		troops3=30;
		troops4=30;}	
	if (players==5){
		troops1=25;
		troops2=25;
		troops3=25;
		troops4=25;
		troops5=25;}
	if (players==6){
		troops1=20;
		troops2=20;
		troops3=20;
		troops4=20;
		troops5=20;
		troops6=20;}
		
	
	for (int l=0; l<players; l++){
		cout << "Enter name of Player "<< l+1<<":";
		cin >> player[l];}
	colorSelector();
	fstream obj;
	obj.open("highscores.txt", ios::out);
	for (int l=0; l<players; l++){	
	obj<<player[l]<< "_____" << "0" << endl;}
	obj.close();
	
	
	glutTimerFunc(1000.0, Timer, 0);
	glutMouseFunc(MouseClicked);
	/*
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse*/
	glutMainLoop();
	return 1;
}
void winnerCheck(){
	int win=0;
	for (int l=0; l<51; l++){
		if (t1[l]>=1)
			win+=1;}
	if (win==51){
		winner[0]=1;}
	else win=0;
	for (int l=0; l<51; l++){
		if (t2[l]>=1)
			win+=1;}
	if (win==51){
		winner[1]=1;}
	else win=0;
	for (int l=0; l<51; l++){
		if (t3[l]>=1)
			win+=1;}
	if (win==51){
		winner[2]=1;}
	else win=0;
	for (int l=0; l<51; l++){
		if (t4[l]>=1)
			win+=1;}
	if (win==51){
		winner[3]=1;}
	else win=0;
	for (int l=0; l<51; l++){
		if (t5[l]>=1)
			win+=1;}
	if (win==51){
		winner[4]=1;}
	else win=0;
	for (int l=0; l<51; l++){
		if (t6[l]>=1)
			win+=1;}
	if (win==51){
		winner[5]=1;}
	else win=0;}
void extraTroops(){ 
	p1occ=troops1-score[0];
        p2occ=troops2-score[1];
        p3occ=troops3-score[2];
       	p4occ=troops4-score[3];
        p5occ=troops5-score[4];
        p6occ=troops6-score[5];

}
void colorSelector(){		// FUNCTION FOR EACH PLAYER TO SELECT COLOR
	int num;
	bool colorTaken[6] = {false}; 
	for (int l=0; l<players;l++){
	
		do{cout<< player[l] << "\npress 1 for red\npress 2 for black\npress 3 for yellow\npress 4 for orange\npress 5 for purple\npress 6 for green\nyou can't choose an already chosen colour";
		cin>> num;} while (colorTaken[num-1]||(num<1||num>6));
		switch (num){
			case 1:
				playerscol[l]="red";
				colorTaken[0]=true;
				break;
			case 2:
				playerscol[l]="black";
				colorTaken[1]=true;
				break;
			case 3:
				playerscol[l]="yellow";
				colorTaken[2]=true;
				break;
			case 4:
				playerscol[l]="orange";
				colorTaken[3]=true;
				break;
			case 5:
				playerscol[l]="purple";
				colorTaken[4]=true;
				break;
			case 6:
				playerscol[l]="green";
				colorTaken[5]=true;
				break;}}}
void winnerDecider(){	// TO DECIDE WINNER IN THE MIDDLE OF THE GAME IF USER WANTS TO DECLARE WINNER
	int s1,s2,s3,s4,s5,s6;
		if (score[0]>score[1]&&score[0]>score[2]&&score[0]>score[3]&&score[0]>score[4]&&score[0]>score[5])
        		winner[0]=1;
        	else if (score[1]>score[0]&&score[1]>score[2]&&score[1]>score[3]&&score[1]>score[4]&&score[1]>score[5])
        		winner[1]=1;
        	else if (score[2]>score[0]&&score[2]>score[1]&&score[2]>score[3]&&score[2]>score[4]&&score[2]>score[5])
        		winner[2]=1;
        	else if (score[3]>score[0]&&score[3]>score[2]&&score[3]>score[1]&&score[3]>score[4]&&score[3]>score[5])
        		winner[3]=1;
        	else if (score[4]>score[0]&&score[4]>score[2]&&score[4]>score[3]&&score[4]>score[1]&&score[4]>score[5])
        		winner[4]=1;
        	else if (score[5]>score[0]&&score[5]>score[2]&&score[5]>score[3]&&score[5]>score[4]&&score[5]>score[1])
        		winner[5]=1;
        	else {
        		for (int l=1; l<5; l++){
        			if (score[0]>score[l])
        				s1+=1;}
        		for (int l=0; l<5; l++){
        			if (l==1)
        				continue;
        			if (score[1]>score[l])
        				s2+=1;}
        		for (int l=0; l<5; l++){
        			if (l==2)
        				continue;
        			if (score[2]>score[l])
        				s3+=1;}
        		for (int l=0; l<5; l++){
        			if (l==3)
        				continue;
        			if (score[3]>score[l])
        				s4+=1;}
        		for (int l=0; l<5; l++){
        			if (l==4)
        				continue;
        			if (score[4]>score[l])
        				s5+=1;}
        		for (int l=0; l<5; l++){
        			if (l==5)
        				continue;
        			if (score[5]>score[l])
        				s6+=1;}
        	
        	if (s1<s2||s1<s3||s1<s4||s1<s5||s1<s6)
        		s1=0;
        	else if (s2<s1||s2<s3||s2<s4||s2<s5||s2<s6)
        		s2=0;	
        	else if (s3<s1||s3<s2||s3<s4||s3<s5||s3<s6)
        		s3=0;
        	else if (s4<s1||s4<s3||s4<s2||s4<s5||s4<s6)
        		s4=0;
        	else if (s5<s1||s5<s3||s5<s4||s5<s2||s5<s6)
        		s5=0;
        	else if (s6<s1||s6<s3||s6<s4||s6<s5||s6<s2)
        		s2=0;
        	
        	int z=(rand()%players)+1;
        	if (z==1&&s1==0){
        		do {z=(rand()%players)+1;}while (z==1);}
        	else if (z==2&&s2==0){
        		do {z=(rand()%players)+1;}while (z==2);}
        	else if (z==3&&s3==0){
        		do {z=(rand()%players)+1;}while (z==3);}	
        	else if (z==4&&s4==0){
        		do {z=(rand()%players)+1;}while (z==4);}	
        	else if (z==5&&s5==0){
        		do {z=(rand()%players)+1;}while (z==5);}
        	else if (z==6&&s6==0){
        		do {z=(rand()%players)+1;}while (z==6);}
        	else if (z==1&&s1!=0)
        		winner[0]=1;
        	else if (z==2&&s2!=0)
        		winner[1]=1;
        	else if (z==3&&s3!=0)
        		winner[2]=1;
        	else if (z==4&&s4!=0)
        		winner[3]=1;
        	else if (z==5&&s5!=0)
        		winner[4]=1;
        	else if (z==6&&s6!=0)
        		winner[5]=1;
        	}
	}
void defendTerr(float X, float Y){
	int width = 1200;
   	int height = 840;
   	if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selte = 1;
            }
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[1]=1;
            selte = 2;}
         if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selte = 3;}
         if (X >326.0 / width && X <= 436.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selte = 4;}
          if (X >436.0 / width && X <= 542.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selte = 5;}   
          if (X > 3.0 / width && X <=109.0 / width &&
            Y >662.0  / height && Y < 748.0 / height) {
           selte = 6;}
           if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selte = 7;}
           if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selte = 8;}
           if (X >326.0 / width && X <= 436.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selte = 9;} 
           if (X >436.0 / width && X <= 542.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selte = 10;}
           if (X > 3.0 / width && X <=109.0 / width &&
            Y >579.0  / height && Y < 662.0 / height) {
           selte = 11;}
            if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selte = 12;}
 	if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selte = 13;}
         if (X >326.0 / width && X <= 436.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selte = 14;}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selte = 15;}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >495.0  / height && Y < 579.0 / height) {
           selte = 16;}
         if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selte = 17;}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selte = 18;}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selte = 19;}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selte = 20;}
         if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 388.0 / height && Y <= 469.0 / height) {
            selte = 21;}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selte = 22;}
         if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selte = 23;}
          if (X >326.0 / width && X <= 436.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selte = 24;}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selte = 25;}
       if (X > 3.0 / width && X <=109.0 / width &&
            Y >303.0  / height && Y < 388.0 / height) {
           selte = 26;}
         if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selte = 27;}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selte = 28;}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selte = 29;}
	if (X >436.0 / width && X <= 542.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selte = 30;}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >219.0  / height && Y < 303.0 / height) {
           selte = 31;}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selte = 32;}
       if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selte = 33;}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selte = 34;}
         if (X >436.0 / width && X <= 542.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selte = 35;}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >136.0  / height && Y < 219.0 / height) {
           selte = 36;}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selte = 37;}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selte = 38;}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selte = 39;}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selte = 40;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selte = 41;}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[41]=1;
            selte = 42;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 663.0 / height && Y <= 747.0 / height) {
            selte = 43;}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 663.0 / height && Y <= 747.0 / height) {
            t[43]=1;
            selte = 44;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 580.0 / height && Y <= 663.0 / height) {
            selte = 45;}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 580.0 / height && Y <= 663.0 / height) {
            t[45]=1;
            selte = 46;}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 495.0 / height && Y <= 580.0 / height) {
            selte = 47;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 387.0 / height && Y <= 469.0 / height) {
            selte = 48;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 302.0 / height && Y < 387.0 / height) {
            selte = 49;}
         if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 219.0 / height && Y <= 302.0 / height) {
            selte =50;}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 130.0 / height && Y <= 219.0 / height) {
            selte = 51;}
            
         if (randno==1){
        	if (t1[selte-1]<=0){
        		dice=rand()%2;
        		if (dice==0){
        			if (t2[selte-1]>=1){
					t2[terrcheck-1]=t1[terrcheck-1];
					t1[terrcheck-1]=0;}
     				else if (t3[selte-1]>=1){
					t3[terrcheck-1]=t1[terrcheck-1];
					t1[terrcheck-1]=0;}
				else if (t4[selte-1]>=1){
					t4[terrcheck-1]=t1[terrcheck-1];
					t1[terrcheck-1]=0;}
				else if (t5[selte-1]>=1){
					t5[terrcheck-1]=t1[terrcheck-1];
					t1[terrcheck-1]=0;}
				else if (t6[selte-1]>=1){
					t6[terrcheck-1]=t1[terrcheck-1];
					t1[terrcheck-1]=0;}}
        		else {
        			if (t2[selte-1]>=1){
					t1[selte-1]=t2[selte-1];
					t2[selte-1]=0;}
     				else if (t3[selte-1]>=1){
					t1[selte-1]=t3[selte-1];
					t3[selte-1]=0;}
				else if (t4[selte-1]>=1){
					t1[selte-1]=t4[selte-1];
					t4[selte-1]=0;}
				else if (t5[selte-1]>=1){
					t1[selte-1]=t5[selte-1];
					t5[selte-1]=0;}
				else if (t6[selte-1]>=1){
					t1[selte-1]=t6[selte-1];
					t6[selte-1]=0;}}
			randno+=1;}}
        else if (randno==2){
        	if (t2[selte-1]<=0){
        		dice=rand()%2;
        		if (dice==0){
        			if (t1[selte-1]>=1){
					t1[terrcheck-1]=t2[terrcheck-1];
					t2[terrcheck-1]=0;}
     				else if (t3[selte-1]>=1){
					t3[terrcheck-1]=t2[terrcheck-1];
					t2[terrcheck-1]=0;}
				else if (t4[selte-1]>=1){
					t4[terrcheck-1]=t2[terrcheck-1];
					t2[terrcheck-1]=0;}
				else if (t5[selte-1]>=1){
					t5[terrcheck-1]=t2[terrcheck-1];
					t2[terrcheck-1]=0;}
				else if (t6[selte-1]>=1){
					t6[terrcheck-1]=t2[terrcheck-1];
					t2[terrcheck-1]=0;}}
        		else {
        			if (t2[selte-1]>=1){
					t2[selte-1]=t1[selte-1];
					t1[selte-1]=0;}
     				else if (t3[selte-1]>=1){
					t2[selte-1]=t3[selte-1];
					t3[selte-1]=0;}
				else if (t4[selte-1]>=1){
					t2[selte-1]=t4[selte-1];
					t4[selte-1]=0;}
				else if (t5[selte-1]>=1){
					t2[selte-1]=t5[selte-1];
					t5[selte-1]=0;}
				else if (t6[selte-1]>=1){
					t2[selte-1]=t6[selte-1];
					t6[selte-1]=0;}}
			randno+=1;}}
        else if (randno==3){
        	if (t3[selte-1]<=0){
        		dice=rand()%2;
        		if (dice==0){
        			if (t2[selte-1]>=1){
					t2[terrcheck-1]=t3[terrcheck-1];
					t3[terrcheck-1]=0;}
     				else if (t1[selte-1]>=1){
					t1[terrcheck-1]=t3[terrcheck-1];
					t3[terrcheck-1]=0;}
				else if (t4[selte-1]>=1){
					t4[terrcheck-1]=t3[terrcheck-1];
					t3[terrcheck-1]=0;}
				else if (t5[selte-1]>=1){
					t5[terrcheck-1]=t3[terrcheck-1];
					t3[terrcheck-1]=0;}
				else if (t6[selte-1]>=1){
					t6[terrcheck-1]=t3[terrcheck-1];
					t3[terrcheck-1]=0;}}
        		else {
        			if (t2[selte-1]>=1){
					t3[selte-1]=t2[selte-1];
					t2[selte-1]=0;}
     				else if (t1[selte-1]>=1){
					t3[selte-1]=t1[selte-1];
					t1[selte-1]=0;}
				else if (t4[selte-1]>=1){
					t3[selte-1]=t4[selte-1];
					t4[selte-1]=0;}
				else if (t5[selte-1]>=1){
					t3[selte-1]=t5[selte-1];
					t5[selte-1]=0;}
				else if (t6[selte-1]>=1){
					t3[selte-1]=t6[selte-1];
					t6[selte-1]=0;}}
			randno+=1;}}
        else if (randno==4){
        	if (t4[selte-1]<=0){
        		dice=rand()%2;
        		if (dice==0){
        			if (t2[selte-1]>=1){
					t2[terrcheck-1]=t4[terrcheck-1];
					t4[terrcheck-1]=0;}
     				else if (t3[selte-1]>=1){
					t3[terrcheck-1]=t4[terrcheck-1];
					t4[terrcheck-1]=0;}
				else if (t1[selte-1]>=1){
					t1[terrcheck-1]=t4[terrcheck-1];
					t4[terrcheck-1]=0;}
				else if (t5[selte-1]>=1){
					t5[terrcheck-1]=t4[terrcheck-1];
					t4[terrcheck-1]=0;}
				else if (t6[selte-1]>=1){
					t6[terrcheck-1]=t4[terrcheck-1];
					t4[terrcheck-1]=0;}}
        		else {
        			if (t2[selte-1]>=1){
					t4[selte-1]=t2[selte-1];
					t2[selte-1]=0;}
     				else if (t3[selte-1]>=1){
					t4[selte-1]=t3[selte-1];
					t3[selte-1]=0;}
				else if (t1[selte-1]>=1){
					t4[selte-1]=t4[selte-1];
					t1[selte-1]=0;}
				else if (t5[selte-1]>=1){
					t4[selte-1]=t5[selte-1];
					t5[selte-1]=0;}
				else if (t6[selte-1]>=1){
					t4[selte-1]=t6[selte-1];
					t6[selte-1]=0;}}
			randno+=1;}}	
        else if (randno==5){
        	if (t5[selte-1]<=0){
        	dice=rand()%2;
        		if (dice==0){
        			if (t2[selte-1]>=1){
					t2[terrcheck-1]=t5[terrcheck-1];
					t5[terrcheck-1]=0;}
     				else if (t3[selte-1]>=1){
					t3[terrcheck-1]=t5[terrcheck-1];
					t5[terrcheck-1]=0;}
				else if (t4[selte-1]>=1){
					t4[terrcheck-1]=t5[terrcheck-1];
					t5[terrcheck-1]=0;}
				else if (t1[selte-1]>=1){
					t1[terrcheck-1]=t5[terrcheck-1];
					t5[terrcheck-1]=0;}
				else if (t6[selte-1]>=1){
					t6[terrcheck-1]=t5[terrcheck-1];
					t5[terrcheck-1]=0;}}
        		else {
        			if (t2[selte-1]>=1){
					t5[selte-1]=t2[selte-1];
					t2[selte-1]=0;}
     				else if (t3[selte-1]>=1){
					t5[selte-1]=t3[selte-1];
					t3[selte-1]=0;}
				else if (t4[selte-1]>=1){
					t5[selte-1]=t4[selte-1];
					t4[selte-1]=0;}
				else if (t1[selte-1]>=1){
					t5[selte-1]=t1[selte-1];
					t1[selte-1]=0;}
				else if (t6[selte-1]>=1){
					t5[selte-1]=t6[selte-1];
					t6[selte-1]=0;}}
			randno+=1;}}
        else if (randno==6){
        	if (t6[selte-1]<=0){
        		dice=rand()%2;
        		if (dice==0){
        			if (t2[selte-1]>=1){
					t2[terrcheck-1]=t6[terrcheck-1];
					t6[terrcheck-1]=0;}
     				else if (t3[selte-1]>=1){
					t3[terrcheck-1]=t6[terrcheck-1];
					t6[terrcheck-1]=0;}
				else if (t4[selte-1]>=1){
					t4[terrcheck-1]=t6[terrcheck-1];
					t6[terrcheck-1]=0;}
				else if (t1[selte-1]>=1){
					t1[terrcheck-1]=t6[terrcheck-1];
					t6[terrcheck-1]=0;}
				else if (t5[selte-1]>=1){
					t5[terrcheck-1]=t6[terrcheck-1];
					t6[terrcheck-1]=0;}}
        		else {
        			if (t2[selte-1]>=1){
					t6[selte-1]=t2[selte-1];
					t2[selte-1]=0;}
     				else if (t3[selte-1]>=1){
					t6[selte-1]=t3[selte-1];
					t3[selte-1]=0;}
				else if (t4[selte-1]>=1){
					t6[selte-1]=t4[selte-1];
					t4[selte-1]=0;}
				else if (t1[selte-1]>=1){
					t6[selte-1]=t1[selte-1];
					t1[selte-1]=0;}
				else if (t5[selte-1]>=1){
					t6[selte-1]=t5[selte-1];
					t5[selte-1]=0;}}
			randno+=1;}}   
            }
void attackTerr(float X, float Y){
	int width = 1200;
   	int height = 840;
   	if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            terrcheck = 1;}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[1]=1;
            terrcheck = 2;}
         if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            terrcheck = 3;}
         if (X >326.0 / width && X <= 436.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            terrcheck = 4;}
          if (X >436.0 / width && X <= 542.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            terrcheck = 5;}   
          if (X > 3.0 / width && X <=109.0 / width &&
            Y >662.0  / height && Y < 748.0 / height) {
           terrcheck = 6;}
           if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            terrcheck = 7;}
           if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            terrcheck = 8;}
           if (X >326.0 / width && X <= 436.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            terrcheck = 9;} 
           if (X >436.0 / width && X <= 542.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            terrcheck = 10;}
           if (X > 3.0 / width && X <=109.0 / width &&
            Y >579.0  / height && Y < 662.0 / height) {
           terrcheck = 11;}
            if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            terrcheck = 12;}
 	if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            terrcheck = 13;}
         if (X >326.0 / width && X <= 436.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            terrcheck = 14;}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            terrcheck = 15;}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >495.0  / height && Y < 579.0 / height) {
           terrcheck = 16;}
         if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            terrcheck = 17;}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            terrcheck = 18;}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            terrcheck = 19;}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            terrcheck = 20;}
         if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 388.0 / height && Y <= 469.0 / height) {
            terrcheck = 21;}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            terrcheck = 22;}
         if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            terrcheck = 23;}
          if (X >326.0 / width && X <= 436.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            terrcheck = 24;}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            terrcheck = 25;}
       if (X > 3.0 / width && X <=109.0 / width &&
            Y >303.0  / height && Y < 388.0 / height) {
           terrcheck = 26;}
         if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            terrcheck = 27;}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            terrcheck = 28;}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            terrcheck = 29;}
	if (X >436.0 / width && X <= 542.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            terrcheck = 30;}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >219.0  / height && Y < 303.0 / height) {
           terrcheck = 31;}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            terrcheck = 32;}
       if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            terrcheck = 33;}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            terrcheck = 34;}
         if (X >436.0 / width && X <= 542.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            terrcheck = 35;}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >136.0  / height && Y < 219.0 / height) {
           terrcheck = 36;}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            terrcheck = 37;}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            terrcheck = 38;}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            terrcheck = 39;}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            terrcheck = 40;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            terrcheck = 41;}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[41]=1;
            terrcheck = 42;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 663.0 / height && Y <= 747.0 / height) {
            terrcheck = 43;}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 663.0 / height && Y <= 747.0 / height) {
            t[43]=1;
            terrcheck = 44;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 580.0 / height && Y <= 663.0 / height) {
            terrcheck = 45;}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 580.0 / height && Y <= 663.0 / height) {
            t[45]=1;
            terrcheck = 46;}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 495.0 / height && Y <= 580.0 / height) {
            terrcheck = 47;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 387.0 / height && Y <= 469.0 / height) {
            terrcheck = 48;}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 302.0 / height && Y < 387.0 / height) {
            terrcheck = 49;}
         if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 219.0 / height && Y <= 302.0 / height) {
            terrcheck =50;}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 130.0 / height && Y <= 219.0 / height) {
            terrcheck = 51;} 
            
        if (randno==1){
        	if (t1[terrcheck-1]>=1){
        		r =2;}}
        if (randno==2){
        	if (t2[terrcheck-1]>=1){
        		r =2;}}
        if (randno==3){
        	if (t3[terrcheck-1]>=1){
        		r =2;}}
        if (randno==4){
        	if (t4[terrcheck-1]>=1){
        		r =2;}}	
        if (randno==5){
        	if (t5[terrcheck-1]>=1){
        		r =2;}}
       if (randno==6){
        	if (t6[terrcheck-1]>=1){
        		r =2;}}			
   	}
void moveTerr(float X, float Y){
	int width = 1200;
   	int height = 840;
   	if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 1;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[0]>=1){
            	t1[0]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[0]>=1){
          	 t2[0]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[0]>=1){
           	t3[0]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[0]>=1){
            	t4[0]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[0]>=1){
            	t5[0]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[0]>=1){
           	 t6[0]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[1]=1;
            selectedterritory = 2;
            cout << "Troops landed in Territory " << selectedterritory << endl;
              if (randno==1 && t1[1]>=1){
            	t1[1]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[1]>=1){
          	 t2[1]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[1]>=1){
           	t3[1]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[1]>=1){
            	t4[1]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[1]>=1){
            	t5[1]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[1]>=1){
           	 t6[1]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 3;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[2]>=1){
            	t1[2]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[2]>=1){
          	 t2[2]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[2]>=1){
           	t3[2]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[2]>=1){
            	t4[2]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[2]>=1){
            	t5[2]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[2]>=1){
           	 t6[2]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 4;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[3]>=1){
            	t1[3]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[3]>=1){
          	 t2[3]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[3]>=1){
           	t3[3]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[3]>=1){
            	t4[3]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[3]>=1){
            	t5[3]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[3]>=1){
           	 t6[3]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 5;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[4]>=1){
            	t1[4]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[4]>=1){
          	 t2[4]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[4]>=1){
           	t3[4]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[4]>=1){
            	t4[4]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[4]>=1){
            	t5[4]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[4]>=1){
           	 t6[4]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >662.0  / height && Y < 748.0 / height) {
           selectedterritory = 6;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[5]>=1){
            	t1[5]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[5]>=1){
          	 t2[5]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[5]>=1){
           	t3[5]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[5]>=1){
            	t4[5]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[5]>=1){
            	t5[5]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[5]>=1){
           	 t6[5]+=troop;
            	 randno+=1;
            	mov=1; }}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 7;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[6]>=1){
            	t1[6]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[6]>=1){
          	 t2[6]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[6]>=1){
           	t3[6]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[6]>=1){
            	t4[6]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[6]>=1){
            	t5[6]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[6]>=1){
           	 t6[6]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 8;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[7]>=1){
            	t1[7]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[7]>=1){
          	 t2[7]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[7]>=1){
           	t3[7]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[7]>=1){
            	t4[7]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[7]>=1){
            	t5[7]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[7]>=1){
           	 t6[7]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 9;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[8]>=1){
            	t1[8]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[8]>=1){
          	 t2[8]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[8]>=1){
           	t3[8]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[8]>=1){
            	t4[8]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[8]>=1){
            	t5[8]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[8]>=1){
           	 t6[8]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 10;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[9]>=1){
            	t1[9]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[9]>=1){
          	 t2[9]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[9]>=1){
           	t3[9]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[9]>=1){
            	t4[9]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[9]>=1){
            	t5[9]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[9]>=1){
           	 t6[9]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >579.0  / height && Y < 662.0 / height) {
           selectedterritory = 11;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[10]>=1){
            	t1[10]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[10]>=1){
          	 t2[10]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[10]>=1){
           	t3[10]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[10]>=1){
            	t4[10]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[10]>=1){
            	t5[10]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[10]>=1){
           	 t6[10]+=troop;
            	 randno+=1;
            	mov=1; }}
        
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 12;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[11]>=1){
            	t1[11]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[11]>=1){
          	 t2[11]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[11]>=1){
           	t3[11]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[11]>=1){
            	t4[11]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[11]>=1){
            	t5[11]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[11]>=1){
           	 t6[11]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 13;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[12]>=1){
            	t1[12]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[12]>=1){
          	 t2[12]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[12]>=1){
           	t3[12]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[12]>=1){
            	t4[12]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[12]>=1){
            	t5[12]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[12]>=1){
           	 t6[12]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 14;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[13]>=1){
            	t1[13]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[13]>=1){
          	 t2[13]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[13]>=1){
           	t3[13]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[13]>=1){
            	t4[13]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[13]>=1){
            	t5[13]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[13]>=1){
           	 t6[13]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 15;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[14]>=1){
            	t1[14]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[14]>=1){
          	 t2[14]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[14]>=1){
           	t3[14]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[14]>=1){
            	t4[14]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[14]>=1){
            	t5[14]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[14]>=1){
           	 t6[14]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >495.0  / height && Y < 579.0 / height) {
           selectedterritory = 16;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[15]>=1){
            	t1[15]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[15]>=1){
          	 t2[15]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[15]>=1){
           	t3[15]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[15]>=1){
            	t4[15]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[15]>=1){
            	t5[15]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[15]>=1){
           	 t6[15]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 17;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[16]>=1){
            	t1[16]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[16]>=1){
          	 t2[16]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[16]>=1){
           	t3[16]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[16]>=1){
            	t4[16]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[16]>=1){
            	t5[16]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[16]>=1){
           	 t6[16]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 18;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[17]>=1){
            	t1[17]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[17]>=1){
          	 t2[17]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[17]>=1){
           	t3[17]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[17]>=1){
            	t4[17]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[17]>=1){
            	t5[17]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[17]>=1){
           	 t6[17]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 19;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[18]>=1){
            	t1[18]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[18]>=1){
          	 t2[18]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[18]>=1){
           	t3[18]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[18]>=1){
            	t4[18]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[18]>=1){
            	t5[18]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[18]>=1){
           	 t6[18]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 20;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[19]>=1){
            	t1[19]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[19]>=1){
          	 t2[19]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[19]>=1){
           	t3[19]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[19]>=1){
            	t4[19]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[19]>=1){
            	t5[19]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[19]>=1){
           	 t6[19]+=troop;
            	 randno+=1;
            	mov=1; }}
        
        
        
        if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 21;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[20]>=1){
            	t1[20]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[20]>=1){
          	 t2[20]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[20]>=1){
           	t3[20]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[20]>=1){
            	t4[20]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[20]>=1){
            	t5[20]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[20]>=1){
           	 t6[20]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 22;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[21]>=1){
            	t1[21]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[21]>=1){
          	 t2[21]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[21]>=1){
           	t3[21]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[21]>=1){
            	t4[21]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[21]>=1){
            	t5[21]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[21]>=1){
           	 t6[21]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 23;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[22]>=1){
            	t1[22]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[22]>=1){
          	 t2[22]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[22]>=1){
           	t3[22]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[22]>=1){
            	t4[22]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[22]>=1){
            	t5[22]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[22]>=1){
           	 t6[22]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 24;
          if (randno==1 && t1[23]>=1){
            	t1[23]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[23]>=1){
          	 t2[23]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[23]>=1){
           	t3[23]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[23]>=1){
            	t4[23]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[23]>=1){
            	t5[23]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[23]>=1){
           	 t6[23]+=troop;
            	 randno+=1;
            	mov=1; }cout << "Troops landed in Territory " << selectedterritory << endl;
            }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 25;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[24]>=1){
            	t1[24]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[24]>=1){
          	 t2[24]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[24]>=1){
           	t3[24]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[24]>=1){
            	t4[24]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[24]>=1){
            	t5[24]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[24]>=1){
           	 t6[24]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >303.0  / height && Y < 388.0 / height) {
           selectedterritory = 26;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[25]>=1){
            	t1[25]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[25]>=1){
          	 t2[25]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[25]>=1){
           	t3[25]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[25]>=1){
            	t4[25]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[25]>=1){
            	t5[25]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[25]>=1){
           	 t6[25]+=troop;
            	 randno+=1;
            	mov=1; }}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 27;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[26]>=1){
            	t1[26]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[26]>=1){
          	 t2[26]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[26]>=1){
           	t3[26]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[26]>=1){
            	t4[26]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[26]>=1){
            	t5[26]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[26]>=1){
           	 t6[26]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 28;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[27]>=1){
            	t1[27]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[27]>=1){
          	 t2[27]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[27]>=1){
           	t3[27]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[27]>=1){
            	t4[27]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[27]>=1){
            	t5[27]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[27]>=1){
           	 t6[27]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 29;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[28]>=1){
            	t1[28]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[28]>=1){
          	 t2[28]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[28]>=1){
           	t3[28]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[28]>=1){
            	t4[28]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[28]>=1){
            	t5[28]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[28]>=1){
           	 t6[28]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 30;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[29]>=1){
            	t1[29]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[29]>=1){
          	 t2[29]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[29]>=1){
           	t3[29]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[29]>=1){
            	t4[29]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[29]>=1){
            	t5[29]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[29]>=1){
           	 t6[29]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >219.0  / height && Y < 303.0 / height) {
           selectedterritory = 31;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[30]>=1){
            	t1[30]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[30]>=1){
          	 t2[30]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[30]>=1){
           	t3[30]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[30]>=1){
            	t4[30]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[30]>=1){
            	t5[30]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[30]>=1){
           	 t6[30]+=troop;
            	 randno+=1;
            	mov=1; }}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 32;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[31]>=1){
            	t1[31]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[31]>=1){
          	 t2[31]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[31]>=1){
           	t3[31]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[31]>=1){
            	t4[31]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[31]>=1){
            	t5[31]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[31]>=1){
           	 t6[31]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 33;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[32]>=1){
            	t1[32]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[32]>=1){
          	 t2[32]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[32]>=1){
           	t3[32]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[32]>=1){
            	t4[32]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[32]>=1){
            	t5[32]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[32]>=1){
           	 t6[32]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 34;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[33]>=1){
            	t1[33]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[33]>=1){
          	 t2[33]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[33]>=1){
           	t3[33]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[33]>=1){
            	t4[33]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[33]>=1){
            	t5[33]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[33]>=1){
           	 t6[33]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 35;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[34]>=1){
            	t1[34]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[34]>=1){
          	 t2[34]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[34]>=1){
           	t3[34]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[34]>=1){
            	t4[34]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[34]>=1){
            	t5[34]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[34]>=1){
           	 t6[34]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >136.0  / height && Y < 219.0 / height) {
           selectedterritory = 36;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[35]>=1){
            	t1[35]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[35]>=1){
          	 t2[35]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[35]>=1){
           	t3[35]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[35]>=1){
            	t4[35]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[35]>=1){
            	t5[35]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[35]>=1){
           	 t6[35]+=troop;
            	 randno+=1;
            	mov=1; }}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 37;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[36]>=1){
            	t1[36]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[36]>=1){
          	 t2[36]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[36]>=1){
           	t3[36]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[36]>=1){
            	t4[36]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[36]>=1){
            	t5[36]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[36]>=1){
           	 t6[36]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 38;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[37]>troop){
            	t1[37]-=troop;
            	g+=1;}
            if (randno==2&& t2[37]>troop){
          	 t2[37]-=troop;
          	 g+=1;}
            if (randno==3&& t3[37]>troop){
           	t3[37]-=troop;
           	 g+=1;}
            if (randno==4&& t4[37]>troop){
            	t4[37]-=troop;
            	g+=1;}
            if (randno==5 && t5[37]>troop){
            	t5[37]-=troop;
            	g+=1; }
            if (randno==6&&t6[37]>troop){
           	 t6[37]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 39;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[38]>=1){
            	t1[38]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[38]>=1){
          	 t2[38]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[38]>=1){
           	t3[38]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[38]>=1){
            	t4[38]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[38]>=1){
            	t5[38]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[38]>=1){
           	 t6[38]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 40;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[39]>=1){
            	t1[39]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[39]>=1){
          	 t2[39]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[39]>=1){
           	t3[39]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[39]>=1){
            	t4[39]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[39]>=1){
            	t5[39]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[39]>=1){
           	 t6[39]+=troop;
            	 randno+=1;
            	mov=1; }}
        
        
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 41;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[40]>=1){
            	t1[40]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[40]>=1){
          	 t2[40]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[40]>=1){
           	t3[40]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[40]>=1){
            	t4[40]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[40]>=1){
            	t5[40]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[40]>=1){
           	 t6[40]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[41]=1;
            selectedterritory = 42;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[41]>=1){
            	t1[41]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[41]>=1){
          	 t2[41]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[41]>=1){
           	t3[41]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[41]>=1){
            	t4[41]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[41]>=1){
            	t5[41]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[41]>=1){
           	 t6[41]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 663.0 / height && Y <= 747.0 / height) {
            selectedterritory = 43;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[42]>=1){
            	t1[42]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[42]>=1){
          	 t2[42]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[42]>=1){
           	t3[42]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[42]>=1){
            	t4[42]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[42]>=1){
            	t5[42]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[42]>=1){
           	 t6[42]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 663.0 / height && Y <= 747.0 / height) {
            t[43]=1;
            selectedterritory = 44;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[43]>=1){
            	t1[43]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[43]>=1){
          	 t2[43]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[43]>=1){
           	t3[43]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[43]>=1){
            	t4[43]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[43]>=1){
            	t5[43]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[43]>=1){
           	 t6[43]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 580.0 / height && Y <= 663.0 / height) {
            selectedterritory = 45;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[44]>=1){
            	t1[44]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[44]>=1){
          	 t2[44]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[44]>=1){
           	t3[44]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[44]>=1){
            	t4[44]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[44]>=1){
            	t5[44]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[44]>=1){
           	 t6[44]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 580.0 / height && Y <= 663.0 / height) {
            t[45]=1;
            selectedterritory = 46;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[45]>=1){
            	t1[45]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[45]>=1){
          	 t2[45]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[45]>=1){
           	t3[45]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[45]>=1){
            	t4[45]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[45]>=1){
            	t5[45]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[45]>=1){
           	 t6[45]+=troop;
            	 randno+=1;
            	mov=1; }}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 495.0 / height && Y <= 580.0 / height) {
            selectedterritory = 47;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[46]>=1){
            	t1[46]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[46]>=1){
          	 t2[46]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[46]>=1){
           	t3[46]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[46]>=1){
            	t4[46]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[46]>=1){
            	t5[46]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[46]>=1){
           	 t6[46]+=troop;
            	 randno+=1;
            	mov=1; }}
        
        
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 387.0 / height && Y <= 469.0 / height) {
            selectedterritory = 48;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[47]>=1){
            	t1[47]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[47]>=1){
          	 t2[47]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[47]>=1){
           	t3[47]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[47]>=1){
            	t4[47]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[47]>=1){
            	t5[47]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[47]>=1){
           	 t6[47]+=troop;
            	 randno+=1;
            	mov=1; }}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 302.0 / height && Y < 387.0 / height) {
            selectedterritory = 49;
            cout << "Troops landed in Territory " << selectedterritory << endl;
          if (randno==1 && t1[48]>=1){
            	t1[48]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[48]>=1){
          	 t2[48]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[48]>=1){
           	t3[48]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[48]>=1){
            	t4[48]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[48]>=1){
            	t5[48]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[48]>=1){
           	 t6[48]+=troop;
            	 randno+=1;
            	mov=1; }}
         if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 219.0 / height && Y <= 302.0 / height) {
            selectedterritory =50;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[49]>=1){
            	t1[49]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[49]>=1){
          	 t2[49]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[49]>=1){
           	t3[49]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[49]>=1){
            	t4[49]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[49]>=1){
            	t5[49]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[49]>=1){
           	 t6[49]+=troop;
            	 randno+=1;
            	mov=1; }}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 130.0 / height && Y <= 219.0 / height) {
            selectedterritory = 51;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[50]>=1){
            	t1[50]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==2&& t2[50]>=1){
          	 t2[50]+=troop;
          	 randno+=1;
            	mov=1;}
            if (randno==3&& t3[50]>=1){
           	t3[50]+=troop;
           	 randno+=1;
            	mov=1;}
            if (randno==4&& t4[50]>=1){
            	t4[50]+=troop;
            	randno+=1;
            	mov=1;}
            if (randno==5 && t5[50]>=1){
            	t5[50]+=troop;
            	randno+=1;
            	mov=1; }
            if (randno==6&&t6[50]>=1){
           	 t6[50]+=troop;
            	 randno+=1;
            	mov=1; }}}
void moveTerrCheck(float X,  float Y){
	int width = 1200;
   	int height = 840;
	if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 1;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[0]>troop){
            	t1[0]-=troop;
            	g+=1;}
            if (randno==2&& t2[0]>troop){
          	 t2[0]-=troop;
          	 g+=1;}
            if (randno==3&& t3[0]>troop){
           	t3[0]-=troop;
           	 g+=1;}
            if (randno==4&& t4[0]>troop){
            	t4[0]-=troop;
            	g+=1;}
            if (randno==5 && t5[0]>troop){
            	t5[0]-=troop;
            	g+=1; }
            if (randno==6&&t6[0]>troop){
           	 t6[0]-=troop;
            	 g+=1; }}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[1]=1;
            selectedterritory = 2;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[1]>troop){
            	t1[1]-=troop;
            	g+=1;}
            if (randno==2&& t2[1]>troop){
          	 t2[1]-=troop;
          	 g+=1;}
            if (randno==3&& t3[1]>troop){
           	t3[1]-=troop;
           	 g+=1;}
            if (randno==4&& t4[1]>troop){
            	t4[1]-=troop;
            	g+=1;}
            if (randno==5 && t5[1]>troop){
            	t5[1]-=troop;
            	g+=1; }
            if (randno==6&&t6[1]>troop){
           	 t6[1]-=troop;
            	 g+=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 3;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[2]>troop){
            	t1[2]-=troop;
            	g+=1;}
            if (randno==2&& t2[2]>troop){
          	 t2[2]-=troop;
          	 g+=1;}
            if (randno==3&& t3[2]>troop){
           	t3[2]-=troop;
           	 g+=1;}
            if (randno==4&& t4[2]>troop){
            	t4[2]-=troop;
            	g+=1;}
            if (randno==5 && t5[2]>troop){
            	t5[2]-=troop;
            	g+=1; }
            if (randno==6&&t6[2]>troop){
           	 t6[2]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 4;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[3]>troop){
            	t1[3]-=troop;
            	g+=1;}
            if (randno==2&& t2[3]>troop){
          	 t2[3]-=troop;
          	 g+=1;}
            if (randno==3&& t3[3]>troop){
           	t3[3]-=troop;
           	 g+=1;}
            if (randno==4&& t4[3]>troop){
            	t4[3]-=troop;
            	g+=1;}
            if (randno==5 && t5[3]>troop){
            	t5[3]-=troop;
            	g+=1; }
            if (randno==6&&t6[3]>troop){
           	 t6[3]-=troop;
            	 g+=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 5;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[4]>troop){
            	t1[4]-=troop;
            	g+=1;}
            if (randno==2&& t2[4]>troop){
          	 t2[4]-=troop;
          	 g+=1;}
            if (randno==3&& t3[4]>troop){
           	t3[4]-=troop;
           	 g+=1;}
            if (randno==4&& t4[4]>troop){
            	t4[4]-=troop;
            	g+=1;}
            if (randno==5 && t5[4]>troop){
            	t5[4]-=troop;
            	g+=1; }
            if (randno==6&&t6[4]>troop){
           	 t6[4]-=troop;
            	 g+=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >662.0  / height && Y < 748.0 / height) {
           selectedterritory = 6;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[5]>troop){
            	t1[5]-=troop;
            	g+=1;}
            if (randno==2&& t2[5]>troop){
          	 t2[5]-=troop;
          	 g+=1;}
            if (randno==3&& t3[5]>troop){
           	t3[5]-=troop;
           	 g+=1;}
            if (randno==4&& t4[5]>troop){
            	t4[5]-=troop;
            	g+=1;}
            if (randno==5 && t5[5]>troop){
            	t5[5]-=troop;
            	g+=1; }
            if (randno==6&&t6[5]>troop){
           	 t6[5]-=troop;
            	 g+=1; }}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 7;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[6]>troop){
            	t1[6]-=troop;
            	g+=1;}
            if (randno==2&& t2[6]>troop){
          	 t2[6]-=troop;
          	 g+=1;}
            if (randno==3&& t3[6]>troop){
           	t3[6]-=troop;
           	 g+=1;}
            if (randno==4&& t4[6]>troop){
            	t4[6]-=troop;
            	g+=1;}
            if (randno==5 && t5[6]>troop){
            	t5[6]-=troop;
            	g+=1; }
            if (randno==6&&t6[6]>troop){
           	 t6[6]-=troop;
            	 g+=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 8;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[7]>troop){
            	t1[7]-=troop;
            	g+=1;}
            if (randno==2&& t2[7]>troop){
          	 t2[7]-=troop;
          	 g+=1;}
            if (randno==3&& t3[7]>troop){
           	t3[7]-=troop;
           	 g+=1;}
            if (randno==4&& t4[7]>troop){
            	t4[7]-=troop;
            	g+=1;}
            if (randno==5 && t5[7]>troop){
            	t5[7]-=troop;
            	g+=1; }
            if (randno==6&&t6[7]>troop){
           	 t6[7]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 9;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[8]>troop){
            	t1[8]-=troop;
            	g+=1;}
            if (randno==2&& t2[8]>troop){
          	 t2[8]-=troop;
          	 g+=1;}
            if (randno==3&& t3[8]>troop){
           	t3[8]-=troop;
           	 g+=1;}
            if (randno==4&& t4[8]>troop){
            	t4[8]-=troop;
            	g+=1;}
            if (randno==5 && t5[8]>troop){
            	t5[8]-=troop;
            	g+=1; }
            if (randno==6&&t6[8]>troop){
           	 t6[8]-=troop;
            	 g+=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 10;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[9]>troop){
            	t1[9]-=troop;
            	g+=1;}
            if (randno==2&& t2[9]>troop){
          	 t2[9]-=troop;
          	 g+=1;}
            if (randno==3&& t3[9]>troop){
           	t3[9]-=troop;
           	 g+=1;}
            if (randno==4&& t4[9]>troop){
            	t4[9]-=troop;
            	g+=1;}
            if (randno==5 && t5[9]>troop){
            	t5[9]-=troop;
            	g+=1; }
            if (randno==6&&t6[9]>troop){
           	 t6[9]-=troop;
            	 g+=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >579.0  / height && Y < 662.0 / height) {
           selectedterritory = 11;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[10]>troop){
            	t1[10]-=troop;
            	g+=1;}
            if (randno==2&& t2[10]>troop){
          	 t2[10]-=troop;
          	 g+=1;}
            if (randno==3&& t3[10]>troop){
           	t3[10]-=troop;
           	 g+=1;}
            if (randno==4&& t4[10]>troop){
            	t4[10]-=troop;
            	g+=1;}
            if (randno==5 && t5[10]>troop){
            	t5[10]-=troop;
            	g+=1; }
            if (randno==6&&t6[10]>troop){
           	 t6[10]-=troop;
            	 g+=1; }}
        
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 12;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[11]>troop){
            	t1[11]-=troop;
            	g+=1;}
            if (randno==2&& t2[11]>troop){
          	 t2[11]-=troop;
          	 g+=1;}
            if (randno==3&& t3[11]>troop){
           	t3[11]-=troop;
           	 g+=1;}
            if (randno==4&& t4[11]>troop){
            	t4[11]-=troop;
            	g+=1;}
            if (randno==5 && t5[11]>troop){
            	t5[11]-=troop;
            	g+=1; }
            if (randno==6&&t6[11]>troop){
           	 t6[11]-=troop;
            	 g+=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 13;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[12]>troop){
            	t1[12]-=troop;
            	g+=1;}
            if (randno==2&& t2[12]>troop){
          	 t2[12]-=troop;
          	 g+=1;}
            if (randno==3&& t3[12]>troop){
           	t3[12]-=troop;
           	 g+=1;}
            if (randno==4&& t4[12]>troop){
            	t4[12]-=troop;
            	g+=1;}
            if (randno==5 && t5[12]>troop){
            	t5[12]-=troop;
            	g+=1; }
            if (randno==6&&t6[12]>troop){
           	 t6[12]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 14;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[13]>troop){
            	t1[13]-=troop;
            	g+=1;}
            if (randno==2&& t2[13]>troop){
          	 t2[13]-=troop;
          	 g+=1;}
            if (randno==3&& t3[13]>troop){
           	t3[13]-=troop;
           	 g+=1;}
            if (randno==4&& t4[13]>troop){
            	t4[13]-=troop;
            	g+=1;}
            if (randno==5 && t5[13]>troop){
            	t5[13]-=troop;
            	g+=1; }
            if (randno==6&&t6[13]>troop){
           	 t6[13]-=troop;
            	 g+=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 15;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[14]>troop){
            	t1[14]-=troop;
            	g+=1;}
            if (randno==2&& t2[14]>troop){
          	 t2[14]-=troop;
          	 g+=1;}
            if (randno==3&& t3[14]>troop){
           	t3[14]-=troop;
           	 g+=1;}
            if (randno==4&& t4[14]>troop){
            	t4[14]-=troop;
            	g+=1;}
            if (randno==5 && t5[14]>troop){
            	t5[14]-=troop;
            	g+=1; }
            if (randno==6&&t6[14]>troop){
           	 t6[14]-=troop;
            	 g+=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >495.0  / height && Y < 579.0 / height) {
           selectedterritory = 16;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[15]>troop){
            	t1[15]-=troop;
            	g+=1;}
            if (randno==2&& t2[15]>troop){
          	 t2[15]-=troop;
          	 g+=1;}
            if (randno==3&& t3[15]>troop){
           	t3[15]-=troop;
           	 g+=1;}
            if (randno==4&& t4[15]>troop){
            	t4[15]-=troop;
            	g+=1;}
            if (randno==5 && t5[15]>troop){
            	t5[15]-=troop;
            	g+=1; }
            if (randno==6&&t6[15]>troop){
           	 t6[15]-=troop;
            	 g+=1; }}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 17;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[16]>troop){
            	t1[16]-=troop;
            	g+=1;}
            if (randno==2&& t2[16]>troop){
          	 t2[16]-=troop;
          	 g+=1;}
            if (randno==3&& t3[16]>troop){
           	t3[16]-=troop;
           	 g+=1;}
            if (randno==4&& t4[16]>troop){
            	t4[16]-=troop;
            	g+=1;}
            if (randno==5 && t5[16]>troop){
            	t5[16]-=troop;
            	g+=1; }
            if (randno==6&&t6[16]>troop){
           	 t6[16]-=troop;
            	 g+=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 18;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[17]>troop){
            	t1[17]-=troop;
            	g+=1;}
            if (randno==2&& t2[17]>troop){
          	 t2[17]-=troop;
          	 g+=1;}
            if (randno==3&& t3[17]>troop){
           	t3[17]-=troop;
           	 g+=1;}
            if (randno==4&& t4[17]>troop){
            	t4[17]-=troop;
            	g+=1;}
            if (randno==5 && t5[17]>troop){
            	t5[17]-=troop;
            	g+=1; }
            if (randno==6&&t6[17]>troop){
           	 t6[17]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 19;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[18]>troop){
            	t1[18]-=troop;
            	g+=1;}
            if (randno==2&& t2[18]>troop){
          	 t2[18]-=troop;
          	 g+=1;}
            if (randno==3&& t3[18]>troop){
           	t3[18]-=troop;
           	 g+=1;}
            if (randno==4&& t4[18]>troop){
            	t4[18]-=troop;
            	g+=1;}
            if (randno==5 && t5[18]>troop){
            	t5[18]-=troop;
            	g+=1; }
            if (randno==6&&t6[18]>troop){
           	 t6[18]-=troop;
            	 g+=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 20;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[19]>troop){
            	t1[19]-=troop;
            	g+=1;}
            if (randno==2&& t2[19]>troop){
          	 t2[19]-=troop;
          	 g+=1;}
            if (randno==3&& t3[19]>troop){
           	t3[19]-=troop;
           	 g+=1;}
            if (randno==4&& t4[19]>troop){
            	t4[19]-=troop;
            	g+=1;}
            if (randno==5 && t5[19]>troop){
            	t5[19]-=troop;
            	g+=1; }
            if (randno==6&&t6[19]>troop){
           	 t6[19]-=troop;
            	 g+=1; }}
        
        
        
        if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 21;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[20]>troop){
            	t1[20]-=troop;
            	g+=1;}
            if (randno==2&& t2[20]>troop){
          	 t2[20]-=troop;
          	 g+=1;}
            if (randno==3&& t3[20]>troop){
           	t3[20]-=troop;
           	 g+=1;}
            if (randno==4&& t4[20]>troop){
            	t4[20]-=troop;
            	g+=1;}
            if (randno==5 && t5[20]>troop){
            	t5[20]-=troop;
            	g+=1; }
            if (randno==6&&t6[20]>troop){
           	 t6[20]-=troop;
            	 g+=1; }}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 22;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[21]>troop){
            	t1[21]-=troop;
            	g+=1;}
            if (randno==2&& t2[21]>troop){
          	 t2[21]-=troop;
          	 g+=1;}
            if (randno==3&& t3[21]>troop){
           	t3[21]-=troop;
           	 g+=1;}
            if (randno==4&& t4[21]>troop){
            	t4[21]-=troop;
            	g+=1;}
            if (randno==5 && t5[21]>troop){
            	t5[21]-=troop;
            	g+=1; }
            if (randno==6&&t6[21]>troop){
           	 t6[21]-=troop;
            	 g+=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 23;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[22]>troop){
            	t1[22]-=troop;
            	g+=1;}
            if (randno==2&& t2[22]>troop){
          	 t2[22]-=troop;
          	 g+=1;}
            if (randno==3&& t3[22]>troop){
           	t3[22]-=troop;
           	 g+=1;}
            if (randno==4&& t4[22]>troop){
            	t4[22]-=troop;
            	g+=1;}
            if (randno==5 && t5[22]>troop){
            	t5[22]-=troop;
            	g+=1; }
            if (randno==6&&t6[22]>troop){
           	 t6[22]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 24;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[23]>troop){
            	t1[23]-=troop;
            	g+=1;}
            if (randno==2&& t2[23]>troop){
          	 t2[23]-=troop;
          	 g+=1;}
            if (randno==3&& t3[23]>troop){
           	t3[23]-=troop;
           	 g+=1;}
            if (randno==4&& t4[23]>troop){
            	t4[23]-=troop;
            	g+=1;}
            if (randno==5 && t5[23]>troop){
            	t5[23]-=troop;
            	g+=1; }
            if (randno==6&&t6[23]>troop){
           	 t6[23]-=troop;
            	 g+=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 25;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[24]>troop){
            	t1[24]-=troop;
            	g+=1;}
            if (randno==2&& t2[24]>troop){
          	 t2[24]-=troop;
          	 g+=1;}
            if (randno==3&& t3[24]>troop){
           	t3[24]-=troop;
           	 g+=1;}
            if (randno==4&& t4[24]>troop){
            	t4[24]-=troop;
            	g+=1;}
            if (randno==5 && t5[24]>troop){
            	t5[24]-=troop;
            	g+=1; }
            if (randno==6&&t6[24]>troop){
           	 t6[24]-=troop;
            	 g+=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >303.0  / height && Y < 388.0 / height) {
           selectedterritory = 26;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[25]>troop){
            	t1[25]-=troop;
            	g+=1;}
            if (randno==2&& t2[25]>troop){
          	 t2[25]-=troop;
          	 g+=1;}
            if (randno==3&& t3[25]>troop){
           	t3[25]-=troop;
           	 g+=1;}
            if (randno==4&& t4[25]>troop){
            	t4[25]-=troop;
            	g+=1;}
            if (randno==5 && t5[25]>troop){
            	t5[25]-=troop;
            	g+=1; }
            if (randno==6&&t6[25]>troop){
           	 t6[25]-=troop;
            	 g+=1; }}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 27;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[26]>troop){
            	t1[26]-=troop;
            	g+=1;}
            if (randno==2&& t2[26]>troop){
          	 t2[26]-=troop;
          	 g+=1;}
            if (randno==3&& t3[26]>troop){
           	t3[26]-=troop;
           	 g+=1;}
            if (randno==4&& t4[26]>troop){
            	t4[26]-=troop;
            	g+=1;}
            if (randno==5 && t5[26]>troop){
            	t5[26]-=troop;
            	g+=1; }
            if (randno==6&&t6[26]>troop){
           	 t6[26]-=troop;
            	 g+=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 28;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[27]>troop){
            	t1[27]-=troop;
            	g+=1;}
            if (randno==2&& t2[27]>troop){
          	 t2[27]-=troop;
          	 g+=1;}
            if (randno==3&& t3[27]>troop){
           	t3[27]-=troop;
           	 g+=1;}
            if (randno==4&& t4[27]>troop){
            	t4[27]-=troop;
            	g+=1;}
            if (randno==5 && t5[27]>troop){
            	t5[27]-=troop;
            	g+=1; }
            if (randno==6&&t6[27]>troop){
           	 t6[27]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 29;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[28]>troop){
            	t1[28]-=troop;
            	g+=1;}
            if (randno==2&& t2[28]>troop){
          	 t2[28]-=troop;
          	 g+=1;}
            if (randno==3&& t3[28]>troop){
           	t3[28]-=troop;
           	 g+=1;}
            if (randno==4&& t4[28]>troop){
            	t4[28]-=troop;
            	g+=1;}
            if (randno==5 && t5[28]>troop){
            	t5[28]-=troop;
            	g+=1; }
            if (randno==6&&t6[28]>troop){
           	 t6[28]-=troop;
            	 g+=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 30;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[29]>troop){
            	t1[29]-=troop;
            	g+=1;}
            if (randno==2&& t2[29]>troop){
          	 t2[29]-=troop;
          	 g+=1;}
            if (randno==3&& t3[29]>troop){
           	t3[29]-=troop;
           	 g+=1;}
            if (randno==4&& t4[29]>troop){
            	t4[29]-=troop;
            	g+=1;}
            if (randno==5 && t5[29]>troop){
            	t5[29]-=troop;
            	g+=1; }
            if (randno==6&&t6[29]>troop){
           	 t6[29]-=troop;
            	 g+=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >219.0  / height && Y < 303.0 / height) {
           selectedterritory = 31;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[30]>troop){
            	t1[30]-=troop;
            	g+=1;}
            if (randno==2&& t2[30]>troop){
          	 t2[30]-=troop;
          	 g+=1;}
            if (randno==3&& t3[30]>troop){
           	t3[30]-=troop;
           	 g+=1;}
            if (randno==4&& t4[30]>troop){
            	t4[30]-=troop;
            	g+=1;}
            if (randno==5 && t5[30]>troop){
            	t5[39]-=troop;
            	g+=1; }
            if (randno==6&&t6[30]>troop){
           	 t6[30]-=troop;
            	 g+=1; }}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 32;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[31]>troop){
            	t1[31]-=troop;
            	g+=1;}
            if (randno==2&& t2[31]>troop){
          	 t2[31]-=troop;
          	 g+=1;}
            if (randno==3&& t3[31]>troop){
           	t3[31]-=troop;
           	 g+=1;}
            if (randno==4&& t4[31]>troop){
            	t4[31]-=troop;
            	g+=1;}
            if (randno==5 && t5[31]>troop){
            	t5[31]-=troop;
            	g+=1; }
            if (randno==6&&t6[31]>troop){
           	 t6[31]-=troop;
            	 g+=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 33;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[32]>troop){
            	t1[32]-=troop;
            	g+=1;}
            if (randno==2&& t2[32]>troop){
          	 t2[32]-=troop;
          	 g+=1;}
            if (randno==3&& t3[32]>troop){
           	t3[32]-=troop;
           	 g+=1;}
            if (randno==4&& t4[32]>troop){
            	t4[32]-=troop;
            	g+=1;}
            if (randno==5 && t5[32]>troop){
            	t5[32]-=troop;
            	g+=1; }
            if (randno==6&&t6[32]>troop){
           	 t6[32]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 34;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[33]>troop){
            	t1[33]-=troop;
            	g+=1;}
            if (randno==2&& t2[33]>troop){
          	 t2[33]-=troop;
          	 g+=1;}
            if (randno==3&& t3[33]>troop){
           	t3[33]-=troop;
           	 g+=1;}
            if (randno==4&& t4[33]>troop){
            	t4[33]-=troop;
            	g+=1;}
            if (randno==5 && t5[33]>troop){
            	t5[33]-=troop;
            	g+=1; }
            if (randno==6&&t6[33]>troop){
           	 t6[33]-=troop;
            	 g+=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 35;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[34]>troop){
            	t1[34]-=troop;
            	g+=1;}
            if (randno==2&& t2[34]>troop){
          	 t2[34]-=troop;
          	 g+=1;}
            if (randno==3&& t3[34]>troop){
           	t3[34]-=troop;
           	 g+=1;}
            if (randno==4&& t4[34]>troop){
            	t4[34]-=troop;
            	g+=1;}
            if (randno==5 && t5[34]>troop){
            	t5[34]-=troop;
            	g+=1; }
            if (randno==6&&t6[34]>troop){
           	 t6[34]-=troop;
            	 g+=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >136.0  / height && Y < 219.0 / height) {
           selectedterritory = 36;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[35]>troop){
            	t1[35]-=troop;
            	g+=1;}
            if (randno==2&& t2[35]>troop){
          	 t2[35]-=troop;
          	 g+=1;}
            if (randno==3&& t3[35]>troop){
           	t3[35]-=troop;
           	 g+=1;}
            if (randno==4&& t4[35]>troop){
            	t4[35]-=troop;
            	g+=1;}
            if (randno==5 && t5[35]>troop){
            	t5[35]-=troop;
            	g+=1; }
            if (randno==6&&t6[35]>troop){
           	 t6[35]-=troop;
            	 g+=1; }}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 37;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[36]>troop){
            	t1[36]-=troop;
            	g+=1;}
            if (randno==2&& t2[36]>troop){
          	 t2[36]-=troop;
          	 g+=1;}
            if (randno==3&& t3[36]>troop){
           	t3[36]-=troop;
           	 g+=1;}
            if (randno==4&& t4[36]>troop){
            	t4[36]-=troop;
            	g+=1;}
            if (randno==5 && t5[36]>troop){
            	t5[36]-=troop;
            	g+=1; }
            if (randno==6&&t6[36]>troop){
           	 t6[36]-=troop;
            	 g+=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 38;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[37]>troop){
            	t1[37]-=troop;
            	g+=1;}
            if (randno==2&& t2[37]>troop){
          	 t2[37]-=troop;
          	 g+=1;}
            if (randno==3&& t3[37]>troop){
           	t3[37]-=troop;
           	 g+=1;}
            if (randno==4&& t4[37]>troop){
            	t4[37]-=troop;
            	g+=1;}
            if (randno==5 && t5[37]>troop){
            	t5[37]-=troop;
            	g+=1; }
            if (randno==6&&t6[37]>troop){
           	 t6[37]-=troop;
            	 g+=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 39;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[38]>troop){
            	t1[38]-=troop;
            	g+=1;}
            if (randno==2&& t2[38]>troop){
          	 t2[38]-=troop;
          	 g+=1;}
            if (randno==3&& t3[38]>troop){
           	t3[38]-=troop;
           	 g+=1;}
            if (randno==4&& t4[38]>troop){
            	t4[38]-=troop;
            	g+=1;}
            if (randno==5 && t5[38]>troop){
            	t5[38]-=troop;
            	g+=1; }
            if (randno==6&&t6[38]>troop){
           	 t6[38]-=troop;
            	 g+=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 40;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[39]>troop){
            	t1[39]-=troop;
            	g+=1;}
            if (randno==2&& t2[39]>troop){
          	 t2[39]-=troop;
          	 g+=1;}
            if (randno==3&& t3[39]>troop){
           	t3[39]-=troop;
           	 g+=1;}
            if (randno==4&& t4[39]>troop){
            	t4[39]-=troop;
            	g+=1;}
            if (randno==5 && t5[39]>troop){
            	t5[39]-=troop;
            	g+=1; }
            if (randno==6&&t6[39]>troop){
           	 t6[39]-=troop;
            	 g+=1; }}
        
        
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 41;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[40]>troop){
            	t1[40]-=troop;
            	g+=1;}
            if (randno==2&& t2[40]>troop){
          	 t2[40]-=troop;
          	 g+=1;}
            if (randno==3&& t3[40]>troop){
           	t3[40]-=troop;
           	 g+=1;}
            if (randno==4&& t4[40]>troop){
            	t4[40]-=troop;
            	g+=1;}
            if (randno==5 && t5[40]>troop){
            	t5[40]-=troop;
            	g+=1; }
            if (randno==6&&t6[40]>troop){
           	 t6[40]-=troop;
            	 g+=1; }}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[41]=1;
            selectedterritory = 42;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[41]>troop){
            	t1[41]-=troop;
            	g+=1;}
            if (randno==2&& t2[41]>troop){
          	 t2[41]-=troop;
          	 g+=1;}
            if (randno==3&& t3[41]>troop){
           	t3[41]-=troop;
           	 g+=1;}
            if (randno==4&& t4[41]>troop){
            	t4[41]-=troop;
            	g+=1;}
            if (randno==5 && t5[41]>troop){
            	t5[41]-=troop;
            	g+=1; }
            if (randno==6&&t6[41]>troop){
           	 t6[41]-=troop;
            	 g+=1; }}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 663.0 / height && Y <= 747.0 / height) {
            selectedterritory = 43;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[42]>troop){
            	t1[42]-=troop;
            	g+=1;}
            if (randno==2&& t2[42]>troop){
          	 t2[42]-=troop;
          	 g+=1;}
            if (randno==3&& t3[42]>troop){
           	t3[42]-=troop;
           	 g+=1;}
            if (randno==4&& t4[42]>troop){
            	t4[42]-=troop;
            	g+=1;}
            if (randno==5 && t5[42]>troop){
            	t5[42]-=troop;
            	g+=1; }
            if (randno==6&&t6[42]>troop){
           	 t6[42]-=troop;
            	 g+=1; }}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 663.0 / height && Y <= 747.0 / height) {
            t[43]=1;
            selectedterritory = 44;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[43]>troop){
            	t1[43]-=troop;
            	g+=1;}
            if (randno==2&& t2[43]>troop){
          	 t2[43]-=troop;
          	 g+=1;}
            if (randno==3&& t3[43]>troop){
           	t3[43]-=troop;
           	 g+=1;}
            if (randno==4&& t4[43]>troop){
            	t4[43]-=troop;
            	g+=1;}
            if (randno==5 && t5[43]>troop){
            	t5[43]-=troop;
            	g+=1; }
            if (randno==6&&t6[43]>troop){
           	 t6[43]-=troop;
            	 g+=1; }}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 580.0 / height && Y <= 663.0 / height) {
            selectedterritory = 45;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[44]>troop){
            	t1[44]-=troop;
            	g+=1;}
            if (randno==2&& t2[44]>troop){
          	 t2[44]-=troop;
          	 g+=1;}
            if (randno==3&& t3[44]>troop){
           	t3[44]-=troop;
           	 g+=1;}
            if (randno==4&& t4[44]>troop){
            	t4[44]-=troop;
            	g+=1;}
            if (randno==5 && t5[44]>troop){
            	t5[44]-=troop;
            	g+=1; }
            if (randno==6&&t6[44]>troop){
           	 t6[44]-=troop;
            	 g+=1; }}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 580.0 / height && Y <= 663.0 / height) {
            t[45]=1;
            selectedterritory = 46;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[45]>troop){
            	t1[45]-=troop;
            	g+=1;}
            if (randno==2&& t2[45]>troop){
          	 t2[45]-=troop;
          	 g+=1;}
            if (randno==3&& t3[45]>troop){
           	t3[45]-=troop;
           	 g+=1;}
            if (randno==4&& t4[45]>troop){
            	t4[45]-=troop;
            	g+=1;}
            if (randno==5 && t5[45]>troop){
            	t5[45]-=troop;
            	g+=1; }
            if (randno==6&&t6[45]>troop){
           	 t6[45]-=troop;
            	 g+=1; }}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 495.0 / height && Y <= 580.0 / height) {
            selectedterritory = 47;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[46]>troop){
            	t1[46]-=troop;
            	g+=1;}
            if (randno==2&& t2[46]>troop){
          	 t2[46]-=troop;
          	 g+=1;}
            if (randno==3&& t3[46]>troop){
           	t3[46]-=troop;
           	 g+=1;}
            if (randno==4&& t4[46]>troop){
            	t4[46]-=troop;
            	g+=1;}
            if (randno==5 && t5[46]>troop){
            	t5[46]-=troop;
            	g+=1; }
            if (randno==6&&t6[46]>troop){
           	 t6[46]-=troop;
            	 g+=1; }}
        
        
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 387.0 / height && Y <= 469.0 / height) {
            selectedterritory = 48;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[47]>troop){
            	t1[47]-=troop;
            	g+=1;}
            if (randno==2&& t2[47]>troop){
          	 t2[47]-=troop;
          	 g+=1;}
            if (randno==3&& t3[47]>troop){
           	t3[47]-=troop;
           	 g+=1;}
            if (randno==4&& t4[47]>troop){
            	t4[47]-=troop;
            	g+=1;}
            if (randno==5 && t5[47]>troop){
            	t5[47]-=troop;
            	g+=1; }
            if (randno==6&&t6[47]>troop){
           	 t6[47]-=troop;
            	 g+=1; }}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 302.0 / height && Y < 387.0 / height) {
            selectedterritory = 49;
            cout << "Troops landed in Territory " << selectedterritory << endl;
          if (randno==1 && t1[48]>troop){
            	t1[48]-=troop;
            	g+=1;}
            if (randno==2&& t2[48]>troop){
          	 t2[48]-=troop;
          	 g+=1;}
            if (randno==3&& t3[48]>troop){
           	t3[48]-=troop;
           	 g+=1;}
            if (randno==4&& t4[48]>troop){
            	t4[48]-=troop;
            	g+=1;}
            if (randno==5 && t5[48]>troop){
            	t5[48]-=troop;
            	g+=1; }
            if (randno==6&&t6[48]>troop){
           	 t6[48]-=troop;
            	 g+=1; }}
         if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 219.0 / height && Y <= 302.0 / height) {
            selectedterritory =50;
            cout << "Troops landed in Territory " << selectedterritory << endl;
             if (randno==1 && t1[49]>troop){
            	t1[49]-=troop;
            	g+=1;
            	 }
            if (randno==2&& t2[49]>troop){
          	 t2[49]-=troop;
          	 g+=1;}
            if (randno==3&& t3[49]>troop){
           	t3[49]-=troop;
           	 g+=1;}
            if (randno==4&& t4[49]>troop){
            	t4[49]-=troop;
            	g+=1;}
            if (randno==5 && t5[49]>troop){
            	t5[49]-=troop;
            	g+=1; }
            if (randno==6&&t6[49]>troop){
           	 t6[49]-=troop;
            	 g+=1; }}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 130.0 / height && Y <= 219.0 / height) {
            selectedterritory = 51;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[50]>troop){
            	t1[50]-=troop;
            	g+=1;
            	 }
            if (randno==2&& t2[50]>troop){
          	 t2[50]-=troop;
          	 g+=1;}
            if (randno==3&& t3[50]>troop){
           	t3[50]-=troop;
           	 g+=1;}
            if (randno==4&& t4[50]>troop){
            	t4[50]-=troop;
            	g+=1;}
            if (randno==5 && t5[50]>troop){
            	t5[50]-=troop;
            	g+=1; }
            if (randno==6&&t6[50]>troop){
           	 t6[50]-=troop;
            	 g+=1; }}}
void occTerrChecker(float X, float Y){// TO CHECK WHETHER THE TERRITORY SELECTED BY PLAYER IS OCCUPIED BY HIM OR NOT FOR TROOPS PLACEMENT.
	int width = 1200;
   	int height = 840,z=0;
	if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 1;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[0]>=1&&p1occ>0){
            	t1[0]+=1;
            	 p1occ-=1;}
          else if (randno==2 && t2[0]>=1&&p2occ>0){
          	 t2[0]+=1;
          	 p2occ-=1;}
          else if (randno==3&& t3[0]>=1&&p3occ>0){
           	t3[0]+=1;
           	p3occ-=1;
           	 }
          else if (randno==4&& t4[0]>=1&&p4occ>0){
            	t4[0]+=1;
            	p4occ-=1;}
          else if (randno==5 && t5[0]>=1&&p5occ>0){
            	t5[0]+=1;
            	p5occ-=1;
            	 }
          else  if (randno==6&&t6[0]>=1&&p6occ>0){
           	 t6[0]+=1;
           	 p6occ-=1;
           	 	 }}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[1]=1;
            selectedterritory = 2;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[1]>=1&&p1occ>0){
            	t1[1]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[1]>=1&&p2occ>0){
          	 t2[1]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[1]>=1&&p3occ>0){
           	t3[1]+=1;
           	p3occ-=1;
           	}
            if (randno==4&& t4[1]>=1&&p4occ>0){
            	t4[1]+=1;
	  	p4occ-=1;}
            if (randno==5 && t5[1]>=1&&p5occ>0){
            	t5[1]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[1]>=1&&p6occ>0){
           	 t6[1]+=1;
            	p6occ-=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 3;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[2]>=1&&p1occ>0){
            	t1[2]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[2]>=1&&p2occ>0){
          	 t2[2]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[2]>=1&&p3occ>0){
           	t3[2]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[2]>=1&&p4occ>0){
            	t4[2]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[2]>=1&&p5occ>0){
            	t5[2]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[2]>=1&&p6occ>0){
           	 t6[2]+=1;
            	 p6occ-=1;}}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 4;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[3]>=1&&p1occ>0){
            	t1[3]+=1;
            	p1occ-=1;
	    	}
            if (randno==2&& t2[3]>=1&&p2occ>0){
          	 t2[3]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[3]>=1&&p3occ>0){
           	t3[3]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[3]>=1&&p4occ>0){
            	t4[3]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[3]>=1&&p5occ>0){
            	t5[3]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[3]>=1&&p6occ>0){
           	 t6[3]+=1;
            	p6occ-=1;}}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 5;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[4]>=1&&p1occ>0){
            	t1[4]+=1;
            	p1occ-=1;
	    	}
            if (randno==2&& t2[4]>=1&&p2occ>0){
          	 t2[4]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[4]>=1&&p3occ>0){
           	t3[4]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[4]>=1&&p4occ>0){
            	t4[4]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[4]>=1&&p5occ>0){
            	t5[4]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[4]>=1&&p6occ>0){
           	 t6[4]+=1;
            	 p6occ-=1;}}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >662.0  / height && Y < 748.0 / height) {
           selectedterritory = 6;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[5]>=1&&p1occ>0){
            	t1[5]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[5]>=1&&p2occ>0){
          	 t2[5]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[5]>=1&&p3occ>0){
           	t3[5]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[5]>=1&&p4occ>0){
            	t4[5]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[5]>=1&&p5occ>0){
            	t5[5]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[5]>=1&&p6occ>0){
           	 t6[5]+=1;
            	 p6occ-=1;}}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 7;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[6]>=1&&p1occ>0){
            	t1[6]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[6]>=1&&p2occ>0){
          	 t2[6]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[6]>=1&&p3occ>0){
           	t3[6]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[6]>=1&&p4occ>0){
            	t4[6]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[6]>=1&&p5occ>0){
            	t5[6]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[6]>=1&&p6occ>0){
           	 t6[6]+=1;
            	 p6occ-=1;}}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 8;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[7]>=1&&p1occ>0){
            	t1[7]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[7]>=1&&p2occ>0){
          	 t2[7]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[7]>=1&&p3occ>0){
           	t3[7]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[7]>=1&&p4occ>0){
            	t4[7]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[7]>=1&&p5occ>0){
            	t5[7]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[7]>=1&&p6occ>0){
           	 t6[7]+=1;
            	 p6occ-=1;}}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 9;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[8]>=1&&p1occ>0){
            	t1[8]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[8]>=1&&p2occ>0){
          	 t2[8]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[0]>=1&&p3occ>0){
           	t3[8]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[8]>=1&&p4occ>0){
            	t4[8]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[8]>=1&&p5occ>0){
            	t5[8]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[8]>=1&&p6occ>0){
           	 t6[8]+=1;
            	 p6occ-=1;}}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 10;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[9]>=1&&p1occ>0){
            	t1[9]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[9]>=1&&p2occ>0){
          	 t2[9]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[9]>=1&&p3occ>0){
           	t3[9]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[9]>=1&&p4occ>0){
            	t4[9]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[9]>=1&&p5occ>0){
            	t5[9]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[9]>=1&&p6occ>0){
           	 t6[9]+=1;
            	 p6occ-=1;}}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >579.0  / height && Y < 662.0 / height) {
           selectedterritory = 11;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[10]>=1&&p1occ>0){
            	t1[10]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[10]>=1&&p2occ>0){
          	 t2[10]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[10]>=1&&p3occ>0){
           	t3[10]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[10]>=1&&p4occ>0){
            	t4[10]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[10]>=1&&p5occ>0){
            	t5[10]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[10]>=1&&p6occ>0){
           	 t6[10]+=1;
            	 p6occ-=1;}}
        
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 12;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[11]>=1&&p1occ>0){
            	t1[11]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[11]>=1&&p2occ>0){
          	 t2[11]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[11]>=1&&p3occ>0){
           	t3[11]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[11]>=1&&p4occ>0){
            	t4[11]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[11]>=1&&p5occ>0){
            	t5[11]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[11]>=1&&p6occ>0){
           	 t6[11]+=1;
            	 p6occ-=1;}}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 13;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[12]>=1&&p1occ>0){
            	t1[12]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[12]>=1&&p2occ>0){
          	 t2[12]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[12]>=1&&p3occ>0){
           	t3[12]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[12]>=1&&p4occ>0){
            	t4[12]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[12]>=1&&p5occ>0){
            	t5[12]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[12]>=1&&p6occ>0){
           	 t6[12]+=1;
            	 p6occ-=1;}}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 14;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[13]>=1&&p1occ>0){
            	t1[13]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[13]>=1&&p2occ>0){
          	 t2[13]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[13]>=1&&p3occ>0){
           	t3[13]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[13]>=1&&p4occ>0){
            	t4[13]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[13]>=1&&p5occ>0){
            	t5[13]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[13]>=1&&p5occ>0){
           	 t6[13]+=1;
            	p6occ-=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 15;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[14]>=1&&p1occ>0){
            	t1[14]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[14]>=1&&p2occ>0){
          	 t2[14]+=1;
          	 }
            if (randno==3&& t3[14]>=1&&p3occ>0){
           	t3[14]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[14]>=1&&p4occ>0){
            	t4[14]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[14]>=1&&p5occ>0){
            	t5[14]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[14]>=1&&p6occ>0){
           	 t6[14]+=1;
            	p6occ-=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >495.0  / height && Y < 579.0 / height) {
           selectedterritory = 16;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[15]>=1&&p1occ>0){
            	t1[15]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[15]>=1&&p2occ>0){
          	 t2[15]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[15]>=1&&p3occ>0){
           	t3[15]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[15]>=1&&p4occ>0){
            	t4[15]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[15]>=1&&p5occ>0){
            	t5[15]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[15]>=1&&p6occ>0){
           	 t6[15]+=1;
            	 p6occ-=1;}}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 17;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[16]>=1&&p1occ>0){
            	t1[16]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[16]>=1&&p2occ>0){
          	 t2[16]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[16]>=1&&p3occ>0){
           	t3[16]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[16]>=1&&p4occ>0){
            	t4[16]+=1;
            	randno+=1;p4occ-=1;}
            if (randno==5 && t5[16]>=1&&p5occ>0){
            	t5[16]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[16]>=1&&p6occ>0){
           	 t6[16]+=1;
            	 p6occ-=1;}}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 18;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[17]>=1&&p1occ>0){
            	t1[17]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[17]>=1&&p2occ>0){
          	 t2[17]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[17]>=1&&p3occ>0){
           	t3[17]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[17]>=1&&p4occ>0){
            	t4[17]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[17]>=1&&p5occ>0){
            	t5[17]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[17]>=1&&p6occ>0){
           	 t6[17]+=1;
            	p6occ-=1; }}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 19;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[18]>=1&&p1occ>0){
            	t1[18]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[18]>=1&&p2occ>0){
          	 t2[18]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[18]>=1&&p3occ>0){
           	t3[18]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[18]>=1&&p4occ>0){
            	t4[18]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[18]>=1&&p5occ>0){
            	t5[18]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[18]>=1&&p6occ>0){
           	 t6[18]+=1;
            	 p6occ-=1;}}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 20;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[19]>=1&&p1occ>0){
            	t1[19]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[19]>=1&&p2occ>0){
          	 t2[19]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[19]>=1&&p3occ>0){
           	t3[19]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[19]>=1&&p4occ>0){
            	t4[19]+=1;
		p4occ-=1;}
            if (randno==5 && t5[19]>=1&&p5occ>0){
            	t5[19]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[19]>=1&&p6occ>0){
           	 t6[19]+=1;
            	 p6occ-=1;}}
        
        
        
        if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 21;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[20]>=1&&p1occ>0){
            	t1[20]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[20]>=1&&p2occ>0){
          	 t2[20]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[20]>=1&&p3occ>0){
           	t3[20]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[20]>=1&&p4occ>0){
            	t4[20]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[20]>=1&&p5occ>0){
            	t5[20]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[20]>=1&&p6occ>0){
           	 t6[20]+=1;
            	 p6occ-=1;}}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 22;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[21]>=1&&p1occ>0){
            	t1[21]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[21]>=1&&p2occ>0){
          	 t2[21]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[21]>=1&&p3occ>0){
           	t3[21]+=1;
           	p3occ-=1;}
            if (randno==4&& t4[21]>=1&&p4occ>0){
            	t4[21]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[21]>=1&&p5occ>0){
            	t5[21]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[21]>=1&&p6occ>0){
           	 t6[21]+=1;
            	p6occ-=1; }}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 23;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[22]>=1&&p1occ>0){
            	t1[22]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[22]>=1&&p2occ>0){
          	 t2[22]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[22]>=1&&p3occ>0){
           	t3[22]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[22]>=1&&p4occ>0){
            	t4[22]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[22]>=1&&p5occ>0){
            	t5[22]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[22]>=1&&p6occ>0){
           	 t6[22]+=1;
            	 p6occ-=1;}}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 24;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[23]>=1&&p1occ>0){
            	t1[23]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[23]>=1&&p2occ>0){
          	 t2[23]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[23]>=1&&p3occ>0){
           	t3[23]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[23]>=1&&p4occ>0){
            	t4[23]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[23]>=1&&p5occ>0){
            	t5[23]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[23]>=1&&p6occ>0){
           	 t6[23]+=1;
            	 p6occ-=1;}}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 25;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[24]>=1&&p1occ>0){
            	t1[24]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[24]>=1&&p2occ>0){
          	 t2[24]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[24]>=1&&p3occ>0){
           	t3[24]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[24]>=1&&p4occ>0){
            	t4[24]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[24]>=1&&p5occ>0){
            	t5[24]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[24]>=1&&p6occ>0){
           	 t6[24]+=1;
            	 p6occ-=1;}}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >303.0  / height && Y < 388.0 / height) {
           selectedterritory = 26;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[25]>=1&&p1occ>0){
            	t1[25]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[25]>=1&&p2occ>0){
          	 t2[25]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[25]>=1&&p3occ>0){
           	t3[25]+=1;
           	p3occ-=1;}
            if (randno==4&& t4[25]>=1&&p4occ>0){
            	t4[25]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[25]>=1&&p5occ>0){
            	t5[25]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[25]>=1&&p6occ>0){
           	 t6[25]+=1;
            	 p6occ-=1;}}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 27;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[26]>=1&&p1occ>0){
            	t1[26]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[26]>=1&&p2occ>0){
          	 t2[26]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[26]>=1&&p3occ>0){
           	t3[26]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[26]>=1&&p4occ>0){
            	t4[26]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[26]>=1&&p5occ>0){
            	t5[26]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[26]>=1&&p6occ>0){
           	 t6[26]+=1;
            	 p6occ-=1;}}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 28;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[27]>=1&&p1occ>0){
            	t1[27]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[27]>=1&&p2occ>0){
          	 t2[27]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[27]>=1&&p3occ>0){
           	t3[27]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[27]>=1&&p4occ>0){
            	t4[27]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[27]>=1&&p5occ>0){
            	t5[27]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[27]>=1&&p6occ>0){
           	 t6[27]+=1;
            	 p6occ-=1;}}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 29;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[28]>=1&&p1occ>0){
            	t1[28]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[28]>=1&&p2occ>0){
          	 t2[28]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[28]>=1&&p3occ>0){
           	t3[28]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[28]>=1&&p4occ>0){
            	t4[28]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[28]>=1&&p5occ>0){
            	t5[28]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[28]>=1&&p6occ>0){
           	 t6[28]+=1;
            	p6occ-=1; }}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 30;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[29]>=1&&p1occ>0){
            	t1[29]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[29]>=1&&p2occ>0){
          	 t2[29]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[29]>=1&&p3occ>0){
           	t3[29]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[29]>=1&&p4occ>0){
            	t4[29]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[29]>=1&&p5occ>0){
            	t5[29]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[29]>=1&&p6occ>0){
           	 t6[29]+=1;
            	 p6occ-=1;}}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >219.0  / height && Y < 303.0 / height) {
           selectedterritory = 31;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[30]>=1&&p1occ>0){
            	t1[30]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[30]>=1&&p2occ>0){
          	 t2[30]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[30]>=1&&p3occ>0){
           	t3[30]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[30]>=1&&p4occ>0){
            	t4[30]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[30]>=1&&p5occ>0){
            	t5[30]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[30]>=1&&p6occ>0){
           	 t6[30]+=1;
            	 p6occ-=1;}}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 32;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[31]>=1&&p1occ>0){
            	t1[31]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[31]>=1&&p2occ>0){
          	 t2[31]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[31]>=1&&p3occ>0){
           	t3[31]+=1;
           	p3occ-=1;}
            if (randno==4&& t4[31]>=1&&p4occ>0){
            	t4[31]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[31]>=1&&p5occ>0){
            	t5[31]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[31]>=1&&p6occ>0){
           	 t6[31]+=1;
            	 p6occ-=1;}}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 33;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[32]>=1&&p1occ>0){
            	t1[32]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[32]>=1&&p2occ>0){
          	 t2[32]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[32]>=1&&p3occ>0){
           	t3[32]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[32]>=1&&p4occ>0){
            	t4[32]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[32]>=1&&p5occ>0){
            	t5[32]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[32]>=1&&p6occ>0){
           	 t6[32]+=1;
            	 p6occ-=1;}}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 34;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[33]>=1&&p1occ>0){
            	t1[33]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[33]>=1&&p2occ>0){
          	 t2[33]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[33]>=1&&p3occ>0){
           	t3[33]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[33]>=1&&p4occ>0){
            	t4[33]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[33]>=1&&p5occ>0){
            	t5[33]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[33]>=1&&p6occ>0){
           	 t6[33]+=1;
            	 p6occ-=1;}}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 35;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[34]>=1&&p1occ>0){
            	t1[34]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[34]>=1&&p2occ>0){
          	 t2[34]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[34]>=1&&p3occ>0){
           	t3[34]+=1;
           	p3occ-=1;}
            if (randno==4&& t4[34]>=1&&p4occ>0){
            	t4[34]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[34]>=1&&p5occ>0){
            	t5[34]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[34]>=1&&p6occ>0){
           	 t6[34]+=1;
            	p6occ-=1; }}
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >136.0  / height && Y < 219.0 / height) {
           selectedterritory = 36;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[35]>=1&&p1occ>0){
            	t1[35]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[35]>=1&&p2occ>0){
          	 t2[35]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[35]>=1&&p3occ>0){
           	t3[35]+=1;
           	p3occ-=1;}
            if (randno==4&& t4[35]>=1&&p4occ>0){
            	t4[35]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[35]>=1&&p5occ>0){
            	t5[35]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[35]>=1&&p6occ>0){
           	 t6[35]+=1;
            	 p6occ-=1;}}
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 37;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[36]>=1&&p1occ>0){
            	t1[36]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[36]>=1&&p2occ>0){
          	 t2[36]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[36]>=1&&p3occ>0){
           	t3[36]+=1;
           	p3occ-=1;}
            if (randno==4&& t4[36]>=1&&p4occ>0){
            	t4[36]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[36]>=1&&p5occ>0){
            	t5[36]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[36]>=1&&p6occ>0){
           	 t6[36]+=1;
            	 p6occ-=1;}}
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 38;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[37]>=1&&p1occ>0){
            	t1[37]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[37]>=1&&p2occ>0){
          	 t2[37]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[37]>=1&&p3occ>0){
           	t3[37]+=1;
           	p3occ-=1;}
            if (randno==4&& t4[37]>=1&&p4occ>0){
            	t4[37]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[37]>=1&&p5occ>0){
            	t5[37]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[37]>=1&&p6occ>0){
           	 t6[37]+=1;
            	 p6occ-=1;}}
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 39;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[38]>=1&&p1occ>0){
            	t1[38]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[38]>=1&&p2occ>0){
          	 t2[38]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[38]>=1&&p3occ>0){
           	t3[38]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[38]>=1&&p4occ>0){
            	t4[38]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[38]>=1&&p5occ>0){
            	t5[38]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[38]>=1&&p6occ>0){
           	 t6[38]+=1;
            	 p6occ-=1;}}
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 40;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[39]>=1&&p1occ>0){
            	t1[39]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[39]>=1&&p2occ>0){
          	 t2[39]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[39]>=1&&p3occ>0){
           	t3[39]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[39]>=1&&p4occ>0){
            	t4[39]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[0]>=1&&p5occ>0){
            	t5[39]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[0]>=1&&p6occ>0){
           	 t6[39]+=1;
            	 p6occ-=1;}}
        
        
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 41;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[40]>=1&&p1occ>0){
            	t1[40]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[40]>=1&&p2occ>0){
          	 t2[40]+=1;
          	 p2occ-=1;
          	}
            if (randno==3&& t3[40]>=1&&p3occ>0){
           	t3[40]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[40]>=1&&p4occ>0){
            	t4[40]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[40]>=1&&p5occ>0){
            	t5[40]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[40]>=1&&p6occ>0){
           	 t6[40]+=1;
            	 p6occ-=1;}}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[41]=1;
            selectedterritory = 42;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[41]>=1&&p1occ>0){
            	t1[41]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[41]>=1&&p2occ>0){
          	 t2[41]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[41]>=1&&p3occ>0){
           	t3[41]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[41]>=1&&p4occ>0){
            	t4[41]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[41]>=1&&p5occ>0){
            	t5[41]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[0]>=1&&p6occ>0){
           	 t6[41]+=1;
            	 p6occ-=1;}}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 663.0 / height && Y <= 747.0 / height) {
            selectedterritory = 43;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[42]>=1&&p1occ>0){
            	t1[42]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[42]>=1&&p2occ>0){
          	 t2[42]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[42]>=1&&p3occ>0){
           	t3[42]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[42]>=1&&p4occ>0){
            	t4[42]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[42]>=1&&p5occ>0){
            	t5[42]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[42]>=1&&p6occ>0){
           	 t6[42]+=1;
            	 p6occ-=1;}}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 663.0 / height && Y <= 747.0 / height) {
            t[43]=1;
            selectedterritory = 44;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[43]>=1&&p1occ>0){
            	t1[43]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[43]>=1&&p2occ>0){
          	 t2[43]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[43]>=1&&p3occ>0){
           	t3[43]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[43]>=1&&p4occ>0){
            	t4[43]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[43]>=1&&p5occ>0){
            	t5[43]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[43]>=1&&p6occ>0){
           	 t6[43]+=1;
            	 p6occ-=1;}}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 580.0 / height && Y <= 663.0 / height) {
            selectedterritory = 45;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[44]>=1&&p1occ>0){
            	t1[44]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[44]>=1&&p2occ>0){
          	 t2[44]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[44]>=1&&p3occ>0){
           	t3[44]+=1;
           	p3occ-=1;}
            if (randno==4&& t4[44]>=1&&p4occ>0){
            	t4[44]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[44]>=1&&p5occ>0){
            	t5[44]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[44]>=1&&p6occ>0){
           	 t6[44]+=1;
            	 p6occ-=1;}}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 580.0 / height && Y <= 663.0 / height) {
            t[45]=1;
            selectedterritory = 46;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[45]>=1&&p1occ>0){
            	t1[45]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[45]>=1&&p2occ>0){
          	 t2[45]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[45]>=1&&p3occ>0){
           	t3[45]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[45]>=1&&p4occ>0){
            	t4[45]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[45]>=1&&p5occ>0){
            	t5[45]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[45]>=1&&p6occ>0){
           	 t6[45]+=1;
            	 p6occ-=1;}}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 495.0 / height && Y <= 580.0 / height) {
            selectedterritory = 47;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[46]>=1&&p1occ>0){
            	t1[46]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[46]>=1&&p2occ>0){
          	 t2[46]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[46]>=1&&p3occ>0){
           	t3[46]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[46]>=1&&p4occ>0){
            	t4[46]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[46]>=1&&p5occ>0){
            	t5[46]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[46]>=1&&p6occ>0){
           	 t6[46]+=1;
            	 p6occ-=1;}}
        
        
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 387.0 / height && Y <= 469.0 / height) {
            selectedterritory = 48;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[47]>=1&&p1occ>0){
            	t1[47]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[47]>=1&&p2occ>0){
          	 t2[47]+=1;
          	 p2occ-=1;
          	 }
            if (randno==3&& t3[47]>=1&&p3occ>0){
           	t3[47]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[47]>=1&&p4occ>0){
            	t4[47]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[47]>=1&&p5occ>0){
            	t5[47]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[47]>=1&&p6occ>0){
           	 t6[47]+=1;
            	 p6occ-=1;}}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 302.0 / height && Y < 387.0 / height) {
            selectedterritory = 49;
            cout << "Troops landed in Territory " << selectedterritory << endl;
           if (randno==1 && t1[48]>=1&&p1occ>0){
            	t1[48]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[48]>=1&&p2occ>0){
          	 t2[48]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[48]>=1&&p3occ>0){
           	t3[48]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[48]>=1&&p4occ>0){
            	t4[48]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[48]>=1&&p5occ>0){
            	t5[48]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[48]>=1&&p6occ>0){
           	 t6[48]+=1;
            	 p6occ-=1;}}
         if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 219.0 / height && Y <= 302.0 / height) {
            selectedterritory =50;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[49]>=1&&p1occ>0){
            	t1[49]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[49]>=1&&p2occ>0){
          	 t2[49]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[49]>=1&&p3occ>0){
           	t3[49]+=1;
           	p3occ-=1; }
            if (randno==4&& t4[49]>=1&&p4occ>0){
            	t4[49]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[49]>=1&&p5occ>0){
            	t5[49]+=1;
            	 p5occ-=1;}
            if (randno==6&&t6[49]>=1&&p6occ>0){
           	 t6[49]+=1;
            	 p6occ-=1;}}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 130.0 / height && Y <= 219.0 / height) {
            selectedterritory = 51;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1 && t1[50]>=1&&p1occ>0){
            	t1[50]+=1;
            	p1occ-=1;
            	 }
            if (randno==2&& t2[50]>=1&&p2occ>0){
          	 t2[50]+=1;
          	 p2occ-=1;}
            if (randno==3&& t3[50]>=1&&p3occ>0){
           	t3[50]+=1;
           	 p3occ-=1;}
            if (randno==4&& t4[50]>=1&&p4occ>0){
            	t4[50]+=1;
            	p4occ-=1;}
            if (randno==5 && t5[50]>=1&&p5occ>0){
            	t5[50]+=1;
            	p5occ-=1; }
            if (randno==6&&t6[50]>=1&&p6occ>0){
           	 t6[50]+=1;
            	p6occ-=1; }}
        
        if (p1occ==0&&p2occ==0&&p3occ==0&&p4occ==0&&p5occ==0&&p6occ==0){
       		fight=1;
       		mov=1;}
        
        if (randno==1&&p1occ==0){
        	randno+=1;
        	if(randno>players)
        		randno=1;}
        else if (randno==2&&p2occ==0){
        	randno+=1;
        	if(randno>players)
        		randno=1;}
        if (randno==3&&p3occ==0){
        		randno+=1;
        		if(randno>players)
        			randno=1;}
        if (randno==4&&p4occ==0){
        		randno+=1;
        		if(randno>players)
        			randno=1;}
        if (randno==5&&p5occ==0){
        		randno+=1;
        		if(randno>players)
        			randno=1;}
        if (randno==6&&p6occ==0){
        		randno+=1;
        		if(randno>players)
        		randno=1;}}
       
void territoryDecider(float X, float Y){		// TO DECIDE WHICH COORDINATE'S TERRITORY USER HAS CLICKED
	int width = 1200;
   	int height = 840;
	if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 1;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[0]=1;
            if (randno==2)
            t2[0]=1;
            if (randno==3)
            t3[0]=1;
            if (randno==4)
            t4[0]=1;
            if (randno==5)
            t5[0]=1;
            if (randno==6)
            t6[0]=1;
            t[0]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[1]=1;
            selectedterritory = 2;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[1]=1;
            if (randno==2)
            t2[1]=1;
            if (randno==3)
            t3[1]=1;
            if (randno==4)
            t4[1]=1;
            if (randno==5)
            t5[1]=1;
            if (randno==6)
            t6[1]=1;
            t[1]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 3;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[2]=1;
            if (randno==2)
            t2[2]=1;
            if (randno==3)
            t3[2]=1;
            if (randno==4)
            t4[2]=1;
            if (randno==5)
            t5[2]=1;
            if (randno==6)
            t6[2]=1;
            t[2]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 4;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[3]=1;
            if (randno==2)
            t2[3]=1;
            if (randno==3)
            t3[3]=1;
            if (randno==4)
            t4[3]=1;
            if (randno==5)
            t5[3]=1;
            if (randno==6)
            t6[3]=1;
            t[3]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 5;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[4]=1;
            if (randno==2)
            t2[4]=1;
            if (randno==3)
            t3[4]=1;
            if (randno==4)
            t4[4]=1;
            if (randno==5)
            t5[4]=1;
            if (randno==6)
            t6[4]=1;
            t[4]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >662.0  / height && Y < 748.0 / height) {
           selectedterritory = 6;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[5]=1;
            if (randno==2)
            t2[5]=1;
            if (randno==3)
            t3[5]=1;
            if (randno==4)
            t4[5]=1;
            if (randno==5)
            t5[5]=1;
            if (randno==6)
            t6[5]=1;
            t[5]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 7;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[6]=1;
            if (randno==2)
            t2[6]=1;
            if (randno==3)
            t3[6]=1;
            if (randno==4)
            t4[6]=1;
            if (randno==5)
            t5[6]=1;
            if (randno==6)
            t6[6]=1;
            t[6]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 8;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[7]=1;
            if (randno==2)
            t2[7]=1;
            if (randno==3)
            t3[7]=1;
            if (randno==4)
            t4[7]=1;
            if (randno==5)
            t5[7]=1;
            if (randno==6)
            t6[7]=1;
            t[7]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 9;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[8]=1;
            if (randno==2)
            t2[8]=1;
            if (randno==3)
            t3[8]=1;
            if (randno==4)
            t4[8]=1;
            if (randno==5)
            t5[8]=1;
            if (randno==6)
            t6[8]=1;
            t[8]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 662.0 / height && Y <= 748.0 / height) {
            selectedterritory = 10;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[9]=1;
            if (randno==2)
            t2[9]=1;
            if (randno==3)
            t3[9]=1;
            if (randno==4)
            t4[9]=1;
            if (randno==5)
            t5[9]=1;
            if (randno==6)
            t6[9]=1;
            t[9]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >579.0  / height && Y < 662.0 / height) {
           selectedterritory = 11;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[10]=1;
            if (randno==2)
            t2[10]=1;
            if (randno==3)
            t3[10]=1;
            if (randno==4)
            t4[10]=1;
            if (randno==5)
            t5[10]=1;
            if (randno==6)
            t6[10]=1;
            t[10]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 12;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[11]=1;
            if (randno==2)
            t2[11]=1;
            if (randno==3)
            t3[11]=1;
            if (randno==4)
            t4[11]=1;
            if (randno==5)
            t5[11]=1;
            if (randno==6)
            t6[11]=1;
            t[11]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 13;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[12]=1;
            if (randno==2)
            t2[12]=1;
            if (randno==3)
            t3[12]=1;
            if (randno==4)
            t4[12]=1;
            if (randno==5)
            t5[12]=1;
            if (randno==6)
            t6[12]=1;
            t[12]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 14;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[13]=1;
            if (randno==2)
            t2[13]=1;
            if (randno==3)
            t3[13]=1;
            if (randno==4)
            t4[13]=1;
            if (randno==5)
            t5[13]=1;
            if (randno==6)
            t6[13]=1;
            t[13]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 579.0 / height && Y <= 662.0 / height) {
            selectedterritory = 15;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[14]=1;
            if (randno==2)
            t2[14]=1;
            if (randno==3)
            t3[14]=1;
            if (randno==4)
            t4[14]=1;
            if (randno==5)
            t5[14]=1;
            if (randno==6)
            t6[14]=1;
            t[14]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >495.0  / height && Y < 579.0 / height) {
           selectedterritory = 16;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[15]=1;
            if (randno==2)
            t2[15]=1;
            if (randno==3)
            t3[15]=1;
            if (randno==4)
            t4[15]=1;
            if (randno==5)
            t5[15]=1;
            if (randno==6)
            t6[15]=1;
            t[15]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 17;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[16]=1;
            if (randno==2)
            t2[16]=1;
            if (randno==3)
            t3[16]=1;
            if (randno==4)
            t4[16]=1;
            if (randno==5)
            t5[16]=1;
            if (randno==6)
            t6[16]=1;
            t[16]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 18;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[17]=1;
            if (randno==2)
            t2[17]=1;
            if (randno==3)
            t3[17]=1;
            if (randno==4)
            t4[17]=1;
            if (randno==5)
            t5[17]=1;
            if (randno==6)
            t6[17]=1;
            t[17]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 19;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[18]=1;
            if (randno==2)
            t2[18]=1;
            if (randno==3)
            t3[18]=1;
            if (randno==4)
            t4[18]=1;
            if (randno==5)
            t5[18]=1;
            if (randno==6)
            t6[18]=1;
            t[18]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 495.0 / height && Y <= 579.0 / height) {
            selectedterritory = 20;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[19]=1;
            if (randno==2)
            t2[19]=1;
            if (randno==3)
            t3[19]=1;
            if (randno==4)
            t4[19]=1;
            if (randno==5)
            t5[19]=1;
            if (randno==6)
            t6[19]=1;
            t[19]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        
        
        
        if (X >= 3.0 / width && X <= 109.0 / width &&
           Y >= 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 21;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[20]=1;
            if (randno==2)
            t2[20]=1;
            if (randno==3)
            t3[20]=1;
            if (randno==4)
            t4[20]=1;
            if (randno==5)
            t5[20]=1;
            if (randno==6)
            t6[20]=1;
            t[20]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 22;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[21]=1;
            if (randno==2)
            t2[21]=1;
            if (randno==3)
            t3[21]=1;
            if (randno==4)
            t4[21]=1;
            if (randno==5)
            t5[21]=1;
            if (randno==6)
            t6[21]=1;
            t[21]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 23;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[22]=1;
            if (randno==2)
            t2[22]=1;
            if (randno==3)
            t3[22]=1;
            if (randno==4)
            t4[22]=1;
            if (randno==5)
            t5[22]=1;
            if (randno==6)
            t6[22]=1;
            t[22]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 24;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[23]=1;
            if (randno==2)
            t2[23]=1;
            if (randno==3)
            t3[23]=1;
            if (randno==4)
            t4[23]=1;
            if (randno==5)
            t5[23]=1;
            if (randno==6)
            t6[23]=1;
            t[23]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 388.0 / height && Y <= 469.0 / height) {
            selectedterritory = 25;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[24]=1;
            if (randno==2)
            t2[24]=1;
            if (randno==3)
            t3[24]=1;
            if (randno==4)
            t4[24]=1;
            if (randno==5)
            t5[24]=1;
            if (randno==6)
            t6[24]=1;
            t[24]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >303.0  / height && Y < 388.0 / height) {
           selectedterritory = 26;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[25]=1;
            if (randno==2)
            t2[25]=1;
            if (randno==3)
            t3[25]=1;
            if (randno==4)
            t4[25]=1;
            if (randno==5)
            t5[25]=1;
            if (randno==6)
            t6[25]=1;
            t[25]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 27;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[26]=1;
            if (randno==2)
            t2[26]=1;
            if (randno==3)
            t3[26]=1;
            if (randno==4)
            t4[26]=1;
            if (randno==5)
            t5[26]=1;
            if (randno==6)
            t6[26]=1;
            t[26]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 28;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[27]=1;
            if (randno==2)
            t2[27]=1;
            if (randno==3)
            t3[27]=1;
            if (randno==4)
            t4[27]=1;
            if (randno==5)
            t5[27]=1;
            if (randno==6)
            t6[27]=1;
            t[27]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 29;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[28]=1;
            if (randno==2)
            t2[28]=1;
            if (randno==3)
            t3[28]=1;
            if (randno==4)
            t4[28]=1;
            if (randno==5)
            t5[28]=1;
            if (randno==6)
            t6[28]=1;
            t[28]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 303.0 / height && Y <= 388.0 / height) {
            selectedterritory = 30;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[29]=1;
            if (randno==2)
            t2[29]=1;
            if (randno==3)
            t3[29]=1;
            if (randno==4)
            t4[29]=1;
            if (randno==5)
            t5[29]=1;
            if (randno==6)
            t6[29]=1;
            t[29]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >219.0  / height && Y < 303.0 / height) {
           selectedterritory = 31;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[30]=1;
            if (randno==2)
            t2[30]=1;
            if (randno==3)
            t3[30]=1;
            if (randno==4)
            t4[30]=1;
            if (randno==5)
            t5[30]=1;
            if (randno==6)
            t6[30]=1;
            t[30]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 32;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[31]=1;
            if (randno==2)
            t2[31]=1;
            if (randno==3)
            t3[31]=1;
            if (randno==4)
            t4[31]=1;
            if (randno==5)
            t5[31]=1;
            if (randno==6)
            t6[31]=1;
            t[31]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 33;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[32]=1;
            if (randno==2)
            t2[32]=1;
            if (randno==3)
            t3[32]=1;
            if (randno==4)
            t4[32]=1;
            if (randno==5)
            t5[32]=1;
            if (randno==6)
            t6[32]=1;
            t[32]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 34;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[33]=1;
            if (randno==2)
            t2[33]=1;
            if (randno==3)
            t3[33]=1;
            if (randno==4)
            t4[33]=1;
            if (randno==5)
            t5[33]=1;
            if (randno==6)
            t6[33]=1;
            t[33]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 219.0 / height && Y <= 303.0 / height) {
            selectedterritory = 35;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[34]=1;
            if (randno==2)
            t2[34]=1;
            if (randno==3)
            t3[34]=1;
            if (randno==4)
            t4[34]=1;
            if (randno==5)
            t5[34]=1;
            if (randno==6)
            t6[34]=1;
            t[34]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 3.0 / width && X <=109.0 / width &&
            Y >136.0  / height && Y < 219.0 / height) {
           selectedterritory = 36;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[35]=1;
            if (randno==2)
            t2[35]=1;
            if (randno==3)
            t3[35]=1;
            if (randno==4)
            t4[35]=1;
            if (randno==5)
            t5[35]=1;
            if (randno==6)
            t6[35]=1;
            t[35]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
          if (X > 109.0 / width && X <= 219.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 37;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[36]=1;
            if (randno==2)
            t2[36]=1;
            if (randno==3)
            t3[36]=1;
            if (randno==4)
            t4[36]=1;
            if (randno==5)
            t5[36]=1;
            if (randno==6)
            t6[36]=1;
            t[36]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X > 219.0 / width && X <= 326.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 38;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[37]=1;
            if (randno==2)
            t2[37]=1;
            if (randno==3)
            t3[37]=1;
            if (randno==4)
            t4[37]=1;
            if (randno==5)
            t5[37]=1;
            if (randno==6)
            t6[37]=1;
            t[37]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >326.0 / width && X <= 436.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 39;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[38]=1;
            if (randno==2)
            t2[38]=1;
            if (randno==3)
            t3[38]=1;
            if (randno==4)
            t4[38]=1;
            if (randno==5)
            t5[38]=1;
            if (randno==6)
            t6[38]=1;
            t[38]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        if (X >436.0 / width && X <= 542.0 / width &&
           Y > 136.0 / height && Y <= 219.0 / height) {
            selectedterritory = 40;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[39]=1;
            if (randno==2)
            t2[39]=1;
            if (randno==3)
            t3[39]=1;
            if (randno==4)
            t4[39]=1;
            if (randno==5)
            t5[39]=1;
            if (randno==6)
            t6[39]=1;
            t[39]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}
        }
        
        
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 748.0 / height && Y <= 830.0 / height) {
            selectedterritory = 41;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[40]=1;
            if (randno==2)
            t2[40]=1;
            if (randno==3)
            t3[40]=1;
            if (randno==4)
            t4[40]=1;
            if (randno==5)
            t5[40]=1;
            if (randno==6)
            t6[40]=1;
            t[40]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 748.0 / height && Y <= 830.0 / height) {
            t[41]=1;
            selectedterritory = 42;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[41]=1;
            if (randno==2)
            t2[41]=1;
            if (randno==3)
            t3[41]=1;
            if (randno==4)
            t4[41]=1;
            if (randno==5)
            t5[41]=1;
            if (randno==6)
            t6[41]=1;
            t[41]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 663.0 / height && Y <= 747.0 / height) {
            selectedterritory = 43;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[42]=1;
            if (randno==2)
            t2[42]=1;
            if (randno==3)
            t3[42]=1;
            if (randno==4)
            t4[42]=1;
            if (randno==5)
            t5[42]=1;
            if (randno==6)
            t6[42]=1;
            t[42]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 663.0 / height && Y <= 747.0 / height) {
            t[43]=1;
            selectedterritory = 44;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[43]=1;
            if (randno==2)
            t2[43]=1;
            if (randno==3)
            t3[43]=1;
            if (randno==4)
            t4[43]=1;
            if (randno==5)
            t5[43]=1;
            if (randno==6)
            t6[43]=1;
            t[43]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 580.0 / height && Y <= 663.0 / height) {
            selectedterritory = 45;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[44]=1;
            if (randno==2)
            t2[44]=1;
            if (randno==3)
            t3[44]=1;
            if (randno==4)
            t4[44]=1;
            if (randno==5)
            t5[44]=1;
            if (randno==6)
            t6[44]=1;
            t[44]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
        if (X < 764.0 / width && X > 659.0 / width &&
           Y > 580.0 / height && Y <= 663.0 / height) {
            t[45]=1;
            selectedterritory = 46;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[45]=1;
            if (randno==2)
            t2[45]=1;
            if (randno==3)
            t3[45]=1;
            if (randno==4)
            t4[45]=1;
            if (randno==5)
            t5[45]=1;
            if (randno==6)
            t6[45]=1;
            t[45]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 495.0 / height && Y <= 580.0 / height) {
            selectedterritory = 47;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[46]=1;
            if (randno==2)
            t2[46]=1;
            if (randno==3)
            t3[46]=1;
            if (randno==4)
            t4[46]=1;
            if (randno==5)
            t5[46]=1;
            if (randno==6)
            t6[46]=1;
            t[46]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
        
        
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 387.0 / height && Y <= 469.0 / height) {
            selectedterritory = 48;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[47]=1;
            if (randno==2)
            t2[47]=1;
            if (randno==3)
            t3[47]=1;
            if (randno==4)
            t4[47]=1;
            if (randno==5)
            t5[47]=1;
            if (randno==6)
            t6[47]=1;
            t[47]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
        if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 302.0 / height && Y < 387.0 / height) {
            selectedterritory = 49;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[48]=1;
            if (randno==2)
            t2[48]=1;
            if (randno==3)
            t3[48]=1;
            if (randno==4)
            t4[48]=1;
            if (randno==5)
            t5[48]=1;
            if (randno==6)
            t6[48]=1;
            t[48]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
         if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 219.0 / height && Y <= 302.0 / height) {
            selectedterritory =50;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[49]=1;
            if (randno==2)
            t2[49]=1;
            if (randno==3)
            t3[49]=1;
            if (randno==4)
            t4[49]=1;
            if (randno==5)
            t5[49]=1;
            if (randno==6)
            t6[49]=1;
            t[49]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}
          if (X >= 552.0 / width && X <= 659.0 / width &&
           Y >= 130.0 / height && Y <= 219.0 / height) {
            selectedterritory = 51;
            cout << "Troops landed in Territory " << selectedterritory << endl;
            if (randno==1)
            t1[50]=1;
            if (randno==2)
            t2[50]=1;
            if (randno==3)
            t3[50]=1;
            if (randno==4)
            t4[50]=1;
            if (randno==5)
            t5[50]=1;
            if (randno==6)
            t6[50]=1;
            t[50]=1;
            randno+=1;
	    if (randno>players){
        	randno=1;}}}
#endif /* AsteroidS_CPP_ */
