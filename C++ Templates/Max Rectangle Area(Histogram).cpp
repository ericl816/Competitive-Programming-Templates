vi hist;
stack<int> st;

inline int getMaxArea () {
    int n = hist.size();
    int max_area = 0, tp = 0, area_with_top = 0, i = 0;
    while (i < n) {
        if (st.empty() || hist[st.top()] <= hist[i]) st.push(i++);
        else {
            tp = st.top();  // store the top index
            st.pop();  // pop the top
            area_with_top = hist[tp] * (st.empty() ? i + 1 : i - st.top() );
            if (max_area < area_with_top) max_area = area_with_top;
       }
    }
    while (!st.empty()) {
        tp = st.top();
        st.pop();
        area_with_top = hist[tp] * (st.empty() ? i + 1 : i - st.top());
        if (max_area < area_with_top) max_area = area_with_top;
    }
    return max_area;
}