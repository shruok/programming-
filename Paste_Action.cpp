#include "Paste_Action.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"


Paste_Action::Paste_Action(ApplicationManager* pMan) :Action(pMan)
{
}


void Paste_Action::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please Click on the Drawing Area to paste");
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->ClearStatusBar();

}


void Paste_Action::Execute()
{
	Output* pOut = pManager->GetOutput();

	CFigure* ptr,* ptro;

	if (pManager->GetClipboard())
	{
		ReadActionParameters();
		ptr = pManager->GetClipboard();
		ptro = ptr->Paste(p1);

		pManager->AddFigure(ptro);
	}
	else
	{
		pOut->PrintMessage("please copy/cut a figure first");
	}
}