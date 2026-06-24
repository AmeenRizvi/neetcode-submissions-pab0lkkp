class Solution {
public:
    int firstUniqChar(string s) {
	
	int n = s.size();
	unordered_map<char, int>uniqueCharToIdx;
	
	for(int i = 0; i < n; i++ )
	{
		if( uniqueCharToIdx.find( s[i] )   == uniqueCharToIdx.end()  )
		{
			uniqueCharToIdx[  s[i] ] = i;
        }
        else
        {
	    uniqueCharToIdx[ s[i] ] = n;
        }
    }

    int ans = n;
    for( auto &[ch, idx] : uniqueCharToIdx )
    {
	    ans = min(ans, idx);
    }

    return ans == n ? -1 : ans;
    }
};