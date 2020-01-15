#include "stdafx.h"
#include "CCouleurStatic.h"
CCouleurStatic::CCouleurStatic()
{
}
void CCouleurStatic::SetBgCouleur(COLORREF couleur) {
	bgCouleur = couleur;
	bgBrush.DeleteObject();
	bgBrush.CreateSolidBrush(couleur);
	Invalidate();

}
CCouleurStatic::~CCouleurStatic()
{
}
BEGIN_MESSAGE_MAP(CCouleurStatic, CStatic)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

HBRUSH CCouleurStatic::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);
	pDC->SetBkColor(bgCouleur);
	return (HBRUSH)bgBrush;
}
