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
ll bfs(ll n)
{
    if(n==1)return 1;
    vector<ll>vis(n+1,0);
    pair<ll,ll>parent[n+1];
    queue<ll>q;
    if(n<10)
    {
        q.push(1);
        vis[1]=1;
        parent[1]={0,1};
    }
    else
    {
        q.push(0);
        vis[0]=0;
    }
    ll ans_tot=INT_MAX;
    while(q.size())
    {
        ll par=q.front();
        q.pop();
        for(int i=(par==0);i<=9;i++)
        {
            ll child=(par*10+i)%n;
            cout<<child<<endl;
            if(child==0)
            {
                ll ans=i;
                string out;
                out.push_back(('0'+i));
                while(par!=0)
                {
                    ans+=parent[par].second;
                    out.push_back('0'+parent[par].second);
                    par=parent[par].first;
                }
                reverse(all(out));
                //cout<<out<<endl;
                ans_tot=min(ans_tot,ans);
            }
            else if(vis[child]==0)
            {
                vis[child]=1;
                parent[child]={par,i};
            }
        }
    }
    return ans_tot;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    cout<<bfs(n)<<endl;
}