/*
  Esteban Arango Medina
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <tuple>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

using ll=long long;
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <char,int> mci;
typedef map <int,int> mii;
typedef map <string,string> mss;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }

void dfs(vector<vi> &paths, vi &dep, vi &siz, int u) {
  siz[u] = 0;
  rep(i, 0, paths[u].size()){
    int v = paths[u][i];
    if(siz[v] == -1) {
      dep[v] = dep[u] + 1;
      dfs(paths, dep, siz, v);
      siz[u] += siz[v] + 1;
    }
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  int T = 1; //cin>>T;
  while(T--) {
    int n, k, u , v;
    cin>>n>>k;
    vector<vi> paths(n);
    rep(i, 0, n-1) {
      cin>>u>>v;
      paths[u-1].pb(v-1);
      paths[v-1].pb(u-1);
    }

    vi dep(n, 0);
    vi siz(n, -1);
    dfs(paths, dep, siz, 0);

    vi happinesses(n);
    rep(i, 0, n) { happinesses[i] = dep[i] - siz[i]; }
    sort(all(happinesses), greater<int>());
    cout<<accumulate(happinesses.begin(), happinesses.begin()+k, int(0))<<endl;
  }
  return 0;
}