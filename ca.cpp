1️⃣ s–t path (Is there a path between s and t?)
Algorithm: DFS / BFS
Code (BFS)
bool hasPath(int n, vector<vector<int>>& adj, int s, int t) {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) return true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

Time Complexity
O(V + E)

2️⃣ Shortest s–t path
Algorithm

Unweighted graph → BFS

Weighted graph → Dijkstra

BFS (unweighted)
O(V + E)

Dijkstra (weighted)
O((V + E) log V)

3️⃣ Cycle detection
Algorithm

Undirected graph → DFS with parent

Directed graph → DFS with recursion stack

Undirected graph code
bool dfs(int u, int p, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfs(v, u, adj, vis)) return true;
        } else if (v != p) return true;
    }
    return false;
}

Time Complexity
O(V + E)

4️⃣ Euler cycle
Condition (undirected graph)

Graph is connected

Every vertex has even degree

Code (check only)
bool isEulerCycle(int n, vector<vector<int>>& adj) {
    for (int i = 0; i < n; i++)
        if (adj[i].size() % 2 != 0)
            return false;
    return true;
}

Time Complexity
O(V + E)

5️⃣ Hamilton cycle
Important ❌

NP-Complete

No known polynomial-time algorithm

Backtracking required

Time Complexity
O(n!)


👉 Not expected to write full code in exams

6️⃣ Connectivity
Algorithm: DFS/BFS from one node
bool isConnected(int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    dfs(0, -1, adj, vis);
    for (bool x : vis)
        if (!x) return false;
    return true;
}

Time Complexity
O(V + E)

7️⃣ Biconnectivity
Algorithm

Tarjan’s Algorithm

Uses discovery time + low values

Concept only (exam standard)
O(V + E)


👉 Full code is long and advanced, usually not required

8️⃣ Planarity
Important ❌

Uses Kuratowski’s theorem

Complex algorithms (Hopcroft–Tarjan)

Time Complexity
O(V)


👉 Not expected to implement
Only theory question.

9️⃣ Graph Isomorphism
Important ⚠️

Not known to be P or NP-Complete

Practical algorithms are very complex

Best known
Quasi-polynomial time


👉 No simple code expected

📌 Summary Table (VERY exam-useful)
Problem	Algorithm	Time Complexity	Code Expected?
s–t path	BFS / DFS	O(V+E)	✅ Yes
shortest s–t	BFS / Dijkstra	O(V+E) / O(E log V)	✅ Yes
cycle	DFS	O(V+E)	✅ Yes
Euler cycle	Degree check	O(V+E)	✅ Yes
Hamilton cycle	Backtracking	O(n!)	❌ No
connectivity	DFS / BFS	O(V+E)	✅ Yes
biconnectivity	Tarjan	O(V+E)	⚠️ Rare
planarity	Advanced	O(V)	❌ No
graph isomorphism	Advanced	Quasi-poly	❌ No
