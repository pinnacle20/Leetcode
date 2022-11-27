//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	    string ans;
	    bool carry=false;
	    while(a.size() and b.size()){
	        int sum=a.back()-'0'+b.back()-'0'+carry;
	        if(sum==0) ans+='0',carry=false;
	        else if(sum==1) ans+='1',carry=false;
	        else if(sum==2) ans+='0',carry=true;
	        else ans+='1',carry=true;
	        a.pop_back(),b.pop_back();
	    }
	    while(a.size()){
	        int sum=a.back()-'0'+carry;
	        if(sum==0) ans+='0',carry=false;
	        else if(sum==1) ans+='1',carry=false;
	        else if(sum==2) ans+='0',carry=true;
	        else ans+='1',carry=true;
	        a.pop_back();
	    }
	    while(b.size()){
	        int sum=b.back()-'0'+carry;
	        if(sum==0) ans+='0',carry=false;
	        else if(sum==1) ans+='1',carry=false;
	        else if(sum==2) ans+='0',carry=true;
	        else ans+='1',carry=true;
	        b.pop_back();
	    }
	    if(carry) ans+='1';
	    while(ans.size() and ans.back()=='0') ans.pop_back();
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends