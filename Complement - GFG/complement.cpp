//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n){
        int l,r,mx=0,a=0,b=0;
        int tmpl=-1;
        for(int j=0;j<n;j++){
            if(str[j]=='0'){
                a++;
                if(a==1) tmpl=j;
            }
            else b++;
            if(a<b){
                tmpl=-1;
                a=0,b=0;
            }
            else if(a-b>mx){
                l=tmpl,r=j;
                mx=a-b;
            }
        }
        if(mx==0) return {-1};
        else return {l+1,r+1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends