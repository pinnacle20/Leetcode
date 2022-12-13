//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

int dirx[8]={-2,-2,-1,-1,1,1,2,2};
int diry[8]={1,-1,2,-2,2,-2,1,-1};
int mod=1e9+7;
long long numOfWays(int n, int m){
    long long int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp=1; 
            for(int k=0;k<8;k++){
                int x=i+dirx[k],y=j+diry[k];
                if(x<n and y<m and x>=0 and y>=0) tmp++;
            }
            //cout<<tmp<<" ";
            cnt=(cnt+n*m-tmp+mod)%mod;
            //cout<<cnt<<endl;
        }
    }
    return cnt;
}