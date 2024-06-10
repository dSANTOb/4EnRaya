#include <Menu.hh>

wxBEGIN_EVENT_TABLE(Menu, wxDialog)
    EVT_BUTTON(wxID_EXIT, Menu::OnExit)
    EVT_BUTTON(wxID_OK, Menu::OnStart)
wxEND_EVENT_TABLE()

Menu::Menu(wxWindow* parent, wxWindowID id, const wxString& title)
    : wxDialog(parent, id, title, wxDefaultPosition, wxSize(300, 200)) {

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* gridSizer = new wxBoxSizer(wxHORIZONTAL);
    gridSizer->Add(new wxStaticText(this, wxID_ANY, "Rows: "), 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    rowsCtrl = new wxTextCtrl(this, wxID_ANY);
    gridSizer->Add(rowsCtrl, 1, wxALL, 5);

    gridSizer->Add(new wxStaticText(this, wxID_ANY, "Cols: "), 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    colsCtrl = new wxTextCtrl(this, wxID_ANY);
    gridSizer->Add(colsCtrl, 1, wxALL, 5);

    mainSizer->Add(gridSizer, 0, wxEXPAND | wxALL, 10);

    wxArrayString choices;
    choices.Add("Jugador 2");
    choices.Add("IA Facil");
    choices.Add("IA Dificil");
    opponentChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
    mainSizer->Add(opponentChoice, 0, wxALL | wxEXPAND, 10);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->Add(new wxButton(this, wxID_EXIT, "Salir"), 0, wxALL, 5);
    buttonSizer->Add(new wxButton(this, wxID_OK, "Iniciar"), 0, wxALL, 5);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER);

    SetSizer(mainSizer);
    mainSizer->Fit(this);
}

int Menu::GetRows() const {
    long rows;
    rowsCtrl->GetValue().ToLong(&rows);
    return static_cast<int>(rows);
}

int Menu::GetCols() const {
    long cols;
    colsCtrl->GetValue().ToLong(&cols);
    return static_cast<int>(cols);
}

wxString Menu::GetOpponent() const {
    return opponentChoice->GetStringSelection();
}

void Menu::OnExit(wxCommandEvent& event) {
    Close();
}

void Menu::OnStart(wxCommandEvent& event) {
    EndModal(wxID_OK);
}
