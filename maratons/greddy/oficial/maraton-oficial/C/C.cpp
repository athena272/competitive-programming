#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;

int main()
{
    ll qtd;
    cin >> qtd;
    vll bebidas(qtd);
    for (ll i = 0; i < qtd; i++)
    {
        cin >> bebidas[i];
    }
    
    ll cafes_bebidos = 0;
    for (ll i = 0; i < qtd; i++)
    {
        if(bebidas[i] == 3)
        {
            cafes_bebidos++;
        }
    }
    cout << cafes_bebidos << endl;

    return 0;
}