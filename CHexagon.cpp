#include <fstream>
#include "CHexagon.h"
#include "Figures/CRectangle.h"
#include "CTriangle.h"
#include "GUI/Output.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}

void CHexagon::Save(ofstream& f, int y) {
	int x = HEX1;
	int z;
	int fill;

	if (FigGfxInfo.DrawClr == RED)
		z = RED1;
	else if (FigGfxInfo.DrawClr == ORANGE)
		z = ORANGE1;
	else if (FigGfxInfo.DrawClr == YELLOW)
		z = YELLOW1;
	else if (FigGfxInfo.DrawClr == GREEN)
		z = GREEN1;
	else if (FigGfxInfo.DrawClr == BLUE)
		z = BLUE1;
	else if (FigGfxInfo.DrawClr == BLACK)
		z = BLACK1;
	else if (FigGfxInfo.DrawClr == MAGENTA)
		z = MAGENTA;
	if (FigGfxInfo.isFilled) {
		if (FigGfxInfo.FillClr == RED)
			fill = RED1;
		else if (FigGfxInfo.FillClr == ORANGE)
			fill = ORANGE1;
		else if (FigGfxInfo.FillClr == YELLOW)
			fill = YELLOW1;
		else if (FigGfxInfo.FillClr == GREEN)
			fill = GREEN1;
		else if (FigGfxInfo.FillClr == BLUE)
			fill = BLUE1;
		else if (FigGfxInfo.FillClr == BLACK)
			fill = BLACK1;
	}
	else
		fill = Nofill;
	//writes the info in the file
	f << x << "   " << y << "    " << Center.x << "    " << Center.y << "    " << z << "    " << fill << '\n';
}
void CHexagon::Load(ifstream& f, CFigure*& R) {
	int z2;
	int fill2;
	//to get the colors to be saved
	f >> Center.x >> Center.y >> z2 >> fill2;
	setcolours(z2, fill2, FigGfxInfo);
	CHexagon* p = new CHexagon(Center, FigGfxInfo);
	R = p;
}
void CHexagon::move(int x, int y, CFigure*& l, CFigure*& m) {
	l = new CHexagon(Center, FigGfxInfo);
	//sets the new center
	Center.x = x;
	Center.y = y;
	m = new CHexagon(Center, FigGfxInfo);
}
void CHexagon::dlt(CFigure*& l) {
	l = new CHexagon(Center, FigGfxInfo);
}

void CHexagon::clr(CFigure*& l, CFigure*& m) {
	l = new CHexagon(Center, FigGfxInfo);
}