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
ll dp[101][100010];
ll func(ll n,ll v,ll wt[],ll val[])
{
    if(v==0)return 0;
    if(n<0)return INT_MAX;
    if(dp[n][v]!=-1)return dp[n][v];
    ll ans=func(n-1,v,wt,val);
    if(val[n]<=v)ans=min(ans,func(n-1,v-val[n],wt,val)+wt[n]);
    return dp[n][v]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,w;
    cin>>n>>w;
    memn(dp);
    ll wt[n];
    ll val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    for(int i=100000;i>=0;i--)
    {
        if(func(n-1,i,wt,val)<=w)
        {
            cout<<i<<endl;
            break;
        }
    }
}