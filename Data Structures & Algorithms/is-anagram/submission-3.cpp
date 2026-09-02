class Solution {
public:
    bool isAnagram(string s, string t) {
        auto sit = s.begin();
        auto tit = t.begin();

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        while (sit != s.end() && tit != t.end()) {
            smap[*sit]++;
            tmap[*tit]++;
            ++sit;
            ++tit;
        }

        return smap == tmap && sit == s.end() && tit == t.end();
    }
};
