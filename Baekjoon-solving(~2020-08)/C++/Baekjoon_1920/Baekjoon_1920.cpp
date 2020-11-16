#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t, tmp;
    map <int, bool> map;
    
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &tmp);
        map[tmp] = true;
    }
    
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &tmp);
        printf("%d\n", map[tmp]);
    }
    
    return 0;
}