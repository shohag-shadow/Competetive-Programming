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
double dp[3010][6010];
double func(ll i,ll k,ll n,double arr[])
{
    if(i<0)
    {
        if(k>0)return 1;
        else return 0;
    }
    if(dp[i][k+n+1]!=-1)return dp[i][k+n+1];
    return dp[i][k+n+1]=func(i-1,k-1,n,arr)*(1-arr[i])+func(i-1,k+1,n,arr)*arr[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=2*n+2;j++)
        {   
            dp[i][j]=-1;
        }
    }
    double arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<setprecision(12)<<fixed<<func(n-1,0,n,arr)<<endl;
}