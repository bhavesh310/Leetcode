class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        //Main Loop
        while(x){
            rev=(rev*10)+(x%10);
            //rev is an int,so rev*10+digit may overflow before check runs
            //long long has a much larger range than int,so rev*10+digit can be computed safely
            if(rev>INT_MAX || rev<INT_MIN)
            return 0;

            x=x/10;
        }
        return (int)rev;
    }
};