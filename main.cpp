#include "queue_header.h"


int main()
{
    double time1=0,time2=0,stoim=0,Max=0,Sum=0;
    int nom=0,k=0,l=0,kk=0,number=0,NomMax=0;

    queue* Head=(queue*)malloc(sizeof(queue));
    Head->next=NULL;
    //Head->prev=NULL;
    Head->num=665;Head->prob=0.9;Head->tobr=0.0;Head->tprih=0.0;

    queue* Tail=(queue*)malloc(sizeof(queue));
    Tail->next=Head;
    Tail->prev=NULL;
    Tail->num=666;Tail->prob=0.9;Tail->tobr=0.0;Tail->tprih=0.0;
    Head->prev=Tail;

    //Print(Head,Tail);

    while(k<1000)
    {
        //cout<<"Before while length H->p->n  "<<" "<<Head->prev->num<<" T->n->n "<<Tail->next->num<<endl;
        while(Length(&Head,&Tail,time2) /*&& (time2<time1)*/)
        {
            //cout<<"Before POP H->p->n  "<<" "<<Head->prev->num<<" T->n->n "<<Tail->next->num<<endl;
            double a;
            a=Pop(&Head,&Tail,/*&nom,*/ &k, &l,&time2,&number);
            Sum+=a;
            if(a> Max)
                {
                    Max=a;
                    NomMax=number;
                }
            //Print(Head,Tail);
            if(!(k%100) && (kk!=k))
                {cout<<"Length: "<<Length(&Head,&Tail)<<" Released: "<<k <<" Done: "<<k+l <<" time: "<<time2<<endl;kk=k;}
        }
        if(!(Length(&Head, &Tail,time2))  && (Head->prev->prishla >time2))
            {
                stoim+=(Head->prev->prishla - time2);
                time2=Head->prev->prishla;

            }
        //cout<<"hpp: "<<Head->prev->prishla<<endl;
        //cout<<"time2: "<<time2<<endl;
        Add(&Tail,&nom,&time1);

        //cout<<"time1: "<<time1<<endl;
        //Print(Head,Tail);

        //time1+= Tail->next->tprih;
    }

    /*cout<<"time1: "<<time1<<endl;
    cout<<"time2: "<<time2<<endl;
    Print(Head, Tail);*/
    cout<<" Downtime: "<<stoim<<endl<<" Max waiting time: "<<Max<<" request number: "<< NomMax<<endl<<" Average waiting time: "<< Sum/1000;
    return 0;
}
