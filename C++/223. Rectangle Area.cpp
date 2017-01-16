223. Rectangle Area 
My Submissions QuestionEditorial Solution
Total Accepted: 34834 Total Submissions: 117121 Difficulty: Easy
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.

Subscribe to see which companies asked this question


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int maxae = A > E ? A : E;
        int mincg = C > G ? G : C;
        int maxfb = F > B ? F : B;
        int minhd = H > D ? D : H;
        int overlap;
        if(maxae >= mincg || maxfb >= minhd)
            overlap = 0;
        else
            overlap = (mincg - maxae) * (minhd - maxfb);
        return (C - A) * (D - B) + (G - E) * (H - F) - overlap;
    }
};