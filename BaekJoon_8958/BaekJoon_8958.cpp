//1���� Line�� 0~80���� ���̿� ���ڿ��� �ֿ����� O,X�θ� �̷������.
//O�� ���ӵǸ� O,O,O 1,2,3 ���·� ������ ����Ŀ���� X�� ������ �ʱ�ȭ�� �ȴ�.

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char check[80];
	int max_line;
	cin >> max_line;
	int  *result=new int[max_line];
	int r = 0;
	int j_result=0;
	int i = 0;
	int ii = 0;
	while (i!=max_line) {
		r = 0;
		j_result = 0;
		cin >> check;
		for (int j = 0; j < strlen(check); j++)
		{
			if (check[j] == 'O') {
				j_result++;
			}
			else if (check[j] == 'X')
				j_result = 0;
			r += j_result;
			
		}
		result[ii] = r;
		i++;
		ii++;
	}

	for (int i = 0; i < max_line; i++) {
		cout << result[i] << endl;
	}
	delete[] result;
	return 0;
}