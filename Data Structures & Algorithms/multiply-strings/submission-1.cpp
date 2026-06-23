class Solution {
   private:
    string add(string num1, string num2) {
        if (num1.size() < num2.size()) swap(num1, num2);

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += num1[i] - '0';
            if (j >= 0) sum += num2[j] - '0';

            carry = sum / 10;
            sum %= 10;

            if (i >= 0) {
                num1[i] = '0' + sum;
                i--;
            } else {
                num1 = char('0' + sum) + num1;
            }

            j--;
        }

        return num1;
    }

   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        string product = "0";
        int m = num1.size(), n = num2.size();

        for (int i = m - 1; i >= 0; i--) {
            string singleP = "";
            int carry = 0;

            for (int j = n - 1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0') + carry;

                carry = prod / 10;
                prod %= 10;

                singleP = char('0' + prod) + singleP;
            }

            if (carry) singleP = char('0' + carry) + singleP;

            singleP += string(m - 1 - i, '0');
            product = add(product, singleP);
        }

        return product;
    }
};
