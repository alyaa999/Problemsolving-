#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define pi pair<int,int>
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector <int> adj[200100];
int pa[200100],X[200100],Y[200100],n,m,u,deg[200100];
int F(int x)
{
    if(pa[x]==x)
        return x;
    return pa[x]=F(pa[x]);
}
int main()
{
    go;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        X[i]=x;
        Y[i]=y;
        adj[x].pb(y);
        adj[y].pb(x);
        deg[x]++;
        deg[y]++;
        if(deg[u]<deg[x])
            u=x;
        if(deg[u]<deg[y])
            u=y;
    }
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=0;i<adj[u].size();i++)
    {
        pa[adj[u][i]]=u;
        cout<<u<<" "<<adj[u][i]<<endl;
    }
    for(int i=0;i<m;i++)
    {
        int x=F(X[i]);
        int y=F(Y[i]);
        if(x==y)
            continue;
        pa[x]=y;
        cout<<X[i]<<" "<<Y[i]<<endl;
    }
    return 0;
}
