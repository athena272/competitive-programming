# Guia Completo de Stack em C++ para Programação Competitiva

## 📚 O que é Stack?

`stack` é um container adaptador da STL que implementa uma estrutura de dados **LIFO** (Last In, First Out) - o último elemento inserido é o primeiro a ser removido, como uma pilha de pratos.

## 🔧 Declaração

```cpp
#include <stack>

stack<int> s;                    // Pilha de inteiros
stack<string> s;                 // Pilha de strings
stack<pair<int, int>> s;         // Pilha de pares
```

## ✨ Operações Essenciais

### 1. Adicionar Elementos

```cpp
stack<int> s;

s.push(10);        // Adiciona 10 no topo da pilha - O(1)
s.push(20);        // Adiciona 20 no topo
s.push(30);

// Estado: [10, 20, 30] (30 é o topo)
```

### 2. Remover Elementos

```cpp
s.pop();           // Remove o elemento do topo - O(1)
                   // ⚠️ Não retorna o valor! Use top() antes
```

### 3. Acessar Elementos

```cpp
s.top();           // Retorna o elemento do topo (mais recente) - O(1)
                   // ⚠️ Único elemento acessível!
```

### 4. Informações

```cpp
s.size();          // Número de elementos - O(1)
s.empty();         // Retorna true se vazia - O(1)
```

## 🔄 Iteração

**⚠️ IMPORTANTE**: Stack NÃO suporta iteração direta! Você precisa:

```cpp
stack<int> s;
s.push(1);
s.push(2);
s.push(3);

// Forma 1: Esvaziar e processar (ordem reversa)
while(!s.empty()) {
    int elemento = s.top();
    cout << elemento << " ";  // Imprime: 3 2 1
    s.pop();
}

// Forma 2: Copiar para outro container (mantém ordem)
vector<int> vec;
while(!s.empty()) {
    vec.push_back(s.top());
    s.pop();
}
reverse(vec.begin(), vec.end());  // Agora está na ordem original
```

## 🎯 Casos de Uso Comuns

### 1. Parênteses Balanceados

```cpp
bool isBalanced(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if(st.empty()) return false;
            char top = st.top();
            if((c == ')' && top != '(') ||
               (c == ']' && top != '[') ||
               (c == '}' && top != '{')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
```

### 2. Conversão de Expressões (Infixa para Pós-fixa)

```cpp
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    
    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;
        }
        else if(c == '(') {
            s.push(c);
        }
        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Remove '('
        }
        else {
            // Operador: processar precedência
            while(!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}
```

### 3. DFS (Depth-First Search) Iterativo

```cpp
stack<int> s;
vector<bool> visited(n, false);

s.push(start);
visited[start] = true;

while(!s.empty()) {
    int current = s.top();
    s.pop();
    
    // Processar current
    for(int neighbor : graph[current]) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            s.push(neighbor);
        }
    }
}
```

### 4. Histograma - Maior Retângulo

```cpp
int largestRectangle(vector<int> heights) {
    stack<int> s;
    int maxArea = 0;
    
    for(int i = 0; i <= heights.size(); i++) {
        int h = (i == heights.size()) ? 0 : heights[i];
        
        while(!s.empty() && heights[s.top()] > h) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    
    return maxArea;
}
```

### 5. Próximo Maior Elemento

```cpp
vector<int> nextGreaterElement(vector<int> nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && nums[s.top()] < nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    
    return result;
}
```

## ⚡ Dicas para Competição

### 1. Sempre verificar se está vazia antes de acessar

```cpp
if(!s.empty()) {
    int topo = s.top();
    s.pop();
}
```

### 2. Usar pair para armazenar informações adicionais

```cpp
stack<pair<int, int>> s;  // (valor, índice)
s.push({10, 5});
auto [valor, indice] = s.top();
```

### 3. Limpar a pilha rapidamente

```cpp
// Forma 1: Loop
while(!s.empty()) s.pop();

// Forma 2: Trocar com pilha vazia (mais eficiente)
stack<int> empty;
swap(s, empty);
```

### 4. Monotonic Stack

Pilha monotônica é muito útil para problemas de "próximo maior/menor elemento":

```cpp
// Pilha monotônica crescente
stack<int> s;
for(int x : arr) {
    while(!s.empty() && s.top() > x) {
        s.pop();  // Remove elementos maiores
    }
    s.push(x);
}
```

## 🚀 Exemplo Completo

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    
    // Adicionar elementos
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Tamanho: " << s.size() << endl;
    cout << "Topo: " << s.top() << endl;  // 30
    
    // Remover do topo
    s.pop();  // Remove 30
    cout << "Após pop, topo: " << s.top() << endl;  // 20
    
    // Processar todos (ordem reversa)
    cout << "Elementos (do topo para base): ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}
```

## 📝 Complexidade das Operações

- `push()`: **O(1)**
- `pop()`: **O(1)**
- `top()`: **O(1)**
- `size()`, `empty()`: **O(1)**

## ⚠️ Erros Comuns

1. **Acessar top() em pilha vazia**: Sempre verifique `!s.empty()`
2. **Tentar iterar diretamente**: Stack não tem iteradores, use while loop
3. **Esperar que pop() retorne valor**: Pop() não retorna nada, use top() antes
4. **Esquecer que só acessa o topo**: Não é possível acessar elementos do meio
5. **Ordem de processamento**: Lembre-se que processa do topo (mais recente) para base

## 🔀 Stack vs Queue vs Deque

| Estrutura | Ordem | Acesso | Uso |
|-----------|-------|--------|-----|
| `stack` | LIFO | Apenas top | Parênteses, DFS, expressões |
| `queue` | FIFO | Front/back | BFS, simulação de fila |
| `deque` | Ambos | Qualquer posição | Quando precisa de flexibilidade |

## 💡 Problemas Clássicos com Stack

1. **Parênteses balanceados** - Validar expressões
2. **Conversão de expressões** - Infixa, pós-fixa, pré-fixa
3. **Próximo maior/menor elemento** - Monotonic stack
4. **Histograma** - Maior retângulo em histograma
5. **Árvore de expressão** - Construção e avaliação
6. **DFS iterativo** - Busca em profundidade
7. **Reversão** - Reverter string usando stack

