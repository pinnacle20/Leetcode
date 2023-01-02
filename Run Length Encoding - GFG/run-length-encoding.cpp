//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{  
    string ans;
    int cnt=1;
    for(int i=1;i<s.length();i++){
        if(s[i]!=s[i-1]){
            ans.push_back(s[i-1]);
            ans+=to_string(cnt);
            cnt=1;
        }
        else cnt++;
    }
    ans.push_back(s.back());
    ans+=to_string(cnt);
    return ans;
}     
 
