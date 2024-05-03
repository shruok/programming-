#ifndef COPY_ACTION_H
#define COPY_ACTION_H

#include "Actions/Action.h"

class Copy_Action: public Action
{
public:
	Copy_Action(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif