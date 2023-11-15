#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
#include <queue>

using namespace std;
typedef pair<int,int> ii;
vector<ii> activities;
bool check(int personas){
    int a;
    priority_queue< int,vector<int>,greater<int> > pq;
    for(int i=0;i<personas;i++){
        pq.push(0);
    }
    for(int i = 0;i<activities.size();i++){
        if(pq.top()<=activities[i].first){
            pq.pop();
            pq.push(activities[i].second);
        }
        else return false;
    }
    
    return true;
}
int busbin(int d,int i){
    int a;
    if(d+1==i) return i;
    a=d+i;
    a/=2;
    if(check(a)){
        busbin(d,a);
    }
    else{
        busbin(a,i);
    }
}
int main(int argc, char** argv) {
    int per;
    int a,b;
    while(cin>>per){
        activities.clear();
        for(int i=0;i<per;++i){
            cin>>a>>b;
            activities.push_back(make_pair(a,b));
        }
        sort(activities.begin(),activities.end());
        cout<<busbin(0,per)-1<<"\n";
        
    }
    return 0;
}
