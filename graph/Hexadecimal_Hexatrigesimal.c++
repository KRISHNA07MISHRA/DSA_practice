class Solution {
public:


    string toHex(int num) {
    string hex = "";
    const string digits = "0123456789ABCDEF";
    if (num == 0) return "0";
    while (num > 0) {
        hex += digits[num % 16];
        num /= 16;
    }
    reverse(hex.begin(), hex.end());
    return hex;
}

string toBase36(int num) {
    string base36 = "";
    const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (num == 0) return "0";
    while (num > 0) {
        base36 += digits[num % 36];
        num /= 36;
    }
    reverse(base36.begin(), base36.end());
    return base36;
}
    string concatHex36(int n) {
        int n2 = n * n;
    int n3 = n * n * n;
    string hexPart = toHex(n2);
    string base36Part = toBase36(n3);
    return hexPart + base36Part;
    }
};