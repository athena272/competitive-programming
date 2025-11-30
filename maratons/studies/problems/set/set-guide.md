# Guia Completo de Set em C++ para Programação Competitiva

## 📚 O que é Set?

`set` é um container associativo da STL que armazena elementos **únicos** em ordem **ordenada**. É como um conjunto matemático onde cada elemento aparece apenas uma vez e os elementos são mantidos ordenados.

## 🔧 Declaração

```cpp
#include <set>

set<int> s;                    // Set de inteiros
set<string> s;                 // Set de strings
set<pair<int, int>> s;         // Set de pares
```

## ✨ Operações Essenciais

### 1. Inserir Elementos

```cpp
set<int> s;

s.insert(10);        // Insere 10 - O(log n)
s.insert(20);
s.insert(10);        // Ignorado (já existe)
s.insert(30);

// Resultado: s = {10, 20, 30} (ordenado e sem duplicatas)
```

### 2. Verificar Existência

```cpp
if(s.count(10)) {    // Retorna 0 ou 1 - O(log n)
    // Elemento existe
}

if(s.find(10) != s.end()) {  // Retorna iterador - O(log n)
    // Elemento existe
    auto it = s.find(10);
    cout << *it << endl;
}
```

### 3. Remover Elementos

```cpp
s.erase(10);         // Remove por valor - O(log n)
s.erase(s.find(20)); // Remove por iterador - O(log n)
s.erase(s.begin(), s.end()); // Remove range - O(n)
s.clear();           // Remove todos - O(n)
```

### 4. Acessar Elementos

```cpp
s.begin();           // Iterador para primeiro elemento (menor)
s.end();             // Iterador após último elemento
s.rbegin();          // Iterador reverso para último elemento (maior)
s.rend();            // Iterador reverso antes do primeiro

// Acessar menor elemento
int menor = *s.begin();

// Acessar maior elemento
int maior = *s.rbegin();
```

### 5. Informações

```cpp
s.size();            // Número de elementos - O(1)
s.empty();           // Retorna true se vazio - O(1)
```

## 🔄 Iteração

```cpp
set<int> s;
s.insert(30);
s.insert(10);
s.insert(20);

// 1. Range-based for loop (C++11) - ordem crescente
for(int x : s) {
    cout << x << " ";  // Imprime: 10 20 30
}

// 2. Iteradores
for(auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
}

// 3. Iteradores reversos (ordem decrescente)
for(auto it = s.rbegin(); it != s.rend(); it++) {
    cout << *it << " ";  // Imprime: 30 20 10
}
```

## 🎯 Casos de Uso Comuns

### 1. Remover Duplicatas

```cpp
vector<int> arr = {1, 2, 2, 3, 3, 3, 4};
set<int> s(arr.begin(), arr.end());

// s = {1, 2, 3, 4} (sem duplicatas e ordenado)
vector<int> unicos(s.begin(), s.end());
```

### 2. Verificar Pertencimento

```cpp
set<int> validos = {1, 2, 3, 5, 7, 11};

int num;
cin >> num;

if(validos.count(num)) {
    cout << "Número válido!" << endl;
}
```

### 3. Manter Elementos Únicos e Ordenados

```cpp
set<int> s;
int n;
cin >> n;

for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);  // Automaticamente ordena e remove duplicatas
}

// s contém elementos únicos e ordenados
```

### 4. Lower Bound e Upper Bound

```cpp
set<int> s = {10, 20, 30, 40, 50};

// Primeiro elemento >= 25
auto it = s.lower_bound(25);  // it aponta para 30
cout << *it << endl;

// Primeiro elemento > 30
auto it2 = s.upper_bound(30);  // it2 aponta para 40
cout << *it2 << endl;

// Encontrar elemento mais próximo
int target = 27;
auto it3 = s.lower_bound(target);
if(it3 != s.end()) {
    cout << "Elemento mais próximo: " << *it3 << endl;
}
```

### 5. Operações de Conjunto

```cpp
set<int> a = {1, 2, 3, 4};
set<int> b = {3, 4, 5, 6};

// Interseção (elementos em ambos)
set<int> intersecao;
set_intersection(a.begin(), a.end(), 
                 b.begin(), b.end(),
                 inserter(intersecao, intersecao.begin()));
// intersecao = {3, 4}

// União (elementos em qualquer um)
set<int> uniao;
set_union(a.begin(), a.end(),
          b.begin(), b.end(),
          inserter(uniao, uniao.begin()));
// uniao = {1, 2, 3, 4, 5, 6}

// Diferença (elementos em a mas não em b)
set<int> diferenca;
set_difference(a.begin(), a.end(),
               b.begin(), b.end(),
               inserter(diferenca, diferenca.begin()));
// diferenca = {1, 2}
```

## ⚡ Dicas para Competição

### 1. Set ordena automaticamente

