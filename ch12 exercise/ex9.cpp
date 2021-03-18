/*
    g++ ex9.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex9 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{150,150}, 700,750, "Horse"};
	
	Image paci {Point{0,0},"horse.jpg"};
	win.attach(paci);
	
	Text caption{Point{100,620},"A horse from 'Atacama Horse Adventure' Ranch, San Pedro "};
	win.attach(caption);
	
	win.wait_for_button();
}