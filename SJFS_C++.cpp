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

bool com (strint a, strint b)
{
    if(a.intNumber==b.intNumber)
    {
        if(a.stringName<b.stringName)
            return 1;
        else
            return 0;
    }
    else
    {
        if(a.intNumber<b.intNumber)
            return 1;
        else
            return 0;
    }
}

int main()
{
    vector <strint> v;
    vector <strint> v2;
    vector<int>wt;

    int n, i, m;
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

    sort(v.begin(),v.end(),com);

    int x = 0;
    wt.push_back(x);
    int j = 0;
    for(i=0; i<n-1; i++)
    {
        x = x+v[j].intNumber;
        wt.push_back(x);
        j++;
    }

    int sum =0;
    for(j=0; j<n; j++)
    {
        sum = sum + wt[j];
    }
    double avg = sum * 1.0 / n*1.0;

    cout<<endl;
    cout<<"Process Name |"<<" Burst Time |"<<" Waiting Time"<<endl;

    for(i=0; i<v.size(); i++)
    {
        cout<<v[i].stringName<<"\t\t "<<v[i].intNumber<<"\t\t"<<wt[i]<<endl;
    }
    cout<<endl;
    cout<<"Avarage Time is = "<<avg<<endl;
    cout<<endl;

    return 0;
}
