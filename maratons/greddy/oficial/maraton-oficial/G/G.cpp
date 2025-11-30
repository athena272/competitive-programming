#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

int main()
{
    ll num;
    cin >> num;
    vll racoes(num);
    for (ll i = 0; i < num; i++)
    {
        cin >> racoes[i];
    }
    
    ll soma = 0;
    for (ll i = 0; i < num; i++)
    {
        soma += racoes[i];
    }
    
    string answer = "NAO";
    if(soma % num == 0)
    {
        answer = "SIM";
    }

    cout << answer << endl;
    return 0;
}