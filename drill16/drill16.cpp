/*
    g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp lines_window.cpp -o drill `fltk-config --ldflags --use-images`
*/
#include "lines_window.h"
#include "Graph.h"
#include "GUI.h"


int main()
{
    Lines_window win {Point{100,100}, 900, 600, "Polyline"};
    
    return gui_main();
}