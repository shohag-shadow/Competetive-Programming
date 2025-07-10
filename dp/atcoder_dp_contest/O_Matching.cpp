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
ll m[22][22];
ll dp[23][3000000];
ll func(ll i,ll n,ll x)
{
    if(i<0)return 1;
    if(dp[n][x]!=-1)return dp[n][x];
    ll ans=0;
    for(int j=0;j<n;j++)
    {
        if((((1ll<<j)&x)==0)&&(m[i][j]))
        {
            ans=(ans+func(i-1,n,(x+(1ll<<j))))%M;
        }
    }
    return dp[n][x]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memn(dp);
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cin>>m[i][j];
    }
    cout<<func(n-1,n,0ll)<<endl;
}