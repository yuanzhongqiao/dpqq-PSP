//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: Workspace.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "WorkspaceBase.h"


// Declare the bitmap loading function
extern void wxC52C4InitBitmapResources();

static bool bBitmapLoaded = false;


WorkspaceBase::WorkspaceBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC52C4InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer_lvl_1_1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer_lvl_1_1);
    
    int *m_glCanvasAttr = new int[ 5 ];
    m_glCanvasAttr[0] = WX_GL_SAMPLE_BUFFERS;
    m_glCanvasAttr[1] = 1;
    m_glCanvasAttr[2] = WX_GL_SAMPLES;
    m_glCanvasAttr[3] = 4;
    m_glCanvasAttr[4] = 0;
    m_glCanvas = new wxGLCanvas(this, wxID_ANY, m_glCanvasAttr, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    wxDELETEA( m_glCanvasAttr );
    
    boxSizer_lvl_1_1->Add(m_glCanvas, 1, wxEXPAND, WXC_FROM_DIP(5));
    
    SetName(wxT("WorkspaceBase"));
    SetSize(500,300);
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    // Connect events
    m_glCanvas->Connect(wxEVT_PAINT, wxPaintEventHandler(WorkspaceBase::OnPaint), NULL, this);
    m_glCanvas->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(WorkspaceBase::OnLeftClickDown), NULL, this);
    m_glCanvas->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(WorkspaceBase::OnKeyDown), NULL, this);
    m_glCanvas->Connect(wxEVT_MOTION, wxMouseEventHandler(WorkspaceBase::OnMouseMotion), NULL, this);
    m_glCanvas->Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(WorkspaceBase::OnMiddleDown), NULL, this);
    m_glCanvas->Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(WorkspaceBase::OnMiddleUp), NULL, this);
    m_glCanvas->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(WorkspaceBase::OnLeftClickUp), NULL, this);
    m_glCanvas->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(WorkspaceBase::OnScroll), NULL, this);
    
}

WorkspaceBase::~WorkspaceBase()
{
    m_glCanvas->Disconnect(wxEVT_PAINT, wxPaintEventHandler(WorkspaceBase::OnPaint), NULL, this);
    m_glCanvas->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(WorkspaceBase::OnLeftClickDown), NULL, this);
    m_glCanvas->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(WorkspaceBase::OnKeyDown), NULL, this);
    m_glCanvas->Disconnect(wxEVT_MOTION, wxMouseEventHandler(WorkspaceBase::OnMouseMotion), NULL, this);
    m_glCanvas->Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(WorkspaceBase::OnMiddleDown), NULL, this);
    m_glCanvas->Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(WorkspaceBase::OnMiddleUp), NULL, this);
    m_glCanvas->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(WorkspaceBase::OnLeftClickUp), NULL, this);
    m_glCanvas->Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(WorkspaceBase::OnScroll), NULL, this);
    
}
