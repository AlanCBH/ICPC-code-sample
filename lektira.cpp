#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
bool smaller(char* a, char* b);
char* fold_string(string a,int start_index,int split) {
	int size = a.length();
	char* res = new char[size-start_index];
	if (split == 1) {
		for (int i = 0; i < size-start_index; i++) {
			res[i] = a[size - i -1];
		}
		return res;
	}

	vector<int> positions;
	int small = int(a[start_index]);
	//positions.push_back(start_index);
	for (int i = start_index; i <= a.length() - split; i++) {
		if (int(a[i]) == small)  {
			positions.push_back(i-start_index);
		} else if (int(a[i] < small)) {
			positions.clear();
			positions.push_back(i-start_index);
			small = int(a[i]);
		}
	}
	for (int i = 0; i <= positions.back(); i++) {
		res[positions.back()-i] = a[i+start_index];
		//cout <<  res << endl;
	}
	char* append = fold_string(a,positions.back()+1,split-1);
	for (int i = positions.back()+1; i < size-start_index; i++) {
		res[i] = append[i-positions.back()-1];
	}

	positions.pop_back();
	int vector_size = positions.size();
	for (int i = 0; i < vector_size; i++) {
		char* temp = new char[size-start_index];
		for (int j = 0; j <= positions.back(); j++) {
			temp[positions.back()-j] = a[start_index+j];
		}
		char* append = fold_string(a,positions.back()+1,split-1);
		for (int j = positions.back()+1; j < size-start_index; j++) {
			temp[j] = append[j-positions.back()-1];
		}

		if (smaller(res,temp)) {
			//continue;
			delete(temp);
		} else {
			delete(res);
			res = temp;
		}
		//cout <<  res << endl;
		positions.pop_back();
	}
	return res;
}

bool smaller(char* a,char* b) {
	
	for (int i = 0; i < strlen(a); i++) {
		if ( int(a[i]) > int(b[i]) ) {
			return false;
		} else if (int(a[i]) < int(b[i])) {
			return true;
		}
			
	}
	return true;
}

int main ()
{
  string a;
  cin >> a;
  char* res = fold_string(a,0,3);
  cout << res << endl;
  

  return 0;
}