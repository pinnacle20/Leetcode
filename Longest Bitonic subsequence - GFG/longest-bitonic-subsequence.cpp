//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int dp[1001][2];
	
	int solve(int i,bool f,vector<int>& nums){
	    int tmp=0;
	    if(dp[i][f]!=-1) return dp[i][f];
	    for(int j=i+1;j<nums.size();j++){
	       if(f==0 and nums[j]>nums[i]) tmp=max(tmp,1+solve(j,0,nums));
	       if(nums[j]<nums[i]) tmp=max(tmp,1+solve(j,1,nums));
	    }
	    return dp[i][f]=tmp;
	}
	// 0 inc
	int LongestBitonicSequence(vector<int>nums)
	{
	    memset(dp,-1,sizeof(dp));
	    int mx=0;
	    for(int i=0;i<nums.size();i++){
	        mx=max(mx,1+solve(i,0,nums));
	        mx=max(mx,1+solve(i,1,nums));
	    }
	    return mx;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends