class Solution {
public:
    bool checkpalindrome(string s,int left,int right)
    {
         while(left<right)
         {
             if(s[left]!=s[right])
             {
                 return false;
             }
             left++;
             right--;
         }
        return true;
    }
    
    
    bool validPalindrome(string s) 
    {
        int left=0,right=s.size()-1;
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                return checkpalindrome(s,left+1,right) || checkpalindrome(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
        
    }
};