/* 
Given an integer array nums, return all the triplets 
[nums[i], nums[j], nums[k]] 
such that 
i != j, i != k, and j != k, 
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        set<vector<int> > a;
        if(n<3)
        {
            return res;
        }
        for(int i=0;i<=n-3;i++)
        {
            int s = i+1;
            int e = n-1;
            while(s<e)
            {
                int temp = nums[i]+nums[s]+nums[e];
                if(temp==0)
                {
                    a.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(temp<0)
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        for(auto i:a)
        {
            res.push_back(i);
        }
        return res;
    }
};