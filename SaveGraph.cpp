#include "SaveGraph.h"
#include <iostream>
#include <fstream>
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

SaveGraph::SaveGraph(ApplicationManager* pApp) : Action(pApp)
{}
void SaveGraph::ReadActionParameters()
{
	int x, y;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the file name to save it");
	filename = pIn->GetSrting(pOut);
	pOut->PrintMessage("saved");
}
void SaveGraph::Execute(bool co)
{
	Output* pOut = pManager->GetOutput();
	if (co) {
		ReadActionParameters();
	}
	else
	{
		filename = "original file ";
	}
	int drawcolor;
	int fillcolor;

	if (pOut->getCrntDrawColor() == RED)
		drawcolor = RED1;
	else if (pOut->getCrntDrawColor() == ORANGE)
		drawcolor = ORANGE1;
	else if (pOut->getCrntDrawColor() == YELLOW)
		drawcolor = YELLOW1;
	else if (pOut->getCrntDrawColor() == GREEN)
		drawcolor = GREEN1;
	else if (pOut->getCrntDrawColor() == BLUE)
		drawcolor = BLUE1;
	else if (pOut->getCrntDrawColor() == BLACK)
		drawcolor = BLACK1;

	if (pOut->getCrntFillColor() == RED)
		fillcolor = RED1;
	else if (pOut->getCrntFillColor() == ORANGE)
		fillcolor = ORANGE1;
	else if (pOut->getCrntFillColor() == YELLOW)
		fillcolor = YELLOW1;
	else if (pOut->getCrntFillColor() == GREEN)
		fillcolor = GREEN1;
	else if (pOut->getCrntFillColor() == BLUE)
		fillcolor = BLUE1;
	else if (pOut->getCrntFillColor() == BLACK)
		fillcolor = BLACK1;
	else
		fillcolor = Nofill;

	fstream f ;
	f.open(filename + ".txt", ios::out);
	f << drawcolor << "   " << fillcolor << '\n';
	f.close();
}
void SaveGraph::undo() {}
void SaveGraph::redo() {}