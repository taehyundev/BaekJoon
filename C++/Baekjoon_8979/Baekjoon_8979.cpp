#include <iostream>
using namespace std;

int main() {
	int city_N[1000];
	long long Gold;
	long long Silver;
	long long Dong;
	long long sum[1000];
	long long rank;
	long long n, n1; //몇개의 국가: n , 보고싶은 국가 등수, n1;

	cin >> n >> n1;
	for (int i = 0; i < n; i++) {
		cin >> city_N[i] >> Gold >> Silver >> Dong;
		sum[i] = (Gold * 1000000000000) + (Silver * 1000000) + Dong;
	}
	rank = 0;
	
	int search = -1;
	for (int i = 0; i <n; i++) {
		if (city_N[i] == n1) {
			search = i+1;
		}
	}
	for (int i = 0; i < n; i++) {

		if (i != search - 1) {
			if (sum[i] > sum[search - 1]) {
				rank++;
			}
		}
	}
	rank = rank + 1;

	cout << rank;
}
