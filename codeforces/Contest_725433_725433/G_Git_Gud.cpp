#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace algo {}
template <typename T>
concept string_like = std::convertible_to<const T &, std::string_view>;
template <typename T>
concept iterable = std::ranges::range<T> && (!string_like<T>);
template <typename T>
concept iterator_like = std::input_iterator<T> && (!std::is_pointer_v<T>) &&
                        (!std::ranges::range<T>);
template <typename... T>
inline void no_debug(const T &...) {
}
template <size_t N>
std::ostream &operator<<(std::ostream &os, const std::bitset<N> &v);
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, std::queue<T, U> q);
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, std::stack<T, U> s);
template <typename T, typename U, typename V>
std::ostream &operator<<(std::ostream &os, std::priority_queue<T, U, V> pq);
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p);
template <typename... T>
std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &t);
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::optional<T> &o);
std::ostream &operator<<(std::ostream &os, unsigned __int128 v);
std::ostream &operator<<(std::ostream &os, __int128 v);
template <iterable T>
std::ostream &operator<<(std::ostream &os, const T &t);
template <iterator_like T>
std::ostream &operator<<(std::ostream &os, const T &it);
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
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, std::stack<T, U> s) {
    os << "[";
    bool first = true;
    for (; !s.empty(); s.pop()) {
        if (!first) os << ", ";
        first = false;
        os << s.top();
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
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::optional<T> &o) {
    if (!o) return os << "nullopt";
    return os << *o;
}
inline std::ostream &operator<<(std::ostream &os, unsigned __int128 v) {
    std::string s;
    do {
        s += static_cast<char>('0' + v % 10);
        v /= 10;
    } while (v);
    return os << std::string(s.rbegin(), s.rend());
}
inline std::ostream &operator<<(std::ostream &os, __int128 v) {
    if (v < 0) os << '-';
    return os << (v < 0 ? -static_cast<unsigned __int128>(v)
                        : static_cast<unsigned __int128>(v));
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
template <iterator_like T>
std::ostream &operator<<(std::ostream &os, const T &it) {
    return os << "->" << *it;
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
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    int k = 70;
    for (int j = 1; j <= n; j *= k) {
        for (int i = k - 1; i >= 1; i--) {
            for (int l = n - i * j; l >= 1; l -= j * k) {
                ans.emplace_back(l, j);
            }
        }
    }
    int m = ans.size();
    cout << m << '\n';
    for (auto [l, r] : ans) {
        cout << l << ' ' << r << '\n';
    }
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
}
