class Solution {
public
    int trap(vectorint& height) {
        int n = height.size();
        vectorint lmx(n), rmx(n);
        int res = 0;
        
        lmx[0] = height[0];
        for(int i = 1; i  n; i++)
            lmx[i] = max(lmx[i - 1], height[i]);
        
        rmx[n - 1] = height[n - 1];
        for(int i = n - 2; i=0; i--)
            rmx[i] = max(rmx[i + 1], height[i]);
        
        for(int i = 1; i  n - 1; i++)
            res += max( 0, ( min(lmx[i], rmx[i]) - height[i] ) );
        return res;
    }
};
