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
ll dp[3001][3001][2];
ll func(ll l,ll r,bool x,ll arr[])
{
    if(l>r)return 0;
    if(dp[l][r][x]!=-1)return dp[l][r][x];
    ll ans;
    if(x)
    {
        ans=INT64_MIN;
        ans=max(ans,func(l+1,r,!x,arr)+arr[l]);
        ans=max(ans,func(l,r-1,!x,arr)+arr[r]);
    }
    else
    {
        ans=INT64_MAX;
        ans=min(ans,func(l+1,r,!x,arr)-arr[l]);
        ans=min(ans,func(l,r-1,!x,arr)-arr[r]);
        
    }
    //cout<<l<<" "<<r<<" "<<x<<" "<<ans<<endl;
    return dp[l][r][x]= ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memn(dp);
    ll n;
    cin>>n;
    ll arr[n];
    for(auto &u:arr)cin>>u;
    cout<<func(0,n-1,true,arr)<<endl;
   
}