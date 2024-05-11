#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+2;

int n, m;
vector<int> g[N];

void graphInput() {
    cin >> n >> m;
    cout << "Enter the edges (format: u v):\n";
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        // For undirected graph, uncomment the following line
        g[b].push_back(a);
    }
}

void printGraph() {
    for(int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(auto d: g[i]) {
            cout << d << ' ';
        }
        cout << endl;
    }
}

void dfsUtil(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for(int neighbor : g[node]) {
        if(!visited[neighbor]) {
            dfsUtil(neighbor, visited);
        }
    }
}

void dfs(int start) {
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    dfsUtil(start, visited);
    cout << endl;
}

void bfs(int start) {
    vector<bool> visited(n, false);
    queue<int> q;
    cout << "BFS Traversal: ";
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int neighbor : g[node]) {
            if(!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[]){
    graphInput();
    printGraph();
    
    int startNode;
    cout << "Enter the starting node for DFS and BFS: ";
    cin >> startNode;

    dfs(startNode);
    bfs(startNode);

    return 0;
}
