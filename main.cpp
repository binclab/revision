#include "cnc.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "com.tibertium.alliance");

  CNCWindow window;

  //Shows the window and returns when it is closed.
  return app->run(window);
}
