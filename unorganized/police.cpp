#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

// Function to perform BFS and find shortest distances from the source
vector<int> bfs(int src, int N, const vector<vector<int>>& adj) {
    vector<int> dist(N, numeric_limits<int>::max());
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == numeric_limits<int>::max()) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

// Helper function for DFS to detect cycle and check cycle length
bool dfs(int u, int p, vector<bool>& visited, vector<int>& depth, int& cycle_length, const vector<vector<int>>& adj) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            cycle_length = depth[u] - depth[v] + 1;
            if (cycle_length >= 4) return true;
        } else {
            depth[v] = depth[u] + 1;
            if (dfs(v, u, visited, depth, cycle_length, adj)) return true;
        }
    }
    return false;
}

// Function to check if there exists a cycle of length >= 4
bool hasCycle(int N, const vector<vector<int>>& adj) {
    vector<bool> visited(N, false);
    vector<int> depth(N, 0);
    int cycle_length = 0;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, depth, cycle_length, adj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, T, P, M;
    cin >> N >> T >> P >> M;

    vector<vector<int>> adj(N);

    for (int i = 0; i < M; ++i) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    vector<int> distFromPolice = bfs(P, N, adj);
    vector<int> distFromThief = bfs(T, N, adj);
    bool cycleExists = hasCycle(N, adj);

    // If the police can't reach the thief and there exists a cycle of length 4 or more
    if (distFromPolice[T] == numeric_limits<int>::max() || (cycleExists && distFromThief[T] <= distFromPolice[T])) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}