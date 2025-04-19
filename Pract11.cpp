#include<iostream>
#include<pthread.h>
using namespace std;

struct SumArgs {
    int* arr;
    int size;
};


// function to compute sum 
void* computeSum(void* arg) {
    SumArgs* args = (SumArgs*)arg;
    int* arr = args->arr;
    int size = args->size;

    int sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    cout << "Sum of given numbers: " << sum << endl;
    return NULL;
}

int main() {
    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    int* arr = new int[n]; // create arr or n size 
    cout << "Enter the elements: ";
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    pthread_t thread;
    SumArgs args;
    args.arr = arr;
    args.size = n;

    pthread_create(&thread, NULL, computeSum, &args); // create thread
    pthread_join(thread, NULL);

    delete[] arr;
    return 0;
}
