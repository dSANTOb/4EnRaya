#include <App.hh>
#include <Frame.hh>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    Frame* frame = new Frame("4 en Línea");
    frame->Show(true);
    return true;
}
