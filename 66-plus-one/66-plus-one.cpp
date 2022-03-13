class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry=0, n=digits.size(), i=0;
        while(i<n){
            if(i==0){
                int x=digits[i]+1;
                digits[i]=x%10;
                carry=x/10;
            } else {
                int x=digits[i]+carry;
                digits[i]=x%10;
                carry=x/10;
            }
            
            i++;
            
        }
        if(carry){
            digits.push_back(carry);
        }
         reverse(digits.begin(), digits.end());
        return digits;
        
    }
};