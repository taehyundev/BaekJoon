//1개의 Line에 0~80개의 길이에 문자열이 주워지고 O,X로만 이루워진다.
//O가 연속되면 O,O,O 1,2,3 형태로 점수가 점점커지고 X를 만나면 초기화가 된다.

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