#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H

#include "Actions/Action.h"

class Paste_Action : public Action
{
	Point  p1;

public:
	Paste_Action(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual void Execute();


};
#endif
