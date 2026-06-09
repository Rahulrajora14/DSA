#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;



bool cmp(pair<int, int>&a, pair<int, int>&b) {
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}
int functionalknapsack(vector<int>& weights , vector<int> & values,int w, int n){
    vector<pair<int,int>> items;
    for(int i=0;i<n;i++){
        items.push_back({values[i],weights[i]});
    }
    
    sort(items.begin(),items.end(),cmp);
    int totalvalue =0;
    for(int i=0;i<n;i++){
        if(items[i].second<=w){
            totalvalue=totalvalue+items[i].first;
            w=w-items[i].second;

        }
        else{
            totalvalue= totalvalue+(items[i].first/items[i].second)*w;
            w=0;
            break;

        }

    }
    return totalvalue;

}

int main() {
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int w = 50;
    int n = weights.size();
    int maxValue = functionalknapsack(weights, values, w, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);
    printf("Start small. Ship something.");

    return 0;
}