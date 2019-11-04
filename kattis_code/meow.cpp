#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
long long int* prime_factors(long long int num,long long int* res) {
	long long int * arr = new long long int[2*100];
	for (long long int i = 0; i < 2*100; i++) {
		arr[i] = 0;
	}
	
	long long int index = 0;
	//arr[index][0] = 0;
	//arr[index][1] = 0;
	while (num % 2 == 0)  
    {  
        arr[index] = 2;
		arr[index+1] += 1;
        num = num/2;  
    }  
	index += 2;  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
	//cout << pow(num,1.0/9.0)+1 << endl;
    for (long long int i = 3; i <= (long long int)(pow(num,1.0/9.0))+2; i = i + 2)  
    {  
        // While i divides n, print i and divide n
		int factor = 0;
        while (num % i == 0)  
        { 
			factor += 1;
            num = num/i;  
        }
		if (factor >= 9) {
			arr[index] = i;
			arr[index+1] = factor;
		}
		index += 2;
    }  
	/*if (num > 2) {
		arr[index] = num;
		arr[index+1] = 1;
		index += 2;
	}*/
	*res = index;
	//for (int i = 0; i < index; i++) {
	//	cout << arr[i][0] << " " <<arr[i][1] << endl;
	//}
	return arr;
	
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
		/*if (num > 2) {
			cout << n << " ";  
		} */ 
}


int main()
{
	long long int factor;	
	cin >>  factor;
	long long int size = 0;
	long long int largest = 1;
	long long int* arr = prime_factors(factor,&size);
	for (long long int i = 0; i < size; i = i+2) {
		long long int expo = arr[i+1]/9;
		largest = largest * pow(arr[i],expo);
	}
	cout << largest << endl;


	return 0;
}
