#include "LoadGraph.h"
#include "CHexagon.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CTriangle.h"
#include "Figures/CRectangle.h"
#include <fstream>
#include "Actions/Action.h"
#include "ClearAllAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "DEFS.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}

void ClearAllAction::ReadActionParameters() {}
void ClearAllAction::Execute(bool co) {
	//clearing draw area
	//Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();
	//pOut->ClearDrawArea();
	//clearing fig list
	pManager->clearActions(1);
	//Record action
	if (pManager->getisrec())
		pManager->Addreco(this);
}
void ClearAllAction::undo()
{

}

void ClearAllAction::redo()
{

}