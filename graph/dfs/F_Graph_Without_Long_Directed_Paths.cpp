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
const ll N=200010;
vector<pair<ll,ll>>edge;
vector<pair<ll,ll>>graph[N];
ll out[N+10];
ll vis[N];
bool ans;
void dfs(ll source,ll flag)
{
    vis[source]=1;
    out[source]=flag;
    //cout<<source<<" ";
    for(auto child:graph[source])
    {
        if(out[child.first]==flag)ans=false;
        if(vis[child.first]==0)
        {
            dfs(child.first,!flag);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        out[i]=-1;
    }
    ans=true;
    for(int i=0;i<m;i++)
    {
        
        ll a,b;
        cin>>a>>b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
        edge.push_back({a,b});
    }
    dfs(1,1);
    if(ans)
    {
        cout<<"YES"<<endl;
        for(ll i=0;i<m;i++)
        {
            if(out[edge[i].first]==1)cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }
}