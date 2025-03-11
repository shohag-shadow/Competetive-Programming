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
const ll inf=10000000000000000;
ll dijkstra(ll n,vector<pair<ll,ll>>graph[],vector<ll>&s)
{
    ll dis[n+1][1001];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=1000;j++)dis[i][j]=inf;
    }
    dis[1][s[1]]=0;
    set<pair<pair<ll,ll>,ll>>pq;
    pq.insert({{0,s[1]},1});
    while(!pq.empty())
    {
        pair<pair<ll,ll>,ll>parent=*pq.begin();
        pq.erase(pq.begin());
        ll x=min(parent.first.second,s[parent.second]);
        for(auto child:graph[parent.second])
        {
            if(dis[child.first][x]>dis[parent.second][parent.first.second]+x*child.second)
            {
                dis[child.first][x]=dis[parent.second][parent.first.second]+x*child.second;
                pq.insert({{dis[child.first][x],x},child.first});
            }
        }
    }
    ll ans=inf;
    for(int i=1;i<=1000;i++)ans=min(ans,dis[n][i]);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,ll>>graph[n+1];
        for(int i=0;i<m;i++)
        {
            ll a,b,v;
            cin>>a>>b>>v;
            graph[a].push_back({b,v});
            graph[b].push_back({a,v});
        }
        vector<ll>dis(n+1,100000000000000000);
        vector<ll>par(n+1,-1);
        vector<ll>s(n+1);
        for(int i=1;i<=n;i++)cin>>s[i];
        cout<<dijkstra(n,graph,s)<<endl;
    }
}