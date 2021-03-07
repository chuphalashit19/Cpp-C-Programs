#include <iostream>
using namespace std;


void separate_odd_even(int a[], int n) {
    int i = -1;

    for( int j = 0; j < n; j++) {

        // If array of element is even then swap
        if (a[j] % 2 != 0) {
            i++;

            // swap the element
            swap(a[j], a[i]);
        }
    }
}

int main(void) {
    int i;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length_array = sizeof(a)/sizeof(int);
    separate_odd_even(a,length_array);
    cout << endl;
    for (i=0;i<length_array;i++) {
        if (i != length_array - 1)
            cout << a[i] << ", ";
        else
            cout << a[i];
    }
    cout << endl << endl;
}
