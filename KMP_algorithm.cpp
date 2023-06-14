// Repeated Substring Pattern(LeetCode)
#include <bits/stdc++.h>
using namespace std;
vector<int>longestPrefixEqualsSuffix(string s)
{
    vector<int> prefixTrack(s.size(), 0);
    int n = s.size();
    for (int i = 1; i < n; ++i)
    {
        int j = prefixTrack[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = prefixTrack[j - 1];
        }
        if (s[i] == s[j])
            j++;
        prefixTrack[i] = j;
    }
    return prefixTrack;
}
int main()
{
    string pattern = "abcaby";
    vector<int> prefix =longestPrefixEqualsSuffix(pattern);
    string text = "abxabcabcaby";
    int i = 0, j = 0, pos = -1;
    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            i++, j++;
        }
        else
        {
            if (j != 0)
            {
                j = prefix[j - 1];
            }
            else
            {
                i++;
            }
        }
        if(j==pattern.size()){
            pos=i-pattern.size();
            break;
        }
    }
    cout<<pos<<endl;
    
}
