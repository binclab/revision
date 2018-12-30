#include "cnc.hpp"
#include <iostream>
#include <vector>
#include <array>

CNCWindow::CNCWindow()
: m_VBox(Gtk::ORIENTATION_VERTICAL)/*,
  m_Button_Quit("Quit")*/
{
  set_title("Custom Widget example");
  set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  set_border_width(6);
  set_has_resize_grip(true);
  set_size_request(1024, 576);
  maximize();
  resize_to_geometry(1024, 576);

  WebApp *game_1 = new WebApp;
  WebApp *game_2 = new WebApp;
  WebApp *game_3 = new WebApp;
  WebApp *game_4 = new WebApp;
  WebApp *game_5 = new WebApp;

  games_Notebook.set_show_tabs(1);
  add(games_Notebook);

  games_Notebook.append_page(*game_1, "Game 1");
  game_1->load_uri("https://tiberiumalliances.com/home");
  games_Notebook.append_page(*game_2, "Game 2");
  game_2->load_uri("https://tiberiumalliances.com/home");
  games_Notebook.append_page(*game_3, "Game 3");
  game_3->load_uri("https://tiberiumalliances.com/home");
  games_Notebook.append_page(*game_4, "Game 4");
  game_4->load_uri("https://tiberiumalliances.com/home");
  games_Notebook.append_page(*game_5, "Game 5");
  game_5->load_uri("https://tiberiumalliances.com/home");
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
