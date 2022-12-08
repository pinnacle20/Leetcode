//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q){
        vector<int> v;
        for(int i=0;i<q;i++){
            long long int num=query[i];
            int arr[num+1];
            memset(arr,0,sizeof(arr));
            arr[1]=1;
            for(int i=2;i*i<=num;i++){
                if(!arr[i]){
                    for(int j=i*i;j<=num;j+=i){
                        arr[j]=1;
                    }
                }
            }
            int count=0;
            for(int i=1;i*i<=num;i++){
                if(!arr[i]){
                    if(i*i<=num) count++;
                }
            }
            v.push_back(count);

        }
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends