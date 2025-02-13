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
const ll N=100010;
vector<pair<ll,ll>>graph[N];
vector<pair<ll,ll>>edges;
ll tim[N];
ll flag[4*N];
ll vis[N];
bool ans=true;
ll dfs(ll node)
{
    vis[node]=1;
    ll back=INT_MAX;
    for(auto child:graph[node])
    {
        if(vis[child.first]==0)
        {
            if(edges[child.second].first!=node)
            {
                flag[child.second]=1;
            }
            tim[child.first]=tim[node]+1;
            ll x=dfs(child.first);
            if(x>tim[node])
            {
                ans=false;
            }
            back=min(x,back);
        }
        else
        {
            back=min(back,tim[child.first]);
            if(edges[child.second].first==node)
            {
                flag[child.second]=1;
            }
        }
    }
    return back;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
        edges.push_back({a,b});
    }
    tim[1]=0;
    dfs(1);
    //for(int i=1;i<=n;i++)cout<<tim[i]<<" ";
    // cout<<endl;
    if(ans)
    {
        for(int i=0;i<m;i++)
        {
            if(flag[i])cout<<edges[i].second<<" "<<edges[i].first<<endl;
            else cout<<edges[i].first<<" "<<edges[i].second<<endl;
        }
    }
    else
    {
        cout<<0<<endl;
    }
}