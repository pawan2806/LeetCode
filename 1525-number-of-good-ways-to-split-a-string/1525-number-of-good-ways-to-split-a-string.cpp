class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> freq;
    for(char ch:s){
        freq[ch]++;
    }
    
    int result = 0;
    unordered_map<char, int> currFreq;
    
    for(int i=0; i<s.length(); i++){
        if(currFreq.size()==freq.size()) result++; 
        freq[s[i]]--;
        if(freq[s[i]]==0) freq.erase(s[i]);
        currFreq[s[i]]++;
    }
    
    return result;
    }
};