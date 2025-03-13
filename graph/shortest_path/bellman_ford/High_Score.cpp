#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
template <class T> using pbds= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl        
#define no cout << "NO" << endl          
#define M 1000000007                     
#define lcm(a, b) a *b / gcd(a, b)       
#define memz(a) memset(a, 0, sizeof(a))  
#define memn(a) memset(a, -1, sizeof(a)) 
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
const ll inf=-10000000000000000;
bool dfs(ll node,ll n,vector<ll>graph[],vector<ll>&vis,vector<bool>&possible)
{
    if(node==n)return possible[n]=true;
    if(vis[node])return possible[node];
    vis[node]=1;
    bool ans=false;
    for(auto child:graph[node])
    {
        ans|=dfs(child,n,graph,vis,possible);
    }
    return possible[node]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pair<pair<ll,ll>,ll>>edge;
    vector<ll>graph[n+1];
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edge.push_back({{a,b},c});
        graph[a].push_back(b);
    }
    vector<ll>dis(n+1,inf);
    dis[1]=0;
    for(int i=1;i<n;i++)
    {
        for(auto e:edge)
        {
            if(dis[e.first.second]<dis[e.first.first]+e.second)
            {
                dis[e.first.second]=dis[e.first.first]+e.second;
            }
        }
    }
    vector<ll>somossa;
    for(int i=0;i<n;i++)
    {
        for(auto e:edge)
        {
            if(dis[e.first.second]<dis[e.first.first]+e.second)
            {
                dis[e.first.second]=dis[e.first.first]+e.second;
                somossa.push_back(e.first.second);
            }
        }
    }
    vector<ll>vis(n+1,0);
    vector<bool>possible(n+1,false);
    dfs(1,n,graph,vis,possible);
    bool ans=true;
    for(auto u:somossa)
    {
        if(possible[u])
        {
            ans=false;
        }
    }
    if(ans)cout<<dis[n]<<endl;
    else cout<<-1<<endl;
}