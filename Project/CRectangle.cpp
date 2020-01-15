#include "stdafx.h"
#include "CRectangle.h"


CRectangle::CRectangle()
{
}


CRectangle::CRectangle(CPoint hautGauche, CPoint basDroite, COLORREF couleur)
{
	this->hautGauche = hautGauche;
	this->basDroite = basDroite;
	this->couleur = couleur;
}

void CRectangle::dessiner(CDC *pDC, COLORREF couleur) {
	CPen crayon(PS_SOLID, 1, couleur);
	CPen *pCrayon = pDC->SelectObject(&crayon);

	int dx = hautGauche.x - basDroite.x;
	int dy = hautGauche.y - basDroite.y;

	int fx = 2 * (dx < 0) - 1;
	int fy = 2 * (dy < 0) - 1;

	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;

	int max = dx > dy ? dx : dy;
	CRect rect(hautGauche, CPoint(hautGauche.x + max * fx, hautGauche.y + max * fy));
	pDC->Rectangle(&rect);


	pDC->SelectObject(pCrayon);
	pCrayon->DeleteObject();


}

CRectangle::~CRectangle()
{
}
