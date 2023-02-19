#include <iostream>

#include "sorts.h"
using namespace std;

void insertionSort(int* ar,int size){
        int element;
        int indexArr;
        int j;
        int key=0;
        for(int i = 1; i < size; i++) {//i- текущий элемент
        

                key=0;
                for( j = i-1; j >= 0; j--) { //j- по какой элемент с i мы будим двигать
                       
                        if (ar[j] > ar[i]) {
                                key=1;
                                element = ar[i];//запомнили элемнт который мы будем двигать
                                indexArr = j+1; //запомнили по какой индекс с конца по начало будем двигаться 
                                break;
                        }
                }
                if(key==0){
                     element = ar[i];
                     indexArr = j+1;
                }
                for(  j= i-1; j>=indexArr; j--){
                      
                        ar[ j+1] = ar[ j];
                }//переставили элементы
                ar[indexArr] = element;//в ручную бахнули элемент с конца по начало 
        }
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void quickSort(int* ar, int size) {
	int left = 0;
	int right = size - 1;
	int pivot = ar[size >> 1];

	while(left <= right) {
		while(ar[left] < pivot) {
			left++;
		}

		while (ar[right] > pivot) {
			right--;
		}

		if (left <= right) {
			swap(ar[right], ar[left]);
			right--;
			left++;
		}
	}
	if (right > 0) {
		quickSort(&ar[0], right + 1);
	}

	if (left < size) {
		quickSort(&ar[left], size - left);
	}
}
static void merge(int* ar, int size, int central) {
    int left = 0;
    int right = central;
    int* arTemp = new int [size];
    int indexTemp = 0;

    while (left < central && right < size) {
        while(ar[left] <= ar[right] && left < central) {
            arTemp[indexTemp++] = ar[left++];
//            left++;
//            indexTemp++;
        }
        while(ar[left] > ar[right] && right < size) {
            arTemp[indexTemp] = ar[right];
            indexTemp++;
            right++;
        }
    }

    while (left < central) {
        arTemp[indexTemp++] = ar[left++];
    }
    while (right < size) {
        arTemp[indexTemp++] = ar[right++];
    }

    memcpy(ar, arTemp, size * sizeof(int));

    delete [] arTemp;
}

void mergeSort(int* ar, int size) {
    if (size <= 1) {
        return;
    }
    mergeSort(&ar[0], size >> 1);
    mergeSort(&ar[size >> 1], size - (size >> 1));

    merge(ar, size, size >> 1);
}

void bubbleSort(int* ar,int size){
    int num;
    for(int s=size;s>0;s--){
        for(int i=0;i<size-1;i++){
            if (ar[i]<ar[i+1]){
                num = ar[i];
                ar[i]=ar[i+1];
                ar[i+1]=num;
            }
        }
    }
}
void selectionSort(int* ar,int size){
    int tmpMax;
    int nb;
    int tmp;
    int bufer;
     for(int i=0;i<size;i++){
         tmpMax=ar[i];//предпологаем что 1 элемент последовательности максимальный
        nb=i;//запоминаем индекс начала проверяемого массива
       tmp=i;//для индекса максимума
       for (int j=i+1;j<size;j++){
          if(tmpMax>ar[j]){
              tmpMax=ar[j];//нашли локальный максимум
              tmp=j;//сохранили индекс максимума
          }
       }
         
       bufer=ar[nb];//меняем местами макс и начало
        ar[nb]=ar[tmp];
        ar[tmp]=bufer;
        }
}
void countsort(int *ar, int size){
    int max = retMax(ar,size);
    int array[max+1];
	for (int i = 0; i <max+1; i++){
		array[i] = 0;
	}
	
	
    for (int i = 0; i < size; i++){
		array[ar[i]]++;
	}
    
    int key = 0;
    for (int i = 0; i <= max; i++){
		for (int j = key; j < key + array[i]; j++){
			ar[j] = i;
		}
		key += array[i];
	}
}
