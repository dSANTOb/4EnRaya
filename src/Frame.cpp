#include <Frame.hh>
#include <JugadorHumano.hh>
#include <JugadorIaFacil.hh>
#include <JugadorIaDificil.hh>

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_PAINT(Frame::OnPaint)
    EVT_LEFT_DOWN(Frame::OnMouseClick)
    EVT_SIZE(Frame::OnResize)
wxEND_EVENT_TABLE()

Frame::Frame(const wxString& title, int rows, int cols, const wxString& opponent)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(700, 600)),
      cellWidth(100), cellHeight(100), tablero(rows, cols), opponent(opponent) {
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    if (opponent == "IA Dificil") {
        iaDificil = std::make_unique<JugadorIaDificil>("IA Dificil");
    } else if (opponent == "IA Facil") {
        iaFacil = std::make_unique<JugadorIaFacil>("IA Facil");
    } else {
        jugadorHumano = std::make_unique<JugadorHumano>("Humano 2");
    }
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
        int ganador = 0;
        for (int fila = 0; fila < tablero.getGrid().size(); ++fila) {
            ganador = tablero.verificarGanador(fila, column);
            if (ganador != 0) break;
        }
        Refresh();
        if (ganador != 0) {
            wxString msg = wxString::Format("Jugador %d ha ganado!", ganador);
            wxMessageBox(msg, "Fin del Juego", wxOK | wxICON_INFORMATION, this);
            return;
        }

        if (iaDificil) {
            int columnaIA = iaDificil->realizarMovimiento(tablero);
            if (tablero.colocarFicha(columnaIA, 2)) {
                for (int fila = 0; fila < tablero.getGrid().size(); ++fila) {
                    ganador = tablero.verificarGanador(fila, columnaIA);
                    if (ganador != 0) break;
                }
                Refresh();
                if (ganador != 0) {
                    wxString msg = wxString::Format("Jugador %d ha ganado!", ganador);
                    wxMessageBox(msg, "Fin del Juego", wxOK | wxICON_INFORMATION, this);
                }
            }
        } else if (iaFacil) {
            int columnaIA = iaFacil->realizarMovimiento(tablero);
            if (tablero.colocarFicha(columnaIA, 2)) {
                for (int fila = 0; fila < tablero.getGrid().size(); ++fila) {
                    ganador = tablero.verificarGanador(fila, columnaIA);
                    if (ganador != 0) break;
                }
                Refresh();
                if (ganador != 0) {
                    wxString msg = wxString::Format("Jugador %d ha ganado!", ganador);
                    wxMessageBox(msg, "Fin del Juego", wxOK | wxICON_INFORMATION, this);
                }
            }
        } else if (jugadorHumano) {
            // Esperar a que el segundo jugador humano haga clic
        }
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
