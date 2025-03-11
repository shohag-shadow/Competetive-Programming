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

ll find_parent(ll n,ll par[])
{
    if(par[n]==n)return n;
    else par[n]=find_parent(par[n],par);
}
bool union_set(ll a,ll b,ll par[])
{
    a=find_parent(a,par);
    b=find_parent(b,par);
    if(a==b)return false;
    par[a]=b;
    return true;
}
ll minimum_spanning_tree(vector<pair<ll,pair<ll,ll>>>&graph,vector<pair<ll,ll>>&mst,ll par[])
{
    ll ans=0;
    sort(all(graph));
    for(auto u:graph)
    {
        if(union_set(u.second.first,u.second.second,par))
        {
            ans+=u.first;
            mst.push_back(u.second);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>>graph;
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        graph.push_back({c,{a,b}});
    }
    vector<pair<ll,ll>>mst;
    ll par[n+1];
    for(int i=1;i<=n;i++)par[i]=i;
    ll ans=minimum_spanning_tree(graph,mst,par);
    cout<<ans<<endl;
    for(auto u:mst)cout<<u.first<<" "<<u.second<<endl;
}