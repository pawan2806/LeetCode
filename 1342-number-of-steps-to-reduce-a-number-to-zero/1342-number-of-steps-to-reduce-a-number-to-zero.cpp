class Solution {
public:
    int numberOfSteps(int num) {
        int count=0;
        while(num){
             count++;
            if(num%2==0){
                num=num/2;
                
            } else {
                num=num-1;
            }
           
        }
        return count;
    }
};