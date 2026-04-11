#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int N_meeting_in_one_room(vector<int>start,vector<int>end,int n){
    vector<pair<int,int>>timer;
    for(int i=0;i<n;i++){
        timer.push_back({start[i],end[i]});
    }
    sort(timer.begin(),timer.end(),cmp); // first sort get called  then internally it calls cmp many times
    int total=0,ending=-1;
    for(int i=0;i<n;i++){
        if(timer[i].first>ending){
            total++;
            ending=timer[i].second;
        }
    }
    return total;
}

// job sequencing problem
struct jobs{
    int job_id;
    int deadline;
    int profit;
};
bool comp(jobs a,jobs b){
    return a.profit>b.profit;
}
vector<int> job_sequencing(vector<jobs>jobs,int n){

    sort(jobs.begin(),jobs.end(),comp);
    int deadline=0;
    for(int i=0;i<n;i++){
        deadline=max(deadline,jobs[i].deadline);
    }
    vector<int>task(deadline+1,0);
    vector<int>ans(2,0);
    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline;j>=0;j--){
            if(task[j]==false){
                task[j]=1;
                ans[0]++;
                ans[1] += jobs[i].profit;
            }
        }
    }
  return ans;
}
int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};
    cout<<N_meeting_in_one_room(start,end,6);
    vector<jobs>arr={{1,4,20},{2,1,10},{3,1,40},{4,1,30}};

}