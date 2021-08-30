#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        //if(s=="") return 0;
        int l = 0, r = 0;
        int ans = 0;
        while(r < s.size()){
            char c = s[r];
            r++;
            mp[c]++;
            while(mp[c]>1){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l);
        }
        return ans;
    }

int main(){
    string s = "pwwkew";
    cout<< lengthOfLongestSubstring(s) <<endl;
    return 0;
}