1. Show the Adjacency Matrix / Adjacency List Representation of a graph.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<vector<int>> adj(n);

    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        matrix[u][v] = matrix[v][u] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Adjacency List:\n";
    for(int i = 0; i < n; i++){
        cout << i << " -> ";
        for(int v : adj[i]) cout << v << " ";
        cout << "\n";
    }
    return 0;
}

2. Perform a Breadth First Search Traversal on a given graph.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cin >> src;

    vector<int> visited(n, 0);
    queue<int> q;

    visited[src] = 1;
    q.push(src);

    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    return 0;
}

3. Find the maximum depth from the source node to any node in a given
graph.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int src;
    cin >> src;

    vector<int> depth(n, -1);
    queue<int> q;

    depth[src] = 0;
    q.push(src);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(depth[v] == -1){
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    int maxDepth = 0;
    for(int d : depth) maxDepth = max(maxDepth, d);

    cout << maxDepth;
    return 0;
}

4. Find the Depth first search Traversal on a given graph.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cin >> src;

    vector<int> visited(n, 0);
    stack<int> st;
    st.push(src);

    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]){
            visited[u] = 1;
            cout << u << " ";
            for(int i = adj[u].size() - 1; i >= 0; i--){
                st.push(adj[u][i]);
            }
        }
    }
    return 0;
}


5. Find the shortest path from a source to any given node using single source
shortest path algorithms.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto p : adj[u]){
            int v = p.first;
            int w = p.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    return 0;
}

6. Use Euclidean Algorithm to find the GCD of two given integers.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    cout << a;
    return 0;
}


7. Apply Greedy algorithm to solve fractional knapsack problem.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
    }

    vector<pair<double,int>> ratio;
    for(int i = 0; i < n; i++){
        ratio.push_back({(double)value[i] / weight[i], i});
    }

    sort(ratio.rbegin(), ratio.rend());

    double maxValue = 0;
    for(auto r : ratio){
        int i = r.second;
        if(W >= weight[i]){
            W -= weight[i];
            maxValue += value[i];
        } else {
            maxValue += r.first * W;
            break;
        }
    }

    cout << maxValue;
    return 0;
}


8. Use Optimal Substructure property to find the maximum number of tasks
that you can take from a given lists of tasks (Each task contains the
following information: Start time, Finish Time)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> tasks(n);
    for(int i = 0; i < n; i++){
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end(),
         [](auto a, auto b){ return a.second < b.second; });

    int count = 1;
    int lastFinish = tasks[0].second;

    for(int i = 1; i < n; i++){
        if(tasks[i].first >= lastFinish){
            count++;
            lastFinish = tasks[i].second;
        }
    }

    cout << count;
    return 0;
}


9. Given a pattern P and a String S, show the comparisons of Naïve String
Matching Algorithm.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, P;
    cin >> S >> P;

    int n = S.size(), m = P.size();

    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(S[i + j] != P[j]) break;
        }
        if(j == m){
            cout << i << " ";
        }
    }
    return 0;
}


10. Use Rabin-Karp Algorithm for String matching, use polynomial rolling hash
as the Hash Function.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, P;
    cin >> S >> P;

    int n = S.size(), m = P.size();
    int base = 31, mod = 1000000007;

    long long pHash = 0, sHash = 0, power = 1;

    for(int i = 0; i < m; i++){
        pHash = (pHash * base + P[i]) % mod;
        sHash = (sHash * base + S[i]) % mod;
        if(i < m - 1) power = (power * base) % mod;
    }

    for(int i = 0; i <= n - m; i++){
        if(pHash == sHash){
            if(S.substr(i, m) == P){
                cout << i << " ";
            }
        }
        if(i < n - m){
            sHash = (sHash - S[i] * power % mod + mod) % mod;
            sHash = (sHash * base + S[i + m]) % mod;
        }
    }
    return 0;
}




@@ -1,601 +1,314 @@
1️⃣ s–t path (Is there a path between s and t?)
Algorithm: DFS / BFS
Code (BFS)
bool hasPath(int n, vector<vector<int>>& adj, int s, int t) {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
1. Show the Adjacency Matrix / Adjacency List Representation of a graph.
#include <bits/stdc++.h>
using namespace std;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) return true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
int main() {
    int n = 4;
    int adjMatrix[4][4] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,0},
        {0,1,0,0}
    };

    cout << "Adjacency Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    return false;
}

Time Complexity
O(V + E)

2️⃣ Shortest s–t path
Algorithm

Unweighted graph → BFS

Weighted graph → Dijkstra
    vector<int> adjList[4];
    adjList[0] = {1,2};
    adjList[1] = {0,2,3};
    adjList[2] = {0,1};
    adjList[3] = {1};

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
    cout << "\nAdjacency List:\n";
    for(int i=0;i<n;i++){
        cout << i << " -> ";
        for(int v : adjList[i]) cout << v << " ";
        cout << "\n";
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
    return 0;
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



