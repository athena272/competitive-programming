#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int n;
    cin >> n;

    // PASSO 1: Converter o polinômio em um número binário
    // Cada bit do número representa se o termo x^i está presente
    // Exemplo: x³ + 1 (coeficientes 1,0,0,1) vira o binário 1001 = 9
    long long x = 0;
    for (int i = n; i >= 0; i--) {
        long long bit;
        cin >> bit;
        // Adiciona o bit na posição i: se bit=1, adiciona 2^i ao número
        x += (bit << i);
    }

    // PASSO 2: Aplicar as regras do Collatz polynomial até chegar a 1
    long long ans = 0;
    while (x != 1) {
        ans++;
        
        // REGRA 1: Se o polinômio TEM termo constante (bit menos significativo = 1)
        if (x & 1) {
            // Multiplica por (x+1) e adiciona 1
            // Operação: P(x) * (x+1) + 1
            // 
            // Como trabalhamos com binários:
            // - (x << 1) = multiplica por x (desloca bits para esquerda)
            // - (x << 1) ^ x = multiplica por (x+1) usando XOR (soma módulo 2)
            // - ^ 1 = adiciona 1
            // 
            // Nota: Se algum coeficiente ficar 2, ele é descartado (mod 2)
            // O XOR já faz isso automaticamente!
            x = ((x << 1) ^ x) ^ 1;
        } 
        // REGRA 2: Se o polinômio NÃO tem termo constante (bit menos significativo = 0)
        else {
            // Divide por x (remove o termo de menor grau)
            // Isso é equivalente a deslocar os bits para direita
            x = x >> 1;
        }
    }
    cout << ans << endl;
}
