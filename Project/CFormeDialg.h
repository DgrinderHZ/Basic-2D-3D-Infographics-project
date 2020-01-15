#pragma once
#include"CCouleurStatic.h"

// CFormeDialg dialog

class CFormeDialg : public CDialog
{
	DECLARE_DYNAMIC(CFormeDialg)

public:
	CFormeDialg(CWnd* pParent = nullptr);   // standard constructor
	COLORREF bgCouleur;
	CString bitmapPath;
	// ajouter apartir de la Class Wizard
	afx_msg void OnDblclkFillStatic();
	virtual BOOL OnInitDialog();

	afx_msg void OnClickedOuvrirButton();
	afx_msg void OnClickedModecolorRadio();
	afx_msg void OnClickedModeimageRadio();
	CCouleurStatic stFillClr;
	int typeForme; // m_typeForme
	int mode; // m_mode
	CEdit editerChemin;
	CButton ouvrirBtn;
	afx_msg void OnClickedFillStatic();
	virtual ~CFormeDialg();


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	
};
