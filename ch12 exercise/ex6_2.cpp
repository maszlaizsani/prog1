/*
g++ ex6_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex6 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"


int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{200,200}, 2000,2000, "Chapter 12 exercise, task 6"};
	

	win.wait_for_button();

}