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
int arr[18][18];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cin>>arr[i][j];
    }
    pair<ll,ll>dp[(1ll<<n)];
    ll m=(1ll<<n);
    dp[0]={0,0};
    for(ll mask=1;mask<m;mask++)
    {
        dp[mask]={INT64_MIN,0};
        for(int bit=0;bit<n;bit++)
        {
            if((mask>>bit)&1)
            {
                ll new_mask=(mask^(1ll<<bit));
                if(dp[mask].first<=dp[new_mask].first)
                {
                    dp[mask]={dp[new_mask].first,(1ll<<bit)};
                }
                ll score=0;
                for(int j=0;j<n;j++)
                {
                    if((dp[new_mask].second>>j)&1)
                    {
                        score+=arr[bit][j];
                    }
                }
                if(dp[mask].first<=dp[new_mask].first+score)
                {
                    dp[mask]={dp[new_mask].first+score,(dp[new_mask].second|(1ll<<bit))};
                }
            }
        }
    }
    cout<<dp[(1ll<<n)-1].first<<endl;
}