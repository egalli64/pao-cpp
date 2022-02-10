#include <iostream>
#include <string>
using namespace std;

void f(const string& message) {
	cout << message << endl;
}

class Functor {
public:
	void operator()(const string& message) const { cout << message << endl; }
};

int main() {
	cout << "\nC++ Callable Objects\n" << endl;

	f("Hello function");

	void (*pf)(const string&) = &f;
	pf("Hello pointer to function");

	Functor fr;
	fr("Hello functor");

	auto lambda = [](const string& message) { cout << message << endl; };
	lambda("Hello lambda");
}
