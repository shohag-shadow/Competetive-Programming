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
const ll N=100000+100;
ll dp[N];
ll func(ll n)
{
    if(n==1)return 0;
    if(dp[n]!=-1)return dp[n];
    ll ans=INT32_MAX;
    if(n%2==0)ans=min(ans,func(n/2)+1);
    if(n%3==0)ans=min(ans,func(n/3)+1);
    ans=min(ans,func(n-1)+1);
    return dp[n]= ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++)dp[i]=-1;
    cout<<func(n)<<endl;
}