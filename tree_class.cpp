#include <vector>
#include <iostream>
#include <math.h>
#include "conio.h"
#include "mymath.cpp"

#define INF INT64_MAX

using namespace::std;


typedef long long lint;
typedef lint * msint;


class Tree{
    private:
    void _build(int v, int l, int r){
        if (l == r){
            data[v] = input_ms[l];
            max_index = max(max_index, v);
            return;
        }
        int mid = (l + r) / 2;
        _build(2 * v + 1, l, mid);
        _build(2 * v + 2, mid + 1, r);
        data[v] = data[2 * v + 1] + data[2 * v + 2];
    }
    lint _count_sum(int v, int vl, int vr, int l, int r){
        if (r < vl || l > vr){ // No intersection
            return 0;
        }
        if (l <= vl && r >= vr){ // full intersection
            return (lint)(data[v]);
        }
        // Else:
        int mid = (vl + vr) / 2;
        lint sum_l = _count_sum(2 * v + 1, vl, mid, l, r);
        lint sum_r = _count_sum(2 * v + 2, mid + 1, vr, l, r);
        return sum_l + sum_r;
    }
    
    
    public:

    int n, max_index = 0;
    msint input_ms, data;

    void input(){
        cin >> n;
        input_ms = new lint[n];
        for(int i = 0; i < n; i++){
            cin >> input_ms[i];
        }
    }

    void build(){
        data = new lint[4 * n];
        _build(0, 0, n - 1);
    }

    lint count_sum(int l, int r){
        return _count_sum(0, 0, n - 1, l, r);
    }

    void print_input(){
        for(int i = 0; i < n; i++){
            cout << input_ms[i] << " ";
        }
        cout << "\n";
    }

    void print_data(){
        cout << "Max index: " << max_index << endl;
        for(int i = 0; i < max_index; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }
};


Tree tree;


int main(){
    tree = Tree();
    tree.input();
    tree.build();
    tree.print_data();

    cout << tree.count_sum(1, 2) << endl;

    _getch();
    return 0;
}