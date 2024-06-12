#ifndef Frame_HH
#define Frame_HH

#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <Tablero.hh>
#include <JugadorHumano.hh>
#include <JugadorIaFacil.hh>
#include <JugadorIaDificil.hh>
#include <memory>

class Frame : public wxFrame {
public:
    Frame(const wxString& title, int rows, int cols, const wxString& opponent);
        
private:
    Tablero tablero;
    int cellWidth;
    int cellHeight;
    wxString opponent;

    void OnPaint(wxPaintEvent& event);
    void OnMouseClick(wxMouseEvent& event);
    void OnResize(wxSizeEvent& event);
    void DrawBoard(wxDC& dc);

    std::unique_ptr<IJugador> iaDificil;
    std::unique_ptr<IJugador> iaFacil;
    std::unique_ptr<IJugador> jugadorHumano;

    wxDECLARE_EVENT_TABLE();
};

#endif