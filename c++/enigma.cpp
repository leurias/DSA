
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string shuffle(string input) {
	string temp = input;
	random_shuffle(temp.begin(), temp.end());
	return temp;
}

char reflector(char c) {
	return alphabet[26 - alphabet.find(c) - 1];
}

void leftRotate(string &s, int d) 
{ 
    reverse(s.begin(), s.begin()+d); 
    reverse(s.begin()+d, s.end()); 
    reverse(s.begin(), s.end()); 
}

void rotate(int round, string r1, string r2, string r3) {
	leftRotate(r1, 1);

	if (round % 26)
		leftRotate(r2, 1);
	
	if (round % (26 * 26))
		leftRotate(r3, 1);
}

char enigma(char c, string &r1, string &r2, string &r3) {
	char cr1 = r1[alphabet.find(c)];
	char cr2 = r2[alphabet.find(cr1)];
	char cr3 = r3[alphabet.find(cr2)];
	char reflected = reflector(cr3);
	cr3 = alphabet[r3.find(reflected)];
	cr2 = alphabet[r2.find(cr3)];
	cr1 = alphabet[r1.find(cr2)];
	return cr1;
}

int main() {
	string plain = "FARIDMOHAMMADI";
	string cipher = "";
	string r1 = shuffle(alphabet);
	string r2 = shuffle(alphabet);
	string r3 = shuffle(alphabet);
	int round = 0;

	for (int i = 0; i < plain.size(); i++) {
		round++;
		cipher += enigma(plain[i], r1, r2, r3);
		rotate(round, r1, r2, r3);
	}

	cout << cipher;

	return 0;
}