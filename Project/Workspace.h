#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <wx/dcclient.h>
#include <wx/msgdlg.h>
#include <wx/statusbr.h>

#include "WorkspaceBase.h"

class Camera;
class Element;

enum WorkspaceMode
{
	MODE_EDIT = 0,
	MODE_DRAG,
	MODE_INSERT
};

class Workspace : public WorkspaceBase
{
   protected:
    virtual void OnLeftClickUp(wxMouseEvent& event);
    virtual void OnScroll(wxMouseEvent& event);
    virtual void OnMiddleDown(wxMouseEvent& event);
    virtual void OnMiddleUp(wxMouseEvent& event);
    virtual void OnMouseMotion(wxMouseEvent& event);
    virtual void OnKeyDown(wxKeyEvent& event);
    virtual void OnLeftClickDown(wxMouseEvent& event);
    virtual void OnPaint(wxPaintEvent& event);

    void SetViewport();

    wxGLContext* m_glContext;
	wxStatusBar* m_statusBar;
    Camera* m_camera;
    wxString m_name;

    //bool m_insertMode = false;
    //bool m_dragMode = false;
	WorkspaceMode m_mode = MODE_EDIT;

    std::vector<Element*> m_elementList;
	
	void UpdateStatusBar();

   public:
    Workspace();
    Workspace(wxWindow* parent, wxString name = wxEmptyString, wxStatusBar* statusBar = NULL);
    ~Workspace();

    wxString GetName() const { return m_name; }
    void SetName(wxString name) { m_name = name; }
    std::vector<Element*> GetElementList() { return m_elementList; }
    void Redraw() { m_glCanvas->Refresh(); }
};

class Camera
{
   protected:
    wxPoint2DDouble m_translation;
    wxPoint2DDouble m_translationStartPt;
    double m_scale;
	
	wxPoint2DDouble m_mousePosition;

   public:
    Camera();
    ~Camera();

    void SetScale(wxPoint2DDouble screenPoint, double delta);
    void SetTranslation(wxPoint2DDouble screenPoint);
    void StartTranslation(wxPoint2DDouble startPoint) { this->m_translationStartPt = startPoint; }
	void UpdateMousePosition(wxPoint2DDouble mousePosition) {this->m_mousePosition = mousePosition;}
    double GetScale() const { return m_scale; }
    wxPoint2DDouble GetTranslation() const { return m_translation; }
	wxPoint2DDouble GetMousePosition(bool worldCoords = true) const;
    wxPoint2DDouble ScreenToWorld(wxPoint2DDouble screenCoords) const;
};

#endif  // WORKSPACE_H
