/*
    g++ ex7.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex7 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

double sm(double x) { return sin(x*4)+x/2; };

int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{150,150}, 700,750, "Chapter 12 exercise, task 7-8"};

	//------- WALL
	Rectangle wall{Point {140,160},300,200};
	win.attach(wall);	

	//------- ROOF
	Open_polyline roof;
	roof.add(Point{140,160});
	roof.add(Point{290,100});
	roof.add(Point{440,160});
	win.attach(roof);

	//------- WINDOWS

	Rectangle win1{Point {180,220},50,50};
	win.attach(win1);	

	Rectangle win2{Point {350,220},50,50};
	win.attach(win2);

	//------- DOOR

	Rectangle door{Point {260,260},60,100};
	win.attach(door);

	//------- CHIMNEY	
	Open_polyline chim;
	chim.add(Point{310,108});
	chim.add(Point{310,60});
	chim.add(Point{330,60});
	chim.add(Point{330,115});

	win.attach(chim);

	//------- SMOKE

	Function smoke{sm,0,3,Point{320,55}};
	win.attach(smoke);



//---- Task 8

	Circle c1(Point(100,420),50);
	c1.set_style((Line_style(Line_style::solid,8)));
    c1.set_color(Color::blue);
    win.attach(c1);

    Circle c2(Point(170,420),50);
    c2.set_style((Line_style(Line_style::solid,8)));
    win.attach(c2);

    Circle c3(Point(240,420),50);
    c3.set_style((Line_style(Line_style::solid,8)));
    c3.set_color(Color::red);
    win.attach(c3);

    Circle c4(Point(135,470),50);
    c4.set_style((Line_style(Line_style::solid,8)));
    c4.set_color(Color::yellow);
    win.attach(c4);

    Circle c5(Point(205,470),50);
    c5.set_color(Color::green);
    c5.set_style((Line_style(Line_style::solid,8)));
    win.attach(c5);

    win.wait_for_button();

}