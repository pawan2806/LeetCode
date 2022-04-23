class Solution {
public:

    
    map<string,string>mpp;
    string key = "1";
    string encode(string longUrl) {
        mpp[key] = longUrl;
        string encode = key;
        key +='x';
        return encode;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));