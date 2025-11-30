# CSES - Dice Combinations - Explicação Detalhada

## 📋 Problema

**Tarefa**: Contar o número de formas de construir a soma N lançando um dado uma ou mais vezes. Cada lançamento produz um resultado entre 1 e 6.

## 🎯 Entendendo o Problema

### Exemplo: N = 3

Queremos fazer soma = 3. As formas possíveis são:

1. **1 dado**: {3} → soma = 3
2. **2 dados**: {1, 2} → soma = 1 + 2 = 3
3. **2 dados**: {2, 1} → soma = 2 + 1 = 3
4. **3 dados**: {1, 1, 1} → soma = 1 + 1 + 1 = 3

**Total: 4 formas**

### Exemplo: N = 4

1. **1 dado**: {4} → soma = 4
2. **2 dados**: {1, 3} → soma = 4
3. **2 dados**: {2, 2} → soma = 4
4. **2 dados**: {3, 1} → soma = 4
5. **3 dados**: {1, 1, 2} → soma = 4
6. **3 dados**: {1, 2, 1} → soma = 4
7. **3 dados**: {2, 1, 1} → soma = 4
8. **4 dados**: {1, 1, 1, 1} → soma = 4

**Total: 8 formas**

## 💡 Ideia da Solução

### Pensamento Recursivo

Para fazer soma = S, qual foi o último dado lançado?

- Se o último dado foi **1**, então antes precisávamos fazer soma = S - 1
- Se o último dado foi **2**, então antes precisávamos fazer soma = S - 2
- Se o último dado foi **3**, então antes precisávamos fazer soma = S - 3
- Se o último dado foi **4**, então antes precisávamos fazer soma = S - 4
- Se o último dado foi **5**, então antes precisávamos fazer soma = S - 5
- Se o último dado foi **6**, então antes precisávamos fazer soma = S - 6

**Conclusão**: O número de formas de fazer soma S é a soma de todas as formas de fazer somas de S-6 até S-1!

### Fórmula de Recorrência

```
dp[S] = dp[S-1] + dp[S-2] + dp[S-3] + dp[S-4] + dp[S-5] + dp[S-6]
```

### Caso Base

- **dp[0] = 1**: Há exatamente 1 forma de fazer soma 0 (não lançar nenhum dado)

## 🔍 Visualização Passo a Passo

Vamos calcular para N = 4:

```
dp[0] = 1  (caso base: não lançar dado)

Para fazer soma = 1:
  - Último dado pode ser 1
  - Precisamos fazer soma = 0 antes
  - dp[1] = dp[0] = 1

Para fazer soma = 2:
  - Último dado pode ser 1 ou 2
  - Precisamos fazer soma = 1 ou 0 antes
  - dp[2] = dp[1] + dp[0] = 1 + 1 = 2

Para fazer soma = 3:
  - Último dado pode ser 1, 2 ou 3
  - Precisamos fazer soma = 2, 1 ou 0 antes
  - dp[3] = dp[2] + dp[1] + dp[0] = 2 + 1 + 1 = 4

Para fazer soma = 4:
  - Último dado pode ser 1, 2, 3 ou 4
  - Precisamos fazer soma = 3, 2, 1 ou 0 antes
  - dp[4] = dp[3] + dp[2] + dp[1] + dp[0] = 4 + 2 + 1 + 1 = 8
```

## 📊 Tabela DP Completa (N = 4)

| Soma | Formas | Explicação |
|------|--------|------------|
| 0 | 1 | Não lançar dado |
| 1 | 1 | {1} |
| 2 | 2 | {2}, {1,1} |
| 3 | 4 | {3}, {1,2}, {2,1}, {1,1,1} |
| 4 | 8 | {4}, {1,3}, {2,2}, {3,1}, {1,1,2}, {1,2,1}, {2,1,1}, {1,1,1,1} |

## 🎓 Por que Funciona?

1. **Subestrutura Ótima**: A solução para soma S depende das soluções para somas menores
2. **Subproblemas Sobrepostos**: Calculamos dp[i] múltiplas vezes na recursão
3. **Memoização/Tabulação**: Armazenamos resultados para evitar recálculos

## ⚠️ Pontos Importantes

1. **Ordem de cálculo**: Devemos calcular dp[0], dp[1], dp[2], ... em ordem crescente
2. **Verificação de limites**: Só somamos dp[i-j] se i >= j
3. **Módulo**: Como números podem ser grandes, usamos módulo 10⁹ + 7
4. **Caso base**: dp[0] = 1 é crucial para a solução funcionar

## 🔄 Comparação: Recursivo vs DP

### Recursivo (Lento - O(6^n))
```cpp
int ways(int n) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    
    int total = 0;
    for(int dice = 1; dice <= 6; dice++) {
        total += ways(n - dice);
    }
    return total;
}
```

### DP (Rápido - O(n))
```cpp
long long ways(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    
    for(int sum = 1; sum <= n; sum++) {
        for(int dice = 1; dice <= 6 && dice <= sum; dice++) {
            dp[sum] = (dp[sum] + dp[sum - dice]) % MOD;
        }
    }
    
    return dp[n];
}
```

## 💻 Código com Variáveis Descritivas

Veja o arquivo `dice-combinations.cpp` para a implementação completa com variáveis bem nomeadas!

