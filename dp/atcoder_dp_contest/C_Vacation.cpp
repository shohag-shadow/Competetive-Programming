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
ll dp[100010][3];
ll func(ll i,ll pre,ll a[],ll b[],ll c[])
{
    if(i<0)return 0;
    if(pre!=-1&&dp[i][pre]!=-1)return dp[i][pre];
    ll ans=0;
    if(pre!=0)ans=max(ans,func(i-1,0,a,b,c)+a[i]);
    if(pre!=1)ans=max(ans,func(i-1,1,a,b,c)+b[i]);
    if(pre!=2)ans=max(ans,func(i-1,2,a,b,c)+c[i]);
    if(pre!=-1)dp[i][pre]=ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    memn(dp);
    ll a[n],b[n],c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<func(n-1,-1,a,b,c)<<endl;
}