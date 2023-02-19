#include <iostream>

#include "arraywork.h"
using namespace std;
int isSort (int* ar,int size){
    int key=-1;
    int i=0;
   while(i<size-1){
      if ((ar[i]>ar[i+1] and  key==1) or (ar[i]<ar[i+1] and key==0)){
          key=-1;
          
          break;
       }
      else if (ar[i]<=ar[i+1]){
           key=1;
           
       }
       else if(ar[i]>=ar[i+1]){
           key=0;
           
       }
       i++;
   }
   return key;
}
void randomFilling(int* ar,int size,int min,int max){
     srand(time(0));
     for(int p = 0;p < size; p++){
        int num = min + rand() % (max - min + 1);
        ar[p] = num;
}}
void print(int* ar,int size){
    for (int n=0;n<size;n++){
        cout << ar[n] << " ";
    }
    }

int retMax(int* ar,int size){
    int  max=ar[0];    
    for (int n=0;n<size;n++){
        if (ar[n]>max){max=ar[n];}
    }
    return(max);
    }
int retMin(int* ar,int size){
    int  min=ar[0];    
    for (int n=0;n<size;n++){
        if (ar[n]<min){min=ar[n];}
    }
    return(min);
    }
