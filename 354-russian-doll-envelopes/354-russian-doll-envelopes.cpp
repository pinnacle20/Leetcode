class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
    
//     int dp[100001];  
//     int lis(int i,vector<int>& v){
//         if(i==v.size()) return 0;
//         if(dp[i]!=-1) return dp[i];
//         int y=1;
//         for(int j=i+1;j<v.size();j++){
//             if(v[j]>v[i]) y=max(y,1+lis(j,v));
//         }
//         return dp[i]=y;
//     }
    
    int maxEnvelopes(vector<vector<int>>& e){
        // memset(dp,-1,sizeof(dp));
        
        sort(e.begin(),e.end(),comp);
        vector<int> nums;
        for(auto x:e) nums.push_back(x[1]);
        
        // O(n*n)
        // int ans=0;
        // for(int i=0;i<v.size();i++){
        //     ans=max(ans,lis(i,v));
        // }
        
        // O(nlogn)
        vector<int> tmp;
        int ans=1;
        tmp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>tmp.back()) tmp.push_back(nums[i]),ans++;
            else{
                int idx=lower_bound(tmp.begin(),tmp.end(),nums[i])-tmp.begin();
                tmp[idx]=nums[i];
            }
        }
        return ans;
    }
};