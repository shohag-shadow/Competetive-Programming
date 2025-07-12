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
ll dp[10001][101][2];
ll func(ll i,ll m,bool finish,string &k,ll d)
{
    if(i==k.size())return m==0;
    if(dp[i][m][finish]!=-1)return dp[i][m][finish];
    ll ans=0;
    if(finish==1)
    {
        ll x=k[i]-'0';
        for(int j=0;j<x;j++)
        {
            ans=(ans+func(i+1,(m+j)%d,!finish,k,d))%M;
        }
        ans=(ans+func(i+1,(m+x)%d,finish,k,d))%M;
    }
    else
    {
        for(int j=0;j<=9;j++)
        {
            ans=(ans+func(i+1,(m+j)%d,finish,k,d))%M;
        }
    }
    return dp[i][m][finish]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string k;
    ll d;
    cin>>k>>d;
    memn(dp);
    cout<<(func(0,0,1,k,d)-1+M)%M<<endl;
}