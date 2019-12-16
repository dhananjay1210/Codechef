#include<iostream>
#define MAX 100001
using namespace std;

int main(){
	int T,flag;
	long i,n,arr[MAX],aai[MAX],hash[MAX];
	
	cin >> T;
	while(T--){
		cin >> n;
		for(i=1 ; i<=n ; i++){
			cin >> arr[i];
		}
		
		for(i=1 ; i<=n ; i++){
			aai[i] = arr[arr[i]];
		}
		
		for(i=1 ; i<=n ; i++){
			hash[i] = 0;
		}
		
		flag=0;
		for(i=1 ; i<=n ; i++){
			if(hash[aai[i]]==0)
				hash[aai[i]] = arr[i];
			else if(hash[aai[i]] != arr[i]){
				flag=1;
				break;
			}
		}
		
		if(flag==1)
			cout << "Truly Happy" << endl;
		else
			cout << "Poor Chef" << endl;	
	}
}