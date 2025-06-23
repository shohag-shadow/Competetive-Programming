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
const ll N=1e5+100;
ll dp[N];
ll func(ll n,string &s)
{
    if(n>=s.size())return 1;
    if(dp[n]!=-1)return dp[n];
    ll ans=func(n+1,s);
    if(s[n]=='0')return 0;
    if(s[n]=='1'&&n+1<s.size())ans+=func(n+2,s);
    if(s[n]=='2'&&n+1<s.size()&&s[n+1]<='6')ans+=func(n+2,s);
    return dp[n]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while(cin>>s)
    {
        if(s=="0")break;
        for(int i=0;i<=s.size();i++)dp[i]=-1;
        cout<<func(0,s)<<endl;
    }
}