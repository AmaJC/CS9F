#include <iostream>
#include <sstream>
using namespace std;

/** Returns the string representation of x */
std::string toString(int x) 
{
	std::ostringstream oss;
	oss << x;
	return oss.str();
}

int main()
{
	int total = 0, subtotal = 0;
	bool firstZero = false;
	while (true) {
		int input;
		cin >> input;
		subtotal += input;
		total += input;
		if (input == 0 and not firstZero) {
			cout << "Subtotal " + toString(subtotal);
			subtotal = 0;
			firstZero = true;
		} else if (input == 0 and firstZero) {
			cout << "Total " + toString(total);
			return 0;
		} else {
			firstZero = false;
		}
	}
	return 0;
}