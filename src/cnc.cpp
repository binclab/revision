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
    /*

        std::array<std::string, 5> games = {"WebApp_1","WebApp_2","WebApp_3","WebApp_4","WebApp_5"};
        for(const auto& game : games)
        {
            games_Notebook.append_page(*game, "Game 1");
            game->load_uri("https://tiberiumalliances.com/home");
        }
    */
    on_title_entry_activate();
    //on_subtitle_entry_activate();
    // Header Bar
    {
        m_headerbar.set_show_close_button();
        m_headerbar.pack_start(m_toolbar);
        m_combotext.set_size_request(200, -1);
        m_combotext.append("Add");
        //m_combotext.set_active_text("Add");
        m_headerbar.pack_end(m_combotext);
        m_combotext.signal_changed().connect( sigc::mem_fun(*this, &CNCWindow::on_switch_account));

        set_titlebar(m_headerbar);
    }

    WebApp *game_1 = new WebApp;
    /*WebApp *game_2 = new WebApp;
    WebApp *game_3 = new WebApp;
    WebApp *game_4 = new WebApp;
    WebApp *game_5 = new WebApp;*/

    m_notebook.set_show_tabs(0);
    add(m_notebook);
    m_notebook.append_page(*game_1, "Game 1");
    game_1->load_uri("https://tiberiumalliances.com/home");
    /*m_notebook.append_page(*game_2, "Game 2");
    //game_2->load_uri("https://tiberiumalliances.com/home");
    m_notebook.append_page(*game_3, "Game 3");
    //game_3->load_uri("https://tiberiumalliances.com/home");
    m_notebook.append_page(*game_4, "Game 4");
    //game_4->load_uri("https://tiberiumalliances.com/home");
    m_notebook.append_page(*game_5, "Game 5");
    //game_5->load_uri("https://tiberiumalliances.com/home");
    m_notebook.get_current_page();*/
    std::cout << "Loading URL" << std::endl;
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
    Glib::ustring sz = m_combotext.get_active_text();

    if(sz == "Add")
    {
        std::string name = "Account" + std::to_string(m_notebook.get_n_pages() + 1);
        std::cout << name << std::endl;
        std::map<std::string, WebApp*> m_accounts;
        m_combotext.append(m_accounts[name]);
        m_accounts[name] = new WebApp;
        m_notebook.append_page(m_accounts[name]);
    }
    //if(!(sz.empty()))
    //    std::cout << sz  << std::endl;
    // Save session
    // Swithc to new tab
}

void CNCWindow::on_title_entry_activate()
{
    const Glib::ustring title = m_title_entry.get_text();
    if(!title.empty())
    {
        m_headerbar.set_title(title);
    }
}
