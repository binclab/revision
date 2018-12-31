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
    void on_title_entry_activate();
    void on_switch_account();

    //Child widgets:
    Gtk::Button m_button;
    Gtk::HeaderBar m_headerbar;
    Gtk::Toolbar m_toolbar;
    Gtk::ComboBoxText m_combotext;
    Gtk::Entry m_title_entry;
    //WebApp *m_WebApp;
    Gtk::Notebook m_notebook;
    //Gtk::Button m_Button_Quit;
};

#endif //GTKMM_EXAMPLEWINDOW_H
