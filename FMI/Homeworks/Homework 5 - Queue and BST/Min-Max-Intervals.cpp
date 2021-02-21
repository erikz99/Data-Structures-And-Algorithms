#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct tripple {
    int num;
    int max;
    int min;
};

int n, k;
int nums[2000010];

void init() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }
}

void solve() {
    stack <tripple> s1;
    stack <tripple> s2;
    long long counter = 0;
    bool toAdd = true;
    for (int i=0; i<n; i++) {
        if (toAdd) {
            int minimum = s1.empty() ? nums[i] : min(nums[i],s1.top().min);
            int maximum = s1.empty() ? nums[i] : max(nums[i],s1.top().max);
            s1.push({nums[i],maximum,minimum});
        }
        int minEl, maxEl;
        if (s1.empty() || s2.empty()) {
            minEl = s1.empty() ? s2.top().min : s1.top().min;
            maxEl = s1.empty() ? s2.top().max : s1.top().max;
        } 
        else {
            minEl = s1.top().min < s2.top().min ? s1.top().min : s2.top().min;
            maxEl = s1.top().max > s2.top().max ? s1.top().max : s2.top().max;
        }
        counter++;
        while (maxEl-minEl>k) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    int element = s1.top().num;
                    s1.pop();
                    int currMin = s2.empty() ? element : min(element,s2.top().min);
                    int currMax = s2.empty() ? element : max(element,s2.top().max);
                    s2.push({element,currMax,currMin});
                }
            }
            s2.pop();
            counter+=(s1.size()+s2.size()-1);
            if (s1.empty() || s2.empty()) {
                minEl = s1.empty() ? s2.top().min : s1.top().min;
                maxEl = s1.empty() ? s2.top().max : s1.top().max;
            } 
            else {
                minEl = s1.top().min < s2.top().min ? s1.top().min : s2.top().min;
                maxEl = s1.top().max > s2.top().max ? s1.top().max : s2.top().max;
            }
        }
    }
    while (!(s1.empty() && s2.empty())) {
        if (s2.empty()) {
                while (!s1.empty()) {
                    int element = s1.top().num;
                    s1.pop();
                    int currMin = s2.empty() ? element : min(element,s2.top().min);
                    int currMax = s2.empty() ? element : max(element,s2.top().max);
                    s2.push({element,currMax,currMin});
                }
            }
            s2.pop();
            counter+=(s1.size()+s2.size());
    }
    printf("%lld",counter);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
    
    return 0;
}