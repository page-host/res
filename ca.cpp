1. Show the Adjacency Matrix / Adjacency List Representation of a graph.
#include <bits/stdc++.h>
using namespace std;

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

    vector<int> adjList[4];
    adjList[0] = {1,2};
    adjList[1] = {0,2,3};
    adjList[2] = {0,1};
    adjList[3] = {1};

    cout << "\nAdjacency List:\n";
    for(int i=0;i<n;i++){
        cout << i << " -> ";
        for(int v : adjList[i]) cout << v << " ";
        cout << "\n";
    }
    return 0;
}

2. Perform a Breadth First Search Traversal on a given graph.
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> adj[5] = {
        {1,2},{0,3},{0,4},{1},{2}
    };

    vector<int> visited(5,0);
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    cout << "BFS Traversal: ";
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
    vector<int> adj[5] = {
        {1,2},{3},{4},{},{ }
    };

    vector<int> depth(5,-1);
    queue<int> q;

    q.push(0);
    depth[0] = 0;

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

    cout << "Maximum Depth: " << maxDepth;
    return 0;
}


4. Find the Depth first search Traversal on a given graph.

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> adj[5] = {
        {1,2},{3},{4},{},{}
    };

    vector<int> visited(5,0);
    stack<int> st;
    st.push(0);

    cout << "DFS Traversal: ";
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]){
            visited[u] = 1;
            cout << u << " ";
            for(int i = adj[u].size()-1; i>=0; i--){
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
    int n = 5;
    vector<pair<int,int>> adj[5] = {
        {{1,2},{2,4}},
        {{2,1},{3,7}},
        {{4,3}},
        {{4,1}},
        {}
    };

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto e : adj[u]){
            int v = e.first;
            int w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances:\n";
    for(int i=0;i<n;i++){
        cout << "0 -> " << i << " = " << dist[i] << "\n";
    }
    return 0;
}


6. Use Euclidean Algorithm to find the GCD of two given integers.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 48, b = 18;
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    cout << "GCD = " << a;
    return 0;
}


7. Apply Greedy algorithm to solve fractional knapsack problem.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int w[] = {10,20,30};
    int v[] = {60,100,120};
    int n = 3, W = 50;

    vector<pair<double,int>> ratio;
    for(int i=0;i<n;i++){
        ratio.push_back({(double)v[i]/w[i], i});
    }

    sort(ratio.rbegin(), ratio.rend());

    double maxValue = 0;
    for(auto r : ratio){
        int i = r.second;
        if(W >= w[i]){
            W -= w[i];
            maxValue += v[i];
        } else {
            maxValue += r.first * W;
            break;
        }
    }

    cout << "Maximum value: " << maxValue;
    return 0;
}

8. Use Optimal Substructure property to find the maximum number of tasks
that you can take from a given lists of tasks (Each task contains the
following information: Start time, Finish Time)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> tasks = {
        {1,3},{2,5},{4,7},{6,9},{8,10}
    };

    sort(tasks.begin(), tasks.end(),
         [](auto a, auto b){ return a.second < b.second; });

    int count = 1;
    int lastFinish = tasks[0].second;

    for(int i=1;i<tasks.size();i++){
        if(tasks[i].first >= lastFinish){
            count++;
            lastFinish = tasks[i].second;
        }
    }

    cout << "Maximum number of tasks: " << count;
    return 0;
}


9. Given a pattern P and a String S, show the comparisons of Naïve String
Matching Algorithm.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S = "ABABABC";
    string P = "ABAB";

    int n = S.size(), m = P.size();

    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            cout << "Compare " << S[i+j] << " with " << P[j] << "\n";
            if(S[i+j] != P[j]) break;
        }
        if(j == m){
            cout << "Pattern found at index " << i << "\n";
        }
    }
    return 0;
}

10. Use Rabin-Karp Algorithm for String matching, use polynomial rolling hash
as the Hash Function.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S = "ABABABC";
    string P = "ABAB";

    int n = S.size(), m = P.size();
    int base = 31, mod = 1e9+7;

    long long pHash = 0, sHash = 0, power = 1;

    for(int i=0;i<m;i++){
        pHash = (pHash*base + P[i]) % mod;
        sHash = (sHash*base + S[i]) % mod;
        if(i < m-1) power = (power * base) % mod;
    }

    for(int i=0;i<=n-m;i++){
        if(pHash == sHash){
            if(S.substr(i,m) == P){
                cout << "Pattern found at index " << i << "\n";
            }
        }
        if(i < n-m){
            sHash = (sHash - S[i]*power % mod + mod) % mod;
            sHash = (sHash*base + S[i+m]) % mod;
        }
    }
    return 0;
}
