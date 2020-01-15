
// ProjetDoc.h : interface of the CProjetDoc class
//
#pragma once
#include "CForme.h"

class CProjetDoc : public CDocument
{
protected: // create from serialization only
	CProjetDoc() noexcept;
	DECLARE_DYNCREATE(CProjetDoc)

// Attributes
public:
	// mon code
	CArray<CForme*, CForme*> arrForme;
	ETypeDeForme typeForme;
	COLORREF bgCouleur;
	CString bitmapPath;
	EMode mode;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CProjetDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFormesgeometrique2d();
};
