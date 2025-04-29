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
const ll N=3e5+100;
vector<pair<ll,ll>>graph[N];
vector<ll>vis(N,0);
vector<ll>in_time(N);
vector<ll>min_time(N);
ll T=1;
ll find_bridges(ll node ,ll par)
{
    vis[node]=1;
    in_time[node]=T++;
    ll ans=in_time[node];
    for(auto child:graph[node])
    {
        if(vis[child.first]==0)
        {
            ans=min(ans,find_bridges(child.first,node));
        }
        else
        {
            if(child.first!=par)ans=min(ans,in_time[child.first]);
        }
    }
    min_time[node]=ans;
    return ans;
}
vector<ll>visited(N,0);
vector<pair<ll,ll>>bridge_tree[N];
ll group[N];
ll value[N];

void make_tree(ll node,ll v,ll pre,ll par)
{
    visited[node]=1;
    bool flag=true;
    if(min_time[node]>=in_time[node])
    {
        //cout<<node<<endl;
        ll u=++T;
        if(pre!=-1)
        {
            bridge_tree[pre].push_back({u,v});
            bridge_tree[u].push_back({pre,v});
        }
        pre=u;
        flag=false;
    }
    if(flag)value[pre]+=v;
    group[node]=pre;
    for(auto child:graph[node])
    {
        if(visited[child.first]==0)make_tree(child.first,child.second,pre,node);
        else
        {
            if(child.first!=par)value[pre]+=child.second;
        }
    }

}
bool ans=false;
ll a,b;
void dfs(ll node,ll v,ll par)
{
    v+=value[node];
    //cout<<node<<" "<<v<<endl;
    if(node==group[b])
    {
        if(v>0)ans=true;
        return;
    }
    for(auto child:bridge_tree[node])
    {
        if(child.first!=par)
        {
            dfs(child.first,v+child.second,node);
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
    for(int i=0;i<m;i++)
    {
        ll a,b,v;
        cin>>a>>b>>v;
        graph[a].push_back({b,v});
        graph[b].push_back({a,v});
    }
    find_bridges(1,-1);
    T=0;
    make_tree(1,0,-1,-1);
    //cout<<endl;
    cin>>a>>b;
    if(group[a]==group[b])
    {
        if(value[group[a]]>0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else
    {
        dfs(group[a],0,-1);
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}