#include<stdio.h>
#include<iostream>
#define MAX 1001
using namespace std;

int main(){
	int T;
	long i,n,arr[MAX],hash[MAX],count,ai,ai_c;
	
	scanf("%d",&T);
	while(T--){
		cin >> n;
		for(i=0 ; i<n ;i++){
			cin >> arr[i];
		}
		for(i=0 ; i<MAX ;i++){
			hash[i] = 0;
		}
		count=0;
		
		for(i=0 ; i<n ;i++){
			hash[arr[i]] += 1;
		}
		for(i=1 ; i<MAX ;i++){
			ai = i;
			ai_c = hash[i];
			if(ai_c > 0){
				if(ai_c >= ai)
					count++;
				if(hash[ai_c] >= ai && ai_c!=ai)
					count += 2;
				
			}
		}
		printf("%ld\n",count);
	}
}