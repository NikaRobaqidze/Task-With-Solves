#include <iostream>
#include "staque.h"

#include <vector>

using namespace std;

int main() {

	vector <int> v = { 1, 3, 2, 4, 6, 8, 9 };
	Staque S(v);

	cout << S << endl;

	return EXIT_SUCCESS;
}