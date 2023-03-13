#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define F first
#define pb push_back
#define S second
#define er erase
#define fi find
#define in insert
#define pi pair<int,int>
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int vis[300100],n,m,sum,Sum,odd,even;
ll mod=998244353,ans,two[300100];
bool ok;
vector <int> adj[300100];
void dfs(int i,int color)
{
    if(vis[i]==Sum-color)
    {
        ok=0;
        return;
    }
    if(vis[i]==color)
        return;
    odd+=(color==sum);
    even+=(color!=sum);
    vis[i]=color;
    for(int j=0;j<adj[i].size();j++)
        dfs(adj[i][j],Sum-color);
}
int main()
{
    go;
    int t;
    cin>>t;
    two[0]=1;
    for(ll i=1;i<=3e5;i++)
        two[i]=(two[i-1]*2)%mod;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=n;i++)
            adj[i].clear();
        ans=1;
        sum+=100;
        Sum=sum+sum+1;
        for(int i=0,x,y;i<m;i++)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]!=sum&&vis[i]!=sum+1)
            {
                ok=1;
                even=odd=0;
                dfs(i,sum);
                if(!ok)
                break;
                ans*=(two[even]+two[odd])%mod;
                ans%=mod;
            }
        }
        ok?cout<<ans%mod<<endl:cout<<0<<endl;
    }
    return 0;
}
Beautiful Graph
