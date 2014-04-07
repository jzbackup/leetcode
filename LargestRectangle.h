/*
for each bar, we want to know how left and how right it can extends, to do so, we can do a o(n) check.
To do it better, we can use DP.
left[], right[]
for left,
if height(i) == height(i-1), left(i) = left(i-1)
if height(i) > height(i-1), left(i) = i
if height(i) < height(i-1), left(i) = something left of left(i-1), to calc that, we can check height(i) and height(left(i-1))
left(0) = 0;
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() == 0)return 0;
        if(height.size() == 1)return height[0];
        
        vector<int> left(height.size());
        vector<int> right(height.size());
        
        left[0] = 0;
        for(int i = 1; i < left.size(); i ++){
            if(height[i] == height[i-1]){
                left[i] = left[i-1];
            }else if(height[i] > height[i-1]){
                left[i] = i;
            }else{
                int pos = i-1;
                while(pos >= 0 && height[i] <= height[pos]){
                    left[i] = left[pos];
                    pos = left[pos]-1;
                }
            }
        }
        right.back() = right.size()-1;
        for(int i = right.size() - 2; i >= 0; i --){
            if(height[i] == height[i+1]){
                right[i] = right[i+1];
            }else if(height[i] > height[i+1]){
                right[i] = i;
            }else{
                int pos = i+1;
                while(pos <= right.size()-1 && height[i] <= height[pos]){
                    right[i] = right[pos];
                    pos = right[pos]+1;
                }
            }
        }
        
        int rlt = 0;
        for(int i = 0; i < height.size(); i ++){
            int area = height[i] * (right[i] - left[i] + 1);
            rlt = max(rlt, area);
        }
        return rlt;
    }
};
