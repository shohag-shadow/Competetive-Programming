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
ll dp[3001][3001];
ll func(ll i,ll j,string &s,string &s1)
{
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s1[j])return dp[i][j]=func(i-1,j-1,s,s1)+1;
    return dp[i][j]=max(func(i-1,j,s,s1),func(i,j-1,s,s1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s,s1;
    cin>>s>>s1;
    memn(dp);
    ll v=func(s.size()-1,s1.size()-1,s,s1);
    ll i=s.size()-1,j=s1.size()-1;
    string ans;
    while(v)
    {
        if(i>0&&dp[i-1][j]==v)
        {
            i--;
            continue;
        }
        if(j>0&&dp[i][j-1]==v)
        {
            j--;
            continue;
        }
        ans.push_back(s[i]);
        i--;
        j--;
        v--;
    }
    reverse(all(ans));
    cout<<ans<<endl;
}