#include<stdio.h>
#include<math.h>


int main(){
	long T,N,bit,nibble,byte,time,rem;
	scanf("%ld",&T);
	
	while(T--){
		scanf("%ld",&N);
		bit=1;nibble=0;byte=0,time=0;
		rem = N / 26;
		bit = pow(2,rem);
		if(bit==0)
			bit=1;
		N = N % 26;
		//time = rem * 26;
		//printf("Debud ---  %ld %ld %ld\n",bit,nibble,byte);
		if(N==0 ){
			byte = bit/2;
			bit = 0;
			nibble =0;
		}
		while(time<N){
			//printf("Debud ---  %ld %ld %ld %ld\n",bit,nibble,byte,time);
			time += 2;
			if(time<N){
				nibble = bit;
				bit=0;
				time += 8;
				if(time<N){
					byte=nibble;
					nibble=0;
					time += 16;
					if(time<N){
						bit = 2 * byte;
						byte = 0;
					}
				}
				
			}
		}
		printf("%ld %ld %ld\n",bit,nibble,byte);
	}
}