#ifndef _zduiListCtrl_h
#define _zduiListCtrl_h
#pragma pack (push, 8)

#pragma once

#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiListCtrl : public CListCtrl {
    DECLARE_DYNAMIC(CZdUiListCtrl);

public:
                CZdUiListCtrl ();
virtual         ~CZdUiListCtrl ();

protected:
        CPoint  m_lastMousePoint;
        int     m_tipIndex;
        int     m_tipItem;
        CRect   m_tipRect;

public:
        CZdUiHeaderCtrl m_headerCtrl;

        int     ColumnCount ();
virtual void    GetContentExtent (
                    int item, int index, LPCTSTR text, int& width, int& height
                );
        BOOL    GetItemAtPoint (CPoint& p, int& item, int& index);
        BOOL    GetSubItemRect (int item, int index, CRect& rect);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    IsOwnerDraw ();

protected:
        CWnd    *m_aduiParent;

virtual ZDUI_REPLY DoZdUiMessage (
                    ZDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual void    OnDrawTip (CDC& dc);
virtual BOOL    OnDrawTipText (CZdUiDrawTipText& dtt);
virtual ZDUI_REPLY OnGetTipSupport (CPoint& p);
virtual BOOL    OnGetTipRect (CRect& r);
virtual BOOL    OnGetTipText (CString& text);
virtual BOOL    OnHitTipRect (CPoint& p);
public:
        CWnd    *GetZdUiParent ();
        void    SetZdUiParent (CWnd *w);

public:
    //{{AFX_VIRTUAL(CZdUiListCtrl)
    protected:
    virtual void PreSubclassWindow();
    //}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CZdUiListCtrl)
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
