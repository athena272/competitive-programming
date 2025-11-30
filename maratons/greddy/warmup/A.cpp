#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll N, H, total = 0;
    cin >> N >> H;
    vector<ll> alturas(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> alturas[i];
    }
    for (ll i = 0; i < N; i++)
    {
        if(alturas[i] <= H)
        {
            total++;
        }
    }
    
    cout << total << endl;
    return 0;
}