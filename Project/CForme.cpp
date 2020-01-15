#include "stdafx.h"
#include "CForme.h"

CForme::CForme()
{
}

CForme::CForme(CPoint hautGauche, CPoint basDroite, ETypeDeForme typeForme, COLORREF bgCouleur, CString bitmapPath, EMode mode)
{
	this->hautGauche = hautGauche;
	this->basDroite = basDroite;
	this->typeForme = typeForme;
	this->bgCouleur = bgCouleur;
	this->mode = mode;
	this->bitmapPath = bitmapPath;
}

void CForme::dessiner(CDC *pDC, COLORREF couleur) { 
	CPen crayon(PS_SOLID, 1, couleur);
	CPen *pCrayon = pDC->SelectObject(&crayon);
	CBrush brush;

	if (mode == COLOR)
	{
	 brush.CreateSolidBrush(bgCouleur);		
	}
	else
	{
		HBITMAP hbmp = (HBITMAP)::LoadImage(NULL, bitmapPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		CBitmap bmp;
		bmp.Attach(hbmp);
		brush.CreatePatternBrush(&bmp);
				
	}
	
	CBrush* pBrush = pDC->SelectObject(&brush);
	if(typeForme == LOSANGE)
		{
			CRect rectangle(hautGauche, basDroite);

			CPoint tab[] = {
				CPoint(rectangle.left, rectangle.CenterPoint().y),
				CPoint(rectangle.CenterPoint().x, rectangle.top),
				CPoint(rectangle.right, rectangle.CenterPoint().y),
				CPoint(rectangle.CenterPoint().x, rectangle.bottom)
			};

			pDC->Polygon(tab, 4);
		}
	else
		{
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
	    }
	
	pDC->SelectObject(pCrayon);
	pCrayon->DeleteObject();
	pDC->SelectObject(pBrush);
	pBrush->DeleteObject();
}

CForme::~CForme()
{
}
