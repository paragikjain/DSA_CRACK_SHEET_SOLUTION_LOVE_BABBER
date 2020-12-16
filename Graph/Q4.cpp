// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool isCyclic(vector<int> g[], int V)
{
   int visited[V];
   vector<int> parent(V, -1); 
  
   for(int i =0 ;i<V; i++){
       visited[i] = 0;
   }
   queue<int> Q;
  for(int j =0 ;j<V;j++){
      if(visited[j] == 0)
      {
           Q.push(j);
           visited[j] = 1;
           while(!Q.empty()){
               int tmp = Q.front();
               Q.pop();
               for(int i =0;i<g[tmp].size();i++){
                   if(visited[g[tmp][i]] == 0){
                       Q.push(g[tmp][i]);
                       visited[g[tmp][i]] = 1;
                       parent[g[tmp][i]] = tmp;
                   }
                   else if(parent[tmp] != g[tmp][i]){
                       return true;
                   }
               }
           }
      }
  }
   return false;
   
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends