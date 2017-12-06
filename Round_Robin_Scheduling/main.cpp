#include <iostream>

using namespace std;

int main()
{
    int p[5],bt[5],at[5],rt[5],wt,tat,quantum,rem_process;

    int n,i,time,count;
    cout<<"Enter no. of processes\t";
    cin>>n;
    wt=0,tat=0;
    for(i=0;i<n;i++)
    {
        cout<<"Burst Time for Process P["<<i+1<<"]\t";
        cin>>bt[i];
        cout<<"Arrival for Process P["<<i+1<<"]\t";
        cin>>at[i];
        p[i]=i+1;
        rt[i]=bt[i];
    }
    cout<<"Enter Value of Time Quantum\t";
    cin>>quantum;

    rem_process=n;

    cout<<"Process ID\t"<<"Burst Time\t"<<"Arrival Time\t"<<"Waiting Time\t"<<"Turnaround Time\n";
    count=0,time=0;
    while(rem_process!=0)
    {
        if(rt[count]<=quantum && rt[count]!=0)
        {
            time=time+rt[count];
            rt[count]=0;
        }
        else if(rt[count]>0)
        {
            rt[count]=rt[count]-quantum;
            time=time+quantum;
        }

        if(rt[count]==0)
        {
            cout<<"p["<<p[count]<<"]\t\t"<<bt[count]<<"\t\t"<<at[count]<<"\t\t"<<time-at[count]-bt[count]<<"\t\t"<<time-at[count]<<"\n";
            rem_process--;
            wt+=time-at[count]-bt[count];
            tat+=time-at[count];
            }
        if(count== n-1)
            count=0;
        else
            count++;
    }
    cout<<"Average Waiting Time = "<<wt*1.0/n;
    cout<<"Average Turnaround Time = "<<tat*1.0/n;
    return 0;
}
