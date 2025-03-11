#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl        
#define no cout << "NO" << endl          
#define M 1000000007                     
#define lcm(a, b) a *b / gcd(a, b)       
#define memz(a) memset(a, 0, sizeof(a))  
#define memn(a) memset(a, -1, sizeof(a)) 
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>>v;
    for(int i=0;i<k;i++)
    {
        ll x,va;
        cin>>x>>va;
        v.push_back({va,x});
    }
    sort(all(v));
    ll p=0;
    ll ans=0;
    while(p<v.size()&&n>1)
    {

        ll x=__gcd(n,v[p].second);
        ans+=(n-x)*v[p].first;
        p++;
        n=x;
    }
    if(n<=1)cout<<ans<<endl;
    else if(p==v.size())cout<<-1<<endl;
    else cout<<ans+(n-1)*v[p].first<<endl;
}