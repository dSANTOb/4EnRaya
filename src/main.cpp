#include <App.hh>
#include <Frame.hh>
#include <Menu.hh>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    Menu menu(NULL, wxID_ANY, "Conecta 4 - Menu");
    if (menu.ShowModal() == wxID_OK) {
        int rows = menu.GetRows();
        int cols = menu.GetCols();
        wxString opponent = menu.GetOpponent();

        Frame* frame = new Frame("Conecta 4", rows, cols, opponent);
        frame->Show(true);
    }
    return false; // End the app if the dialog is cancelled
}
