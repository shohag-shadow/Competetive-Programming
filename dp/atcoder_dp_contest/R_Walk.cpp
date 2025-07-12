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

void multiply(vector<vector<ll>>&mat1,vector<vector<ll>>&mat2,vector<vector<ll>>&ans,ll n)
{
    vector<vector<ll>>ans1(51,vector<ll>(51,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                ans1[i][j]=(ans1[i][j]+(mat1[i][k]*mat2[k][j]))%M;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i][j]=ans1[i][j];
        }
    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>>mat(n,vector<ll>(n));
    vector<vector<ll>>ans(n,vector<ll>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
            if(i==j)ans[i][j]=1;
        }
    }
    while(k)
    {
        if(k%2)
        {
            multiply(mat,ans,ans,n);
            k--;
        }
        k/=2;
        multiply(mat,mat,mat,n);
    }
    ll out=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            out=(out+ans[i][j])%M;
        }
    }
    cout<<out<<endl;
}