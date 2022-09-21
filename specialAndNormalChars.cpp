#include <iostream>
using namespace std;

class SpecialSubstring
{
public:
    int getSpecialSubstring(string str, string bitString, int k)
    {
        int len = str.length();
        if (!len)
            return 0;
        int maxSubstringLen = 0;
        int windowStart = 0;
        int cnt = 0;
        for (int windowEnd = 0; windowEnd < len; windowEnd++)
        {
            int pos = str[windowEnd] - 'a';
            if (bitString[pos] == '0')
                cnt++;
            while (cnt > k and windowStart <= windowEnd)
            {
                pos = str[windowStart] - 'a';
                if (bitString[pos] == '0')
                    cnt--;
                windowStart++;
            }
            maxSubstringLen = max(maxSubstringLen, windowEnd - windowStart + 1);
        }
        return maxSubstringLen;
    }
};
int main()
{
    SpecialSubstring specialSubstring;
    cout << specialSubstring.getSpecialSubstring("abcde", "10101111111111111111111111", 2) << endl;
    cout << specialSubstring.getSpecialSubstring("giraffe", "01111001111111111011111111", 2) << endl;
    return 0;
}