#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

void pair_diff(string pair) {
	vector<string> values;
	istringstream iss(pair);
	for (pair; iss >> pair;) {
		values.push_back(pair);
	}
	double v0 = stod(values[0]);
	double v1 = stod(values[1]);
	//cout.setf(ios_base::fixed,ios_base::floatfield);
	cout<< abs(v0-v1) << endl;
}
int main ()
{
	string pair;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(0);
	while(getline(cin, pair)) {
		pair_diff(pair);
	}
  return 0;
}