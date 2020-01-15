#pragma once
#include <afx.h>
class CRectangle :
	public CObject
{
public:
	CPoint hautGauche;
	CPoint basDroite;
	COLORREF couleur;

	CRectangle();
	CRectangle(CPoint, CPoint, COLORREF);
	void dessiner(CDC *pDC, COLORREF couleur);
	virtual ~CRectangle();
};

