#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD = 1e9 + 7;

/**
 * Função para encontrar o número de formas de construir a soma N
 * lançando um dado uma ou mais vezes.
 * 
 * Cada lançamento produz um resultado entre 1 e 6.
 */
ll solve(ll targetSum)
{
    // Array DP onde dp[i] armazena o número de formas de fazer soma = i
    vector<ll> waysToMakeSum(targetSum + 1, 0);

    // Caso base: há exatamente 1 forma de fazer soma = 0
    // (não lançar nenhum dado)
    waysToMakeSum[0] = 1;

    // Iterar sobre todas as somas possíveis de 1 até targetSum
    for (ll currentSum = 1; currentSum <= targetSum; currentSum++)
    {
        // Para fazer currentSum, o último dado pode ter sido 1, 2, 3, 4, 5 ou 6
        for (ll lastDiceValue = 1; lastDiceValue <= 6; lastDiceValue++)
        {
            // Só podemos usar este valor de dado se currentSum >= lastDiceValue
            if (lastDiceValue > currentSum)
                break;

            // Se o último dado foi 'lastDiceValue', então antes precisávamos
            // fazer a soma (currentSum - lastDiceValue)
            ll previousSum = currentSum - lastDiceValue;
            ll waysFromPreviousSum = waysToMakeSum[previousSum];

            // Adiciona as formas de fazer previousSum às formas de fazer currentSum
            waysToMakeSum[currentSum] = (waysToMakeSum[currentSum] + waysFromPreviousSum) % MOD;
        }
    }

    // Retorna o número de formas de fazer soma = targetSum
    return waysToMakeSum[targetSum];
}

int main()
{
    // Exemplo de entrada
    ll N = 4;

    cout << "Número de formas de fazer soma " << N << ": " << solve(N) << "\n";

    // Teste com outros valores
    cout << "\nTestando outros valores:\n";
    for (ll i = 1; i <= 10; i++)
    {
        cout << "Soma " << i << ": " << solve(i) << " formas\n";
    }

    return 0;
}

