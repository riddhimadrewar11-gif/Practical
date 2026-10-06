#include<iostream>
#include<utility>
using namespace std;

class Product {
    public:
    int ID;
    string name;
    float price;
};

class List {
    private:
    Product arr[20];
    int size;

    public:
    void input();
    int partition_ascen(int low,int high);
    int partition_descen(int low,int high);
    void quick_sort_ascen(int low , int high);
    void quick_sort_descen(int low , int high);
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
        cout<<"Enter product id: ";
        cin>>arr[i].ID;
        cout<<"Enter product name: ";
        cin>>arr[i].name;
        cout<<"Enter product price: ";
        cin>>arr[i].price;
    }
}


void List :: display() {
    cout<<"ID"<<"         "<<"Name"<<"          "<<"Price"<<endl;
    for(int i=0;i<size;i++){    
        cout<<arr[i].ID<<"          "<<arr[i].name<<"          "<<arr[i].price<<endl;
    }
}

int List ::  partition_ascen(int low,int high) {
    float pivot = arr[low].price;
    int i = low;
    int j = high;

    while(i<j) {
        while(i <= high && arr[i].price <= pivot) {
            i++;
        }
        while(j >= low && arr[j].price > pivot) {
            j--;
        }
        if(i < j) {
            Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Product temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

int List ::  partition_descen(int low,int high) {
    float pivot = arr[low].price;
    int i = low;
    int j = high;

    while(i<j) {
        while(i <= high && arr[i].price >= pivot) {
            i++;
        }
        while(j >= low && arr[j].price < pivot) {
            j--;
        }
        if(i < j) {
            Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Product temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}


void List :: quick_sort_ascen(int low , int high) {
    if(low<high){
        int pIndex = partition_ascen(low , high);
        quick_sort_ascen(low,pIndex-1);
        quick_sort_ascen(pIndex+1 , high);
    }
}

void List :: quick_sort_descen(int low , int high) {
    if(low<high){
        int pIndex = partition_descen(low , high);
        quick_sort_descen(low,pIndex-1);
        quick_sort_descen(pIndex+1 , high);
    }
}


int main() {
    List l;
    l.input();
    int length = l.Size();
    l.quick_sort_ascen(0 , length-1);
    l.display();

    l.quick_sort_descen(0 , length-1);
    l.display();

    return 0;
}