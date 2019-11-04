#include <iostream>
#include <iomanip>
using namespace std;

void read_grades() {
	int total;
	int total_grade = 0;
	int above = 0;
	cin >> total;
	int grades[total];
	//cout << total << endl;
	for (int i = 0; i < total; i++) {
		cin >> grades[i];
		//cout << grades[i] << endl;
		total_grade += grades[i]; 
	}
	double average = (double)total_grade/total;
	//cout << average << endl;
	for (int i = 0; i < total; i++) {
		if ( (double)grades[i] > average) {
			above++;
		} 
	}
	double percentage = 100*(double)above/(double)total;
	//cout << above << endl;
	//cout << total << endl;
	//cout << percentage << endl;
	cout<<fixed<<setprecision(3)<<percentage<<"%"<<endl;
}

int main ()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		read_grades();
	}

	return 0;
}