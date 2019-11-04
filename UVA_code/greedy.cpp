#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned int N, L, U;
	while (scanf("%u %u %u",&N,&L,&U) != EOF) {
		unsigned int temp = 0;
		for (unsigned int i = 1 << 31; i > 0; i = i/2) {
			if ( (i & N) == 0 ) {
				if ((temp | i) <= U) {
					temp = temp | i;
				}
			}
		}
		if (temp < L) {
			unsigned int cur = L;
			for (int i = 31; i >= 0; i--) {
				unsigned int cur_bits = 1 << i;
				if ( (temp & cur_bits) != 0 && ((cur | cur_bits) >> i) << i <= U && L <= ((cur | cur_bits) >> i) << i) {
					cur = ((cur | cur_bits) >> i) << i;
				}
			}
			temp = cur;
		}

		cout << temp << endl;

	}
	return 0;
}