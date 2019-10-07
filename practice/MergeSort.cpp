#include<iostream>
using namespace std;


struct KV {
	char K;
	int V;
};


bool comp(KV X, KV Y) {
	if(X.V!=Y.V) {
		return X.V > Y.V;
	} else {
		return X.K < Y.K;
	}
}


KV a[5];

void merge(int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    KV L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if(comp(L[i],R[j])) { 
            a[k] = L[i]; 
            i++; 
        } else { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


void merge_sort(int low, int high) {
	if(low<high) {
		int mid = (low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);	
		merge(low,mid,high);
	} 
}


int main() {

	KV x;

	x.K = 'n';
	x.V =  5;
	a[0] = x;

	x.K = 'y';
	x.V = 2;
	a[1] = x;

	x.K = 'f';
	x.V =  2;
	a[2] = x;

	x.K = 'd';
	x.V = 2;
	a[3] = x;

	x.K = 'a';
	x.V =  2;
	a[4] = x;

	for(int i=0;i<5;i++) 
		cout<<"{"<<a[i].K<<" "<<a[i].V<<"} ";
	cout<<endl;

	merge_sort(0,4);

	for(int i=0;i<5;i++) 
		cout<<"{"<<a[i].K<<" "<<a[i].V<<"} ";
	cout<<endl;

	return 0;
}