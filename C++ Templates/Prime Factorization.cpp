// Returns the prime factors of N and the count of each factor
// Time Complexity: O(sqrt N)
// Memory Complexity: O(log N)
vector<pair<long long, int>> primeFactorWithCount(long long x) {
    vector<pair<long long, int>> ret;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ret.emplace_back(i, 0);
            while (x % i == 0) { ret.back().second++; x /= i; }
        }
    }
    if (x > 1) ret.push_back(x, 1);
    return ret;
}