#include <fstream>
#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Circle = P2;
}


void CCircle::Draw(Output* pOut) const
{
	pOut->Drawcircle(Center, Circle, FigGfxInfo, Selected);
}

bool CCircle::pointcheck(Point c)
{
	int r = sqrt(pow((Center.x - Circle.x), 2) + pow((Center.y - Circle.y), 2));
	int d = sqrt(pow((Center.x - c.x), 2) + pow((Center.y - c.y), 2));
	if (d <= r)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CCircle::Save(ofstream& f, int y) {
	int x = CIRC1;
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
	f << x << "   " << y << "   " << Center.x << "   " << Center.y << "   " << Circle.x << "   " << Circle.y << "   " << z << "   " << fill << '\n';
}
void CCircle::Load(ifstream& f, CFigure*& R) {
	int z2;
	int fill2;
	//to get the colors to be saved
	f >> Center.x >> Center.y >> Circle.x >> Circle.y >> z2 >> fill2;
	setcolours(z2, fill2, FigGfxInfo);
	CCircle* p = new CCircle(Center, Circle, FigGfxInfo);
	R = p;
}
void CCircle::move(int x, int y, CFigure*& l, CFigure*& m) {
	l = new CCircle(Center, Circle, FigGfxInfo);
	int x2 = Circle.x - Center.x;
	int y2 = Circle.y - Center.y;
	//sets the new center and adjusts the circumfrence
	Center.x = x;
	Center.y = y;
	Circle.x = x + x2;
	Circle.y = y + y2;
	m = new CCircle(Center, Circle, FigGfxInfo);
}
void CCircle::dlt(CFigure*& l) {
	l = new CCircle(Center, Circle, FigGfxInfo);
}
void CCircle::clr(CFigure*& l, CFigure*& m) {
	l = new CCircle(Center, Circle, FigGfxInfo);
}