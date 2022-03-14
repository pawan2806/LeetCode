class Solution
{
    public:
        int sumOddLengthSubarrays(vector<int> &arr)
        {
            int n=arr.size();
            long long int sum = 0;
            vector<int> ans(n, 0);
                ans[0] = arr[0];
            for (int i = 1; i < n; i++)
            {
                ans[i] = ans[i - 1] + arr[i];
            }
            for (int i = 0; i < n; i++)
            {
                sum += arr[i];
            }

            for (int j = 2; j<n; j = j + 2)
            {
                for (int i = 0; i+j < n; i++) {
                   
                    if(i==0){
                        cout<<ans[j]<<endl;
                        sum+=ans[j];
                    } else {
                        cout<<ans[i+j]-ans[i]<<endl;
                        sum+=ans[i+j]-ans[i-1];
                    }
                }
                
            }

            return (int) sum;
        }
};