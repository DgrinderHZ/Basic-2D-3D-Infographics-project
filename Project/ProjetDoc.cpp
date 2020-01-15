
// ProjetDoc.cpp : implementation of the CProjetDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Projet.h"
#endif

#include "ProjetDoc.h"

#include <propkey.h>
#include "CFormeDialg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CProjetDoc

IMPLEMENT_DYNCREATE(CProjetDoc, CDocument)

BEGIN_MESSAGE_MAP(CProjetDoc, CDocument)
	ON_COMMAND(ID_FORMESGEOMETRIQUE_2D, &CProjetDoc::OnFormesgeometrique2d)
END_MESSAGE_MAP()


// CProjetDoc construction/destruction

CProjetDoc::CProjetDoc() noexcept
{
	// TODO: add one-time construction code here

}

CProjetDoc::~CProjetDoc()
{
}

BOOL CProjetDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// mon code
	typeForme = CARRE;
	bgCouleur = RGB(255, 255, 255);
	bitmapPath = "";
	mode = COLOR;
	arrForme.RemoveAll();
	return TRUE;
}




// CProjetDoc serialization

void CProjetDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CProjetDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CProjetDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CProjetDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CProjetDoc diagnostics

#ifdef _DEBUG
void CProjetDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProjetDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CProjetDoc commands
void CProjetDoc::OnFormesgeometrique2d()
{
	CFormeDialg dlg;
	dlg.typeForme = typeForme;
	dlg.bgCouleur = bgCouleur;
	dlg.bitmapPath = bitmapPath;
	dlg.mode = mode;
	if (dlg.DoModal() == IDOK) {
		typeForme = (ETypeDeForme) dlg.typeForme;
		bgCouleur = dlg.bgCouleur;
		bitmapPath = dlg.bitmapPath;
		mode = (EMode)dlg.mode;
	}
		
}
