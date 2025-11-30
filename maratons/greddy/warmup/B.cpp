#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll temp_fala(ll diretores, ll minutes)
{
    ll tempo_intervalo = diretores - 1;
    ll tempo = minutes - tempo_intervalo;
    if(diretores == 1)
    {
        return minutes;
    }

    return tempo / diretores;
 }

int main()
{
    ll diretores, minutes;
    cin >> diretores >> minutes;
    cout << temp_fala(diretores, minutes) << endl;
}