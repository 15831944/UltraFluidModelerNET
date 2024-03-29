// Copyright (C) SAS NET Azure Rangers
// All rights reserved.

#pragma once
#include "Modeler1Doc.h"

class AFX_EXT_CLASS CTabbedView : public CTabView
{
protected: // create from serialization only
	CTabbedView();
	DECLARE_DYNCREATE(CTabbedView)

// Attributes
public:
	CModeler1Doc* GetDocument();

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnActivateView(CView* view);

	BOOL IsScrollBar () const
	{
		return TRUE;
	}

// Implementation
public:
	virtual ~CTabbedView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnFilePrintPreview();

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TabbedView.cpp
inline CModeler1Doc* CTabbedView::GetDocument()
   { return (CModeler1Doc*)m_pDocument; }
#endif
