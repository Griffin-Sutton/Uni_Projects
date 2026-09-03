#include <iostream>
using namespace std;

int get_total(int, int[]);
const int SIZE = 5;

int main(){
    int my_array[SIZE] = {7, 14, 1, 5, 3};
    cout << "The total of the array elements: ";
    cout << get_total(0, my_array) << endl << endl;
    return 0;
}

int get_total(int a, int array[]){
    if (a < SIZE){
        return get_total(a+1, array) + array[a];
    }
    else{
        return 0;
    }
}