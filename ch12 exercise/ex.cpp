/*
    g++ ex.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ex `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"


int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{150,150}, 700,750, "Chapter 12 exercise"};
	
	//1 --------------
	Rectangle rec{Point{40,40},160,100};
	rec.set_color(Color::red);
	
	Polygon rect;
	rect.add(Point{40,40});
	rect.add(Point{200,40});
	rect.add(Point{200,140});
	rect.add(Point{40,140});
	
	win.attach(rect);
	win.attach(rec);
	
	//2 --------------
	Rectangle h{Point{260,60}, 100,30};
	Text howdy{Point{282,79},"Howdy!"};

	win.attach(howdy);
	win.attach(h);

	
	//3 --------------
	Open_polyline m;
	m.add(Point{400,650});
	m.add(Point{400,500});
	m.add(Point{430,580});
	m.add(Point{460,500});
	m.add(Point{460,650});
	m.set_style(Line_style(Line_style::solid,3));

	Open_polyline z;
	z.add(Point{480,500});
	z.add(Point{520,500});
	z.add(Point{480,650});
	z.add(Point{520,650});
	z.set_style(Line_style(Line_style::solid,3));

	win.attach(z);
	win.attach(m);

	
	//4 --------------
	Vector_ref<Rectangle>r;
	for (int i=0;i<3;++i)
 	{
 		r.push_back(new Rectangle(Point{i*50,200},50,50));
 		
 		if(i%2==0)r[i].set_fill_color(Color::red);
 		else r[i].set_fill_color(Color::white);
 		win.attach(r[i]);


 	}

 	Vector_ref<Rectangle>r2;
	for (int i=0;i<3;++i)
 	{
 		r2.push_back(new Rectangle(Point{i*50,250},50,50));
 		
 		if(i%2==1)r2[i].set_fill_color(Color::red);
 		else r2[i].set_fill_color(Color::white);
 		win.attach(r2[i]);
 		
 	}

 	Vector_ref<Rectangle>r3;
	for (int i=0;i<3;++i)
 	{
 		r3.push_back(new Rectangle(Point{i*50,300},50,50));
 		
 		if(i%2==0)r3[i].set_fill_color(Color::red);
 		else r3[i].set_fill_color(Color::white);
 		win.attach(r3[i]);
 		
 	}


	//5 --------------
	Rectangle fr {Point{165,170},525,500}; // 3/4 height and 2/3 width
	fr.set_style(Line_style(Line_style::solid,24)); //0.25 inch=24 pixels
	fr.set_color(Color::red);
	win.attach(fr);

	win.wait_for_button();

}
