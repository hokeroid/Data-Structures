//
//  main.cpp
//  SegmentTree
//
//  Created by Андрей Галицков on 24.06.2018.
//  Copyright © 2018 Андрей Галицков. All rights reserved.
//

#include <iostream>
#include <vector>

int n;
std::vector<int> tree, mas;

const int DEFAULT_VALUE = 0;

int f(int a, int b){
    return a + b;
}

void build(int v = 0, int l = 0, int r = n){
    if(l + 1 == r){
        return void(tree[v] = mas[l]);
    }
    int m = (l + r)/2;
    build(2*v + 1, l, m);
    build(2*v + 2, m, r);
    tree[v] = f(tree[2*v + 1], tree[2*v+2]);
}

void change(int pos, int value, int v = 0, int l = 0, int r = n){
    if(l == r - 1 && l == pos){
        return void(tree[v] = value);
    }
    if(l > pos || r <= pos){
        return;
    }
    int m = (l + r)/2;
    change(pos, value, 2*v + 1, l, m);
    change(pos, value, 2*v + 2, m, r);
    tree[v] = f(tree[2*v + 1], tree[2*v + 2]);
}

int ans(int posL, int posR, int v = 0, int l = 0, int r = n){
    if(l > posR || r <= posL){
        return DEFAULT_VALUE;
    }
    if(l >= posL && r <= posR + 1){
        return tree[v];
    }
    int m = (l+r)/2;
    return f(ans(posL, posR, 2*v + 1, l, m), ans(posL, posR, 2*v + 2, m, r));
}

int main(int argc, const char * argv[]) {
    
}
