#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b,c;
	cin >> a >> b >> c;
	int frac;
	bool f = true;
	for (int i = 0; i < 308; i++) {
		a = a * 10;
		int r = a % b;
		frac = a / b;
		if ( (int)frac %10 == c) {
			printf("%d\n", i+1);
			f = false;
			break;
		}
		a = r;
		
	}
	if (f) {
		printf("-1\n");
	}

	return 0;
}
