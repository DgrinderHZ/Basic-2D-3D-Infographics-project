// CFormeDialg.cpp : implementation file
//

#include "stdafx.h"
#include "Projet.h"
#include "CFormeDialg.h"
#include "afxdialogex.h"


// CFormeDialg dialog

IMPLEMENT_DYNAMIC(CFormeDialg, CDialog)

CFormeDialg::CFormeDialg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	
	, typeForme(0)
	, mode(0)
{
	
}

CFormeDialg::~CFormeDialg()
{
}

void CFormeDialg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Radio(pDX, IDC_LOSANGE_RADIO, typeForme);
	DDX_Control(pDX, IDC_FILL_STATIC, stFillClr);
	//  DDX_Radio(pDX, IDC_ModeColor_RADIO, mode);
	//  DDX_Control(pDX, IDC_CHEMIN_EDIT, editerChemin);
	//  DDX_Control(pDX, IDC_OUVRIR_BUTTON, ouvrirBtn);
	DDX_Radio(pDX, IDC_LOSANGE_RADIO, typeForme);
	DDX_Radio(pDX, IDC_ModeColor_RADIO, mode);
	DDX_Control(pDX, IDC_CHEMIN_EDIT, editerChemin);
	DDX_Control(pDX, IDC_OUVRIR_BUTTON, ouvrirBtn);
}


BEGIN_MESSAGE_MAP(CFormeDialg, CDialog)
	ON_STN_DBLCLK(IDC_FILL_STATIC, &CFormeDialg::OnDblclkFillStatic)
	ON_BN_CLICKED(IDC_OUVRIR_BUTTON, &CFormeDialg::OnClickedOuvrirButton)
	ON_BN_CLICKED(IDC_ModeColor_RADIO, &CFormeDialg::OnClickedModecolorRadio)
	ON_BN_CLICKED(IDC_ModeImage_RADIO, &CFormeDialg::OnClickedModeimageRadio)
	ON_STN_CLICKED(IDC_FILL_STATIC, &CFormeDialg::OnClickedFillStatic)
END_MESSAGE_MAP()


// CFormeDialg message handlers
void CFormeDialg::OnDblclkFillStatic()
{
	// TODO: Add your control notification handler code here
	CColorDialog cdlg(bgCouleur);
	if (cdlg.DoModal() == IDOK) {
		bgCouleur = cdlg.GetColor();
		stFillClr.SetBgCouleur(bgCouleur);
	}
}

BOOL CFormeDialg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	stFillClr.SetBgCouleur(bgCouleur);
	switch (mode) {
	case COLOR:
		ouvrirBtn.EnableWindow(FALSE);
		stFillClr.EnableWindow(TRUE);
		break;
	case BMP:
		ouvrirBtn.EnableWindow(TRUE);
		stFillClr.EnableWindow(FALSE);
		break;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CFormeDialg::OnClickedOuvrirButton()
{
	// TODO: Add your control notification handler code here
	TCHAR filters[] = _T("Bitmap(*.bmp)");
	CFileDialog dlg(TRUE, _T("bmp"), _T("*.bmp"), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, filters);
	if (dlg.DoModal() == IDOK) {
		bitmapPath = dlg.GetPathName();
		editerChemin.SetWindowTextW(bitmapPath);
	}
}

void CFormeDialg::OnClickedModecolorRadio()
{
	// TODO: Add your control notification handler code here
	
	ouvrirBtn.EnableWindow(FALSE);
	stFillClr.EnableWindow(TRUE);
}

void CFormeDialg::OnClickedModeimageRadio()
{
	ouvrirBtn.EnableWindow(TRUE);
	stFillClr.EnableWindow(FALSE);
	// TODO: Add your control notification handler code here
}

void CFormeDialg::OnClickedFillStatic()
{
	CColorDialog cdlg(bgCouleur);
	if (cdlg.DoModal() == IDOK) {
		bgCouleur = cdlg.GetColor();
		stFillClr.SetBgCouleur(bgCouleur);
	}

}


