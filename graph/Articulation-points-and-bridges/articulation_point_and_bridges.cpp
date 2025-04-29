#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=300000;
vector<ll>graph[N+100];
vector<ll>dis_time(N+100);
vector<ll>min_time(N+100,INT_MAX);
vector<ll>vis(N+100,0);
ll t=1;
set<ll>articulation_point;
set<pair<ll,ll>>bridges;
ll root;
ll dfs(ll node,ll par)
{
    vis[node]=1;
    dis_time[node]=t;
    t++;
    ll ans=INT_MAX;
    ll count=0;
    for(auto child:graph[node])
    {
        if(child==par);
        else if(vis[child]==0)
        {
            ll subans=dfs(child,node);
            if(node!=root&&subans>=dis_time[node])
            {
                articulation_point.insert(node);
            }
            if(subans>dis_time[node])
            {
                if(node>child)
                {
                    bridges.insert({child,node});
                }
                else
                {
                    bridges.insert({node,child});
                }
            }
            ans=min(ans,dfs(child,node));
            count++;
        }
        else
        {
            ans=min(ans,dis_time[child]);
        }
    }
    if(node==root&&count>1)
    {
        articulation_point.insert(1);
    }
    min_time[node]=ans;
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    root=1;
    dfs(root,-1);
    cout<<bridges.size()<<endl;
    // cout<<"Bridges:"<<endl;
    // for(auto u:bridges)
    // {
    //     cout<<u.first<<" "<<u.second<<endl;
    // }
    // cout<<"Articulation Points:"<<endl;
    // for(auto u:articulation_point)
    // {
    //     cout<<u<<" ";
    // }
    // cout<<endl;
}