#include <bits/stdc++.h>
using namespace std;

/**
 * Exemplo completo de BFS (Breadth-First Search)
 * 
 * BFS explora o grafo nível por nível,
 * garantindo caminho mais curto em grafos não ponderados.
 */

vector<vector<int>> graph;

/**
 * BFS básico - Explora todos os vértices alcançáveis
 */
void bfs(int start, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    q.push(start);
    visited[start] = true;
    
    cout << "BFS a partir do vértice " << start << ": ";
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << " ";
        
        // Visitar todos os vizinhos não visitados
        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

/**
 * BFS com cálculo de distâncias
 * Retorna distância de start até todos os outros vértices
 */
vector<int> bfsWithDistance(int start, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> distance(n + 1, -1);
    
    q.push(start);
    visited[start] = true;
    distance[start] = 0;
    
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
    
    return distance;
}

/**
 * Encontrar caminho mais curto entre dois vértices
 */
vector<int> shortestPath(int start, int end, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        if(node == end) {
            break;  // Encontrou o destino
        }
        
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

/**
 * BFS em níveis (Level Order)
 * Processa todos os vértices de um nível antes do próximo
 */
void bfsLevels(int start, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> level(n + 1, -1);
    
    q.push(start);
    visited[start] = true;
    level[start] = 0;
    
    while(!q.empty()) {
        int levelSize = q.size();
        int currentLevel = level[q.front()];
        
        cout << "Nível " << currentLevel << ": ";
        
        // Processar todos os vértices do nível atual
        for(int i = 0; i < levelSize; i++) {
            int node = q.front();
            q.pop();
            
            cout << node << " ";
            
            // Adicionar vizinhos do próximo nível
            for(int neighbor : graph[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    level[neighbor] = currentLevel + 1;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
}

/**
 * BFS com múltiplas fontes
 * Útil para problemas como "fogo se espalhando"
 */
vector<int> multiSourceBFS(vector<int>& sources, int n) {
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
    
    return distance;
}

/**
 * Verificar se grafo é bipartido usando BFS
 */
bool isBipartite(int start, int n) {
    queue<int> q;
    vector<int> color(n + 1, -1);  // -1 = não colorido, 0/1 = cores
    
    q.push(start);
    color[start] = 0;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int neighbor : graph[node]) {
            if(color[neighbor] == -1) {
                // Colorir com cor oposta
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            }
            else if(color[neighbor] == color[node]) {
                // Dois vértices adjacentes com mesma cor = não bipartido
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    graph.resize(n + 1);
    
    // Ler arestas (grafo não direcionado)
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // BFS básico
    bfs(1, n);
    
    // BFS com distâncias
    vector<int> distances = bfsWithDistance(1, n);
    cout << "\nDistâncias a partir do vértice 1:" << endl;
    for(int i = 1; i <= n; i++) {
        if(distances[i] != -1) {
            cout << "Vértice " << i << ": distância " << distances[i] << endl;
        }
    }
    
    // Caminho mais curto
    if(n >= 2) {
        vector<int> path = shortestPath(1, n, n);
        cout << "\nCaminho mais curto de 1 até " << n << ": ";
        for(int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    // BFS em níveis
    cout << "\nBFS em níveis:" << endl;
    bfsLevels(1, n);
    
    // Verificar bipartido
    bool bipartite = isBipartite(1, n);
    if(bipartite) {
        cout << "\nO grafo é bipartido" << endl;
    }
    else {
        cout << "\nO grafo não é bipartido" << endl;
    }
    
    return 0;
}


