#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> graph;

vector<ll> shortestPath(ll start, ll end, ll cidades)
{
    queue<ll> queue;
    vector<bool> visited(cidades + 1, false);
    vector<ll> parent(cidades + 1, -1);

    queue.push(start);
    visited[start] = true;
    while (!queue.empty())
    {
        ll node = queue.front();
        queue.pop();

        if(node == end) break;
        for(ll neighbor : graph[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = node;
                queue.push(neighbor);
            }
        }
    }

    vector<ll> path;
    ll current = end;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ll cidades, estradas;
    cin >> cidades >> estradas;
    graph.resize(cidades + 1);
    for (ll i = 0; i < estradas; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(v);
    }   

    vector<ll> answer;
    answer = shortestPath(1, cidades, cidades);
    
    if(answer.size() > 1)
    {
        cout << answer.size() << endl;
    }
    else
    {
        cout << "MAUS CAMINHOS!" << endl;
    }
}
