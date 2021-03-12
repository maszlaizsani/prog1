#include "std_lib_facilities.h"

struct Person {
	string fname;
	string lname;
	int age;
public:

	Person() {fname="Nobody"; lname="Nobody"; age=0;}
	Person (int a, string fn, string ln)
	{
		if ((a>150) || (a<0)) 
			simple_error("Wrong age.");
		else age=a;
		

		const string wchar=";:\"'[]*&^%$#@!0123456789";

		for(int i=0; i<fn.length(); i++)
			for(int j=0; j<wchar.length(); j++)
				if (fn[i]==wchar[j])
				{
					error("No last name given or illegal character used.");
				}
			
		fname=fn;

		for(int i=0; i<ln.length(); i++)
			for(int j=0; j<wchar.length(); j++)
				if (ln[i]==wchar[j])
				{
					error("No last name given or illegal character used.");
				}
			
		lname=ln;

	}

	int get_age() const {return age;};
	string get_fname() const {return fname;};
	string get_lname() const {return lname;};

};


ostream &operator << (ostream &output, Person &p)
{
	output<<"Name: "<<p.fname<<" "<<p.lname<<". Age: "<<p.age<<". \n";
	return output;
};


istream &operator >>(istream &input, Person &p)
{
	cout<<"Enter first name, last name and age: "<<endl;
	input>>p.fname>>p.lname>>p.age;
	p=Person(p.age,p.fname,p.lname);
	return input;
};


int main()
try{
	/*Person pn;
	pn.name="Goofy";
	pn.age=63;
	cout<<"Name: "<<pn.name<<", Age: "<<pn.age<<endl;*/

	Person pe(32,"Pam","Ela");
	cout<<pe;
	
	Person pr;
	cin>>pr;
	cout<<pr;

	cout<<pr.get_age()<<" "<<pr.get_fname()<<" "<<pr.get_lname()<<endl;

	vector<Person>people;
	Person vp;
	while (cin>>vp)
	{
		people.push_back(vp);
	}

	cout<<"-------------\n";
	for(int i=0; i<people.size(); i++)
	{
		cout<<people[i].fname<<" "<<people[i].lname<<" "<<people[i].age<<endl;
	}

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}