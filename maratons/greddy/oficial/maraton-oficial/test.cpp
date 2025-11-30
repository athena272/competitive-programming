#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
ll const MAX = 1e5 + 5;

using namespace std;

struct atv 
{
    ll inicio;
    ll fim;
};

int main()
{
    ll num_atv;
    cin >> num_atv;
    vector<atv> atividades(num_atv);

    
    for (ll i = 0; i < num_atv; i++)
    {   
        ll A, B;
        cin >> A >> B;
        atividades[i].inicio = A;
        atividades[i].fim = B;
    }
    
    vll horarios(MAX, 1);


    ll total_nao_feitas = 0;
    for (ll i = 0; i < num_atv; i++)
    {
        for (ll j = atividades[i].inicio; j <= atividades[i].fim; j++)
        {
            if(horarios[j] == 0)
            {
                total_nao_feitas++;
                break;
            }
            else
            {
                horarios[j] = 0;
            }
        }              
    }
    
    ll answer = num_atv - total_nao_feitas;
    cout << answer << endl;

    return 0;
}