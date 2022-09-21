void subStrings(string s, string a, int n, int i)
{
    if(i == n)
    {
        ans.push_back(a);
        return;
    }
    subStrings(s, a, n, i+1);
    subStrings(s, a+s[i], n, i+1);
}