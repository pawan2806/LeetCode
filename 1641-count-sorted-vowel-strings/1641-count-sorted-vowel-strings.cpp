class Solution {
public:
   void helper(int n, vector<char> &temp,int &count, int idx, vector<char> &vowels)
    {
        if(temp.size()==n)
        {
            count++;
            return;
        }
        
        for(int i=idx; i<vowels.size(); i++)
        {
            temp.push_back(vowels[i]);
            helper(n, temp, count, i, vowels);
            temp.pop_back();
        }
        return;
    }
    
    int countVowelStrings(int n) 
    {
        vector<char> vowels{'a','e','i','o','u'};
        int count=0;
        vector<char> temp;
        helper(n, temp, count, 0, vowels);
        return count;        
    }
};