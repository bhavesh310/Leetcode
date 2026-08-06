class Solution {
public:
    // Function to calculate the product of digits of a number
    int digitProduct(int num) {
        int product=1;
        //Extract each digit and multiply
        while(num>0){
            product*=(num%10);
            num/=10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        //Keep checking numbers starting from n
        while (true) {

            //If digit product is divisible by t, return the answer
            if(digitProduct(n)%t==0)
            return n;

            //Otherwise check the next number
            n++;
        }
    }
};