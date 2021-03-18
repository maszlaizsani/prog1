/*
g++ ex6.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex6 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"


int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{150,150}, 700,750, "Chapter 12 exercise, task 6"};
	
	Rectangle rec{Point{60,100},800,1000};

	win.attach(rec);

	win.wait_for_button();

}