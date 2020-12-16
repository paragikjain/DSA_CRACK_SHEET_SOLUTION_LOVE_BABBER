// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {

    int visited[N];
    vector<int> out;
    for(int i=0;i<N;i++){
        visited[i] = 0;
    }
    visited[0] = 1;
    queue<int> Q;
    Q.push(0);
    
    while(!Q.empty()){
        int tmp = Q.front();
        out.push_back(tmp);
        Q.pop();
        
        for(int i= 0; i<g[tmp].size();i++){
            // cout<<tmp<<": "<<g[tmp][i]<<endl;
            if(visited[g[tmp][i]] == 0){
                visited[g[tmp][i]] = 1;
                 Q.push(g[tmp][i]);
            }
        }
    }
    return out;
}