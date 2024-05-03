#pragma once
#ifndef CHANGEFILLCOLOR
#define CHANGEFILLCOLOR

#include "Actions/Action.h"

class ChangeFillingColor : public Action 
{
	color c;
	bool changed;  //to check if I clicked on a color on the toolbar or anywhere else. 
public:
	ChangeFillingColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif

