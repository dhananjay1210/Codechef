#include<iostream>
#define MAX 6
using namespace std;

int main(){
	long long int i,T,n,arr[MAX],x,y;
	long long int tpn;
	
	cin >> T;	
	for(i=0 ; i<T ; i++){
		cin>>arr[i];
	}
	
	for(i=0 ; i<T ; i++){
		n = arr[i];
		x=1;
		y=2;
		tpn=2;
		
		while(n--){
			x = y - x;
			y = tpn;
			tpn = tpn<<1;;
		}
		cout<<x<<" "<<y<<" ";
	}
	return 0;
}