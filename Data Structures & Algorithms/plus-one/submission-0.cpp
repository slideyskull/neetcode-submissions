class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        auto res = vector<int>();
        digits.back() += 1;
        if (digits.back() >= 10) {
            digits.back() = 0;
            carry = 1;
        }
        res.push_back(digits.back());

        for (int i = digits.size() - 2; i >= 0; --i) {
            digits[i] += carry;
            if (digits[i] >= 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            res.push_back(digits[i]);
        }

        if (carry == 1) {
            res.push_back(1);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
