#pragma once
#include <afx.h>
class CForme :
	public CObject
{
public:
	CPoint hautGauche;
	CPoint basDroite;
	ETypeDeForme typeForme;
	COLORREF bgCouleur;

	CString bitmapPath;
	EMode mode;

	CForme();
	CForme(CPoint, CPoint, ETypeDeForme typeForme, COLORREF bgCouleur, CString bitmapPath, EMode mode);
	void dessiner(CDC *pDC, COLORREF couleur);
	virtual ~CForme();
};

