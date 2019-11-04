#include <iostream>
using namespace std;

int main ()
{
  string order;
  int i,j,k,a,b,c;
  cin >> i >> j >> k >> order;
  if (i > j && i > k) {
		c = i;
		if (j > k) {
			b = j;
			a = k;
		} else {
			b = k;
			a = j;
		}
  } else if (j > k && j > i) {
		c = j;
		if (k > i) {
			b = k;
			a = i;
		} else {
			b = i;
			a = k;
		}
  } else {
		c = k;
		if (j > i) {
			b = j;
			a = i;
		} else {
			b = i;
			a = j;
		}
  
  }
  for (int i = 0; i < 3; i++) {
	if (order[i] == 'A') {
		cout << a;
	} else if (order[i] == 'B' ) {
		cout << b;
	} else {
		cout << c;
	}
	if (i != 2) {
		cout << " ";
	}
  }
  

  return 0;
}