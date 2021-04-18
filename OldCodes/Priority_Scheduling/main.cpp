#include <iostream>

using namespace std;

int main()
{
    int p[5],bt[5],pr[5],wt[5],tat[5];
    float avg_wt,avg_tat;
    int n,i,j,total,temp;
    cout<<"Enter no. of processes\t";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Burst Time for Process P["<<i+1<<"]\t";
        cin>>bt[i];
        cout<<"Priority for Process P["<<i+1<<"]\t";
        cin>>pr[i];
        p[i]=i+1;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[j]< pr[i])
            {
                temp=pr[j];
                pr[j]=pr[i];
                pr[i]=temp;

                temp=bt[j];
                bt[j]=bt[i];
                bt[i]=temp;

                temp=p[j];
                p[j]=p[i];
                p[i]=temp;

            }
        }
    }

    wt[0]=0;
    total=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]=wt[i]+bt[j];
        total=total+wt[i];
    }
    avg_wt=float(total)/float(n);

    total=0;
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total=total+tat[i];
    }
    avg_tat=float(total)/float(n);

    cout<<"Process ID\t"<<"Burst Time\t"<<"Priority\t"<<"Waiting Time\t"<<"Turnaround Time\n";
    for(i=0;i<n;i++)
    {
        cout<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";
    }

    cout<<"Average Waiting Time = "<<avg_wt<<"\n";
    cout<<"Average Turnaround Time = "<<avg_tat<<"\n";
    return 0;
}
