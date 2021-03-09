/*
    g++ drill2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill2 `fltk-config --ldflags --use-images`
*/


#include "Simple_window.h"
#include "Graph.h"


int main()
{
    using namespace Graph_lib;

 	constexpr int x_size=600;
 	constexpr int y_size=750;
 	constexpr int grid_size=75; // 3/4 scale

 	Simple_window win{Point{150,150}, 600,750, "Program"}; // 3/4 scale

 	Lines grid;

 	for (int x=grid_size; x<600; x+=grid_size)
 		grid.add(Point{x,0}, Point{x,600});

 		for (int y=grid_size;y<=600; y+=grid_size)
 			grid.add(Point{0,y}, Point{x_size,y});


    Vector_ref<Rectangle>rec;
 	
 	for (int i=0;i<8;++i)
 	{
 		rec.push_back(new Rectangle(Point{i*75,i*75},75,75));
 		rec[i].set_fill_color(Color::red);
 		win.attach(rec[i]);
 	}

 	Image kep1 {Point{150,0}, "image.jpg"};
 	Image kep2 {Point{300,150}, "image.jpg"};
 	Image kep3 {Point{0,300},"image.jpg"};

 	win.attach(grid);
 	win.attach(kep1);
 	win.attach(kep2);
 	win.attach(kep3);


 	Image kep4 {Point{0,0}, "kuty.jpg"};
 	win.attach(kep4);

 	for(int i=0; i<8; ++i)
 		for(int j=0;j<8; ++j)
 		{
 			win.wait_for_button();
 			if(j<7) kep4.move(75,0);
 			else kep4.move(-525,75);
 		}

}
