#include "webapp.hpp"
#include <iostream>
#include <cstring>

WebApp::WebApp() :
  Gtk::Widget (webkit_web_view_new())
{
  SoupSession *webkit_get_default_session (void);
  WebKitSettings *settings = webkit_settings_new ();
  g_object_set (G_OBJECT(settings), "enable-scripts", FALSE, NULL);
}

WebApp::~WebApp()
{
}

/*operator WebKitWebView * () //  Allow this to stand in for a Web View
{
    return WEBKIT_WEB_VIEW(gobj());
}*/

void WebApp::load_uri (const gchar *strUri)
{
    webkit_web_view_load_uri(*this, strUri);
}
