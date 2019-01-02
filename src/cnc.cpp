#include "cnc.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>

CNCWindow::CNCWindow()
/*: m_VBox(Gtk::ORIENTATION_VERTICAL)*//*,
  m_Button_Quit("Quit")*/
{
    maximize();
    //set_title("Custom Widget example");
    set_position(Gtk::WIN_POS_CENTER_ALWAYS);
    set_border_width(6);
    set_has_resize_grip(true);
    set_size_request(1024, 576);
    resize_to_geometry(1024, 576);

    //on_title_entry_activate();
    //on_subtitle_entry_activate();
    // Header Bar
    {
        m_headerbar.set_show_close_button();
        m_headerbar.pack_start(m_toolbar);
        m_combotext.set_size_request(200, -1);
        for (int i = 1; i <= 10; i++)
            m_combotext.append("Account " + std::to_string(i));
        m_combotext.set_active(0);
        m_headerbar.pack_end(m_combotext);
        m_combotext.signal_changed().connect( sigc::mem_fun(*this, &CNCWindow::on_switch_account));

        set_titlebar(m_headerbar);
    }

    WebApp *account1 = new WebApp;
    WebApp *account2 = new WebApp;
    WebApp *account3 = new WebApp;
    WebApp *account4 = new WebApp;
    WebApp *account5 = new WebApp;
    WebApp *account6 = new WebApp;
    WebApp *account7 = new WebApp;
    WebApp *account8 = new WebApp;
    WebApp *account9 = new WebApp;
    WebApp *account10 = new WebApp;
    m_notebook.append_page(*account1);
    m_notebook.append_page(*account2);
    m_notebook.append_page(*account3);
    m_notebook.append_page(*account4);
    m_notebook.append_page(*account5);
    m_notebook.append_page(*account6);
    m_notebook.append_page(*account7);
    m_notebook.append_page(*account8);
    m_notebook.append_page(*account9);
    m_notebook.append_page(*account10);

    m_notebook.set_show_tabs(0);
    add(m_notebook);
    account1->load_uri("file:///home/bret/Documents/Help/Toolbar.htm");
    //account1->load_uri("https://tiberiumalliances.com/home");
    show_all_children();
}

CNCWindow::~CNCWindow()
{
}

void CNCWindow::on_button_quit()
{
    hide();
}

void CNCWindow::on_switch_account()
{
    //int n = m_combotext.get_active_row_number();
    m_notebook.set_current_page(m_combotext.get_active_row_number());
    /*switch (n)
    {
    case 0:
    {
        m_notebook.set_current_page(*account1);
        break;
    }
    case 1:
    {
        m_notebook.append_page(*account2);
        break;
    }
    case 2:
    {
        m_notebook.append_page(*account3);
        break;
    }
    case 3:
    {
        m_notebook.append_page(*account4);
        break;
    }
    case 4:
    {
        m_notebook.append_page(*account5);
        break;
    }
    case 5:
    {
        m_notebook.append_page(*account6);
        break;
    }
    case 6:
    {
        m_notebook.append_page(*account7);
        break;
    }
    case 7:
    {
        m_notebook.append_page(*account8);
        break;
    }
    case 8:
    {
        m_notebook.append_page(*account9);
        break;
    }
    case 9:
    {
        m_notebook.append_page(*account10);
        break;
    }
    }*/

    /*std::string name = "Account" + std::to_string(m_notebook.get_n_pages() + 1);
    std::cout << name << std::endl;
    std::map<std::string,WebApp*> m_accounts;
    m_combotext.append(name);
    m_accounts[name] = new WebApp;
    m_notebook.append_page(m_accounts[name]);*/

}

void CNCWindow::on_title_entry_activate()
{
    const Glib::ustring title = m_title_entry.get_text();
    if(!title.empty())
    {
        m_headerbar.set_title(title);
    }
}
