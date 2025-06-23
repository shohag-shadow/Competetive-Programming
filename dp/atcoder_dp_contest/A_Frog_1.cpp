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
ll dp[N];
ll func(ll n,ll arr[])
{
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    ll ans=INT32_MAX;
    if(n>0)ans=min(ans,func(n-1,arr)+abs(arr[n-1]-arr[n]));
    if(n>1)ans=min(ans,func(n-2,arr)+abs(arr[n-2]-arr[n]));
    return dp[n]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    memn(dp);
    ll arr[n];
    for(auto &u:arr)cin>>u;
    cout<<func(n-1,arr)<<endl;
}