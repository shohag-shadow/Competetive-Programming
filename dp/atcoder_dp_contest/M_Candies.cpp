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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(auto &u:arr)cin>>u;
    ll dp[k+1]={0};
    ll pref[k+1];
    for(int i=0;i<=min(arr[0],k);i++)dp[i]=1;
    pref[0]=dp[0];
    for(int i=1;i<=k;i++)pref[i]=(pref[i-1]+dp[i])%M;
    for(int i=1;i<n;i++)
    {
        for(ll j=0;j<=k;j++)
        {
            ll x=min(arr[i],j);
            dp[j]=pref[j];
            if(j-x-1>=0)dp[j]=(dp[j]-pref[j-x-1]+M)%M;
        }
        pref[0]=dp[0];
        for(int i=1;i<=k;i++)pref[i]=(pref[i-1]+dp[i])%M;
    }
    cout<<dp[k]<<endl;
}