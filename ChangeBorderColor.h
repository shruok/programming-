#pragma once
#ifndef CHANGEBORDERCOLOR
#define CHANGEBORDERCOLOR
#include "Actions/Action.h"
class ChangeBorderColor :public Action
{
	color c;
	bool changed;  //to check if I clicked on a color on the toolbar or anywhere else. 
public:
	ChangeBorderColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
