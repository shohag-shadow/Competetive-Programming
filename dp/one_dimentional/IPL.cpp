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
ll arr[N+22];
ll dp[N+11];
ll func(ll n)
{
    if(n<=0)return 0;
    if(dp[n]!=-1)return dp[n];
    ll ans=INT64_MAX;
    for(int i=1;i<=3;i++)
    {
        ans=min(ans,arr[n]+func(n-i));
    }
    return dp[n]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<=n+1;i++)dp[i]=-1;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    arr[n+1]=0;
    cout<<sum-func(n+1)<<endl;
}