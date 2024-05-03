#include "ChangeBorderColor.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
ChangeBorderColor::ChangeBorderColor(ApplicationManager* pApp) : Action(pApp) { c = pApp->GetOutput()->getCrntDrawColor(); changed = false; }

void ChangeBorderColor::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    ActionType Act;

    pOut->PrintMessage("Please choose a color");

    Act = pIn->GetUserAction();
    switch (Act) {
    case RED1: c = RED; changed = true; break;
    case BLUE1: c = BLUE; changed = true; break;
    case BLACK1: c = BLACK; changed = true; break;
    case WHITE1: c = WHITE; changed = true; break;
    case GREEN1: c = DARKGREEN; changed = true; break;
    default: break;
    }

    pOut->ClearStatusBar();
}

void ChangeBorderColor::Execute()
{
    ReadActionParameters();
    if (changed) {

        if (pManager->getSelectedFig())
            pManager->getSelectedFig()->ChngBorderClr(c);

        UI.BorderColor = c;
        UI.OBorderd = true;
    }
}