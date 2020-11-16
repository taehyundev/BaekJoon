#include <iostream>
#include <cstdio>
 
using namespace std;
 
int num[1000001];
 
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    num[1] = 1; // 1은 제외하고 2부터 시작하기 위함
 
    // 최초의 소수를 찾고 이것을 제외한 배수를 지워나감 
    // ex) 소수 2를 찾고 2를 제외한 배수를 전부지움 이후 다음 소수 3을 찾고 그의 배수를 지움 다시 소수를 찾고 반복
    for (int i = 2; i <= n; i++)
    {
        if (num[i] == 0) {
            for (int j = 2; n >= i * j; j++)
            {
                num[i * j] = 1;
            }
        }
    }
    for (int i = m; i <= n; i++)
    {
        if(num[i] == 0)
            printf("%d\n", i);
    }
    return 0; 
}
