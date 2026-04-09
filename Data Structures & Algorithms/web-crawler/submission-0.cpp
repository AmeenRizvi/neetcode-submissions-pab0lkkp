/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    string startHostname = "";
    string getHostName(string url)
    {
        int pos = min(url.size(), url.find('/', 7) );

        string hostname = url.substr(7, pos-7);
        return hostname;
    }
    
    void dfs(string url, HtmlParser htmlParser, unordered_set<string>&visited )
    {
        visited.insert(url);

        for(auto nbr : htmlParser.getUrls(url))
        {
            if(getHostName(nbr) == startHostname && visited.find(nbr) == visited.end())
            {
                dfs(nbr, htmlParser, visited);
            }
        }
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        startHostname = getHostName(startUrl);
        
        unordered_set<string>visited;

        dfs(startUrl, htmlParser, visited);
        vector<string>ans(visited.begin(), visited.end());

        return ans;
    }
};
