/* Source - https://leetcode.com/problems/encode-and-decode-tinyurl/
   Author - Shivam Arora
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> encodings;
unordered_map<string, string> decodings;
const string alphanum = "012345678abcdefijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int len = 6;
const string domain = "http://tinyurl.com/";

string getCode() {
    string code = "";
    
    for(int i = 0; i < len; i++)
        code += alphanum[rand() % (alphanum.length() - 1)];
    
    return code;
}

// Encodes a URL to a shortened URL.
string encode(string longUrl) {
    if(encodings.find(longUrl) != encodings.end())
        return domain + encodings[longUrl];
    
    string code = getCode();
    
    if(decodings.find(code) != decodings.end())
        code = getCode();
        
    encodings[longUrl] = code;
    decodings[code] = longUrl;
    
    return domain + code;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
    return decodings[shortUrl.substr(shortUrl.length() - len, len)];
}

int main()
{
    string longUrl;
    cout<<"Enter the url to be encoded: ";
    cin>>longUrl;

    string shortUrl = encode(longUrl);
    cout<<"Encoded URL: "<<shortUrl<<endl;

    string decodedLongURL = decode(shortUrl);
    cout<<"Decoded URL: "<<decodedLongURL<<endl;
}