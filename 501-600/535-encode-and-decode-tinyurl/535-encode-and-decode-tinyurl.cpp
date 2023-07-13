class Solution{
        public:
        int id = 0;
        string ch = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string idToUrl(int n) {
                string ret = "";
                while(n) {
                        ret += ch[n%62];
                        n /= 62;
                }
                return ret;
        }
        map<string, string> mp;
        string encode(string longUrl) {
                string str = idToUrl(id++);
                mp[str] = longUrl;
                return "http://tinyurl.com/" + str;
        }
        
        string decode(string shortUrl) {
                int i = shortUrl.size() - 1;
                while(shortUrl[i]!='/') i--;
                string str = shortUrl.substr(i+1);
                return mp[str];
        }
};
