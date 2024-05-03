#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT, //Draw Rectangle
	DRAW_SQR,
	DRAW_TRI,
	DRAW_HEX,
	DRAW_CIR,
	SAVE,
	LOAD,
	Select,
	Copy,
	Paste,
	EXIT,			
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,	
	CHANGEFILLCOLOR,
	CHANGEBORDERCOLOR,
	RED1,
	GREEN1,
	BLACK1,
	BLUE1,
	WHITE1,
	ORANGE1,
	YELLOW1,
	MAGENTA,
	Nofill,
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
	color BorderClr; // border color of the figure 
	bool isOBordered; // frame of the figure is colored or not

};

#endif