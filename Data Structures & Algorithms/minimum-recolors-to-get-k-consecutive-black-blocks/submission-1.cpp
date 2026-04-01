class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = n;

        int whiteBlocks = 0;
        for(int i = 0; i < k; i++)
        {
            if(blocks[i] == 'W')
            {
                whiteBlocks++;
            }
        }
        ans = min(ans, whiteBlocks);

        int l = 0;
        for(int r = k; r < n; r++)
        {
            if(blocks[l] == 'W')
            {
                whiteBlocks--;
            }
            l++;
            if(blocks[r] == 'W')
            {
                whiteBlocks++;
            }
            ans = min(ans, whiteBlocks);
        }

        return ans;
        
    }
};