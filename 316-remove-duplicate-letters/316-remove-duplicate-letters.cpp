class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int> lastseen(26,0);
        stack<int> st;
        vector<bool> seen(26);
        
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            lastseen[ch]=i;
        }
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            if(seen[ch]){
                continue;
            } else {
                while(!st.empty() && st.top()>ch && i<lastseen[st.top()]){
                    seen[st.top()]=false;
                    st.pop();
                }
                st.push(ch);
                seen[ch]=true;
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top()+'a';
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
//         int n=s.length();
//         map<char,int> m;
//         vector<bool> str(n, false);
//         for(int i=n-1;i>=0;i--){
//             if(!m[s[i]]){
//                 m[s[i]]=i;
//                 str[i]=true;
//             } else {
//                 int index=m[s[i]];
//                 bool check=true;
//                 bool badamilgya=false;
//                 for(int j=i+1;j<=index;j++){
//                     if(s[j]<s[i]){
//                         break;
//                     }
//                     if(str[j] && s[j]>s[i]){
                       
//                         badamilgya=true;
//                         break;
//                     } else if(s[j]>s[i]){
//                         str[m[s[j]]]=false;
//                         m[s[j]]=j;
//                         str[j]=true;
                        
//                     }
//                 }
//                 if(badamilgya){
//                     str[index]=false;
//                     m[s[i]]=i;
//                     str[i]=true;
//                 } else {
//                     m[s[i]]=i;
//                 }
//             }
//         }
        
//         string ans="";
//         for(int i=0;i<n;i++){
//             if(str[i]){
//                 ans=ans+s[i];
//             }
//         }
//         return ans;
    }
};