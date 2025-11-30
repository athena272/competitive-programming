#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
    ll n;
    
    while (cin >> n && n != 0) {
        if (n == 1) {
            cout << "Discarded cards:" << endl;
            cout << "Remaining card: 1" << endl;
            continue;
        }
        
        queue<ll> deck;
        vector<ll> discarded;
        
        // Inicializar o baralho com cartas de 1 a n
        for (ll i = 1; i <= n; i++) {
            deck.push(i);
        }
        
        // Processar enquanto houver mais de 1 carta
        while (deck.size() > 1) {
            // Descartar a carta do topo
            discarded.push_back(deck.front());
            deck.pop();
            
            // Mover a próxima carta do topo para o fundo
            if (deck.size() > 1) {
                deck.push(deck.front());
                deck.pop();
            }
        }
        
        // Imprimir cartas descartadas
        cout << "Discarded cards: ";
        for (ll i = 0; i < discarded.size(); i++) {
            if (i > 0) cout << ", ";
            cout << discarded[i];
        }
        cout << endl;
        
        // Imprimir carta restante
        cout << "Remaining card: " << deck.front() << endl;
    }
    
    return 0;
}