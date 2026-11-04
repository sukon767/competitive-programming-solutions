    #include<bits/stdc++.h>
    
    using namespace std;
    
    using ll = long long;
    using ld = long double;
    
    void solve() {
        int n; cin >> n;
        vector<pair<int, int>> edge = {{1, 1}};
        for(int i = 1; i <= n; i++) {
            int prev = 0;
            while(true) {
            //binsearch on first > prev
                int l = 1; int r = (1<<30);
                while(l < r) {
                    int mid = (l+r)/2, q;
                    cout << "? " << mid << endl;
                    cin >> q;
                    vector<int> query(q); for(int i = 0; i < q; i++) cin >> query[i];
                    if(q == 0) {
                        r = mid;
                    } else if(q == 1){
                        if(query[0] <= i) l = mid+1;
                        else r = mid-1;
                    } else {
                        if(query[0] < i || (query[0] == i && query[1] <= prev)) l = mid+1;
                        else r = mid;
                    }
                    // cout << l << " " << r << endl;
                }
                int q;
                cout << "? " << l << endl;
                cin >> q;
                vector<int> query(q); for(int i = 0; i < q; i++) cin >> query[i];
                if(q < 2 || (query[0] == edge.back().first && query[1] == prev)) break;
                edge.push_back({query[0], query[1]}); prev = query[1];
                // cout << prev << endl;
            }
        }
        cout << "! " << edge.size()-1 << endl;
        for(auto p : edge) if(!(p.first == 1 && p.second == 1)) cout << p.first << " " << p.second << endl;

    }
    
    int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        int t; cin >> t;
        //int t = 1;
        while(t--) {
            solve();
            if(t)   cout << "\n";
        }
    }