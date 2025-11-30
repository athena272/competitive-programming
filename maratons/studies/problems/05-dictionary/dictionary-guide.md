# Guia Completo de Map/Dictionary em C++ para Programação Competitiva

## 📚 O que é Map?

`map` é um container associativo da STL que armazena pares chave-valor em ordem **ordenada** (por chave). Cada chave é única e mapeia para um valor. É como um dicionário onde você procura uma palavra (chave) e encontra seu significado (valor).

## 🔧 Declaração

```cpp
#include <map>

map<string, int> m;                    // Chave: string, Valor: int
map<int, string> m;                     // Chave: int, Valor: string
map<char, int> m;                       // Chave: char, Valor: int
map<pair<int, int>, int> m;             // Chave: pair, Valor: int
```

## ✨ Operações Essenciais

### 1. Inserir Elementos

```cpp
map<string, int> m;

m["alice"] = 25;           // Inserir ou atualizar - O(log n)
m["bob"] = 30;
m.insert({"charlie", 35}); // Inserir (não atualiza se existir) - O(log n)
m.insert(make_pair("david", 40));

// Usando emplace (mais eficiente)
m.emplace("eve", 45);      // O(log n)
```

### 2. Acessar Elementos

```cpp
int idade = m["alice"];    // Acessa valor - O(log n)
                           // ⚠️ Cria elemento com valor padrão se não existir!

int idade2 = m.at("bob");  // Acessa com verificação - O(log n)
                           // ⚠️ Lança exceção se chave não existir

// Verificar se chave existe antes de acessar
if(m.find("alice") != m.end()) {
    int idade = m["alice"];
}
```

### 3. Verificar Existência

```cpp
if(m.count("alice")) {     // Retorna 0 ou 1 (map não tem duplicatas) - O(log n)
    // Chave existe
}

if(m.find("alice") != m.end()) {  // Retorna iterador - O(log n)
    // Chave existe
    auto it = m.find("alice");
    cout << it->first << " -> " << it->second << endl;
}
```

### 4. Remover Elementos

```cpp
m.erase("alice");          // Remove por chave - O(log n)
m.erase(m.find("bob"));    // Remove por iterador - O(log n)
m.erase(m.begin(), m.end()); // Remove range - O(n)
m.clear();                 // Remove todos - O(n)
```

### 5. Informações

```cpp
m.size();                  // Número de elementos - O(1)
m.empty();                 // Retorna true se vazio - O(1)
```

## 🔄 Iteração

```cpp
map<string, int> m;
m["alice"] = 25;
m["bob"] = 30;
m["charlie"] = 35;

// 1. Range-based for loop (C++11)
for(auto &[chave, valor] : m) {  // C++17 structured bindings
    cout << chave << " -> " << valor << endl;
}

// 2. Range-based for loop (forma tradicional)
for(auto &par : m) {
    cout << par.first << " -> " << par.second << endl;
}

// 3. Iteradores
for(auto it = m.begin(); it != m.end(); it++) {
    cout << it->first << " -> " << it->second << endl;
}

// 4. Iteradores reversos
for(auto it = m.rbegin(); it != m.rend(); it++) {
    cout << it->first << " -> " << it->second << endl;
}
```

## 🎯 Casos de Uso Comuns

### 1. Contagem de Frequência

```cpp
vector<int> arr = {1, 2, 2, 3, 3, 3, 4};
map<int, int> freq;

for(int x : arr) {
    freq[x]++;  // Incrementa contador
}

// freq = {1:1, 2:2, 3:3, 4:1}
for(auto &[num, count] : freq) {
    cout << num << " aparece " << count << " vezes" << endl;
}
```

### 2. Mapeamento de Strings

```cpp
map<string, int> nameToId;
int id = 0;

nameToId["alice"] = id++;
nameToId["bob"] = id++;
nameToId["charlie"] = id++;

// Buscar ID
if(nameToId.count("alice")) {
    cout << "ID de alice: " << nameToId["alice"] << endl;
}
```

### 3. Agrupamento

```cpp
vector<pair<string, int>> students = {
    {"alice", 85}, {"bob", 90}, {"alice", 88}, {"charlie", 85}
};

map<string, vector<int>> grades;

for(auto &[name, grade] : students) {
    grades[name].push_back(grade);
}

// grades["alice"] = [85, 88]
// grades["bob"] = [90]
// grades["charlie"] = [85]
```

### 4. Cache/Memoização

