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
const ll N=100010;
ll dp[N][2];
bool func(ll k,bool x,ll arr[],ll n)
{
    //cout<<k<<endl;
    if(dp[k][x]!=-1)return dp[k][x];
    bool ans=!x;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>k)break;
        bool subans=func(k-arr[i],!x,arr,n);
        if(subans==x)
        {
            ans=x;
            break;
        }
    }
    return dp[k][x]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<=k;i++)
    {
        dp[i][0]=-1;
        dp[i][1]=-1;
    }
    for(auto &u:arr)cin>>u;
    if(func(k,true,arr,n))cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}