# Guia Completo de Queue em C++ para Programação Competitiva

## 📚 O que é Queue?

`queue` é um container adaptador da STL que implementa uma estrutura de dados **FIFO** (First In, First Out) - o primeiro elemento inserido é o primeiro a ser removido, como uma fila de pessoas.

## 🔧 Declaração

```cpp
#include <queue>

queue<int> q;                    // Fila de inteiros
queue<string> q;                 // Fila de strings
queue<pair<int, int>> q;         // Fila de pares
```

## ✨ Operações Essenciais

### 1. Adicionar Elementos

```cpp
queue<int> q;

q.push(10);        // Adiciona 10 no final da fila - O(1)
q.push(20);        // Adiciona 20 no final
q.push(30);

// Estado: [10, 20, 30] (10 é o primeiro, 30 é o último)
```

### 2. Remover Elementos

```cpp
q.pop();           // Remove o primeiro elemento (front) - O(1)
                   // ⚠️ Não retorna o valor! Use front() antes
```

### 3. Acessar Elementos

```cpp
q.front();         // Retorna o primeiro elemento (mais antigo) - O(1)
q.back();          // Retorna o último elemento (mais recente) - O(1)
```

### 4. Informações

```cpp
q.size();          // Número de elementos - O(1)
q.empty();         // Retorna true se vazia - O(1)
```

## 🔄 Iteração

**⚠️ IMPORTANTE**: Queue NÃO suporta iteração direta! Você precisa:

```cpp
queue<int> q;
q.push(1);
q.push(2);
q.push(3);

// Forma 1: Esvaziar e processar
while(!q.empty()) {
    int elemento = q.front();
    cout << elemento << " ";
    q.pop();  // Remove após processar
}

// Forma 2: Copiar para outro container
vector<int> vec;
while(!q.empty()) {
    vec.push_back(q.front());
    q.pop();
}
// Agora pode iterar sobre vec
```

## 🎯 Casos de Uso Comuns

### 1. BFS (Breadth-First Search)

```cpp
queue<int> q;
vector<bool> visited(n, false);

q.push(start);
visited[start] = true;

while(!q.empty()) {
    int current = q.front();
    q.pop();
    
    // Processar current
    for(int neighbor : graph[current]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}
```

### 2. Simulação de Fila

```cpp
queue<int> fila;
int n;
cin >> n;

for(int i = 0; i < n; i++) {
    string comando;
    cin >> comando;
    
    if(comando == "push") {
        int x;
        cin >> x;
        fila.push(x);
    }
    else if(comando == "pop") {
        if(!fila.empty()) {
            cout << fila.front() << endl;
            fila.pop();
        }
    }
    else if(comando == "front") {
        if(!fila.empty()) {
            cout << fila.front() << endl;
        }
    }
}
```

### 3. Processamento em Níveis (Level Order)

```cpp
queue<TreeNode*> q;
q.push(root);

while(!q.empty()) {
    int levelSize = q.size();
    
    for(int i = 0; i < levelSize; i++) {
        TreeNode* node = q.front();
        q.pop();
        
        // Processar node
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}
```

## ⚡ Dicas para Competição

### 1. Sempre verificar se está vazia antes de acessar

```cpp
if(!q.empty()) {
    int primeiro = q.front();
    q.pop();
}
```

### 2. Usar pair para armazenar informações adicionais

```cpp
queue<pair<int, int>> q;  // (valor, índice) ou (x, y) para grid
q.push({10, 5});
auto [valor, indice] = q.front();
```

### 3. Limpar a fila rapidamente

```cpp
// Forma 1: Loop
while(!q.empty()) q.pop();

// Forma 2: Trocar com fila vazia (mais eficiente)
queue<int> empty;
swap(q, empty);
```

### 4. Priority Queue vs Queue

- `queue`: FIFO (primeiro a entrar, primeiro a sair)
- `priority_queue`: Sempre remove o maior/menor elemento

## 🚀 Exemplo Completo

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    
    // Adicionar elementos
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Tamanho: " << q.size() << endl;
    cout << "Primeiro: " << q.front() << endl;
    cout << "Último: " << q.back() << endl;
    
    // Processar todos
    cout << "Elementos: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}
```

## 📝 Complexidade das Operações

- `push()`: **O(1)**
- `pop()`: **O(1)**
- `front()`, `back()`: **O(1)**
- `size()`, `empty()`: **O(1)**

## ⚠️ Erros Comuns

1. **Acessar front()/back() em fila vazia**: Sempre verifique `!q.empty()`
2. **Tentar iterar diretamente**: Queue não tem iteradores, use while loop
3. **Esperar que pop() retorne valor**: Pop() não retorna nada, use front() antes
4. **Confundir front() e back()**: Front é o primeiro (mais antigo), back é o último (mais recente)

## 🔀 Queue vs Deque vs Priority Queue

| Estrutura | Ordem | Acesso | Uso |
|-----------|-------|--------|-----|
| `queue` | FIFO | Apenas front/back | BFS, simulação de fila |
| `deque` | Ambos | Qualquer posição | Quando precisa de flexibilidade |
| `priority_queue` | Maior/Menor | Apenas top | Dijkstra, algoritmos gananciosos |

