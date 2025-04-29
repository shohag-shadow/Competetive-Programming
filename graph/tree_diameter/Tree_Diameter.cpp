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
const ll N=200000;
vector<ll>graph[N+100];
vector<ll>dist(N+100,0);
void dfs(ll node,ll par,ll dis)
{
    dist[node]=dis;
    for(auto child:graph[node])
    {
        if(child!=par)
        {
            dfs(child,node,dis+1);
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
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(n>1)dfs(1,-1,0);
    ll s=-1,d=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]>d)
        {
            d=dist[i];
            s=i;
        }
    }
    if(n>1)dfs(s,-1,0);
    d=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]>d)
        {
            d=dist[i];
        }
    }
    cout<<d<<endl;
}