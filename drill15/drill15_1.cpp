/*
    g++ drill15_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

Point origin{300,300};
const int axislength=400;
const int rmax=11;
const int rmin=-10;
const int x_scale=20;
const int y_scale=20;


double one (double x) { return 1; };
double slope(double x) {return x/2;};
double square (double x) {return x*x;};
double cosine (double x) {return cos(x);};
double sloping_cos (double x) {return cos(x)+slope(x);};


int main()
{
    using namespace Graph_lib;
    
    Simple_window win{Point{100,100},600,600,"Function graphs"};

    Axis x {Axis::x, Point{100, 300}, axislength, 20, "1 = = 20"};
	Axis y {Axis::y, Point{300, 500}, axislength, 20, "1 = = 20"};
	x.set_color(Color::red);
	y.set_color(Color::red);

	Function fn (one, rmin, rmax, origin, 400, x_scale, y_scale);
	Function fn2 (slope, rmin, rmax, origin, 400, x_scale, y_scale);
		Text label (Point{95,390},"x/2");
	Function fn3 (square, rmin, rmax, origin, 400, x_scale, y_scale);
	Function fn4 (cosine, rmin, rmax, origin, 400, x_scale, y_scale);
		fn4.set_color(Color::blue);
	Function fn5 (sloping_cos, rmin, rmax, origin, 400, x_scale, y_scale);

	win.attach(fn5);
	win.attach(fn4);
	win.attach(fn3);
	win.attach(label);
	win.attach(fn2);
	win.attach(fn);
	win.attach(x);
	win.attach(y);

    win.wait_for_button();

}