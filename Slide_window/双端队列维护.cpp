//https://leetcode.cn/problems/sliding-window-maximum/
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int> ret;
        deque<int> d;
        int n = a.size();
        for (int i = 0; i < k; ++i) {
            while (!d.empty() && a[i] >= a[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        ret.push_back(a[d.front()]);
        for (int i = k; i < n; ++i) {
            while(!d.empty()&&a[i]>=a[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
            if(i-k+1>d.front()){
                d.pop_front();
            }
            ret.push_back(a[d.front()]);
        }
        return ret;
    }
};
