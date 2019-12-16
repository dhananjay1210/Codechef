#include<stdio.h>

int main(){
	int T,x,y,z;
	
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&x,&y,&z);
		if((x+y==z)  || (y+z==x) || (x+z==y))
			printf("yes\n");
		else
			printf("no\n");
	}
}