#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD = 1e9 + 7;

/**
 * Exemplo básico de Dynamic Programming
 * Problema: Dice Combinations (CSES)
 * 
 * Contar o número de formas de construir soma N
 * lançando um dado (valores 1-6) uma ou mais vezes.
 */
ll countWaysToMakeSum(ll targetSum)
{
    // dp[i] = número de formas de fazer soma i
    vector<ll> waysToMakeSum(targetSum + 1, 0);

    // Caso base: 1 forma de fazer soma 0 (não lançar dado)
    waysToMakeSum[0] = 1;

    // Para cada soma de 1 até targetSum
    for (ll currentSum = 1; currentSum <= targetSum; currentSum++)
    {
        // O último dado pode ter sido 1, 2, 3, 4, 5 ou 6
        for (ll diceValue = 1; diceValue <= 6; diceValue++)
        {
            // Verificar se podemos usar este valor de dado
            if (diceValue > currentSum)
                break;

            // Se o último dado foi 'diceValue', então antes
            // precisávamos fazer soma (currentSum - diceValue)
            ll requiredPreviousSum = currentSum - diceValue;
            ll waysFromPreviousSum = waysToMakeSum[requiredPreviousSum];

            // Adicionar as formas ao total
            waysToMakeSum[currentSum] = (waysToMakeSum[currentSum] + waysFromPreviousSum) % MOD;
        }
    }

    return waysToMakeSum[targetSum];
}

int main()
{
    ll N;
    cin >> N;

    cout << countWaysToMakeSum(N) << "\n";

    return 0;
}

