class Solution {
   private:
    string add(string num1, string num2) {
        int m = num1.size(), n = num2.size();

        int carry = 0;
        int i = m - 1, j = n - 1;
        for (; i >= 0 && j >= 0; i--, j--) {
            int sum = num1[i] + num2[j] - '0' * 2 + carry;
            carry = 0;

            if (sum > 9) {
                carry = 1;
                sum %= 10;
            }

            if (m > n)
                num1[i] = '0' + sum;
            else
                num2[j] = '0' + sum;
        }

        if (carry) {
            if (m > n)
                num1 = "1" + num1;
            else
                num2 = "1" + num2;
        }

        return m > n ? num1 : num2;
    }

   public:
    string multiply(string num1, string num2) {
        string product = "0";
        string singleP = "";
        int m = num1.size(), n = num2.size();
        int carry = 0;
        for (int i = m - 1; i >= 0; i--) {
            carry = 0;
            singleP = "";

            for (int j = n - 1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = 0;

                if (prod > 9) {
                    carry = prod / 10;
                    prod %= 10;
                }

                singleP = to_string(prod) + singleP;
            }

            if (carry) singleP = to_string(carry) + singleP;
            product = add(product + "0", singleP);
        }

        return product;
    }
};
