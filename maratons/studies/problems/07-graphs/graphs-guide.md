# Guia Completo de Grafos, DFS e BFS em C++ para Programação Competitiva

## 📚 O que são Grafos?

Um **grafo** é uma estrutura de dados que consiste em:
- **Vértices (nós)**: Pontos no grafo
- **Arestas (edges)**: Conexões entre vértices

```
    1 --- 2
    |     |
    3 --- 4
```

## 🔧 Representação de Grafos

### 1. Lista de Adjacência (Mais Comum)

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;  // graph[i] = lista de vértices conectados a i

// Exemplo: Grafo não direcionado
int n = 5;  // número de vértices
graph.resize(n + 1);

// Adicionar aresta entre u e v
graph[u].push_back(v);
graph[v].push_back(u);  // Se não direcionado
```

### 2. Matriz de Adjacência

```cpp
vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));

// Adicionar aresta
adjMatrix[u][v] = 1;  // ou peso se for grafo ponderado
adjMatrix[v][u] = 1;  // Se não direcionado
```

### 3. Lista de Arestas

```cpp
vector<pair<int, int>> edges;  // Lista de pares (u, v)
edges.push_back({u, v});
```

## 🎯 Tipos de Grafos

### Grafo Não Direcionado
```cpp
// Aresta (u, v) = aresta (v, u)
graph[u].push_back(v);
graph[v].push_back(u);
```

### Grafo Direcionado (Digrafo)
```cpp
// Aresta vai apenas de u para v
graph[u].push_back(v);
```

### Grafo Ponderado
```cpp
// Armazenar peso junto com o vértice
vector<vector<pair<int, int>>> weightedGraph;
weightedGraph[u].push_back({v, peso});
```

## 🔍 DFS (Depth-First Search) - Busca em Profundidade

DFS explora o grafo indo o mais fundo possível antes de voltar (backtracking).

### Implementação Recursiva (Mais Simples)

```cpp
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";  // Processar nó
    
    // Visitar todos os vizinhos não visitados
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;  // n vértices, m arestas
    cin >> n >> m;
    
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    
    // Ler arestas
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // Se não direcionado
    }
    
    // DFS a partir do vértice 1
    dfs(1);
    
    return 0;
}
```

### Implementação Iterativa (Usando Stack)

```cpp
void dfsIterative(int start) {
    stack<int> s;
    vector<bool> visited(n + 1, false);
    
    s.push(start);
    visited[start] = true;
    
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        
        cout << node << " ";  // Processar nó
        
        // Adicionar vizinhos não visitados
        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}
```

## 🚀 BFS (Breadth-First Search) - Busca em Largura

BFS explora o grafo nível por nível, visitando todos os vértices a distância 1, depois 2, etc.

### Implementação com Queue

```cpp
void bfs(int start) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> distance(n + 1, -1);
    
    q.push(start);
    visited[start] = true;
    distance[start] = 0;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << " ";  // Processar nó
        
        // Visitar todos os vizinhos não visitados
        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
}
```

## 📊 Comparação: DFS vs BFS

| Característica | DFS | BFS |
|----------------|-----|-----|
| Estrutura | Stack (recursão) | Queue |
| Ordem | Profundidade primeiro | Largura primeiro |
| Caminho mais curto | ❌ Não garante | ✅ Sim (grafo não ponderado) |
| Memória | O(h) altura | O(b) largura |
| Uso | Componentes, ciclos | Caminho mais curto, níveis |

## 🎯 Casos de Uso Comuns

### 1. Contar Componentes Conectados (DFS)

```cpp
int countComponents() {
    vector<bool> visited(n + 1, false);
    int components = 0;
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, visited);
            components++;
        }
    }
    
    return components;
}

void dfs(int node, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}
```

### 2. Caminho Mais Curto (BFS)

```cpp
vector<int> shortestPath(int start, int end) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        if(node == end) break;
        
        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    
    // Reconstruir caminho
    vector<int> path;
    int current = end;
    while(current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    
    return path;
}
```

### 3. Detectar Ciclo (DFS)

```cpp
bool hasCycle(int node, int parent, vector<bool>& visited) {
    visited[node] = true;
    
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            if(hasCycle(neighbor, node, visited)) {
                return true;
            }
        }
        else if(neighbor != parent) {
            // Encontrou aresta para vértice já visitado (não é o pai)
            return true;
        }
    }
    
    return false;
}
```

### 4. Árvore de Busca (DFS Tree)

```cpp
vector<int> parent(n + 1, -1);
vector<int> discoveryTime(n + 1, -1);
vector<int> finishTime(n + 1, -1);
int timer = 0;

