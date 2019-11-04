#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int* prime_factors(int num,int* res) {
	int * arr = new int[2*int(sqrt(num))];
	for (int i = 0; i < 2*int(sqrt(num)); i++) {
		arr[i] = 0;
	}
	
	int index = 0;
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
    for (int i = 3; i <= sqrt(num); i = i + 2)  
    {  
        // While i divides n, print i and divide n
		
        while (num % i == 0)  
        {  
            arr[index] = i;
			arr[index+1] += 1;
            num = num/i;  
        }
		index += 2;
    }  
	if (num > 2) {
		arr[index] = num;
		arr[index+1] = 1;
		index += 2;
	}
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
   string num;
   while(getline(cin, num)) {
		int inde = 0;
		int n = stod(num);
		int* arr = prime_factors(n,&inde);
		//cout << inde << endl;
		long total = 1;
		for (int i = 0; i < inde; i += 2) {
			//int factor = 1;
			if (arr[i] != 0) {
				long factor = 1;
				for (int j = 1; j <= arr[i+1]; j++) {
					factor += pow(arr[i],j);
				}
				total = total*factor;
			}	
		}

		total = total - n; 
		if (abs(total - n) == 2 ||abs(total - n) == 1) {
			cout << n << " almost perfect" << endl;
		} else if (abs(total - n) == 0) {
			cout << n << " perfect" << endl;
		} else {
			cout << n << " not perfect" << endl;
		}
		
		delete[] arr;
	} 
	
	return 0;
}
