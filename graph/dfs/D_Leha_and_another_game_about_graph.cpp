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
const ll N=300010;
ll root;
vector<pair<ll,ll>>graph[N];
ll vis[N];
ll d[N];
set<ll>ans;
ll dfs(ll root)
{
    if(vis[root]==1)return 1;
    vis[root]=1;
    ll degree=0;
    for(auto child:graph[root])
    {
        ll k=dfs(child.first);
        if(k==0){
            ans.insert(child.second);
            degree++;
        }
    }
    return d[root]==-1||d[root]==degree%2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll root=1;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        if(d[i]==-1)root=i;
    }
    for(int i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
    }
    ll k=dfs(root);
    if(k==0)cout<<-1<<endl;
    else
    {
        cout<<ans.size()<<endl;
        for(auto u:ans)cout<<u<<" ";
        cout<<endl;
    }

}