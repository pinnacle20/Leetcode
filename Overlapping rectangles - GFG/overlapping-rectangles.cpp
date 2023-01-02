//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool okx(int L1[],int R1[],int L2[],int R2[]){
        bool f=0;
        if((L2[0]-L1[0])*(R2[0]-L1[0])<=0 || (L2[0]-R1[0])*(R2[0]-R1[0])<=0) f=1;
        return f;
    }
    bool oky(int L1[],int R1[],int L2[],int R2[]){
        bool ff=0;
        if((L2[1]-L1[1])*(R2[1]-L1[1])<=0 || (L2[1]-R1[1])*(R2[1]-R1[1])<=0) ff=1;
        return ff;
    }
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        return (okx(L1,R1,L2,R2)||okx(L2,R2,L1,R1))*(oky(L1,R1,L2,R2)||oky(L2,R2,L1,R1));
    }
// L1=(0,2)
// R1=(1,1)
// L2=(-2,0)
// R2=(0,-3)
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}
// } Driver Code Ends