```cpp
set<int> s;
s.insert(30);
s.insert(10);
s.insert(20);

// Ao iterar, ordem será: 10, 20, 30 (não 30, 10, 20)
for(int x : s) {
    cout << x << " ";  // Imprime: 10 20 30
}
```

### 2. Usar lower_bound para busca eficiente

```cpp
set<int> s = {10, 20, 30, 40, 50};

// Encontrar primeiro elemento >= valor
int valor = 25;
auto it = s.lower_bound(valor);
if(it != s.end()) {
    cout << "Encontrado: " << *it << endl;
}
```

### 3. Remover enquanto itera

```cpp
set<int> s = {1, 2, 3, 4, 5};

// ⚠️ CUIDADO: Não use erase() no iterador atual diretamente
for(auto it = s.begin(); it != s.end(); ) {
    if(*it % 2 == 0) {
        it = s.erase(it);  // erase retorna próximo iterador válido
    }
    else {
        ++it;
    }
}
```

### 4. Comparação de Sets

```cpp
set<int> a = {1, 2, 3};
set<int> b = {1, 2, 3};

if(a == b) {  // Compara todos os elementos
    cout << "Iguais" << endl;
}
```

## 🆚 Set vs Unordered Set vs Multiset

| Característica | `set` | `unordered_set` | `multiset` |
|----------------|-------|-----------------|------------|
| Ordenação | Ordenado | Não ordenado | Ordenado |
| Duplicatas | Não permite | Não permite | Permite |
| Complexidade inserção | O(log n) | O(1) média | O(log n) |
| Complexidade busca | O(log n) | O(1) média | O(log n) |
| Iteração | Ordenada | Aleatória | Ordenada |
| Uso | Quando precisa ordem | Quando precisa velocidade | Quando precisa duplicatas |

```cpp
#include <unordered_set>
#include <set>

unordered_set<int> us;  // Mais rápido, mas não ordenado
multiset<int> ms;       // Permite duplicatas
ms.insert(10);
ms.insert(10);  // Agora tem dois 10s
```

## 🚀 Exemplo Completo

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    
    // Inserir elementos
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10);  // Ignorado (duplicata)
    
    cout << "Tamanho: " << s.size() << endl;  // 3
    cout << "Menor: " << *s.begin() << endl;  // 10
    cout << "Maior: " << *s.rbegin() << endl; // 30
    
    // Verificar existência
    if(s.count(20)) {
        cout << "20 está no set" << endl;
    }
    
    // Iterar (ordenado)
    cout << "Elementos: ";
    for(int x : s) {
        cout << x << " ";  // 10 20 30
    }
    cout << endl;
    
    // Remover duplicatas de vetor
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    set<int> unicos(arr.begin(), arr.end());
    
    cout << "Elementos únicos: ";
    for(int x : unicos) {
        cout << x << " ";  // 1 2 3 4 5 6 9
    }
    cout << endl;
    
    // Lower bound
    auto it = unicos.lower_bound(5);
    if(it != unicos.end()) {
        cout << "Primeiro elemento >= 5: " << *it << endl;
    }
    
    return 0;
}
```

## 📝 Complexidade das Operações

- `insert()`, `erase()`, `find()`, `count()`, `lower_bound()`, `upper_bound()`: **O(log n)**
- `size()`, `empty()`: **O(1)**
- `clear()`: **O(n)**
- Iteração: **O(n)**

## ⚠️ Erros Comuns

1. **Esperar ordem de inserção**: Set ordena por valor, não por ordem de inserção
2. **Tentar acessar por índice**: Set não tem `[]`, use iteradores
3. **Esperar duplicatas**: Set não permite duplicatas (use `multiset`)
4. **Usar set quando unordered_set é suficiente**: Unordered_set é mais rápido
5. **Erase durante iteração sem cuidado**: Use o retorno de erase()

## 💡 Problemas Clássicos com Set

1. **Remover duplicatas** - Manter elementos únicos
2. **Verificar pertencimento** - Ver se elemento existe
3. **Manter elementos ordenados** - Ordenação automática
4. **Busca eficiente** - Lower/upper bound
5. **Operações de conjunto** - União, interseção, diferença
6. **Sliding window** - Manter elementos únicos em janela
7. **K-th maior/menor** - Usar iteradores

## 🔍 Exemplo Avançado: K-th Elemento

```cpp
set<int> s = {10, 20, 30, 40, 50};

// Encontrar k-ésimo menor elemento
int k = 3;
auto it = s.begin();
advance(it, k - 1);  // Avança k-1 posições
cout << "K-ésimo menor: " << *it << endl;  // 30

// Encontrar k-ésimo maior elemento
auto it2 = s.rbegin();
advance(it2, k - 1);
cout << "K-ésimo maior: " << *it2 << endl;  // 30
```

