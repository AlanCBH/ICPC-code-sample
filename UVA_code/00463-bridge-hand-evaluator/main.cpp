#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;

int Calpoint(vector<char> cards,bool* stop) {
	int point = 0;
	bool queen = false;
	bool king = false;
	bool jack = false;
	bool ace = false;
	int size = cards.size();
	for (int i = 0; i < size; i++) {
		if (cards[i] == 'A') {
			ace = true;
			point += 4;
		} else if (cards[i] == 'K') {
			king = true;
			point += 3;
		} else if (cards[i] == 'Q') {
			queen = true;
			point += 2;
		} else if (cards[i] == 'J') {
			jack = true;
			point += 1;
		}
	}

	if (king && size == 1) {
		point = point - 1;
	}
	if (queen && size <= 2) {
		point = point - 1;
	} 
	if (jack && size <= 3) {
		point = point - 1;
	}
	if (ace || (king && size >= 2) || (queen && size >= 3)) {
		*stop = true;
	} else {
		*stop = false;
	}


	return point;
}



bool checkPoint() {
	//ofstream myfile;
	//myfile.open("example.txt");
	vector<char> heart;
	vector<char> spade;
	vector<char> diamond;
	vector<char> club;
	for (int i = 0; i < 13; i++) {
		char hand[3];
		if (scanf("%s",hand) == EOF) {
			return false;
		} else {
			if (hand[1] == 'H') {
				heart.push_back(hand[0]);
			} else if (hand[1] == 'S') {
				spade.push_back(hand[0]);
			} else if (hand[1] == 'D') {
				diamond.push_back(hand[0]);
			} else if (hand[1] == 'C') {
				club.push_back(hand[0]);
			} 
		}

	}
	bool hs,ss,cs,ds;
	int point = Calpoint(heart,&hs);
	point += Calpoint(spade,&ss);
	point += Calpoint(club,&cs);
	point += Calpoint(diamond,&ds);
	
	
	if (point >= 16 && hs && ss && cs && ds) {
		//no trump
		printf("BID NO-TRUMP\n");
		fflush(stdout);
		//myfile<<"BID NO-TRUMP\n";
		//myfile.close();
		return true;
	}
	int h_size = heart.size();
	if (h_size == 2) {
		point += 1;
	} else if (h_size <= 1) {
		point += 2;
	} 
	int s_size = spade.size();
	if (s_size == 2) {
		point += 1;
	} else if (s_size <= 1) {
		point += 2;
	} 
	int c_size = club.size();
	if (c_size == 2) {
		point += 1;
	} else if (c_size <= 1) {
		point += 2;
	} 
	int d_size = diamond.size();
	if (d_size == 2) {
		point += 1;
	} else if (d_size <= 1) {
		point += 2;
	}
	if (point >= 14) {
		//
		int max_size = max(max(c_size,d_size),max(h_size,s_size));
		if (max_size == s_size) {
			printf("BID S\n");
			fflush(stdout);
			//myfile<<"BID S\n";
			//myfile.close();
			return true;
		}
		if (max_size == h_size) {
			printf("BID H\n");
			fflush(stdout);
			//myfile<<"BID H\n";
			//myfile.close();
			return true;
		}
		
		if (max_size == d_size) {
			printf("BID D\n");
			fflush(stdout);
			//myfile<<"BID D\n";
			//myfile.close();
			return true;
		}
		if (max_size == c_size) {
			printf("BID C\n");
			fflush(stdout);
			//myfile<<"BID C\n";
			//myfile.close();
			return true;
		}
		
	} else {
		//pass
		printf("PASS\n");
		fflush(stdout);
		//myfile<<"PASS\n";
		//myfile.close();
		return true;
	}

}


int main ()
{
	while(checkPoint()) {
		continue;
	}
	
	return 0;
}
