//This the dp solution to LIS
#include <iostream>
#include <string.h>
#include <cstdio> 
using namespace std;

void DP(string S, int* LIS, int ind) {
	//base case
	if (ind == 0) {
		LIS[ind] = 1;
		return;
	} 
	//general cases
	for (int i = 0; i < ind; i++) {
		if ( int(S[i]) < int(S[ind]) ) {
			if ( 1 + LIS[i] > LIS[ind] ) {
				LIS[ind] = 1+LIS[i];
			}	
		}
	}
	//if (LIS[ind] == 0) {
	//	LIS[ind==1]
	//}

}


int main ()
{
  //string S;
  char S[50];
  cin >> S;
  int length = strlen(S);
  //LIS[i] stores the max_LIS length that ends with S[i] 
  int LIS[length];
  for (int i = 0; i < length; i++) {
		LIS[i] = 1;
		DP(S,LIS,i);  
  }
  int max = LIS[0];
  for (int i = 1; i < length; i++) {
	//cout << LIS[i] << endl;
	if (max < LIS[i]) {
		max = LIS[i];
	}
  }
  cout << 26-max << endl;
  

  return 0;
}