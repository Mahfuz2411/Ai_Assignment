#include <iostream>
#include <vector>
#include <queue>
#include <functional> // for std::greater

using namespace std;

// Function to perform Best-First Search
void bestFirstSearch(int start, vector<pair<int, int>> g[], int n) {
    // Priority queue to select the edge with the minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // To keep track of visited nodes
    vector<bool> visited(n + 1, false);
    
    // Start from the initial node
    pq.push({0, start});
    
    while (!pq.empty()) {
        // Get the node with the smallest edge weight
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        // If the node is already visited, skip it
        if (visited[node]) continue;
        
        // Mark the node as visited
        visited[node] = true;
        
        // Print the node
        cout << node << " ";
        
        // Push all adjacent nodes to the priority queue
        for (auto &edge : g[node]) {
            int adjNode = edge.first;
            int adjWeight = edge.second;
            
            if (!visited[adjNode]) {
                pq.push({adjWeight, adjNode});
            }
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    
    int start;
    cin >> start; // Read the starting node for BFS
    bestFirstSearch(start, g, n);
    
    return 0;
}
