#pragma once
#include <afxwin.h>
class CCouleurStatic :
	public CStatic
{
public:
	COLORREF bgCouleur; // backgroud de la forme
	CBrush bgBrush; // Brush background

	void SetBgCouleur(COLORREF couleur);
	CCouleurStatic();
	virtual ~CCouleurStatic();
	DECLARE_MESSAGE_MAP()
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

