    #include<bits/stdc++.h>

    using namespace std;

    using ll = long long;
    using ld = long double;

    void solve() {
        int n; cin >> n;
        if(n == 1) {cout << "! 0" << endl; return;}
        vector<pair<int, int>> edge;
        int on = 2;
        vector<int> d(n+1);
        vector<bool> done(n+1);
        stack<int> stk; stk.push(1);
        while(true) {
            cout << "? " << on << endl;
            int q; cin >> q; vector<int> path(q); for(int &i : path) cin >> i;

            while(stk.size() && stk.size() >= path.size()) {
                int t = stk.top();
                stk.pop();
                d[t]++;
                done[t] = true;
                if(stk.size()) {d[stk.top()] += d[t];}
            }

            if(!path.size()) break;

            //new edge
            if(!stk.size()) {
                //single
                int ind = path.back();
                while(ind <= n && done[ind]) {on+=d[ind]; ind++;}
                if(ind > n) break;
                else {stk.push(ind); on++;}
            }
            else {
                edge.push_back({stk.top(), path.back()});
                // cout << stk.top() << " " << path.back() << " " << d[path.back()] << endl;
                if(done[path.back()]) {d[stk.top()] += d[path.back()]; on+=d[path.back()];}
                else {stk.push(path.back()); on++;
                    // cout << "pushd " << stk.top() << endl;
                }
            }
            // cout << "upd " << d[4] << endl;
        }
        
        cout << "! " << edge.size() << endl;
        for(auto p : edge) cout << p.first << " " << p.second << endl;
        // cout << d[2] << endl;
        // for(int i = 1; i <= n; i++) cout << i << " " << d[i] << endl;
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