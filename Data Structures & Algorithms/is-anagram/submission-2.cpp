class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);

        // we can use map as well to store the values and compare the quantity of each element.
    }
};
