vector<string> split(string &a, char c) {
    vector<string> ret;
    string cur;
    for (auto &x : a) {
        if (x == c) ret.push_back(cur), cur = "";
        else cur += x;
    }
    if (cur != "") ret.push_back(cur);
    return ret;
}