# Guia Completo de Dynamic Programming (DP) em C++ para Programação Competitiva

## 📚 O que é Dynamic Programming?

**Dynamic Programming (Programação Dinâmica)** é uma técnica de otimização que resolve problemas complexos dividindo-os em subproblemas menores e mais simples, armazenando os resultados para evitar recálculos. É útil quando:

- O problema pode ser dividido em subproblemas sobrepostos
- A solução ótima contém soluções ótimas de subproblemas (propriedade de subestrutura ótima)
- Os subproblemas são calculados repetidamente

## 🎯 Conceitos Fundamentais

### 1. Memoização (Top-Down)

Armazena resultados de subproblemas já calculados para evitar recálculos.

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
long long memo[MAX];

long long fibonacci(int n) {
    // Caso base
    if(n <= 1) return n;
    
    // Se já calculado, retorna o valor armazenado
    if(memo[n] != -1) return memo[n];
    
    // Calcula e armazena
    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
}

int main() {
    memset(memo, -1, sizeof(memo));
    cout << fibonacci(50) << endl;
    return 0;
}
```

### 2. Tabulação (Bottom-Up)

Preenche uma tabela de baixo para cima, resolvendo todos os subproblemas.

```cpp
long long fibonacci(int n) {
    long long dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
```

## 🔑 Padrões Comuns de DP

### 1. DP 1D (Unidimensional)

Problemas com uma única dimensão de estado.

**Exemplo: Escadas**
```cpp
// Quantas formas de subir n degraus (pode pular 1 ou 2 degraus)
int waysToClimb(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // Base: 1 forma de estar no degrau 0
    
    for(int i = 1; i <= n; i++) {
        int waysFromOneStep = (i >= 1) ? dp[i - 1] : 0;
        int waysFromTwoSteps = (i >= 2) ? dp[i - 2] : 0;
        dp[i] = waysFromOneStep + waysFromTwoSteps;
    }
    
    return dp[n];
}
```

### 2. DP 2D (Bidimensional)

Problemas com duas dimensões de estado.

**Exemplo: Grid Paths**
```cpp
// Quantas formas de ir de (0,0) a (n-1, m-1) movendo apenas direita/baixo
int uniquePaths(int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;  // Base: 1 forma de estar na origem
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0) continue;
            
            int waysFromTop = (i > 0) ? dp[i-1][j] : 0;
            int waysFromLeft = (j > 0) ? dp[i][j-1] : 0;
            dp[i][j] = waysFromTop + waysFromLeft;
        }
    }
    
    return dp[n-1][m-1];
}
```

### 3. DP com Prefixos/Sufixos

**Exemplo: Soma Máxima de Subarray**
```cpp
int maxSubarraySum(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    int maxSum = arr[0];
    
    for(int i = 1; i < n; i++) {
        int previousSum = dp[i-1];
        int currentElement = arr[i];
        
        // Continuar subarray anterior ou começar novo
        dp[i] = max(previousSum + currentElement, currentElement);
        maxSum = max(maxSum, dp[i]);
    }
    
    return maxSum;
}
```

### 4. DP com Knapsack

**Exemplo: 0/1 Knapsack**
```cpp
// Maximizar valor sem exceder capacidade
int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        int currentWeight = weights[i-1];
        int currentValue = values[i-1];
        
        for(int w = 0; w <= capacity; w++) {
            int withoutItem = dp[i-1][w];
            int withItem = (w >= currentWeight) 
                ? dp[i-1][w - currentWeight] + currentValue 
                : 0;
            
            dp[i][w] = max(withoutItem, withItem);
        }
    }
    
    return dp[n][capacity];
}
```

### 5. DP com Intervalos

**Exemplo: Matrix Chain Multiplication**
```cpp
int matrixChainOrder(vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // len é o comprimento do intervalo
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            
            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + 
                          dimensions[i] * dimensions[k+1] * dimensions[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    return dp[0][n-1];
}
```

## 🎓 Estratégias para Resolver Problemas de DP

### Passo 1: Identificar o Problema como DP

Sinais de que um problema pode ser resolvido com DP:
- Pede "número de formas", "máximo", "mínimo"
- Tem subproblemas sobrepostos
- Pode ser resolvido recursivamente mas é lento
- Envolve otimização

### Passo 2: Definir o Estado

Pergunte: "O que preciso saber para resolver este subproblema?"

```cpp
// Exemplo: Para calcular dp[i]
// Estado: dp[i] = número de formas de fazer soma i
```

### Passo 3: Definir a Transição

Pergunte: "Como chego ao estado atual a partir de estados anteriores?"

```cpp
// Exemplo: Para fazer soma i, posso ter vindo de i-1, i-2, ..., i-6
dp[i] = dp[i-1] + dp[i-2] + ... + dp[i-6];
```

### Passo 4: Definir o Caso Base

Pergunte: "Qual é o menor caso que posso resolver diretamente?"

```cpp
// Exemplo: Para soma 0, há 1 forma (não fazer nada)
dp[0] = 1;
```

### Passo 5: Implementar

Escolha entre memoização (top-down) ou tabulação (bottom-up).

## ⚡ Otimizações Comuns

### 1. Otimização de Espaço

Se só precisamos de estados anteriores, podemos usar array 1D:

```cpp
// Antes: O(n*m) espaço
vector<vector<int>> dp(n, vector<int>(m));

// Depois: O(m) espaço (se só precisamos da linha anterior)
vector<int> prev(m), curr(m);
```

### 2. Compressão de Estados

```cpp
// Em vez de dp[i][j][k], usar dp[i][j*K + k] se k é limitado
```

### 3. Lazy Evaluation

Calcular apenas os estados necessários.

## 📝 Template Básico de DP

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long solve(int n) {
    // 1. Definir array DP
    vector<long long> dp(n + 1, 0);
    
    // 2. Caso base
    dp[0] = 1;  // Ajustar conforme problema
    
    // 3. Preencher DP
    for(int currentState = 1; currentState <= n; currentState++) {
        // 4. Calcular transições
        for(int previousState = 0; previousState < currentState; previousState++) {
            if(/* condição válida */) {
                long long waysFromPrevious = dp[previousState];
                dp[currentState] = (dp[currentState] + waysFromPrevious) % MOD;
            }
        }
    }
    
    // 5. Retornar resposta
    return dp[n];
}
```

## 🚀 Problemas Clássicos

### 1. Fibonacci
- Estado: `dp[i]` = i-ésimo número de Fibonacci
- Transição: `dp[i] = dp[i-1] + dp[i-2]`

### 2. Coin Change (Contagem)
- Estado: `dp[i]` = número de formas de fazer soma i
- Transição: `dp[i] += dp[i - coin]` para cada moeda

### 3. Longest Increasing Subsequence (LIS)
- Estado: `dp[i]` = comprimento da LIS terminando em i
- Transição: `dp[i] = max(dp[j] + 1)` para todo j < i onde arr[j] < arr[i]

### 4. Edit Distance
- Estado: `dp[i][j]` = distância entre strings[0..i] e strings[0..j]
- Transição: mínimo entre inserir, deletar, substituir

### 5. Rod Cutting
- Estado: `dp[i]` = máximo valor para comprimento i
- Transição: `dp[i] = max(dp[i], price[j] + dp[i-j])`

## ⚠️ Erros Comuns

1. **Esquecer caso base**: Sempre defina dp[0] ou casos iniciais
2. **Ordem errada de iteração**: Garanta que estados anteriores já foram calculados
3. **Overflow**: Use módulo quando necessário
4. **Índices fora de limites**: Sempre verifique antes de acessar dp[i-k]
5. **Não considerar todas as transições**: Revise todas as possibilidades
6. **Confundir memoização com tabulação**: Escolha uma abordagem e seja consistente

## 💡 Dicas para Competição

1. **Comece com força bruta**: Entenda o problema primeiro
2. **Identifique padrões**: Veja o que se repete
3. **Desenhe exemplos**: Visualize os estados e transições
4. **Use nomes descritivos**: `waysToMakeSum` é melhor que `dp[i]`
5. **Teste com casos pequenos**: Verifique manualmente
6. **Otimize depois**: Primeiro faça funcionar, depois otimize

## 🔍 Debugging

```cpp
// Adicione prints para debugar
void debugDP(vector<long long>& dp) {
    cout << "DP array: ";
    for(int i = 0; i < dp.size(); i++) {
        cout << "dp[" << i << "]=" << dp[i] << " ";
    }
    cout << endl;
}
```

## 📚 Recursos Adicionais

- Pratique problemas progressivos (fácil → médio → difícil)
- Estude soluções de problemas clássicos
- Entenda quando NÃO usar DP (problemas que não têm subestrutura ótima)
- Aprenda a identificar complexidade: O(n), O(n²), O(n³), etc.

