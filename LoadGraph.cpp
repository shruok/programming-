#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CTriangle.h" 
#include "CHexagon.h"
#include <fstream>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "ClearAllAction.h"
#include "LoadGraph.h"

LoadGraph::LoadGraph(ApplicationManager* pApp) :Action(pApp)
{}
void LoadGraph::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the file name to load it");
	filename = pIn->GetSrting(pOut);//gets the file name
}
void LoadGraph::Execute(bool co)
{
	if (co) {
		ReadActionParameters();
	}
	else {
		filename = "original file ";
	}
	ClearAllAction c(pManager);
	c.Execute();
	GfxInfo FigureGfxInfo;
	Output* pOut = pManager->GetOutput();

	int drawcolour;
	int fillcolour;
	int countfig; //count of figures
	int type; //type of shape
	int ID; //id of shape
	ifstream f;
	f.open(filename + ".txt");
	f >> drawcolour >> fillcolour;
	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 5;
	p2.y = 5;
	CRectangle pt(p1, p2, FigureGfxInfo);
	pt.setcolours(drawcolour, fillcolour, FigureGfxInfo);
	pOut->setCrntDrawColor(FigureGfxInfo.DrawClr);
	pOut->setCrntFillColor(FigureGfxInfo.FillClr);
	f >> countfig;
	for (int i = 0; i < countfig; i++) {
		f >> type >> ID;
		CFigure* R = NULL;
		if (type == 11) {
			Point p1, p2;
			p1.x = 0;
			p1.y = 0;
			p2.x = 5;
			p2.y = 5;
			CRectangle Rect(p1, p2, FigureGfxInfo);
			Rect.Load(f, R);
			pManager->AddFigure(R);
		}
		else if (type == 12) {
			Point p1, p2;
			p1.x = 0;
			p1.y = 0;
			p2.x = 5;
			p2.y = 5;
			CCircle Circ(p1, p2, FigureGfxInfo);
			Circ.Load(f, R);
			pManager->AddFigure(R);
		}
		else if (type == 13) {
			Point p1;
			p1.x = 0;
			p1.y = 0;
			CSquare Squ(p1, FigureGfxInfo);
			Squ.Load(f, R);
			pManager->AddFigure(R);
		}
		else if (type == 14) {
			Point p1, p2, p3;
			p1.x = 0;
			p1.y = 0;
			p2.x = 5;
			p2.y = 5;
			p3.x = 10;
			p3.y = 10;
			CTriangle Tria(p1, p2, p3, FigureGfxInfo);
			Tria.Load(f, R);
			pManager->AddFigure(R);
		}
		else if (type == 15) {
			Point p1;
			p1.x = 0;
			p1.y = 0;
			CHexagon Hex(p1, FigureGfxInfo);
			Hex.Load(f, R);
			pManager->AddFigure(R);
		}

	}
	f.close();
}
void LoadGraph::undo() {}

void LoadGraph::redo() {}