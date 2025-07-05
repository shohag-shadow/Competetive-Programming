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
double dp[301][301][301];
double func(ll one,ll two,ll three,double n)
{
    if(one==0&&two==0&&three==0)return 0;
    if(dp[one][two][three]!=-1)return dp[one][two][three];
    double ans=0;
    if(one>0)
    {
        ans+=(one/n)*func(one-1,two,three,n);
    }
    if(two>0)
    {
        ans+=(two/n)*func(one+1,two-1,three,n);
    }
    if(three>0)
    {
        ans+=(three/n)*func(one,two+1,three-1,n);
    }
    if(one+two+three<n)
    {
        ans++;
        ans/=(1-(n-(one+two+three))/n);
    }
    else ans++;
    return dp[one][two][three]=ans;
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
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=n;k++)dp[i][j][k]=-1;
        }
    }
    ll arr[n];
    double one=0,two=0,three=0,m=0;
    for(auto &u:arr)
    {
        cin>>u;
        if(u==1)one++;
        if(u==2)two++;
        if(u==3)three++;
    }
    cout<<fixed<<setprecision(15)<<func(one,two,three,n)<<endl;
}