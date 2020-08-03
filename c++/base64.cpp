
#include <stdio.h>
#include <string>
#include <bitset>
#include <iostream>

using namespace std;

const string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

string base64(string input) {
	string base64, binary, temp = "";

	for (int i = 0; i < input.size(); i++) 
		binary += bitset<8>(input[i]).to_string();

	// Final quantum of encoding input is an integral multiple of 24 bits
	for (int i = 0; i < binary.size(); i++) {
		temp += binary[i];

		if (temp.size() == 6) {
			base64 += base64_chars[bitset<6>(temp).to_ulong()];
			temp = "";
		}
	}

	if ((input.size() % 3 == 1) || (input.size() % 3 == 2))
	{
		int shift = 6 - temp.size();
		base64 += base64_chars[(bitset<6>(temp) << shift).to_ulong()];
	}
	
	// Final quantum of encoding input is 8 bit
	if (input.size() % 3 == 1) { 
		base64 += "==";
	}

	// Final quantum of encoding input is 16 bit
	if (input.size() % 3 == 2) { 
		base64 += "=";
	}

	return base64;
}

int main() {

	string text;

	cout << "Enter the text to encode:" << "\n";
	getline(cin, text);
	
	cout << "Result: \n" << base64(text) << "\n";

	return 0;
}