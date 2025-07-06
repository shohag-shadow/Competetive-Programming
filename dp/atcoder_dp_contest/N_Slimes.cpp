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
ll dp[401][401];
ll func(ll l,ll r,ll pref[])
{
    //cout<<l<<" "<<r<<endl;
    if(l==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    ll n=r-l;
    ll ans=INT64_MAX;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,func(l,l+i,pref)+func(l+i+1,r,pref)+pref[r]-pref[l-1]);
    }
    //cout<<l<<" "<<r<<" "<<ans<<endl;
    return dp[l][r]= ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memn(dp);
    ll n;
    cin>>n;
    ll arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    ll pref[n+1];
    pref[0]=0;
    for(int i=1;i<=n;i++)pref[i]=pref[i-1]+arr[i];
    cout<<func(1,n,pref)<<endl;
}