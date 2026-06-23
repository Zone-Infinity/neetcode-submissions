class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> hash;

        while (n != 1) {
            int sumq = 0;
            while (n) {
                int d = n % 10;
                sumq += d * d;
                n /= 10;
            }

            if(hash.count(sumq)) return false;
            hash.insert(sumq);
            n = sumq;
        }

        return true;
    }
};
