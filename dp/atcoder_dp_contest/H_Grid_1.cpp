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
ll dp[1001][1001];
ll func(ll i,ll j,string maze[])
{
    if(i==0&&j==0)return 1;
    if(i<0||j<0)return 0;
    if(maze[i][j]=='#')return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=(func(i-1,j,maze)+func(i,j-1,maze))%M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memn(dp);
    ll n,m;
    cin>>n>>m;
    string maze[n];
    for(int i=0;i<n;i++)cin>>maze[i];
    cout<<func(n-1,m-1,maze)<<endl;
}