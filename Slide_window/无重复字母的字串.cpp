//https://leetcode.cn/problems/longest-substring-without-repeating-characters/
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret=0,flag=0;
        int h[1000]={0};
        for(int i=0,j=0;j<s.size();++j){
            h[s[j]]++;
            if(h[s[j]]==1)flag++;
            while(h[s[j]]!=1) {
                h[s[i]]--;
                if(h[s[i]]==0)flag--;
                i++;
            }
            ret=max(ret,flag);
        }
        return ret;
    }
};