class Solution {
public:
   
    int reachNumber(int target) {
        if(target<0){
            return reachNumber(-1*target);
        }
        long long int counter=0, step=1;
        while(counter<target){
            counter+=step;
            step++;
        }
        while((counter-target)%2==1){
                counter+=step;
                step++;
            }
        return --step;
    }
};