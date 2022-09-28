#include<bits/stdc++.h>

using namespace std;

void randomOrder(vector<int> &order){
    srand(time(0));
    order.clear();
    vector<int> v={1,2,3,4,5,6,7,8,9};
    int size=v.size();
    while(size){
        int x=rand()%size;
        order.push_back(v[x]);
        v.erase(v.begin()+x);
        size-=1;
    }
}