#include<bits/stdc++.h>
using namespace std;
long long _sieve_size;
bitset<1000010> bs;
vector<int> primes;
int max_primes;
void sieve(long long upper) {
	_sieve_size = upper;
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= _sieve_size; i++) {
		if (bs[i]) {
			for (long long j = i * (i); j <= _sieve_size; j+=i) bs[j] = 0;
			//if (i > max_primes) {
			primes.push_back((int)i);
				//max_primes = i;
			//}
		}
	}
}
int main() {
	int temp;
	sieve(1000000);
	while (1) {
		cin >> temp;
		if (temp == 0) {
			break;
		}
		//if (max < temp) {
		//	max = temp
		//}
		for (int i = 0; i < primes.size(); i++) {
			//printf("%d ",primes[i]);
			if (binary_search(primes.begin(), primes.end(), temp - primes[i])) {
				printf("%d = %d + %d\n",temp,primes[i],temp-primes[i]);
				break;
			}
		}
	}
	return 0;
}