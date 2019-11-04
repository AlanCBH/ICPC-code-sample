#include <iostream>
#include <vector>
using namespace std;

int main ()
{
 int num = 0;
 cin >> num;
 vector<int> arrows;
 for (int i = 0; i < num; i++) {
	int b = 0;
	cin >> b;
	bool more = true;
	for (int j = 0; j < arrows.size(); j++) {
		if (arrows.at(j) == b+1) {
			arrows.at(j) = b;
			more = false;
			break;
		}
	}
	if (more) {
		arrows.push_back(b);
	}
 }
  cout << arrows.size() << endl;

  return 0;
}