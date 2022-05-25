class Solution {
public:
   static bool my_comp(vector<int> &a, vector<int> &b){
        if (a[0] == b[0]) {
            return (a[1] > b[1]);
        }
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        /* Sort envelopes in increasing order of width and decreasing order of height.
        *  Then, apply LIS on heights.
        *    LIS:
        *    Create a tmp_arr to save sequence.
        *    If curr_elem in arr is greater than tmp_arr.back(), append curr_elem to tmp_arr.
        *    Else, replace elem in tmp_arr such that,
        *      curr_elem < tmp_elem and it should not break incerasing nature of tmp_arr.
        *      (Binary search for curr_elem in tmp_arr will give you the proper index)
        *    Finally return len of tmp_arr.
        */
        
        sort(envelopes.begin(), envelopes.end(), my_comp);

        vector<int> tmp;
        tmp.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++){
            int curr_elem = envelopes[i][1];
            if (tmp.back() < curr_elem)
            {
                tmp.push_back(curr_elem);
            }
            else 
            {
                int idx = lower_bound(tmp.begin(), tmp.end(), curr_elem) - tmp.begin();
                tmp[idx] = curr_elem;
            }
            
        }
        return tmp.size();
    }
};