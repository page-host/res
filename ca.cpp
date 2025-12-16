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






































knapsack:
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    double t1=(double)p1.first/p1.second;
    double t2=(double)p2.first/p2.second;
    return t1>t2;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>>ar(n);
    for (int i=0;i<n;i++)
    {
        cin >> ar[i].first >> ar[i].second;
    }
    int w;
    cin >> w;
    sort(ar.begin(),ar.end(),cmp);
    double ans=0.0;
    for (int i=0;i<n;i++)
    {
        if(ar[i].second<=w)
        {
            ans+=ar[i].first;
            w-=ar[i].second;
            continue;
        }
        double s=(double)ar[i].first/ar[i].second;
        ans+=s*w;
        break;
    }
    cout << ans << endl;
}




Huffman:
#include <bits/stc++.h>
using namespace std;

// A Tree node
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        // highest priority item has lowest frequency
        return l->freq > r->freq;
    }
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
            unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] =='0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string text)
{
    // count frequency of appearance of each character
    // and store it in a map
    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of
    // Huffman tree;
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1)
    {
        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to root of Huffman Tree
    Node* root = pq.top();

    // traverse the Huffman Tree and store Huffman Codes
    // in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are :\n" << '\n';
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nOriginal string was :\n" << text << '\n';

    // print encoded string
    string str = "";
    for (char ch: text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n" << str << '\n';

    // traverse the Huffman Tree again and this time
    // decode the encoded string
    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
}

// Huffman coding algorithm
int main()
{
    string text = "Huffman coding is a data compression algorithm.";

    buildHuffmanTree(text);

    return 0;
}



activity selection : 
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    return p1.second<p2.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(),cmp);

    int count = 1;
    int last_finish = a[0].second;

    for (int i = 1; i < n; i++) {
        if (a[i].first >= last_finish) {
            count++;
            last_finish = a[i].second;
        }
    }

    cout << count << endl;
    return 0;
}



BFS:
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // number of nodes and edges

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment out this line if graph is directed
    }

    int start;
    cin >> start;

    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // process node

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return 0;
}


DFS:
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // number of vertices and edges

    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment out if directed
    }

    vector<bool> visited(n,false);
    stack<int> s;

    int start;
    cin >> start;
    s.push(start);

    while(!s.empty()){
        int u = s.top(); s.pop();
        if(visited[u]) continue;
        visited[u] = true;
        cout << u << " "; // process node

        // push neighbors
        for(int i=adj[u].size()-1; i>=0; i--){
            int v = adj[u][i];
            if(!visited[v]) s.push(v);
        }
    }

    cout << endl;
    return 0;
}



topological sort : 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // number of nodes and edges

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // edge u -> v
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    if ((int)topo.size() != n) {
        cout << "Graph has a cycle, topological sort not possible.\n";
    } else {
        for (int x : topo) cout << x << " ";
    }

    return 0;
}



floyd-warshall:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // number of vertices and edges

    const long long INF = 1e15;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        // For undirected graph, also:
        // dist[v][u] = w;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}



