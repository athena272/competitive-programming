#include <bits/stdc++.h>
#define ll long long
#define vll queue<ll>

using namespace std;

int main()
{
    ll disposicao, atividades_cansativas, atividades_revigorantes;
    cin >> disposicao >> atividades_cansativas >> atividades_revigorantes;
    vll queue_atividades_cansativas;
    vll queue_atividades_revigorantes;
    for (ll i = 0; i < atividades_cansativas; i++)
    {
        ll value;
        cin >> value;
        queue_atividades_cansativas.push(value);
    }
    for (ll i = 0; i < atividades_revigorantes; i++)
    {
        ll value;
        cin >> value;
        queue_atividades_revigorantes.push(value);
    }

    ll total_atividades = 0;
    while (!queue_atividades_cansativas.empty())
    {
        if(disposicao >= queue_atividades_cansativas.front())
        {
            disposicao -= queue_atividades_cansativas.front();
            queue_atividades_cansativas.pop();
            total_atividades++;
        } 
        while (disposicao < queue_atividades_cansativas.front() && !queue_atividades_cansativas.empty() && !queue_atividades_revigorantes.empty())
        {
            disposicao += queue_atividades_revigorantes.front();
            queue_atividades_revigorantes.pop();
            total_atividades++;
        }
        if (disposicao < queue_atividades_cansativas.front())
        {
            break;
        }
    }

    while (!queue_atividades_revigorantes.empty())
    {
        total_atividades++;
        queue_atividades_revigorantes.pop();
    }

    cout << total_atividades << endl;
}

