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
const ll N=1e5+100;
vector<ll>graph[N];
ll dp[N][2];
ll func(ll node,ll par,bool c)
{
    if(dp[node][c]!=-1)return dp[node][c];
    ll ans=1;
    for(auto child:graph[node])
    {
        if(child!=par)
        {
            if(c==1)ans=(ans*func(child,node,!c))%M;
            else 
            {
                ans=(ans*(func(child,node,!c)+func(child,node,c)))%M;
            }
        }
    }
    return dp[node][c]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memn(dp);
    ll n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<(func(1,0,0)+func(1,0,1))%M<<endl;
}