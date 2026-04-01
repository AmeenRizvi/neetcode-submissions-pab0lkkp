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

        for(int i = k; i < n; i++)
        {
            if(blocks[i-k] == 'W')
            {
                whiteBlocks--;
            }
            if(blocks[i] == 'W')
            {
                whiteBlocks++;
            }
            ans = min(ans, whiteBlocks);
        }

        return ans;
        
    }
};