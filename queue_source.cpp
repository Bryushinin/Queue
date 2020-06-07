#include "queue_header.h"

double Tprih()
{
    return(6*((double)rand()/RAND_MAX));
}

double Tobr()
{
    return((double)rand()/RAND_MAX);
}

void Add(queue** Tail, int* nom, double* time)
{
    ++(*nom);
    queue* A=(queue*)malloc(sizeof(queue));

    A->next=(*Tail)->next;
    A->num=*nom;
    A->waiting=0;
    A->prev=(*Tail);
    A->prob=Tobr();
    A->tobr=Tobr();
    A->tprih=Tprih();
    A->prishla=*time+A->tprih;
    *time=A->prishla;
    ((*Tail)->next)->prev=A;
    (*Tail)->next=A;
    //cout<<endl<<"Add "<<(*Tail)->next->num<<" "<<(*Tail)->next->next->num<<endl;
}

int Length(queue** Head, queue** Tail)
{
    if((*Head)==((*Tail)->next))
        return(0);
    //queue* Temp=(queue*)malloc(sizeof(queue));
    int i=0;
    queue* Temp=(*Tail)->next;
    while(Temp!=(*Head))
    {
            ++i;
        Temp=Temp->next;
    }
    //cout<<"Length: "<<i<<endl;
    return(i);
}

int Length(queue** Head, queue** Tail, double time)
{
    if((*Head)==((*Tail)->next))
        return(0);
    //queue* Temp=(queue*)malloc(sizeof(queue));
    int i=0;
    queue* Temp=(*Tail)->next;
    while(Temp!=(*Head))
    {
        if(Temp->prishla <= time)
            ++i;
        Temp=Temp->next;
    }
    //cout<<"Length: "<<i<<endl;
    return(i);
}

void Print(queue* Head, queue* Tail)
{
    queue* T=Tail;cout<<endl<<T->num<<" ";
    while(T!=Head)
    {
        T=T->next;
        cout<<T->num<<" ";
    }
    cout<<"Printed"<<endl;
}


double Pop(queue** Head, queue** Tail,/*int* nom,*/ int* k, int* l, double* time, int* number)
{
    queue* Temp=(*Head)->prev;//cout<<endl<<"POP H->pr->num: "<<(*Head)->prev->num<<endl;

    while((Temp->prishla)> *time  && (Temp!=*Tail))
        Temp=Temp->prev;

    if( !Length(Head,Tail,*time) || (Temp==*Tail))
    {
        cout<<"Trouble"<<endl;
        return(0);
    }

    double a=Temp->tobr;//cout<<a<<" H->p->tobr: "<<(*Head)->prev->tobr<<" num: "<<(*Head)->prev->num;
    (Temp->prev)->next=(*Head);
    (*Head)->prev=Temp->prev;
    *time+=a;

    if(Temp->prob <0.8)
    {
        //++(*nom);
        queue* A=(queue*)malloc(sizeof(queue));

        A->next=((*Tail)->next);
        A->prev=(*Tail);

        ((*Tail)->next)->prev=A;
        (*Tail)->next=A;

        A->num=Temp->num;
        A->waiting=Temp->waiting + *time - a - Temp->prishla;
        A->prob=Tobr();
        A->tobr=a;
        //A->tprih=Temp->tprih;
        A->prishla=*time;
        ++(*l);
        //Print(*Head,*Tail);
            free(Temp);
            *number=0;
            return (0);
    }
    a=Temp->waiting;
    ++(*k);
    *number=Temp->num;
    free(Temp);
    //cout<<Length(Head,Tail)<<"|"<<a<<endl;
    //Print(*Head,*Tail);
    return(a);
}

