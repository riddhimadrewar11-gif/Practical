#include<iostream>
#include<utility>
using namespace std;

class List {
    private:
    int arr[20];
    int size;

    public:
    void input();
    int partition(int low,int high);
    void quick_sort(int low , int high);
    void display();
    int Size(){
        return size;
    }
};

void List :: input() {
    cout<<"Enter size of list: ";
    cin>>size;

    cout<<"Enter list elements: ";
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
    }
}


void List :: display() {
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int List ::  partition(int low,int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j) {
        while(i <= high && arr[i] <= pivot) {
            i++;
        }
        while(j >= low && arr[j] > pivot) {
            j--;
        }
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void List :: quick_sort(int low , int high) {
    if(low<high){
        int pIndex = partition(low , high);
        quick_sort(low,pIndex-1);
        quick_sort(pIndex+1 , high);
    }
}


int main() {
    List l;
    l.input();
    int length = l.Size();
    l.quick_sort(0 , length-1);

    l.display();

    return 0;
}