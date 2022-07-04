class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int count[n], sum=0;
        
        if(n==1) return 1;
        if(n==2){
            if(ratings[0]==ratings[1]) return 2;
            else return 3;
        }
        
        for(int i=0; i<n; i++){
            count[i]=1;
        }
        
        for(int i=1; i<n-1; i++){
            if(ratings[i]<ratings[i+1]){
                if(count[i]>=count[i+1]) count[i+1]=count[i]+1;
            }
            if(ratings[i]>ratings[i+1]){
                if(count[i]<=count[i+1]) count[i]=count[i+1]+1;
            }
            if(ratings[i]<ratings[i-1]){
                if(count[i]>=count[i-1]) count[i-1]=count[i]+1;
            }
            if(ratings[i]>ratings[i-1]){
                if(count[i]<=count[i-1]) count[i]=count[i-1]+1;
            }   
        }
		
        for(int i=n-2; i>0; i--){
            if(ratings[i]<ratings[i+1]){
                if(count[i]>=count[i+1]) count[i+1]=count[i]+1;
            }
            if(ratings[i]>ratings[i+1]){
                if(count[i]<=count[i+1]) count[i]=count[i+1]+1;
            }
            if(ratings[i]<ratings[i-1]){
                if(count[i]>=count[i-1]) count[i-1]=count[i]+1;
            }
            if(ratings[i]>ratings[i-1]){
                if(count[i]<=count[i-1]) count[i]=count[i-1]+1;
            }   
        }
        
        for(int i=0; i<n; i++){
            sum += count[i];
        }
    
        return sum;
    }
};