class Solution {
public:
    
//  static   bool sortbysec(const vector<int> &a,
//               const vector<int> &b)
// {
//         if(a[0]==b[0]){
//             return a[1]>b[1];
//         }
//     return (a[0] < b[0]);
// }
    
    static bool sortbysec(const vector<int> &a,
              const vector<int> &b)
{
        return (a[0]-a[1]< b[0]-b[1]);
}
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int seats=costs.size();
        int n=seats/2;
        
        sort(costs.begin(), costs.end(), sortbysec);
            
        int i;
        int ans=0;
        for(i=0;i<n;i++){
            ans+=costs[i][0];
        }
        
        for(i=n;i<seats;i++){
            ans+=costs[i][1];
        }
        return ans;
    }
};