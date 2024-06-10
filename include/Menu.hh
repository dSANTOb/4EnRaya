#ifndef MENU_HH
#define MENU_HH

#include <wx/wx.h>

class Menu : public wxDialog {
public:
    Menu(wxWindow* parent, wxWindowID id, const wxString& title);

    int GetRows() const;
    int GetCols() const;
    wxString GetOpponent() const;

private:
    wxTextCtrl* rowsCtrl;
    wxTextCtrl* colsCtrl;
    wxChoice* opponentChoice;

    void OnExit(wxCommandEvent& event);
    void OnStart(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif // Menu_HH
