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
#define M 32768                     // 1e9+7
#define gcd(a, b) __gcd(a, b)            //
#define lcm(a, b) a *b / gcd(a, b)       //
#define memz(a) memset(a, 0, sizeof(a))  //
#define memn(a) memset(a, -1, sizeof(a)) //
ll dis[M+1];
ll inf=10000000000;
vector<ll>graph[M+10];
void bfs()
{
    dis[M]=0;
    dis[0]=0;
    queue<ll>q;
    q.push(0);
    while(q.size())
    {
        ll par=q.front();
        q.pop();
        for(auto child:graph[par])
        {
            if(dis[child]>dis[par]+1)
            {
                dis[child]=dis[par]+1;
                q.push(child);

            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<=M;i++)dis[i]=inf;
    for(int i=0;i<=M;i++)
    {
        graph[(i*2)%M].push_back(i);
        graph[(i+1)%M].push_back(i);
    }
    bfs();
    ll tst;
    cin>>tst;
    
    for(ll test=1;test<=tst;test++)
    {
        //cout<<"Case "<<test<<": ";
        ll n;
        cin>>n;
        cout<<dis[n]<<" ";

    }
    cout<<endl;
}