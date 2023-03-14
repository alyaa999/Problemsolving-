#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e5+5;
#define speed ios_base::sync_with_stdio(0); cin.tie(0);
ll arr[N];
int timer ;
int in[N] , low[N];
int vis[N];

void dfs(int node , int par, vector<vector<int>>&graph )
{
    in[node]=low[node]=++timer;

    vis[node]=true;
    for(auto child : graph[node] )
    {
        if(!vis[child])
        {
            dfs(child , node ,graph);
            low[node]=min(low[node] , low[child]);
            if(low[child]>in[node])
                cout << "bridge";


        }
        else if(child != par  )
        {
            low[node]=min(low[node] ,in[child]);
        }
    }
}
int main()
{
    speed;
    int n ,m ;
    cin>>n>>m;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u , v ;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1 , -1 , graph);

    return 0;
}
