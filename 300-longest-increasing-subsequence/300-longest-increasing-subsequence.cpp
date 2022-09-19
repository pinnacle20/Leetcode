class Solution {
public:
    
    int dp[2501];
    
    int solve(int i,vector<int>& nums){
        if(i==nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];   
        int len=1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]>nums[i]){
                len=max(len,1+solve(j,nums));
            }
        }    
        return dp[i]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        // int len=0;
        // for(int i=0;i<nums.size();i++){
        //     len=max(len,solve(i,nums));
        // }
        // return len;
        
        vector<int> tmp;
        tmp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>tmp.back()) tmp.push_back(nums[i]);
            else{
                int idx=lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                tmp[idx]=nums[i];
            }
        }
        return tmp.size();
        
    }
};