/*This is my first file with Github
Problem: Pow(x, n)
Notes: Implement Pow(x, n),

*/


class Solution{
public:
    double pow(double x, int n) {
    	//for INT_MIN, -n is invalid, so handle this case first
        if(n == INT_MIN) return 1/(x*pow(x, INT_MAX));
    	if(n < 0) return 1/pow(x, -n);
        if(n == 0)return 1;
        if(n == 1)return x;

        double pre = pow(x, n/2);
        if(n%2 == 0)
        	return pre*pre;
        else
        	return pre*pre*x;
    }
};
