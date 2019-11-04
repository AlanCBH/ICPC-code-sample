#include <bits/stdc++.h>
using namespace std;
string P;
int b[1000000];
int m;

void kmpProcess() {
	int i = 0; int j = -1; b[i] = j;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) {
			j = b[j];
		}
		i++; j++;
		b[i] = j;
	}
}


int main() {
	cin >> P;
	m = P.length();
	kmpProcess();
	for (int i = 0; i < P.length(); i++) {
		printf("%d ",b[i]);
	}
	return 0;
}