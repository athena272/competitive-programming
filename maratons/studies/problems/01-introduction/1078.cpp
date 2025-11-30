#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll number;
    cin >> number;
    for (ll i = 1; i <= 10; i++)
    {
        cout << i << " x " << number << " = " << i * number << "\n";
    }
    
    return 0;
}