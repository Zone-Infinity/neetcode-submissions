class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = 0;
        int l = 0, r = heights.size() - 1;

        while(l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            if(area > maxA) maxA = area;
            
            if(heights[l] > heights[r]) r--;
            else l++;
        }

        return maxA;
    }
};
