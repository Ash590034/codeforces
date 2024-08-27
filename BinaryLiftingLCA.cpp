#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class LCA {
    long long n; // number of nodes
    long long LOG; // max depth for binary lifting
    vector<vector<long long>> up; // up[i][j] is the 2^j-th ancestor of node i
    vector<long long> depth; // depth[i] is the depth of node i

public:
    LCA(long long n) : n(n) {
        LOG = ceil(log2(n));
        up.assign(n, vector<long long>(LOG + 1, -1));
        depth.resize(n);
    }

    // Adds an undirected edge between nodes u and v
    void addEdge(long long u, long long v, vector<vector<long long>>& adj) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Preprocess the tree to fill the `up` and `depth` arrays
    void preprocess(long long root, const vector<vector<long long>>& adj) {
        dfs(root, root, adj);
    }

    // Returns the LCA of nodes u and v
    long long query(long long u, long long v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        // Lift u up to the same level as v
        for (long long i = LOG; i >= 0; --i) {
            if (depth[u] - (1LL << i) >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        // Lift u and v together until their LCA is found
        for (long long i = LOG; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0]; // parent of u (or v)
    }

private:
    // DFS to setup binary lifting table and calculate depths
    void dfs(long long node, long long parent, const vector<vector<long long>>& adj) {
        up[node][0] = parent; // the first ancestor (parent)
        for (long long i = 1; i <= LOG; ++i) {
            if (up[node][i-1] != -1)
                up[node][i] = up[up[node][i-1]][i-1];
            else
                up[node][i] = -1;
        }
        for (long long neighbor : adj[node]) {
            if (neighbor != parent) {
                depth[neighbor] = depth[node] + 1;
                dfs(neighbor, node, adj);
            }
        }
    }
};

int main() {
    long long n = 9; // Number of nodes
    LCA lca(n);

    vector<vector<long long>> adj(n);
    lca.addEdge(0, 1, adj);
    lca.addEdge(0, 2, adj);
    lca.addEdge(1, 3, adj);
    lca.addEdge(1, 4, adj);
    lca.addEdge(2, 5, adj);
    lca.addEdge(2, 6, adj);
    lca.addEdge(4, 7, adj);
    lca.addEdge(4, 8, adj);

    lca.preprocess(0, adj); // root the tree at node 0

    // Output the LCAs for some pairs
    cout << "LCA of 7 and 8: " << lca.query(7, 8) << endl; // Output: 4
    cout << "LCA of 3 and 5: " << lca.query(3, 5) << endl; // Output: 0
    cout << "LCA of 3 and 4: " << lca.query(3, 4) << endl; // Output: 1
    cout << "LCA of 7 and 5: " << lca.query(7, 5) << endl; // Output: 0

    return 0;
}
