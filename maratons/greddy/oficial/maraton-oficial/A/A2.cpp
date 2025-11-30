#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9+7;
const ll MAX = 1e5 + 10;
ll memo[MOD];

using namespace std;

long long fibo(ll n)
{
    if(n <= 1)
    {
        return n;
    }
    if(memo[n] != -1) return memo[n];

    memo[n] = fibo(n - 1) + fibo(n - 2);

    return memo[n] % MOD;
}

int main()
{
    memset(memo, -1, sizeof(memo));
    cout << fibo(10) << endl;
   
    return 0;
}