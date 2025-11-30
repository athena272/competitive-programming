#include <bits/stdc++.h>
using namespace std;

/**
 * Template básico para problemas de grafos
 * Inclui representação e funções básicas de DFS e BFS
 */

vector<vector<int>> graph;
int n, m;  // n = vértices, m = arestas

/**
 * DFS simples
 */
void dfs(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

/**
 * BFS simples
 */
void bfs(int start) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << " ";
        
        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    graph.resize(n + 1);
    
    // Ler arestas
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // Se grafo não direcionado
    }
    
    // DFS
    vector<bool> visited(n + 1, false);
    cout << "DFS: ";
    dfs(1, visited);
    cout << endl;
    
    // BFS
    cout << "BFS: ";
    bfs(1);
    cout << endl;
    
    return 0;
}

