#include<iostream>
using namespace std;

int main(){
	int N,i,r;
	cin >> N >> r;
	int arr[N];
	
	for(i=0 ; i<N ; i++){
		cin >> arr[i];
	}
	
	for(i=0 ; i<N ; i++){
		if(arr[i] < r){
			cout << "Bad boi" << endl;
		}
		else{
			cout << "Good boi" << endl;
		}
	}
	
}