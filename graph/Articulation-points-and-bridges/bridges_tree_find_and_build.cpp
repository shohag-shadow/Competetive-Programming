#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=300010;
vector<ll>graph[N+100];
vector<ll>dis_time(N+100);
vector<ll>min_time(N+100,INT64_MAX);
vector<ll>vis(N+100,0);
ll t=1;
ll dfs(ll node,ll par)
{
    vis[node]=1;
    dis_time[node]=t;
    t++;
    ll ans=INT64_MAX;
    for(auto child:graph[node])
    {
        if(child==par);
        else if(vis[child]==0)
        {
            ll subans=dfs(child,node);
            ans=min(ans,subans);
        }
        else
        {
            ans=min(ans,dis_time[child]);
        }
    }
    min_time[node]=ans;
    return ans;
}
vector<ll>bridges_tree[N+100];
vector<ll>visited(N+100,0);
void build_tree(ll node,ll pre)
{
    visited[node]=1;
    if(dis_time[node]<=min_time[node])
    {
        ll v=++t;
        if(pre!=-1)
        {
            bridges_tree[pre].push_back(v);
            bridges_tree[v].push_back(pre);
        }
        pre=v;
    }
    for(auto child:graph[node])
    {
        if(visited[child]==0)
        {
            build_tree(child,pre);
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    t=0;
    build_tree(1,-1);
    cout<<endl;
    for(int i=1;i<=t;i++)
    {
        // if(bridges_tree[i].size()==0)break;
        cout<<i<<" : ";
        for(auto u:bridges_tree[i])
        {
            cout<<u<<" ";
        }
        cout<<endl;
    }
}