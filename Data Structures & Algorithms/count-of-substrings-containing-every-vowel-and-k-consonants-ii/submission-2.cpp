class Solution {
private:
    long long slidingWindow(string word, int k)
    {
        int n = word.size(), l = 0;
        unordered_map<char,long long>vowelFreq;
        long long countConst = 0;
        long long ans = 0;

        for(int r = 0; r < n; r++)
        {
            if(isVowel(word[r]))
            {
                vowelFreq[word[r]]++;
            }
            else
            {
                countConst++;
            }

            while(vowelFreq.size() >= 5 && countConst >= k)
            {
                ans += n-r;
                if(isVowel(word[l]))
                {
                    vowelFreq[word[l]]--;
                    if(vowelFreq[word[l]] == 0)
                    {
                        vowelFreq.erase(word[l]);
                    }
                }
                else
                {
                    countConst--;
                }
                l++;
            }
        }
        return ans;

    }
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    long long countOfSubstrings(string word, int k) {
        
        
        return slidingWindow(word, k)-slidingWindow(word, k+1);

    }
};
