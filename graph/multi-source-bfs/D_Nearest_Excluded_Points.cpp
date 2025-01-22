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
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
map<pair<ll,ll>,pair<ll,ll>>ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<ll,ll>>v;
    map<pair<ll,ll>,ll>m;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        v.push_back({a,b});
        m[{a,b}]=1;
    }
    queue<pair<ll,ll>>q;
    for(int i=0;i<n;i++)
    {
        //cout<<v[i].first<<" "<<v[i].second<<" ";
        for(int j=0;j<4;j++)
        {
            ll x=v[i].first+dx[j];
            ll y=v[i].second+dy[j];
            if(m.find({x,y})==m.end())
            {
                q.push({x,y});
                ans[{x,y}]={x,y};
                //cout<<x<<" "<<y<<" ";
            }
        }
        //cout<<endl;
    }
    //cout<<endl<<endl;
    while(q.size())
    {
        pair<ll,ll>par=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            ll x=par.first+dx[i];
            ll y=par.second+dy[i];
            //cout<<x<<" "<<y<<endl;
            if(m.find({x,y})!=m.end())
            {
                if(ans.find({x,y})==ans.end())
                {
                    ans[{x,y}]=ans[par];
                    q.push({x,y});
                    //cout<<x<<" "<<y<<endl;
                }
            }
        }
    }
    //cout<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        pair<ll,ll>p=ans[v[i]];
        cout<<p.first<<" "<<p.second<<endl;
    }

}