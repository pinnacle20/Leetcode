//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends

string buildLowestNumber(string num, int k)
{
    // 1 4 6
    stack<char> st;
    for(int i=0;i<num.size();i++){
        while(k and st.size() and st.top()>num[i]) st.pop(),k--;
        st.push(num[i]);
    }
    while(k and st.size()){
        st.pop();
        k--;
    }
    stack<char> stt;
    while(st.size()){
        stt.push(st.top()); st.pop();
    }
    string ans;
    while(stt.size() and stt.top()=='0') stt.pop();
    while(stt.size()){
        ans+=stt.top(); stt.pop();
    }
    if(ans.size()==0) ans="0";
    return ans;
}