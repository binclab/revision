#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include "webapp.hpp"

class CNCWindow : public Gtk::Window
{
public:
  CNCWindow();
  virtual ~CNCWindow();

protected:
  //Signal handlers:
  void on_button_quit();

  //Child widgets:
  Gtk::Box m_VBox;
  //WebApp *m_WebApp;
  Gtk::Notebook games_Notebook;
  //Gtk::Button m_Button_Quit;
};

#endif //GTKMM_EXAMPLEWINDOW_H