```cpp
map<pair<int, int>, int> memo;

int fibonacci(int n) {
    if(n <= 1) return n;
    
    if(memo.count({n-1, n-2})) {
        return memo[{n-1, n-2}];
    }
    
    int result = fibonacci(n-1) + fibonacci(n-2);
    memo[{n-1, n-2}] = result;
    return result;
}
```

## ⚡ Dicas para Competição

### 1. Cuidado com m[key] criando elementos

```cpp
map<string, int> m;

// ❌ ERRADO - cria elemento com valor 0
if(m["alice"] > 0) {  // m["alice"] = 0 é criado!
    // ...
}

// ✅ CORRETO - verificar existência primeiro
if(m.count("alice") && m["alice"] > 0) {
    // ...
}

// ✅ OU usar find
auto it = m.find("alice");
if(it != m.end() && it->second > 0) {
    // ...
}
```

### 2. Map ordena automaticamente por chave

```cpp
map<int, string> m;
m[3] = "three";
m[1] = "one";
m[2] = "two";

// Ao iterar, ordem será: 1, 2, 3 (não 3, 1, 2)
for(auto &[k, v] : m) {
    cout << k << " ";  // Imprime: 1 2 3
}
```

### 3. Usar lower_bound e upper_bound

```cpp
map<int, int> m;
m[10] = 1;
m[20] = 2;
m[30] = 3;

// Primeira chave >= 15
auto it = m.lower_bound(15);  // it aponta para 20

// Primeira chave > 20
auto it2 = m.upper_bound(20);  // it2 aponta para 30
```

### 4. Comparação de Maps

```cpp
map<string, int> m1, m2;
// ...
if(m1 == m2) {  // Compara todos os pares chave-valor
    cout << "Iguais" << endl;
}
```

## 🆚 Map vs Unordered Map

| Característica | `map` | `unordered_map` |
|----------------|-------|-----------------|
| Ordenação | Ordenado (árvore) | Não ordenado (hash) |
| Complexidade inserção | O(log n) | O(1) média, O(n) pior caso |
| Complexidade busca | O(log n) | O(1) média, O(n) pior caso |
| Iteração | Ordenada | Aleatória |
| Chaves | Qualquer tipo comparável | Tipos com hash |
| Uso | Quando precisa ordem | Quando precisa velocidade |

```cpp
#include <unordered_map>

unordered_map<string, int> um;  // Mais rápido, mas não ordenado
um["zebra"] = 1;
um["apple"] = 2;
// Ordem de iteração não é garantida
```

## 🚀 Exemplo Completo

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> ages;
    
    // Inserir
    ages["alice"] = 25;
    ages["bob"] = 30;
    ages["charlie"] = 35;
    
    // Acessar
    cout << "Idade de alice: " << ages["alice"] << endl;
    
    // Verificar existência
    if(ages.count("david")) {
        cout << "David existe" << endl;
    }
    else {
        cout << "David não existe" << endl;
    }
    
    // Iterar (ordenado por chave)
    cout << "\nTodos os elementos:" << endl;
    for(auto &[name, age] : ages) {
        cout << name << " -> " << age << endl;
    }
    
    // Contagem de frequência
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    map<int, int> freq;
    for(int x : nums) {
        freq[x]++;
    }
    
    cout << "\nFrequências:" << endl;
    for(auto &[num, count] : freq) {
        cout << num << ": " << count << endl;
    }
    
    return 0;
}
```

## 📝 Complexidade das Operações

- `insert()`, `erase()`, `find()`, `count()`, `[]`: **O(log n)**
- `size()`, `empty()`: **O(1)**
- `clear()`: **O(n)**
- Iteração: **O(n)**

## ⚠️ Erros Comuns

1. **m[key] criando elemento**: Use `count()` ou `find()` antes de acessar
2. **Esperar ordem de inserção**: Map ordena por chave, não por ordem de inserção
3. **Usar map quando unordered_map é suficiente**: Unordered_map é mais rápido
4. **Esquecer que chaves são únicas**: Não pode ter chaves duplicadas
5. **Acessar com at() sem verificar**: Pode lançar exceção

## 💡 Problemas Clássicos com Map

1. **Contagem de frequência** - Contar ocorrências
2. **Agrupamento** - Agrupar elementos por chave
3. **Cache/Memoização** - Armazenar resultados computados
4. **Mapeamento bidirecional** - Converter entre tipos
5. **Anagramas** - Agrupar palavras por letras
6. **Two Sum** - Encontrar pares que somam um valor

