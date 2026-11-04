#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> updates(N, vector<int>(3));
    vector<pair<int, int>> queries(Q);
    vector<pair<int, long long>> coords(2*(N+Q)); //val, prefix
    map<int, int> compress;

    
    for(int i = 0; i < N; i++) {
        cin >> updates[i][0] >> updates[i][1] >> updates[i][2];
        coords[2*i] = {updates[i][0], 0};
        coords[2*i + 1] = {updates[i][1], 0};
    }

    for(int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
        coords[2*(N+i)] = {queries[i].first, 0};
        coords[2*(N+i)+1] = {queries[i].second, 0};
    }

    
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    //compress
    for(int i = 0; i < coords.size(); i++)
        compress[coords[i].first] = i;


    //update prefix
    for(int i = 0; i < N; i++) {
        coords[compress[updates[i][0]]].second += updates[i][2];
        coords[compress[updates[i][1]]].second -= updates[i][2];
    }

    for(int i = 1; i < coords.size(); i++)
        coords[i].second += coords[i-1].second;

    vector<long long> pre_fn(coords.size());
    for(int i = 1; i < coords.size(); i++)
        pre_fn[i] = pre_fn[i-1] + coords[i-1].second*(coords[i].first - coords[i-1].first);

    for(int i = 0; i < Q-1; i++)
        cout << pre_fn[compress[queries[i].second]] - pre_fn[compress[queries[i].first]] << "\n";

    cout << pre_fn[compress[queries[Q-1].second]] - pre_fn[compress[queries[Q-1].first]];
}