#ifndef SELECT_H
#define SELECT_H

#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Figures/CFigure.h"
#include "GUI/Output.h"
#include "GUI/Output.h"
class Select_Action : public Action
{
private:
	Point P1;
	CFigure* figure;
	color OrigColor;
public:
	Select_Action(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool C = true);

	void undo();
	void redo();
};

#endif
