#ifndef QUEUE_HEADER_H_INCLUDED
#define QUEUE_HEADER_H_INCLUDED

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct link
{
    link* next;
    link* prev;
    int num;
    double tprih;
    double prishla;
    double tobr;
    double prob;
    double waiting;

} queue;

double Tprih();
double Tobr();
void Add(queue** Tail, int* nom, double* time);
int Length(queue** Head, queue** Tail);
int Length(queue** Head, queue** Tail, double time);
double Pop(queue** Head,queue** Tail,/*int* nom,*/ int* k, int* l,double* time, int* number);
void Print(queue* Head, queue* Tail);

#endif // QUEUE_HEADER_H_INCLUDED
