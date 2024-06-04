#include <Frame.hh>

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_PAINT(Frame::OnPaint)
    EVT_LEFT_DOWN(Frame::OnMouseClick)
    EVT_SIZE(Frame::OnResize)
wxEND_EVENT_TABLE()

Frame::Frame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(700, 600)),
      cellWidth(100), cellHeight(100), tablero(6, 7) {
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void Frame::OnPaint(wxPaintEvent& event) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();
    DrawBoard(dc);
}

void Frame::OnMouseClick(wxMouseEvent& event) {
    int x = event.GetX();
    int column = x / cellWidth;
    if (tablero.colocarFicha(column, 1)) {
        Refresh();
    }
}

void Frame::OnResize(wxSizeEvent& event) {
    wxSize size = event.GetSize();
    int nuevasColumnas = std::max(1, size.GetWidth() / cellWidth);
    int nuevasFilas = std::max(1, size.GetHeight() / cellHeight);

    tablero.redimensionar(nuevasFilas, nuevasColumnas);

    cellWidth = size.GetWidth() / tablero.getGrid()[0].size();
    cellHeight = size.GetHeight() / tablero.getGrid().size();

    Refresh();
    event.Skip(); // Allows the event to propagate to the base class
}

void Frame::DrawBoard(wxDC& dc) {
    for (int i = 0; i < tablero.getGrid().size(); ++i) {
        for (int j = 0; j < tablero.getGrid()[0].size(); ++j) {
            int x = j * cellWidth;
            int y = i * cellHeight;
            int cellValue = tablero.getGrid()[i][j];

            if (cellValue == 0) {
                dc.SetBrush(*wxWHITE_BRUSH);
            } else if (cellValue == 1) {
                dc.SetBrush(*wxBLUE_BRUSH);
            } else {
                dc.SetBrush(*wxRED_BRUSH);
            }

            dc.DrawRectangle(x, y, cellWidth, cellHeight);
            dc.DrawEllipse(x + 5, y + 5, cellWidth - 10, cellHeight - 10);
        }
    }
}
