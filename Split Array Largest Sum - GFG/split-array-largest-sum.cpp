//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int n, int k) {
        int ans=INT_MAX;
        int beg=0,end=accumulate(arr,arr+n,0);
        while(beg<=end){
            int mid=(beg+end)/2;
            // cnt<=k
            int cnt=1;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=arr[i];
                if(sum>mid){
                    cnt++;
                    sum=arr[i];
                    if(arr[i]>mid){
                        cnt=k+1;
                        break;
                    }
                }
            }
            //cout<<mid<<" "<<cnt<<endl;
            if(cnt<=k){
                ans=min(ans,mid);
                end=mid-1;
            }
            else beg=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends