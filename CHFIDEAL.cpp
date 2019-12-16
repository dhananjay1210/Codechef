#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	int arr[4],i,x,y,z;
	for(i=0 ; i<4 ; i++){
		arr[i] = 0;
	}
	
	x = rand() % 3 + 1;
	arr[x] = 1;
	cout << x <<endl;
	cin >> y ;
	arr[y]=1;
	arr[y] = 1;
	for(i=1 ; i<4 ; i++){
		if(arr[i] == 0){
			cout << i << endl;
		}
	}
}