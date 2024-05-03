#include "Select.h"
Select_Action::Select_Action(ApplicationManager* pApp) : Action(pApp)
{
}
void Select_Action::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//pOut->PrintMessage("Select figure");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();

}
void Select_Action::Execute(bool C)
{
	ReadActionParameters();
	figure = pManager->GetFigure(P1.x, P1.y);
	if (figure != nullptr)
	{
		if (pManager->getSelectedFig() == nullptr)
		{
			figure->SetSelected(true);
			figure->ChangeDrawColor(MAGENTA);
			pManager->setSelectedFig(figure);

		}
		else
		{
			CFigure* h = (pManager->getSelectedFig());
			if (figure->IsSelected())
			{
				if (figure->getcolourinfo().DrawClr == MAGENTA)
				{
					figure->ChangeDrawColor(figure->getOrigColor());
					figure->SetSelected(false);
					pManager->setSelectedFig(nullptr);
				}
				else
				{
					figure->ChangeDrawColor(figure->getcolourinfo().DrawClr);
					figure->SetSelected(false);
					pManager->setSelectedFig(nullptr);
				}
			}
			else
			{

				figure->SetSelected(true);
				pManager->setSelectedFig(figure);
				figure->ChangeDrawColor(MAGENTA);
			}
			if (figure->getcolourinfo().DrawClr == MAGENTA)
			{
				h->ChangeDrawColor(h->getOrigColor());
				h->SetSelected(false);
			}
			else
			{
				h->ChangeDrawColor(h->getcolourinfo().DrawClr);
				h->SetSelected(false);
			}
		}
	}
}

void Select_Action::undo()
{

}

void Select_Action::redo()
{

}