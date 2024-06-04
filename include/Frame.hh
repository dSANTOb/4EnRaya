#ifndef FRAME_HH
#define FRAME_HH

#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <Tablero.hh>

class Frame : public wxFrame {
public:
    Frame(const wxString& title);

private:
    Tablero tablero;
    int cellWidth;
    int cellHeight;

    void OnPaint(wxPaintEvent& event);
    void OnMouseClick(wxMouseEvent& event);
    void OnResize(wxSizeEvent& event);
    void DrawBoard(wxDC& dc);

    wxDECLARE_EVENT_TABLE();
};

#endif
