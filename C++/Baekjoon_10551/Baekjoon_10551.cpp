#include <iostream>
using namespace std;

int main() {
	string txt;
	cin >> txt;
	int finger[8] = {0,};
	for (int i = 0; i < txt.length(); i++) {
		char a = txt[i];
		switch (a) {
		case '1':
		case 'Q':
		case 'A':
		case 'Z':
			finger[0]++;
			break;
		case '2':
		case 'W':
		case 'S':
		case 'X':
			finger[1]++;
			break;
		case '3':
		case 'E':
		case 'D':
		case 'C':
			finger[2]++;
			break;
		case '4':
		case 'R':
		case 'F':
		case 'V':
		case '5':
		case 'T':
		case 'G':
		case 'B':
			finger[3]++;
			break;
		case '6':
		case '7':
		case 'Y':
		case 'U':
		case 'H':
		case 'J':
		case 'N':
		case 'M':
			finger[4]++;
			break;
		case '8':
		case 'I':
		case 'K':
		case ',':
			finger[5]++;
			break;
		case '9':
		case 'O':
		case 'L':
		case '.':
			finger[6]++;
			break;
		default:
			finger[7]++;
			break;
		}
	}
	for (int i = 0; i < 8; i++)
		cout << finger[i] << endl;
}
