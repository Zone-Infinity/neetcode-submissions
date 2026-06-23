class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        digits[i]++;
        int carry = 0;
        if (digits[i] > 9) {
            digits[i] %= 10;
            carry = 1;
        }

        while (carry && i--) {
            if (carry) {
                digits[i]++;
                carry = 0;
            }

            if (digits[i] > 9) {
                digits[i] %= 10;
                carry = 1;
            }
        }

        if (!(i + 1) && carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
