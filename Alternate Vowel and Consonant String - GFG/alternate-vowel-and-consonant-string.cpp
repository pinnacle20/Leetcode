//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int n)
    {
       vector<char> v,c;
       int a[26],b[26];
       memset(a,0,sizeof(a));
       memset(b,0,sizeof(b));
       
       for(auto x:s){
           if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u'){
               a[x-'a']++;
           }
           else b[x-'a']++;
       }
       for(int i=0;i<26;i++){
           while(a[i]--){
               char ch='a'+i;
               v.push_back(ch);
           }
           while(b[i]--){
               char ch='a'+i;
               c.push_back(ch);
           }
       }
       string ss;
       int x=v.size(),y=c.size();
       //cout<<v.size()<<" "<<c.size()<<" "<<abs(x-y)<<endl;
       if(v.size()==c.size()){
           int i=0;
           if(v[0]<c[0]){
               for(int i=0;i<v.size();i++){
                   ss.push_back(v[i]);
                   ss.push_back(c[i]);
               }
           }
           else{
               for(int i=0;i<v.size();i++){
                   ss.push_back(c[i]);
                   ss.push_back(v[i]);
               }
           }
       }
       else if(abs(x-y)==1){
           if(v.size()<c.size()){
               for(int i=0;i<v.size();i++){
                   ss.push_back(c[i]);
                   ss.push_back(v[i]);
               }
               ss.push_back(c.back());
           }
           else{
                for(int i=0;i<c.size();i++){
                   ss.push_back(v[i]);
                   ss.push_back(c[i]);
                }
               ss.push_back(v.back());
           }
       }
       else{
           ss="-1";
       }
       return ss;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends