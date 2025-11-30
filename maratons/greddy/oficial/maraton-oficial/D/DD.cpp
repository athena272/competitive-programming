#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
// ll const MAX = 1e5 + 5;

using namespace std;

struct atv 
{
    ll inicio;
    ll fim;
};

bool compara(atv &A, atv &B)
{
    return A.fim < B.fim;
}


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
    
    sort(atividades.begin(), atividades.end(), compara);
    


    // vll horarios(atividades[num_atv].fim, 1);
    ll total_nao_feitas = 0;
    
    for(ll i = 0; i < atividades.size(); i++){
        if(i==0)
        {
          
        }
        else if(atividades[i-1].fim > atividades[i].inicio){
            total_nao_feitas++;
        }
    }
    
    ll answer = num_atv - total_nao_feitas;
    cout << answer << endl;
    return 0;
}


