//�Է��� �� �ٷ� �̷���� ������, �� �� �ٿ� �빮�� ���ĺ����� ������ �ܾ 1�� �ֽ��ϴ�.
//�Է¹޴� �ܾ�� �ִ� 1000�� �����Դϴ�.


//����� �Է¹��� ī�̻縣 �ܾ ���� �ܾ�� ��ģ �� ����Ͻø� �˴ϴ�.

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