//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    map<int,int> mp;
    bool vis[100001];
    
    int cycle(int pos,vector<int>& nums){
        //cout<<pos<<" ";
        vis[pos]=1;
        int pos1=mp[nums[pos]];
        if(!vis[pos1]) return 1+cycle(pos1,nums);
        else return 1;
    }
    
	int minSwaps(vector<int>&nums){
	   mp.clear();
	   memset(vis,0,sizeof(vis));
	   vector<int> v=nums;
	   sort(v.begin(),v.end());
	   for(int i=0;i<nums.size();i++){
	       mp[v[i]]=i;
	   }
	   int ans=0;
       for(int i=0;i<nums.size();i++){
           if(!vis[i]){
               int tmp=cycle(i,nums);
            //   cout<<tmp<<endl;
               ans+=tmp-1;
            //   cout<<endl;
           }
       }
	   return ans;
	   
	   // vector<int> v=nums;
	   // sort(v.begin(),v.end());
	   // map<int,int> mp,pos;
	   // for(int i=0;i<nums.size();i++){
	   //     mp[v[i]]=i;
	   //     pos[i]=v[i];
	   //     cout<<v[i]<<" ";
	   // }
	    
	   // int ans=0;
	   // for(int i=0;i<nums.size();i++){
	   //     if(i==mp[nums[i]]) continue;
	   //     else{
	   //         ans++;
	   //         int pos=mp[nums[i]];
	            
	   //     }
	   // }
	    
	   // cout<<endl;
	   // int cnt=0;
	   // int k=0;
	   // for(int i=0;i<nums.size();i++){
	   //     if(i==mp[nums[i]]){
	   //         k++; continue;
	   //     }
	   //     if(pos[i]==nums[mp[nums[i]]]) cnt++;
	   // }
	    //cout<<cnt<<" "<<endl;
	   // cnt=cnt/2;
	   // cout<<cnt<<" "<<k<<endl;
	   // return nums.size()-1-cnt-k;
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
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends