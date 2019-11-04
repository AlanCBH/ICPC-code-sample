#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void merge_sort(int** arr,int s,int e,int** res) {
	if (s > e) {
		return;
	}
	if (s == e) {
		res[0][s] = arr[0][s];
		res[1][s] = arr[1][s];
		return;
	}
	int mid = (s+e)/2;
	//cout << s << mid << endl;
	merge_sort(arr,s,mid,res);
	//cout << mid+1 << e << endl;
	merge_sort(arr,mid+1,e,res);
	
	int high_s = mid+1;
	int low_s = s;
	for (int i = 0; i < e-s+1; i++) {
		if (high_s > e && low_s <= mid) {
			//cout << i << "hg_s";
			res[0][s+i] = arr[0][low_s];
			res[1][s+i] = arr[1][low_s];						
			low_s++;
		} else if (low_s > mid && high_s <= e) {
			//cout << i << "low_s";
			res[0][s+i] = arr[0][high_s];
			res[1][s+i] = arr[1][high_s];
			high_s++;
		} else {
			//base on the high temp
			if (arr[1][low_s] > arr[1][high_s]) {
				//cout << i << ">";
				res[0][s+i] = arr[0][high_s];
				res[1][s+i] = arr[1][high_s];
				high_s++;
			} else {//if (arr[1][low_s] < arr[1][high_s]) {
				//cout << i << "<";
				res[0][s+i] = arr[0][low_s];
				res[1][s+i] = arr[1][low_s];						
				low_s++;
			}
		}
		
	}
	for (int i = 0; i < e-s+1; i++) {
		//cout << res[1][i]<< s << endl;
		arr[0][s+i] = res[0][s+i];
		arr[1][i+s] = res[1][i+s];
	}

}
int greedy_count(int** arr,int num) {
	int max = arr[1][0];
	int room = 1;
	for (int i = 0; i < num; i ++) {
		if (arr[0][i] > max) {
			max = arr[1][i];
			room++;
		}
	}
	return room;

}

int main ()
{
	int num = 0;
	cin >> num;
	int** arr = new int*[2];
	for(int i = 0; i < 2; ++i) {
		arr[i] = new int[num];
	}
	//int arr[2][num];
	for (int i = 0; i < num; i++) {
		cin >> arr[0][i]; //low temp
		cin >> arr[1][i]; //high temp
	}
	int** res = new int*[2];
	for(int i = 0; i < 2; ++i) {
		res[i] = new int[num];
	}
	merge_sort(arr,0,num-1,res);
	//for (int i = 0; i < num; i++) {
	//	cout << arr[1][i] << endl;
		//arr[0][s+i] = res[0][s+i];
		//arr[1][i+s] = res[1][i+s];
	//}
	int room = greedy_count(arr,num);
	cout << room << endl;
	return 0;
}