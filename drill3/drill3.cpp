#include "std_lib_facilities.h"


class B1 {
	public: 
		virtual void vf() const {std::cout<<"B1::vf()"<<endl;};
		void f() const {std::cout<<"B1::f()"<<endl;}
		virtual void pvf()const=0;
};


class D1: public B1 {
	public: 
		void vf() const override {std::cout<<"D1::vf()"<<endl;};
		void f() const {std::cout<<"-- D1::f() --"<<endl;};
};


class D2: public D1 {
	public:
		void pvf() const{cout<<"D2::pvf()"<<endl;};
};


class B2 {
	public:
		virtual void pvf()=0;
};

class D21 : public B2 {
	public:
	string a;
	void pvf() {cout<<a<<endl;};
};

class D22 : public B2 {
	public:
	int a;
	void pvf() {cout<<a<<endl;};
};

void f(B2& arg)
{
    arg.pvf();
};

int main()
{
	/*B1 object;
	object.vf();
	object.f();
	cout<<"\n";

	D1 object2;
	object2.vf();
	object2.f();
	cout<<"\n";

	B1& refer=object2;

	refer.vf();
	refer.f(); 
	cout<<"\n";*/

	D2 d;
	d.vf();
	d.f();
	d.pvf();

	D21 str; str.a="Hello";
	D22 num; num.a=64;

	f(str);
	f(num);


}