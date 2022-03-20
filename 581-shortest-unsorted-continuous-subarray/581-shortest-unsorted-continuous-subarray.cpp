class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int maxim=INT_MIN;
        int minim=INT_MAX;
        int  n=arr.size();
        if(n==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(i==0){
                if(arr[i]>arr[i+1]){
                    maxim=max(maxim, arr[i]);
                    minim=min(minim, arr[i]);
                }
            } else if(i==n-1){
                if(arr[i-1]>arr[i]){
                     maxim=max(maxim, arr[i]);
                     minim=min(minim, arr[i]);
                }
            } else {
                if(arr[i]>arr[i+1] || arr[i]<arr[i-1]){
                     maxim=max(maxim, arr[i]);
                     minim=min(minim, arr[i]);
                }
            }
        }
        if(maxim==INT_MIN || minim==INT_MAX){
            return 0;
        }
        int i,j;
        for(i=0;i<n && arr[i]<=minim;i++);
        for(j=n-1;j>=0 && arr[j]>=maxim;j--);
        // cout<<maxim<<" "<<minim<<endl;
        return j-i+1;
    }
};