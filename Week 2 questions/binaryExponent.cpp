#include <climits>
#include <iostream>
using namespace std;
#define INT_MIN (-INT_MAX-1)

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        if (n == INT_MIN) {
            if (x == 1.0 || x == -1.0) return 1.0;
            else {
                x = 1 / (x*x);
                n = INT_MAX;
            }
        }
        
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double result = 1.0;
        double current_product = x;

        while (n > 0) {
            if (n % 2 == 1) {
                result *= current_product;
            }
            current_product *= current_product;
            n /= 2;
        }

        return result;
    }
};