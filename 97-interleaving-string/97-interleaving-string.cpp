// class Solution {
// public:
//     int dp[101][101];
//     bool helper(string s1 , string s2, string s3, int i, int j, int k){
//         if(i==s1.length() && j==s2.length() && k==s3.length()){
//             return  true;
//         } else if(i==s1.length()){
//             return (s2.substr(j)==s3.substr(k));
//         } else if(j==s2.length()){
//             return (s1.substr(i)==s3.substr(k));
//         } 
        
//         if(s1[i]!=s3[k] && s2[j]!=s3[k]){
//             return  false;
//         }
//         if(s1[i]==s3[k] && s2[j]==s3[k]){
//             return dp[i][j] = (helper(s1,s2,s3,i+1,j,k+1 ) || helper(s1,s2,s3,i,j+1,k+1));
//         } else if(s1[i]==s3[k]){
//             return dp[i][j] = helper(s1,s2,s3,i+1,j,k+1);
//         } else {
//             return dp[i][j] = helper(s1,s2,s3,i,j+1,k+1);
//         }
//         return false;
        
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         int n=s1.length(), m=s2.length(), p=s3.length();
//         memset(dp,-1,sizeof(dp));
//         if(s1[0]!=s3[0] && s2[0]!=s3[0]){
//             return false;
//         } else if(s3.length() != (s1.length()+s2.length())){
//             return false;
//         }
   
       
//         return helper(s1,s2,s3,0,0,0);
        
//     }
// };

class Solution {
public:
    int dp[101][101];
    bool solve(string s1,string s2,string s3,int l1,int l2,int n)
    {
        if(l1>=0&&l2>=0 &&dp[l1][l2]!=-1)return dp[l1][l2];
        if(l1<0&&l2<0&&n<0)
        {
            return true;
        }
        
        if(l1>=0&&n>=0&&s1[l1]==s3[n]&&l2>=0&&s2[l2]==s3[n])
        {
            return dp[l1][l2]=(solve(s1,s2,s3,l1-1,l2,n-1) || solve(s1,s2,s3,l1,l2-1,n-1));
        }
        else if(l1>=0&&n>=0&&s1[l1]==s3[n])
        {
            return solve(s1,s2,s3,l1-1,l2,n-1);
        }
        else if(l2>=0&&n>=0&&s2[l2]==s3[n])
        {
           return solve(s1,s2,s3,l1,l2-1,n-1);
        }
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.length()-1);
        
    }
};
