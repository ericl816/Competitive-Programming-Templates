#include <bits/stdc++.h>
using namespace std;
 
const int MAX_POINTS = 500;
 
// Complex class which is available in STL has
// been used to implement points. This helps to
// ensure greater functionality easily
typedef complex<double> Point;
 
Point arr[MAX_POINTS];
double dis[MAX_POINTS][MAX_POINTS];
 
// This function returns the maximum points that can lie inside the circle of radius 'r' being rotated about point 'i'
int getPointsInside(int i, double r, int n) {
    // This vector stores alpha and beta and flag
    // is marked true for alpha and false for beta
    vector<pair<double, bool> > angles;
 
    for (int j=0; j<n; j++)
    {
        if (i != j && dis[i][j] <= 2*r)
        {
            // acos returns the arc cosine of the complex
            // used for cosine inverse
            double B =  acos(dis[i][j]/(2*r));
 
            // arg returns the phase angle of the complex
            double A = arg(arr[j]-arr[i]);
            double alpha = A-B;
            double beta = A+B;
            angles.push_back(make_pair(alpha, true));
            angles.push_back(make_pair(beta, false));
        }
    }
 
    // angles vector is sorted and traversed
    sort(angles.begin(), angles.end());
 
    // count maintains the number of points inside
    // the circle at certain value of theta
    // res maintains the maximum of all count
    int count = 1, res = 1;
    vector<pair<double, bool> >::iterator it;
    for (it=angles.begin(); it!=angles.end(); ++it)
    {
        // entry angle
        if ((*it).second)
            count++;
 
        // exit angle
        else
            count--;
 
        if (count > res)
            res = count;
    }
 
    return res;
}
 
// Returns count of maximum points that can lie in a circle of radius r.
int maxPoints(Point arr[], int n, int r) {
    // dis array stores the distance between every
    // pair of points
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
 
            // abs gives the magnitude of the complex
            // number and hence the distance between
            // i and j
            dis[i][j] = dis[j][i] = abs(arr[i]-arr[j]);
 
    // This loop picks a point p
    int ans = 0;
    for (int i=0; i<n; i++)
        // maximum number of points for point arr[i]
        ans = max(ans, getPointsInside(i, r, n));
 
    return ans;
}
 
int main () {
    /*Point arr[] = {Point(6.47634, 7.69628),
                    Point(5.16828, 4.79915),
                    Point(6.69533, 6.20378)};
                    */
    Point arr[] = {Point(0, 0), Point(2, 0), Point(3, 1), Point(1, 2), Point(3, 3), Point(4, 3), Point(2, 4)};
    int r = 1;
 
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "The maximum number of points are: " << maxPoints(arr, n, r);
 
    return 0;
}