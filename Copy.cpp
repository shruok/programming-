#include "Copy.h"
#include "ApplicationManager.h"
#include "Figures/CFigure.h"

Copy_Action::Copy_Action(ApplicationManager* pMan) : Action(pMan)
{
}

void Copy_Action::ReadActionParameters()
{
}

void Copy_Action::Execute()
{
	Output* pOut = pManager->GetOutput();

	CFigure* ptr;
	CFigure* ptro;

	ptr = pManager->getselfig();

	if (ptr == NULL)
		pOut->PrintMessage("please selsect a figure first!");
	else
	{
		ptro = ptr->Copy();
		pManager->SetClipboard(ptro);
		pOut->PrintMessage("Figure is copied");
	}
}