#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	

private:
	Open_polyline lines;

	bool wait_for_button();


	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	//----COLOR MENU----
	Menu color_menu;
	Button menu_button;

	//----STYLE MENU----
	Menu style_menu;
	Button smenu_button;

	void change(Color c){lines.set_color(c);}
	void style_change(Line_style s) { lines.set_style(s); }

	void hide_menu() {color_menu.hide(); menu_button.show();}
	void show_menu(){color_menu.show(); menu_button.hide();};
	void hide_smenu() {style_menu.hide(); smenu_button.show();}
	void show_smenu(){style_menu.show(); smenu_button.hide();};

	void red_pressed() {change (Color::red); hide_menu();}
	void blue_pressed() {change (Color::blue); hide_menu();}
	void black_pressed() {change (Color::black); hide_menu();}
	void menu_pressed() {menu_button.hide(); show_menu(); }

	void smenu_pressed() {smenu_button.hide(); show_smenu(); }
	void solid_pressed() {style_change(Line_style::solid); hide_smenu();}
	void dash_pressed() {style_change(Line_style::dash); hide_smenu();} 
	void dot_pressed() {style_change(Line_style::dot); hide_smenu();}

	void next();
	void quit();

	static void cb_red(Address,Address);
	static void cb_blue(Address,Address);
	static void cb_black(Address,Address);
	static void cb_menu(Address,Address);
	
	static void cb_smenu(Address,Address);
	static void cb_solid(Address,Address);
	static void cb_dash(Address,Address);
	static void cb_dot(Address,Address);

};