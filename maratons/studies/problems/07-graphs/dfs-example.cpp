#include <bits/stdc++.h>
using namespace std;

/**
 * Exemplo completo de DFS (Depth-First Search)
 * 
 * DFS explora o grafo indo o mais fundo possível
 * antes de voltar (backtracking).
 */

vector<vector<int>> graph;
vector<bool> visited;

/**
 * DFS Recursivo - Implementação mais simples e comum
 */
void dfs(int node) {
    // Marcar nó como visitado
    visited[node] = true;
    cout << node << " ";  // Processar nó (imprimir, contar, etc.)
    
    // Visitar todos os vizinhos não visitados
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

/**
 * DFS Iterativo usando Stack
 */
void dfsIterative(int start) {
    stack<int> s;
    vector<bool> visitedIter(n + 1, false);
    
    s.push(start);
    visitedIter[start] = true;
    
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        
        cout << node << " ";
        
        // Adicionar vizinhos não visitados
        for(int neighbor : graph[node]) {
            if(!visitedIter[neighbor]) {
                visitedIter[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

/**
 * Contar componentes conectados usando DFS
 */
int countComponents(int n) {
    vector<bool> visitedComp(n + 1, false);
    int components = 0;
    
    for(int i = 1; i <= n; i++) {
        if(!visitedComp[i]) {
            dfsComponent(i, visitedComp);
            components++;
        }
    }
    
    return components;
}

void dfsComponent(int node, vector<bool>& visitedComp) {
    visitedComp[node] = true;
    
    for(int neighbor : graph[node]) {
        if(!visitedComp[neighbor]) {
            dfsComponent(neighbor, visitedComp);
        }
    }
}

/**
 * Detectar ciclo em grafo não direcionado
 */
bool hasCycle(int node, int parent, vector<bool>& visitedCycle) {
    visitedCycle[node] = true;
    
    for(int neighbor : graph[node]) {
        if(!visitedCycle[neighbor]) {
            if(hasCycle(neighbor, node, visitedCycle)) {
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

int main() {
    int n, m;  // n vértices, m arestas
    cin >> n >> m;
    
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    
    // Ler arestas (grafo não direcionado)
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    cout << "DFS Recursivo a partir do vértice 1: ";
    dfs(1);
    cout << endl;
    
    // Reset visited para próxima busca
    fill(visited.begin(), visited.end(), false);
    
    cout << "DFS Iterativo a partir do vértice 1: ";
    dfsIterative(1);
    cout << endl;
    
    // Contar componentes
    int components = countComponents(n);
    cout << "Número de componentes conectados: " << components << endl;
    
    // Verificar ciclo
    vector<bool> visitedCycle(n + 1, false);
    bool cycleExists = false;
    for(int i = 1; i <= n; i++) {
        if(!visitedCycle[i]) {
            if(hasCycle(i, -1, visitedCycle)) {
                cycleExists = true;
                break;
            }
        }
    }
    
    if(cycleExists) {
        cout << "O grafo contém ciclo" << endl;
    }
    else {
        cout << "O grafo não contém ciclo (é uma floresta)" << endl;
    }
    
    return 0;
}


