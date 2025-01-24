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
const ll N=2510;
vector<ll>graph[N];
ll vis[N];

ll bfs(ll source,ll des)
{
    vector<ll>dis(N+1,M);
    vis[source]=1;
    dis[source]=0;
    queue<ll>q;
    q.push(source);
    while(q.size())
    {
        ll par=q.front();
        q.pop();
        for(auto child:graph[par])
        {
            if(par==source&&child==des);
            else if(dis[child]>dis[par]+1)
            {
                dis[child]=dis[par]+1;
                if(child==des)return dis[child]+1;
                q.push(child);
            }
        }
    }
    return M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>edges;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.push_back({a,b});
    }
    ll ans=M;
    for(int i=1;i<=m;i++)
    {
        ans=min(ans,bfs(edges[i].first,edges[i].second));
    }
    if(ans==M)cout<<-1<<endl;
    else cout<<ans<<endl;
}