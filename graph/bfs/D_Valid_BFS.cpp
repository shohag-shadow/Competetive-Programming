#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define pb push_back //
#define mp make_pair
#define fi first                         //
#define se second                        //
#define yes cout << "YES" << endl        //
#define no cout << "NO" << endl          //
#define M 1000000007                     // 1e9+7
#define gcd(a, b) __gcd(a, b)            //
#define lcm(a, b) a *b / gcd(a, b)       //
#define memz(a) memset(a, 0, sizeof(a))  //
#define memn(a) memset(a, -1, sizeof(a)) //
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>graph[n+1];
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll arr[n];
    ll vis[n+1]={0};
    for(auto &u:arr)cin>>u;
    ll i=0,j=1;
    vis[1]=1;
    bool valid=true;
    while(i<n)
    {
        vector<ll>v;
        vector<ll>v1;
        for(auto u:graph[arr[i]])
        {
            if(vis[u]==0)v.push_back(u);
        }
        for(ll c=0;c<v.size();c++,j++)
        {
            v1.push_back(arr[j]);
        }
        sort(all(v));
        sort(all(v1));
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=v1[i])
            {
                valid=false;
            }
        }
        if(valid==false)break;
        for(int i=0;i<v.size();i++)vis[v[i]]=1;
        i++;
    }
    if(valid)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}