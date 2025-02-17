/*
  Esteban Arango Medina
*/
#include <bits/stdc++.h>

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
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printA(arr) for(auto x: arr) { cout<<x<<" "; }
#define printMatrix(mat) for(auto x: mat) { printA(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }
#define ROUNDNUM(x) ((int)(x + 0.5f))

int posX[4] = {-1,0,1,0};
int posY[4] = {0,1,0,-1};

signed main(){
  // ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  int T = 1; cin>>T;
  while(T--) {
    int N, P, x, total, inRow; cin>>N>>P;
    vector<vi> A(N, vi(N,0));
    cout<<1<<" "<<1<<" "<<1<<" "<<N<<" "<<N<<endl;
    fflush(stdout);
    cin>>total;
    rep(i, 0, N) {
      if(total <= 0) { break; }
      cout<<1<<" "<<i+1<<" "<<1<<" "<<i+1<<" "<<N<<endl;
      fflush(stdout);
      cin>>inRow;
      if(inRow == N) {
        rep(j,0,N){ A[i][j] = 1; total--; }
        break;
      } else {
        rep(j, 0, N) {
          if(inRow <= 0) { break; }
          if(N - j == inRow){
            rep(k,j,N){ A[i][k] = 1; total--; }
            break;
          } else {
            cout<<1<<" "<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
            fflush(stdout);
            cin>>x;
            if(x == -1) { return 0; }
            A[i][j] = x;
            if(x == 1) { inRow--; total--; }
          }
        }
      }
    }
    cout<<2<<endl;
    printMatrix(A);
    fflush(stdout);
    cin>>x;
    if(x == -1) { return 0; }
  }
  return 0;
}