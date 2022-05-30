class Solution {
public:
    int divide(int dividend, int divisor) {
       long long n=dividend, m=divisor;
        if(n <= INT_MIN && m == -1) return INT_MAX;

        int sign = (n < 0) ^ (m < 0) ? -1: 1;

        n=abs(n);
        m=abs(m);

        long long q=0, temp=0;

        for(int i=31; i>=0; i--){
            if(temp + (m << i) <= n){
                temp += m << i;
					q += 1 << i;      //  q |= 1 << i;
            }
        }
        return sign * q;
    }
};