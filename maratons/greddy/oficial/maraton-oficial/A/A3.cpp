#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9+7;

using namespace std;

int main()
{
    ll num;
    while (cin >> num)
    {
        ll p1 = 0; 
        ll p2 = 1; 
        ll p3; 
        ll cont = 0;
        if(num <= 0)
        {
            cout << 1 % MOD << endl;
            return 0;
        }
        while (cont < num)
        {
            p3 = p1 + p2;
            p1 = p2; 
            p2 = p3;
            cont++;
        }
        
        cout << p1 % MOD << endl;
        return 0;
    }
}