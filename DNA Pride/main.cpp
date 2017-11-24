#include <iostream>

using namespace std;

int main()
{
    int T,f,N,i;
    cin>>T;
    while(T>0)
    {
        f=0;
        cin>>N;
        char dna[N];
        cin>>dna;
        char pair[N];
        for(i=0;i<N;i++)
        {
            if(dna[i]=='A')
                pair[i]='T';
            else if(dna[i]=='T')
                    pair[i]='A';
            else if(dna[i]=='G')
                    pair[i]='C';
            else if(dna[i]=='C')
                    pair[i]='G';
            else
            {
                f=1;
                cout<<"Error RNA nucleobases found!"<<endl;
                break;
            }
        }
        if(f!=1)
        {
            for(i=0;i<N;i++)
            {
                cout<<pair[i];
            }
            cout<<endl;
        }
        T--;
    }
    return 0;
}
