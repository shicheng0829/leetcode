class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string res;
        if (numerator == 0)
            return "0";
        if (numerator > 0 ^ denominator > 0)
            res += "-";
        long dvd = labs(numerator);
        long dvs = labs(denominator);
        res += to_string(dvd / dvs);
        long remain = dvd % dvs;
        if (remain == 0)
            return res;
        res += ".";
        unordered_map<int, int> mp;
        while (remain != 0)
        {
            if (mp.find(remain) != mp.end())
            {
                res.insert(mp[remain], "(");
                res.push_back(')');
                return res;
            }
            mp[remain] = res.size();
            remain *= 10;
            res += to_string(remain / dvs);
            remain = remain % dvs;
        }
        return res;
    }
};