void dfsTree(int node) {
    discoveryTime[node] = timer++;
    visited[node] = true;
    
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            parent[neighbor] = node;
            dfsTree(neighbor);
        }
    }
    
    finishTime[node] = timer++;
}
```

### 5. BFS em Níveis (Level Order)

```cpp
void bfsLevels(int start) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> level(n + 1, -1);
    
    q.push(start);
    visited[start] = true;
    level[start] = 0;
    
    while(!q.empty()) {
        int levelSize = q.size();
        
        cout << "Nível " << level[q.front()] << ": ";
        
        for(int i = 0; i < levelSize; i++) {
            int node = q.front();
            q.pop();
            
            cout << node << " ";
            
            for(int neighbor : graph[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    level[neighbor] = level[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
}
```

### 6. DFS para Grafo Direcionado (Topological Sort)

```cpp
vector<int> topoSort;
vector<bool> visited(n + 1, false);

void dfsTopo(int node) {
    visited[node] = true;
    
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfsTopo(neighbor);
        }
    }
    
    topoSort.push_back(node);  // Adiciona após processar todos os filhos
}

// Chamar para todos os nós não visitados
for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
        dfsTopo(i);
    }
}

reverse(topoSort.begin(), topoSort.end());
```

## ⚡ Otimizações e Variações

### 1. DFS com Cores (Detectar Ciclo em Digrafo)

```cpp
// 0 = branco (não visitado)
// 1 = cinza (em processamento)
// 2 = preto (processado)

vector<int> color(n + 1, 0);

bool hasCycleDirected(int node) {
    color[node] = 1;  // Cinza
    
    for(int neighbor : graph[node]) {
        if(color[neighbor] == 1) {
            return true;  // Ciclo encontrado
        }
        if(color[neighbor] == 0 && hasCycleDirected(neighbor)) {
            return true;
        }
    }
    
    color[node] = 2;  // Preto
    return false;
}
```

### 2. BFS com Múltiplas Fontes

```cpp
void multiSourceBFS(vector<int>& sources) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> distance(n + 1, -1);
    
    // Adicionar todas as fontes
    for(int source : sources) {
        q.push(source);
        visited[source] = true;
        distance[source] = 0;
    }
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
}
```

### 3. DFS com Informações Extras

```cpp
struct NodeInfo {
    int discoveryTime;
    int finishTime;
    int parent;
    int depth;
};

vector<NodeInfo> nodeInfo(n + 1);
int timer = 0;

void dfsWithInfo(int node, int parent, int depth) {
    nodeInfo[node].discoveryTime = timer++;
    nodeInfo[node].parent = parent;
    nodeInfo[node].depth = depth;
    
    for(int neighbor : graph[node]) {
        if(neighbor != parent) {
            dfsWithInfo(neighbor, node, depth + 1);
        }
    }
    
    nodeInfo[node].finishTime = timer++;
}
```

## 🚀 Template Completo

```cpp
#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> adj;
    
public:
    Graph(int vertices) : n(vertices) {
        adj.resize(n + 1);
    }
    
    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if(!directed) {
            adj[v].push_back(u);
        }
    }
    
    void dfs(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";
        
        for(int neighbor : adj[start]) {
            if(!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }
    
    void bfs(int start) {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        vector<int> distance(n + 1, -1);
        
        q.push(start);
        visited[start] = true;
        distance[start] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            cout << node << " ";
            
            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }
    }
    
    int shortestDistance(int start, int end) {
        queue<int> q;
        vector<bool> visited(n + 1, false);
        vector<int> distance(n + 1, -1);
        
        q.push(start);
        visited[start] = true;
        distance[start] = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            if(node == end) {
                return distance[node];
            }
            
            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        return -1;  // Não alcançável
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    Graph g(n);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    vector<bool> visited(n + 1, false);
    cout << "DFS: ";
    g.dfs(1, visited);
    cout << endl;
    
    cout << "BFS: ";
    g.bfs(1);
    cout << endl;
    
    return 0;
}
```

## 📝 Complexidade

- **DFS**: O(V + E) onde V = vértices, E = arestas
- **BFS**: O(V + E) onde V = vértices, E = arestas
- **Espaço**: O(V) para visited/distance arrays

## ⚠️ Erros Comuns

1. **Esquecer de marcar como visitado**: Sempre marque antes de adicionar à fila/pilha
2. **Visitar o pai novamente**: Em grafos não direcionados, verifique se neighbor != parent
3. **Não resetar visited**: Se fizer múltiplas buscas, reset o array visited
4. **Ordem errada em BFS**: Marque como visitado ANTES de adicionar à fila
5. **Stack overflow**: Em grafos grandes, use DFS iterativo

## 💡 Problemas Clássicos

1. **Contar componentes conectados** - DFS
2. **Caminho mais curto** - BFS
3. **Detectar ciclo** - DFS
4. **Topological sort** - DFS em digrafo
5. **Bipartite check** - BFS com cores
6. **Árvore geradora** - DFS/BFS
7. **Strongly Connected Components** - DFS duas vezes
8. **Articulation points** - DFS com low values

## 🎓 Dicas para Competição

1. **Use lista de adjacência**: Mais eficiente que matriz
2. **Template pronto**: Tenha um template de DFS/BFS pronto
3. **Pense no problema**: DFS para exploração, BFS para distância
4. **Grafos direcionados**: Cuidado com a direção das arestas
5. **Grafos ponderados**: Use `vector<vector<pair<int, int>>>`


