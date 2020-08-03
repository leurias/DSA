
#include <iostream>
#include <vector> 

using namespace std;

#define what_is(x) cerr << #x << " is " << x << endl;

long double operator "" _cm(unsigned long long literal) {
	return literal / 100.0;
}

// Post Increment - Pre Increment
void snippet1() {
	int a,b = 0;
	a = b++;
	cout << a << b << "--";

	int c,d = 0;
	d = ++c;
	cout << c << d;
}

// Name of argument in macros
void snippet2() {
	int a_variable = 376;
	what_is(a_variable * 2 + 1)
}

// Raw String
void snippet3() {
	cout << R"(Hello\tWorld\n)";
}

void snippet4() {
	cout << 421_cm << " meters \n";
}

int main() {
	snippet4();

	return 0;
}