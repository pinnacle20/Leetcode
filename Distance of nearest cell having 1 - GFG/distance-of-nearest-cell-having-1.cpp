//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>>grid)
	{
	    int n=grid.size(),m=grid[0].size();
	    queue<pair<pair<int,int>,int>> q;
	    vector<vector<int>> vis(n,vector<int>(m,-1));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]){
	                q.push({{i,j},0});
	                vis[i][j]=0;
	            }
	        }
	    } 
	    int dir[]={-1,0,1,0,-1};
	    while(q.size()){
	        pair<int,int> cur=q.front().first;
	        int x=cur.first,y=cur.second;
	        int dis=q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int X=x+dir[i],Y=y+dir[i+1];
	            if(X>=0 and X<n and Y>=0 and Y<m and vis[X][Y]==-1){
	                vis[X][Y]=dis+1;
	                q.push({{X,Y},dis+1});
	            }
	        }
	    }
	    return vis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends