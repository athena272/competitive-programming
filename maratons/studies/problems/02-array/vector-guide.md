# Guia Completo de Vector em C++ para Programação Competitiva

## 📚 O que é Vector?

`vector` é um container dinâmico da STL (Standard Template Library) que funciona como um array que pode crescer ou diminuir automaticamente.

## 🔧 Declaração e Inicialização

```cpp
// Declaração básica
vector<int> vec;                    // Vetor vazio de inteiros
vector<int> vec(10);                // Vetor com 10 elementos (todos 0)
vector<int> vec(10, 5);             // Vetor com 10 elementos, todos iguais a 5
vector<int> vec = {1, 2, 3, 4, 5}; // Inicialização com valores
vector<int> vec{1, 2, 3, 4, 5};    // Outra forma de inicialização

// Copiar outro vetor
vector<int> vec2(vec);              // Cópia de vec
vector<int> vec3(vec.begin(), vec.end()); // Cópia usando iteradores
```

## ✨ Operações Essenciais

### 1. Adicionar Elementos

```cpp
vector<int> vec;

vec.push_back(10);        // Adiciona 10 no final - O(1)
vec.push_back(20);        // Adiciona 20 no final
vec.push_back(30);

// Resultado: vec = {10, 20, 30}
```

### 2. Acessar Elementos

```cpp
vec[0];                   // Acessa primeiro elemento (sem verificação de limites)
vec.at(0);                // Acessa com verificação de limites (lança exceção se inválido)
vec.front();              // Primeiro elemento
vec.back();               // Último elemento
```

### 3. Tamanho e Capacidade

```cpp
vec.size();               // Número de elementos - O(1)
vec.empty();              // Retorna true se vazio - O(1)
vec.capacity();           // Capacidade atual (memória alocada)
vec.resize(10);           // Redimensiona para 10 elementos
vec.resize(10, 5);        // Redimensiona para 10, preenche novos com 5
```

### 4. Remover Elementos

```cpp
vec.pop_back();           // Remove último elemento - O(1)
vec.clear();              // Remove todos os elementos - O(n)
vec.erase(vec.begin());   // Remove elemento na posição (retorna iterador)
vec.erase(vec.begin(), vec.begin() + 3); // Remove range [início, fim)
```

### 5. Inserir Elementos

```cpp
vec.insert(vec.begin(), 5);              // Insere 5 no início - O(n)
vec.insert(vec.begin() + 2, 5);          // Insere 5 na posição 2
vec.insert(vec.begin(), 3, 5);           // Insere 3 cópias de 5 no início
vec.insert(vec.begin(), {1, 2, 3});      // Insere múltiplos valores
```

## 🔄 Iteração

```cpp
vector<int> vec = {1, 2, 3, 4, 5};

// 1. Loop tradicional com índice
for(int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
}

// 2. Range-based for loop (C++11)
for(int x : vec) {
    cout << x << " ";
}

// 3. Com referência (evita cópia)
for(int &x : vec) {
    x *= 2;  // Modifica o elemento
}

// 4. Iteradores
for(auto it = vec.begin(); it != vec.end(); it++) {
    cout << *it << " ";
}

// 5. Iteradores reversos
for(auto it = vec.rbegin(); it != vec.rend(); it++) {
    cout << *it << " ";  // Imprime de trás para frente
}
```

## 🎯 Operações Úteis para Competição

### Ordenação

```cpp
vector<int> vec = {5, 2, 8, 1, 9};

sort(vec.begin(), vec.end());           // Ordena crescente
sort(vec.begin(), vec.end(), greater<int>()); // Ordena decrescente
sort(vec.rbegin(), vec.rend());         // Outra forma de ordenar decrescente

// Ordenar apenas parte do vetor
sort(vec.begin(), vec.begin() + 3);     // Ordena apenas os 3 primeiros
```

### Busca

```cpp
vector<int> vec = {1, 2, 3, 4, 5};

// Binary search (vetor deve estar ordenado)
binary_search(vec.begin(), vec.end(), 3);  // Retorna true/false

// Lower bound (primeiro elemento >= valor)
auto it = lower_bound(vec.begin(), vec.end(), 3);
int index = it - vec.begin();

// Upper bound (primeiro elemento > valor)
auto it2 = upper_bound(vec.begin(), vec.end(), 3);
```

### Outras Operações Úteis

```cpp
vector<int> vec = {1, 2, 3, 4, 5};

// Reverter
reverse(vec.begin(), vec.end());        // vec = {5, 4, 3, 2, 1}

// Rotacionar
rotate(vec.begin(), vec.begin() + 2, vec.end()); // Rotaciona 2 posições

// Encontrar elemento
auto it = find(vec.begin(), vec.end(), 3); // Retorna iterador ou vec.end()

// Contar ocorrências
int count = count(vec.begin(), vec.end(), 3);

// Soma de elementos
int sum = accumulate(vec.begin(), vec.end(), 0);

// Máximo e mínimo
int max_val = *max_element(vec.begin(), vec.end());
int min_val = *min_element(vec.begin(), vec.end());
```

## 📊 Vector Multidimensional

```cpp
// Matriz 2D
vector<vector<int>> matrix(3, vector<int>(4, 0)); // 3x4 inicializada com 0

// Acessar
matrix[0][1] = 5;

// Iterar
for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[i].size(); j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}

// Ou com range-based loop
for(auto &row : matrix) {
    for(int &x : row) {
        cout << x << " ";
    }
    cout << endl;
}
```

## ⚡ Dicas para Competição

### 1. Pré-alocar tamanho quando possível
```cpp
int n;
cin >> n;
vector<int> vec(n);  // Mais eficiente que push_back em loop
for(int i = 0; i < n; i++) {
    cin >> vec[i];
}
```

### 2. Usar reserve() para evitar realocações
```cpp
vector<int> vec;
vec.reserve(1000000);  // Reserva espaço sem criar elementos
```

### 3. Comparação de vetores
```cpp
vector<int> a = {1, 2, 3};
vector<int> b = {1, 2, 3};
if(a == b) {  // Compara elemento por elemento
    cout << "Iguais";
}
```

### 4. Trocar dois vetores
```cpp
vector<int> a = {1, 2, 3};
vector<int> b = {4, 5, 6};
a.swap(b);  // Troca os conteúdos - O(1)
```

### 5. Remover duplicatas (vetor ordenado)
```cpp
sort(vec.begin(), vec.end());
vec.erase(unique(vec.begin(), vec.end()), vec.end());
```

## 🚀 Exemplo Completo

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Ler n elementos
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    // Ordenar
    sort(vec.begin(), vec.end());
    
    // Remover duplicatas
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    // Imprimir
    for(int x : vec) {
        cout << x << " ";
    }
    
    return 0;
}
```

## 📝 Complexidade das Operações

- `push_back()`, `pop_back()`, `back()`, `front()`, `size()`, `empty()`: **O(1)**
- `insert()`, `erase()`: **O(n)** (onde n é o número de elementos após a posição)
- `clear()`, `resize()`: **O(n)**
- `sort()`: **O(n log n)**
- `binary_search()`, `lower_bound()`, `upper_bound()`: **O(log n)**
- Acesso por índice `[]`: **O(1)**

## ⚠️ Erros Comuns

1. **Acessar índice inválido**: `vec[10]` quando `vec.size() == 5`
   - Use `vec.at(10)` para verificação ou verifique o tamanho antes

2. **pop_back() em vetor vazio**: Sempre verifique `!vec.empty()`

3. **Esquecer de ordenar antes de binary_search**: Binary search requer vetor ordenado

4. **Usar push_back() em loop quando o tamanho é conhecido**: Prefira inicializar com tamanho


