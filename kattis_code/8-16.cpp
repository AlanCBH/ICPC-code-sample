#include <iostream>
using namespace std;

int main ()
{
	string input;
	cin >> input;
	int bitstring[input.length()*3];
	int bs_index = 0;
	for (int i = input.length()-1; i >= 0; i--) {
		int digit = int(input[i]);
		for (int j = 0; j < 3; j++) {
			bitstring[bs_index] = digit%2;
			digit = digit/2;
			bs_index++;
		}
	}
	char result[input.length()*3/4 + 1];
	char true_res[input.length()*3/4 + 1];
	int res_index = 0;
	for (int i = 0; i < bs_index; i = i+4) {
		int num = 0;
		for (int j = 0; j < 4 && i+j < bs_index; j++) {
			int num += bitstring[i+j]*pow(2,j);
		}
		if (num < 10) {
			result[res_index] = char(num);
			res_index ++ ;
		} else if (num == 10) {
			result[res_index] = 'A';
			res_index ++ ;
		} else if (num == 11) {
			result[res_index] = 'B';
			res_index ++ ;
		} else if (num == 12) {
			result[res_index] = 'C';
			res_index ++ ;
		} else if (num == 13) {
			result[res_index] = 'D';
			res_index ++ ;
		} else if (num == 14) {
			result[res_index] = 'E';
			res_index ++ ;
		} else if (num == 15) {
			result[res_index] = 'F';
			res_index ++ ;
		}
	}
	for (int i = res_index-1; i >= 0; i--) {
		true_res[res_index-1-i] = result[i];
	}
	cout <<  true_res << endl;






	return 0;
}