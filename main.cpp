#include <iostream>
#include <vector>
#include <typeinfo>
#include "list_v0.hpp"


using namespace std;

struct seg {
    int l, r;
    seg() {};
    seg(int l_, int r_) {
        l = l_;
        r = r_;
    }
};


void solve(){
    List<seg> a;
    a.push_back(seg(1, 2));
    a.push_front(seg(3, 4));
    a.push_back(seg(5, 6));
    for (ListIterator<seg> it(a); it.check(); it.next()) {
        cout << it.get()->l << " " << it.get()->r << endl;
    }
}




int main(){
    //freopen("intput.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int t; cin >> t;
    //for (int i = 0; i < t; i++){
        solve();
    //}
    return 0;
}

