#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

struct prioritySch
{
    string ProcessName;
    int BurstTime;
    int Priority;
    prioritySch (string ss, int a, int b)
    {
        ProcessName = ss;
        BurstTime = a;
        Priority = b;
    }
};

bool com (prioritySch a, prioritySch b)
{
    if(a.Priority<b.Priority) return 1;
    else return 0;
}

int main()
{
    int i, n,a,b;
    string ss;
    vector <prioritySch> v;

    vector<int>wt;
    double avg;

    cin>>n;

    for (i=0; i<n; i++)
    {
        cout<<"Process Name: ";
        cin>>ss;
        cout<<"Burst Time: ";
        cin>>a;
        cout<<"Priority: ";
        cin>>b;
        v.push_back(prioritySch(ss,a,b));
        cout<<endl;
    }

    sort(v.begin(),v.end(),com);

    int x = 0;
    wt.push_back(x);
    int j = 0;
    for(i=0; i<n-1; i++)
    {
        x = x+v[j].BurstTime;
        wt.push_back(x);
        j++;
    }

    int sum = 0;
    for(i=0; i<wt.size(); i++)
    {
        sum = sum + wt[i];
    }
    avg = sum * 1.0 / n * 1.0;

    cout<<endl;
    cout<<endl;
    cout<<"Process_Name |"<<" Burst_Time |"<<" Priority |"<<" Waiting_Time"<<endl;

    for(i=0; i<v.size(); i++)
    {
        cout<<v[i].ProcessName<<"\t\t "<<v[i].BurstTime<<"  \t\t "<<v[i].Priority<<"\t\t"<<wt[i]<<endl;
    }
    cout<<endl;

    cout<<"Average Waiting Time is: "<<avg<<endl;

    return 0;

}
