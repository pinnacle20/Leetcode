//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        vector<int> v;
        for(int i=0;i<n;i++){
            if(m[0][i]==1 and m[i][0]==0) v.push_back(i);
        }
        int i=0;
        v.push_back(0);
        while(i<v.size()){
            bool f=0;
            int pos=v[i];
            //cout<<pos<<endl;
            for(int i=0;i<n;i++){
                if(i==pos) continue;
                if(m[pos][i]==0 and m[i][pos]==1) continue;
                else {
                    f=1; break;
                }
            }
            if(f) i++;
            else return pos;
        }
        return -1;
        
        // int arr[n];
        // memset(arr,0,sizeof(arr));
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(m[0][i]==1) arr[i]=1,cnt++;
        // }
        // if(cnt==0){
        //     for(int j=1;j<n;j++){
        //         if(m[j][0]==0) return -1;
        //     }
        //     return 0;
        // }
        
        // int i=n-1;
        // while(i>=0){
        //     if(arr[i]){
        //         for(int j=0;j<n;j++){
        //             if(m[i][j]==1){
        //                 arr[i]=0;
        //                 if(arr[j]) arr[j]=0;
        //             }
        //         }
        //     }
        //     i--;
        // }
        // for(int j=0;j<n;j++){
        //     if(arr[j]){
        //         return j;
        //     }
        // }
        // return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends