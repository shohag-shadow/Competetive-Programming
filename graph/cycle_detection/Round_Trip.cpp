#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl        
#define no cout << "NO" << endl          
#define M 1000000007                     
#define lcm(a, b) a *b / gcd(a, b)       
#define memz(a) memset(a, 0, sizeof(a))  
#define memn(a) memset(a, -1, sizeof(a)) 
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
vector<ll>out;
ll dfs(ll node,ll par,vector<ll>graph[],vector<ll>&vis)
{
    if(vis[node]==1)
    {
        out.push_back(node);
        return node;
    }
    vis[node]=1;
    for(auto child:graph[node])
    {
        if(child!=par)
        {
            ll x=dfs(child,node,graph,vis);
            if(x==node)
            {
                out.push_back(node);
                //cout<<node<<" ";
                return 0;
            }
            else if(x==0)
            {
                return 0;
            }
            else if(x!=-1)
            {
                out.push_back(node);
               // cout<<node<<" ";
                return x;
            }
 
        }
        
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll>graph[n+1];
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,-1,graph,vis);
            if(out.size()!=0)
            {
                cout<<out.size()<<endl;
                for(auto u:out)cout<<u<<" ";
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    
}