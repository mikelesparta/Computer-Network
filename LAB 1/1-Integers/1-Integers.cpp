#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "Input a: ";
	cin >> a;
	int b;
	cout << "Input b: ";
	cin >> b;
	cout << "a: " << a << " b: " << b << endl;

	int c = a + b;
	cout << "c: " << c << endl;
	int d = a / 2 + b / 2; // (a + b) / 2 mean
	cout << "d: " << d << endl;


	if (a > 0 && b > 0 && c < 0) {
		cout << "Overflow detected!!!" << endl;
	}

	if (a < 0 && b < 0 && c>0) {
		cout << "Overflow detected!!!" << endl;
	}

	cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;

	if (a < b)
	{
		cout << "a is less than b" << endl;
	}

	const int ONE_MILLION = 1000000;
	int Counter = 0;
	for (int i = 0; i < 3000 * ONE_MILLION; i++)
		Counter++;
	cout << "Counter " << Counter << endl;
	
	return 0;
}
