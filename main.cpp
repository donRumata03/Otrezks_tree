#include <vector>
#include <iostream>
#include <math.h>
#include "conio.h"
#include "tree_class.cpp"

#define INF INT64_MAX

using namespace::std;


typedef long long lint;
typedef lint * msint;


Tree tree;


int main(){
    tree = Tree();
    tree.input();
    tree.build();
    tree.input_and_process_queries();    

    _getch();
    _getch();

    return 0;
}