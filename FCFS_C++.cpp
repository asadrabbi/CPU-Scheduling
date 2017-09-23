#include<stdio.h>
#include<algorithm>
#include <vector>
#include<string.h>
#include<iostream>
using namespace std;

struct strint
{
    string stringName;
    int intNumber;
    strint (string aa, int n)
    {
        stringName = aa;
        intNumber = n;
    }
};


int main()
{
    vector <strint> v;
    vector <strint> v2;
    vector<int>wt;

    int n, i, m,j;


    cout<<"How Many Process: ";
    cin>>n;

    cout<<endl;

    cout<<"Enter Process Name & Burst Time:"<<endl;

    for(i=0; i<n; i++)
    {
        string ss;
        int x;
        cin>>ss;
        cin>>x;
        v.push_back(strint(ss,x));
    }

    int x = 0;
    wt.push_back(x);
    for(i=0; i<v.size()-1; i++)
    {
        x = x + v[i].intNumber;
        wt.push_back(x);
    }

    int sum = 0;
    for(i=0; i<wt.size(); i++)
    {
        sum += wt[i];
    }
    double avg = sum * 1.0 / n*1.0;
    cout<<endl;

    cout<<"Process_Name | "<<"Burst_Time"<<" | Waiting_Time"<<endl;

    for(i=0; i<v.size(); i++)
    {
        cout<<v[i].stringName<<"\t\t "<<v[i].intNumber<<"\t\t"<<wt[i]<<endl;
    }
    cout<<endl;
    cout<<"Avarage Time is = "<<avg<<endl;
    cout<<endl;

    return 0;
}
