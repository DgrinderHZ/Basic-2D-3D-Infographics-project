
// ProjetView.cpp : implementation of the CProjetView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Projet.h"
#endif

#include "ProjetDoc.h"
#include "ProjetView.h"

#include "CForme.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProjetView

IMPLEMENT_DYNCREATE(CProjetView, CView)

BEGIN_MESSAGE_MAP(CProjetView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CProjetView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
ON_WM_RBUTTONDOWN()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CProjetView construction/destruction

CProjetView::CProjetView() noexcept
{
	// TODO:
}

CProjetView::~CProjetView()
{
}

BOOL CProjetView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CProjetView drawing
void CProjetView::OnDraw(CDC* pDC)
{
	CProjetDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rectangle;
	GetClientRect(&rectangle);
	pdc.FillSolidRect(rectangle, RGB(255, 255, 255));
	int cpt;

	cpt = pDoc->arrForme.GetSize();
	for (int i = 0; i < cpt; i++)
		pDoc->arrForme[i]->dessiner(&pdc, RGB(55, 55, 55));

	pDC->BitBlt(0, 0, rectangle.Width(), rectangle.Height(), &pdc, 0, 0, SRCCOPY);
}


// CProjetView printing


void CProjetView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CProjetView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProjetView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProjetView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CProjetView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProjetView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProjetView diagnostics

#ifdef _DEBUG
void CProjetView::AssertValid() const
{
	CView::AssertValid();
}

void CProjetView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjetDoc* CProjetView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjetDoc)));
	return (CProjetDoc*)m_pDocument;
}
#endif //_DEBUG


// CProjetView message handlers
int CProjetView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CClientDC dc(this);
	int x = ::GetSystemMetrics(SM_CXSCREEN);
	int y = ::GetSystemMetrics(SM_CXSCREEN);
	pdc.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&dc, x, y);
	pdc.SelectObject(&bitmap);
	return 0;
}

void CProjetView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CProjetDoc *monDoc = GetDocument();

		CForme *forme = new CForme(point, point, monDoc->typeForme, monDoc->bgCouleur, monDoc->bitmapPath, monDoc->mode);
		monDoc->arrForme.Add(forme);

	CView::OnLButtonDown(nFlags, point);
}

void CProjetView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (nFlags == MK_LBUTTON) {
		
			CProjetDoc *monDoc = GetDocument();
			int cpt;

			
				cpt = monDoc->arrForme.GetSize();
				monDoc->arrForme[cpt - 1]->basDroite = point;
			
			
			monDoc->SetModifiedFlag(TRUE);
			Invalidate();

			CView::OnMouseMove(nFlags, point);
		
	}
}


BOOL CProjetView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return CView::OnEraseBkgnd(pDC);
}

