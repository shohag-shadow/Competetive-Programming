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
ll dp[3000][3000];
ll func(ll i,ll l,string &s)
{
    if(i==s.size())return 1;
    ll ans=0;
    if(s[i]=='>')
    {
        for(int j=0;j<l;j++)
        {
            ans=ans+func(i+1,j,s);
        }
    }
    else
    {
        ll boro=s.size()-l-i;
        for(int j=0;j<boro;j++)
        {
            ans=ans+func(i+1,j+l,s);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     ans=(ans+func(0,i,s))%M;
    // }

    ll dp[n+1][n+1]={0};
    dp[n-1][0]=1;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=1;j<=n;j++)dp[i+1][j]=(dp[i+1][j]+dp[i+1][j-1])%M;

        for(int j=0;j<n-i;j++)
        {
            dp[i][j]=0;
            if(s[i]=='>')
            {
                ll boro=n-j-i;
                if(j+boro-1>=0)dp[i][j]=(dp[i][j]+dp[i+1][j+boro-1])%M;
                if(j!=0)dp[i][j]=(dp[i][j]-dp[i+1][j-1]+M)%M;
            }
            else
            {
                if(j!=0)dp[i][j]=(dp[i][j]+dp[i+1][j-1])%M;
            }
        }

    }
    for(int i=0;i<n;i++)ans=(ans+dp[0][i])%M;
    cout<<ans<<endl;
}