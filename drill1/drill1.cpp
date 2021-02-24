#include "Simple_window.h"
#include "Graph.h"


int main()
{
	using namespace Graph_lib;
	
	Simple_window ablak {Point{100,100}, 600, 400, "My window"};

	Axis xa {Axis::x, Point {70,300},300,30,"X tengely"};
	xa.set_color(Color::dark_blue);

	Axis ya {Axis::y, Point{70,300},250,30,"Y tengely"};
	ya.set_color(Color::red);

	Function sine {sin,0,100,Point{0,300},1000,50,50};
	sine.set_color(Color::dark_red);

	Polygon A;
	A.add(Point{370,300});
	A.add(Point{440,200});
	A.add(Point{410,210});
	A.set_color(Color::dark_red);


	Rectangle B{Point{250,355},100,35};
	B.set_fill_color(Color::white);


	Text txt{Point{280,378},"Hello!"};
	txt.set_font(Font::times_bold);

	Image kep{Point{236,0},"kep.jpg"};

	
	Circle kor1 {Point{364,50},5};
	Circle kor2 {Point{375,58},7};
	Circle kor3 {Point{390,68},10};
	Rectangle rec {Point{405,64}, 80,40};
	Text sz{Point {425,89},"Wow!!"};

	
	ablak.attach(kep);
	ablak.attach(B);
	ablak.attach(txt);
	ablak.attach(A);
	ablak.attach(sine);
	ablak.attach(ya);
	ablak.attach(xa);
	ablak.attach(rec);
	ablak.attach(kor1);
	ablak.attach(kor2);
	ablak.attach(kor3);
	ablak.attach(sz);


	ablak.wait_for_button();
}