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
#define M 998244353                     
#define lcm(a, b) a *b / gcd(a, b)       
#define memz(a) memset(a, 0, sizeof(a))  
#define memn(a) memset(a, -1, sizeof(a)) 
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
bool ans;
pair<ll,ll> dfs(ll source,ll flag,vector<ll>graph[],vector<ll>&vis,vector<ll>&out)
{
    vis[source]=1;
    out[source]=flag;
    //cout<<source<<" ";
    
    pair<ll,ll>p={0,0};
    if(flag==0)p.second++;
    else p.first++;
    for(auto child:graph[source])
    {
        if(out[child]==flag)ans=false;
        if(vis[child]==0)
        {
            pair<ll,ll>x=dfs(child,!flag,graph,vis,out);
            p.first+=x.first;
            p.second+=x.second;
        }
    }
    return p;
}
ll binary_expo(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2)ans=(ans*a)%M;
        a=(a*a)%M;
        b/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tst;
    cin>>tst;
    for(ll test=1;test<=tst;test++)
    {
        //cout<<"Case "<<test<<": ";
        ll n,m;
        cin>>n>>m;
        vector<ll>graph[n+2];
        vector<ll>vis(n+1,0);
        for(int i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        ans=1;
        vector<ll>out(n+1,-1);
        ll x=1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                pair<ll,ll>p=dfs(i,0,graph,vis,out);
                ll zero=p.first,one=p.second;
                x=(x*((binary_expo(2,zero)+binary_expo(2,one))%M))%M;
            }
            if(ans==0)break;
        }
        if(ans)
        {
            
            cout<<x<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        
    }
}