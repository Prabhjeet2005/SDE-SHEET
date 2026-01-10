class Solution {

    void dfs(int node,int timer,int parent,vector<int>&discovery,vector<bool>&visited,vector<int>&low,vector<vector<int>>&adj,vector<vector<int>>&result){

        visited[node] = true;
        discovery[node] = low[node] = timer++;

        for(auto neighbour: adj[node]){
            if(neighbour == parent){
                continue;
            }
            if(!visited[neighbour]){
                dfs(neighbour,timer,node,discovery,visited,low,adj,result);
                low[node] = min(low[node],low[neighbour]);

                if(low[neighbour] > discovery[node]){
                    result.push_back({node,neighbour});
                }
            }
            else{
                //Backedge
                low[node] = min(low[node],discovery[neighbour]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0; i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>discovery(n,-1);
        vector<int>low(n,-1);
        vector<bool>visited(n,false);
        int parent = -1;
        int timer=0;

        vector<vector<int>>result;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i,timer,parent,discovery,visited,low,adj,result);
            }
        }
        return result;
    }
};