#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace algo {}
template <typename T>
concept printable = requires(T t) {
    { std::cout << t } -> std::same_as<std::ostream &>;
};
template <typename T>
concept iterable = std::ranges::range<T> && (!printable<T>);
template <typename... T>
inline void no_debug(const T &...) {
}
template <size_t N>
std::ostream &operator<<(std::ostream &os, const std::bitset<N> &v);
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, std::queue<T, U> q);
template <typename T, typename U, typename V>
std::ostream &operator<<(std::ostream &os, std::priority_queue<T, U, V> pq);
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p);
template <typename... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &t);
template <iterable T>
std::ostream &operator<<(std::ostream &os, const T &t);
namespace algo::search {
template <typename U>
double argmax(double l, double r, U f, double eps = 1e-9) {
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) < f(m2))
            l = m1;
        else
            r = m2;
    }
    return l;
}
template <typename U>
double argmin(double l, double r, U f, double eps = 1e-9) {
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }
    return l;
}
template <typename T, typename U>
T last_true(T l, T r, U f) {
    l--;
    assert(l <= r);
    while (l < r) {
        T mid = l + (r - l + 1) / 2;
        f(mid) ? l = mid : r = mid - 1;
    }
    return l;
}
template <typename T, typename U>
T first_true(T l, T r, U f) {
    r++;
    assert(l <= r);
    while (l < r) {
        T mid = l + (r - l) / 2;
        f(mid) ? r = mid : l = mid + 1;
    }
    return l;
}
}
template <size_t N>
std::ostream &operator<<(std::ostream &os, const std::bitset<N> &v) {
    os << "<";
    for (size_t i = 0; i < N; i++) {
        os << static_cast<char>('0' + v[i]);
    }
    return os << ">";
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, std::queue<T, U> q) {
    os << "[";
    bool first = true;
    for (; !q.empty(); q.pop()) {
        if (!first) os << ", ";
        first = false;
        os << q.front();
    }
    return os << "]";
}
template <typename T, typename U, typename V>
std::ostream &operator<<(std::ostream &os, std::priority_queue<T, U, V> pq) {
    os << "[";
    bool first = true;
    for (; !pq.empty(); pq.pop()) {
        if (!first) os << ", ";
        first = false;
        os << pq.top();
    }
    return os << "]";
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <typename... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &t) {
    os << "(";
    bool first = true;
    auto print = [&os, &first](const auto &arg) {
        if (!first) os << ", ";
        first = false;
        os << arg;
    };
    std::apply([&print](auto &&...args) { (print(args), ...); }, t);
    return os << ")";
}
template <iterable T>
std::ostream &operator<<(std::ostream &os, const T &t) {
    os << "[";
    bool first = true;
    for (const auto &e : t) {
        if (!first) os << ", ";
        first = false;
        os << e;
    }
    return os << "]";
}
inline void debug() {
}
template <typename T, typename... Rest>
void debug(std::string_view name, const T &var, const Rest &...rest) {
    std::cout << "\x1B[31m";
    if (!name.starts_with('"')) std::cout << name << ": ";
    std::cout << var << "\x1B[0m" << '\n';
    std::cout.flush();
    debug(rest...);
}
using namespace std;
using namespace algo;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> cnt(2 * n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    vector<pair<int, int>> st;
    int ans = 0;
    for (int i = 1; i <= 4 * n; i++) {
        if (i <= 2 * n && cnt[i] > 1) {
            st.emplace_back(cnt[i] - 1, i);
        } else if (!st.empty() && (i > 2 * n || cnt[i] == 0)) {
            st.back().first--;
            if (st.back().first == k - 1) {
                ans = max(ans, i - st.back().second);
            }
            if (st.back().first == 0) {
                st.pop_back();
            }
        }
        no_debug(i, st);
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}
