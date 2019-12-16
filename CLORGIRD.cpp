#include<stdio.h>
#include<iostream>
#define MAX 1001
using namespace std;

int main(){
	int T,n,m,i,j,temp,poss,flag;
	char arr[MAX][MAX];
	
	scanf("%d",&T);
	while(T--){
		poss = 1;
		temp = 0;
		scanf("%d %d",&n,&m);
		for(i=0 ; i< n ; i++){
			for(j=0 ; j<m ; j++){
				cin >> arr[i][j];
			}
		}
		/*
		printf("Array is :\n");
		for(i=0 ; i< n ; i++){
			for(j=0 ; j<m ; j++){
				printf("%c  ",arr[i][j]);
			}
			printf("\n");
		}
		*/
		i=1;
		for(j=0 ; j<m ; j++){
			if( (arr[i][j]=='#' && arr[i-1][j]!='#') || (arr[n-2][j]=='#' && arr[n-1][j]!='#')){
				poss=0;
				break;
			}
		}
		
		if(poss){
			j=1;
			for(i=0 ; i<n ; i++){
				if( (arr[i][j]=='#' && arr[i][j-1]!='#') || (arr[i][m-2]=='#' && arr[i][m-1]!='#') ){
					poss=0;
					break;
				}
			}
		}	
		
		if(poss == 0){
			printf("NO\n");
			continue;
		}
		
		i=0;
		for(j=0 ; j<m-2 ; j++){
			if(arr[i][j]=='#'){
				if(arr[i][j+1] == '#'){
					continue;
				}
				else if(arr[i][j+2] == '#'){
					poss=0;
					break;
				}
			}
		}
		if(poss){
			i=n-1;
			for(j=0 ; j<m-2 ; j++){
				if(arr[i][j]=='#'){
					if(arr[i][j+1] == '#'){
						continue;
					}
					else if(arr[i][j+2] == '#'){
						poss=0;
						break;
					}
				}
			}		
		}
		if(poss){
			j=0;
			for(i=0 ; i<n-2 ; i++){
				if(arr[i][j]=='#'){
					if(arr[i+1][j] == '#'){
						continue;
					}
					else if(arr[i+2][j] == '#'){
						poss=0;
						break;
					}
				}
			}		
		}
		if(poss){
			j=m-1;
			for(i=0 ; i<n-2 ; i++){
				if(arr[i][j]=='#'){
					if(arr[i+1][j] == '#'){
						continue;
					}
					else if(arr[i+2][j] == '#'){
						poss=0;
						break;
					}
				}
			}		
		}
		
		if(poss==0){
			printf("NO\n");
			continue;
		}
		//printf("%d",poss);
		flag=0;
		for(i=2 ; i< n-2 ; i++){
			for(j=2 ; j<m-2 ; j++){
				if( (arr[i][j] == '#') && ( (arr[i+2][j]=='#' && arr[i+1][j]!='#') || 
											(arr[i-2][j]=='#' && arr[i-1][j]!='#') || 
											(arr[i][j-2]=='#' && arr[i][j-1]!='#') || 
											(arr[i][j+2]=='#' && arr[i][j+1]!='#') ) 
											) {
					poss=0;
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		
		if(poss==0)
			printf("NO\n");
		else
			printf("YES\n");
		
	}
}