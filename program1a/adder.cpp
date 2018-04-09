#include <iostream>
using namespace std;

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
			cout << "Subtotal " << subtotal << endl;
			subtotal = 0;
			firstZero = true;
		} else if (input == 0 and firstZero) {
			cout << "Total " << total << endl;
			return 0;
		} else {
			firstZero = false;
		}
	}
	return 0;
}