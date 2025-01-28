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
void dfs(ll node,ll par,ll j,vector<pair<ll,ll>>graph[],vector<ll>out[])
{
    ll i=0;
    for(auto u:graph[node])
    {
        if(i==j)i++;
        if(u.first!=par)
        {
            out[i].push_back(u.second);
            dfs(u.first,node,i,graph,out);
            i++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<ll,ll>>graph[n+1];
    ll ans=0;
    ll x=0;
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
        if(graph[a].size()>ans)
        {
            ans=graph[a].size();
            x=a;
        }
        if(graph[b].size()>ans)
        {
            ans=graph[b].size();
            x=b;
        }
        
    }
    //cout<<x<<endl;
    cout<<ans<<endl;
    vector<ll>out[ans];
    dfs(x,-1,-1,graph,out);
    for(int i=0;i<ans;i++)
    {
        cout<<out[i].size()<<" ";
        for(auto u:out[i])cout<<u<<" ";
        cout<<endl;
    }

}