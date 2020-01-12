//입력은 한 줄로 이루어져 있으며, 그 한 줄엔 대문자 알파벳으로 구성된 단어가 1개 있습니다.
//입력받는 단어는 최대 1000자 이하입니다.


//출력은 입력받은 카이사르 단어를 원래 단어로 고친 걸 출력하시면 됩니다.

#include <iostream>
#include <string.h>
using namespace std;
void Decrypt(char * str) {
	int key = 3;
	for (int i = 0; i < strlen(str); i++) {
		str[i] -= 3;
		if (str[i] < 'A') str[i] += 26; // Important
	}
	for (int i = 0; i < strlen(str); i++) {
		cout<<str[i];
	}
	
}
int main() {
	char str[1000];
	cin >> str; 
	Decrypt(str);
}