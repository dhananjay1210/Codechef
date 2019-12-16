#include<stdio.h>

int main(){
	int T;
	long n,v1,v2,speed;
	char* str1;
	char temp,op;
	long long x=0,y=0;
	
	scanf("%d",&T);
	while(T--){
		scanf("%ld %ld %ld",&n,&v1,&v2);
		scanf("%s",str1);
		speed = v1;
		
		while(*str1 != '\0'){
			temp = *str1;
			if(temp == '*'){
				if(speed == v1)
					speed = v2;
				else
					speed = v1;
				
			}
			else{
				if(temp == 'N'){
					y += speed;
				}
				else if(temp == 'S'){
					y -= speed;
				}
				else if(temp == 'E'){
					x += speed;
				}
				else if(temp == 'W'){
					x -= speed;
				}
			}
			str1++;
		}
		if(x<0)
			x *= -1;
		if(y<0)
			y *= -1;
		
		
		if(x%2 == 0){
			op = 'B';
			if(y > x){
				y = y-x;
				if(y%2!=0)
					op = 'W';
			}
		}
		else{
			op = 'W';
			if(y > x){
				y = y-x;
				if(y%2!=0)
					op = 'B';
			}
		}
		printf("%c\n",op);
	}
}