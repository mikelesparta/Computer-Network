#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float f = -27.625;

	cout << "f: " << f << endl;

	float f1 = 0.1;
	float f2 = 0.3;

	cout << "f1: " << f1 << " f2: " << f2 << endl;

	cout << "f1: " << setprecision(15) << f1 << endl;
	cout << "f2: " << setprecision(15) << f2 << endl;

	if (f1 * 3.0 == f2)
		cout << "f1 * 3 equals f2" << endl;
	else
		cout << "f1 * 3 doesn´t equal f2" << endl; //due to the rounding error made when representing f2

	const float TOLERANCE = 0.0000001;
	if (fabs(f1 * 3.0 - f2) < TOLERANCE)
		cout << "Equal" << endl;
	else
		cout << "Different" << endl;

	float euros = 0;
	const int ONE_MILLION = 1000000;
	for (int i = 0; i < 20 * ONE_MILLION; i++)
		euros = euros + 1.0;
	cout << "euros = " << euros << endl;

	float f3 = 19 * ONE_MILLION;
	cout << "f3: " << setprecision(15) << f3 << endl;
	f3 = f3 + 1;
	cout << "f3 + 1: " << setprecision(15) << f3 << endl;

	char c1 = 'a';
	char c2 = 'ñ';
	char value= 0xA4;

	cout << "c1: " << c1 << " c2: " << c2 << " char: " << value << endl;

	return 0;
}
