#include "pch.h"
#include "CHcn.h"

CHcn::CHcn()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	//bcolor = 1;
	bcolor = 0;

}

CHcn::CHcn(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	//bcolor = 1;/xanh
	bcolor = 0;
}

void CHcn::setHcn(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;

}

void CHcn::draw(CPaintDC* dc)
{
	//dc->Rectangle(x1, y1, x2, y2);
	CBrush redBrush(RGB(0, 225, 255));
	CBrush* pOldBrush = new CBrush();


	if (bcolor == 1)
	{
		pOldBrush = dc->SelectObject(&redBrush);
	}
	dc->Rectangle(x1, y1, x2, y2);
	// Khôi ph?c brush c?
	if (bcolor == 1)
	{
		dc->SelectObject(pOldBrush);
	}
}

void CHcn::draw(CClientDC* dc)
{
	CBrush redBrush(RGB(0, 255, 255));
	CBrush* pOldBrush = new CBrush();
	if (bcolor == 1)
	{
		pOldBrush = dc->SelectObject(&redBrush);
	}
	dc->Rectangle(x1, y1, x2, y2);
	// Khôi ph?c brush c?
	if (bcolor == 1)
	{
		dc->SelectObject(pOldBrush);
	}
}

int CHcn::Kttronghinh(CPoint p)
{
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		return 1;
	return 0;
}

void CHcn::up(int d)
{
	y1 -= d;
	y2 -= d;
}
void CHcn::down(int d)
{
	y1 = y1 + d;
	y2 = y2 + d;
}

void CHcn::left(int d)
{
	x1 = x1 - d;
	x2 = x2 - d;
}
void CHcn::right(int d)
{
	x1 = x1 + d;
	x2 = x2 + d;
}
