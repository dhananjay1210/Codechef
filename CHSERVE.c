#include<stdio.h>
typedef long long int lli;

int main(){
	int T;
	lli p1,p2,k,sum,rem;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld",&p1,&p2,&k);
		
		sum = p1+p2;
		rem = sum % (2*k);
		//printf("%lld  %lld",sum,rem);
		if(rem < k){
			
			printf("CHEF\n");
		}
		else{
			printf("COOK\n");
		}
	}
}