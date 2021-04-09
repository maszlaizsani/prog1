#include "lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-170,0}, 80, 30, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-80,0}, 80, 30, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    
    next_x{Point{x_max()-400,0}, 70, 30, "Next x:"},
    next_y{Point{x_max()-270,0}, 70, 30, "Next y:"},
    xy_out{Point{100,0}, 100, 40, "Current (x,y):"},
    
    color_menu{Point{x_max()-80,50},80,30,Menu::vertical,"Color"},
    menu_button{Point{x_max()-80,50},80,30,"Color menu",cb_menu},
    
    style_menu{Point{x_max()-170,50},80,30,Menu::vertical,"Style"},
    smenu_button{Point{x_max()-170,50},80,30,"Style menu",cb_smenu}
{

    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);


    //------ Color menu ------
    color_menu.attach(new Button{Point{0,0},0,0,"Red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"Blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"Black",cb_black});
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);


    //------ Style menu ------
    style_menu.attach(new Button{Point{0,0},0,0,"Solid",cb_solid});
    style_menu.attach(new Button{Point{0,0},0,0,"Dash",cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,"Dot",cb_dot});
    attach(style_menu);
    style_menu.hide();
    attach(smenu_button);


    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

//----COLOR MENU--------------------------------------------------
void Lines_window::cb_red(Address,Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address,Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address,Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_menu(Address,Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
}


//----STYLE MENU---------------------------------------------------

void Lines_window::cb_smenu(Address,Address pw)
{
    reference_to<Lines_window>(pw).smenu_pressed();
}

void Lines_window::cb_solid(Address,Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address,Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address,Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}


