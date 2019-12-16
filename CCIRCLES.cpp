#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<iterator>
#define MAX 1001
typedef float fi;
typedef long long lli;
using namespace std;

struct circle{
	fi x;
	fi y;
	fi r;
};//arr[MAX];

struct range{
	fi r1;
	fi r2;
};

struct rangeAndCount{
	fi r1;
	fi r2;
	int count;
};

float calc(float a,float b,float c){
	return a*a + b*b + c*c + 2*a*b + 2*b*c + 2*a*c;
}

int main(){
	int found;
	lli n,q,i,j,count;
	fi k,tempX1,tempY1,tempR1,tempX2,tempY2,tempR2,maxR1,maxR2;
	fi distCen;
	int start,end,mid,ins1,ins2;
	rangeAndCount rc;
	
	scanf("%lld %lld",&n,&q);
	circle arr[n];
	range ra[n][n],cir;
	for(i=0 ; i<n ;i++){
		scanf("%f %f %f",&arr[i].x,&arr[i].y,&arr[i].r);
	}
	/*
	for(i=0 ; i<n ;i++){
		printf("%ld %ld %ld\n",arr[i].x,arr[i].y,arr[i].r);
	}
	*/
	for(i=0 ; i<n ;i++){
		tempX1 = arr[i].x;
		tempY1 = arr[i].y;
		tempR1 = arr[i].r;
		for(j=i+1 ; j<n ; j++){
			tempX2 = arr[j].x;
			tempY2 = arr[j].y;
			tempR2 = arr[j].r;
			distCen = (tempX2-tempX1)*(tempX2-tempX1) + (tempY2-tempY1)*(tempY2-tempY1);
			distCen = sqrt(distCen);
			if(tempR1 >= tempR2){
				maxR1 = tempR1;
				maxR2 = tempR2;
			}
			else{
				maxR1 = tempR2;
				maxR2 = tempR1;
			}
			//printf("DistCen : %f\t maxR1 : %f\t maxR2 : %f\n",distCen,maxR1,maxR2);
			if(distCen == 0 && maxR1 != maxR2){
				ra[i][j].r1 = (maxR1 - maxR2);//*(maxR1 - maxR2);
				ra[i][j].r2 = (maxR1 + maxR2);//*(maxR1 + maxR2);
			}
			else if(distCen == 0){
				ra[i][j].r1 = 0;
				ra[i][j].r2 = 2*maxR1;//4*maxR1*maxR1;
			}
			else if(distCen+maxR2 <= maxR1){
				ra[i][j].r1 = maxR1-distCen-maxR2;//calc(maxR1,(-1*distCen),(-1*maxR2));
				ra[i][j].r2 = maxR1+distCen+maxR2;//calc(distCen,maxR1,maxR2);
			}
			else if(distCen+maxR2 > maxR1 && distCen <= maxR1 + maxR2){
				ra[i][j].r1 = 0;
				ra[i][j].r2 = maxR1+distCen+maxR2;///calc(maxR1,distCen,maxR2);
			}
			else{
				ra[i][j].r1 = distCen-maxR1-maxR2;//calc(distCen,(-1*maxR1),(-1*maxR2));
				ra[i][j].r2 = maxR1+distCen+maxR2;//calc(distCen,maxR1,maxR2);
			}
		}
	}
	/*
	printf("Matrix is : \n");
	for(i=0 ; i<n ; i++){
		for(j=i+1 ; j<n ; j++){
			printf("%f,%f\t",ra[i][j].r1,ra[i][j].r2);
		}
		printf("\n");
	}
	*/
	vector<rangeAndCount> v1;
	for(i=0 ; i<n ;i++){
		for(j=i+1 ; j<n ; j++){
			cir = ra[i][j];
			tempX1 = cir.r1;
			tempX2 = cir.r2;
			
			start = 0;
			end = v1.size();
			found = 0;
			while(start != end && found != 1){
				mid = (start + end)/2;
				if(v1[mid].r1 <= tempX1 && v1[mid].r2 >= tempX1){
					found = 1;
					ins1 = mid;					
				}
				else if(v1[mid].r2< tempX1 ){
					start = mid + 1;
				}
				else if(v1[mid].r1 > tempX1){
					end = mid -1;
				}
			}
			if(found == 0){
				if(v[start].r1 > tempX2){
				
				}
				else{
				rc.r1 = tempX1;
				rc.r2 = tempX2;
				rc.count = 1;
				v1.push_back(rc);
			}
			else{
				start = ins1;
				end = v1.size();
				found = 0;
				while(start != end && found != 1){
					mid = (start + end)/2;
					if(v1[mid].r1 <= tempX2 && v1[mid].r2 >= tempX2){
						found = 1;
						ins2 = mid;					
					}
					else if(v1[mid].r2< tempX2 ){
						start = mid + 1;
					}
					else if(v1[mid].r1 > tempX2){
						end = mid -1;
					}
				}
			}
			//code for splitting node
			
		}
	}
	
	while(q--){
		scanf("%f",&k);
		//k = k*k;
		count = 0;
		for(i=0 ; i<n ; i++){
			for(j=i+1 ; j<n ; j++){
				if(k>=ra[i][j].r1 && k<=ra[i][j].r2){
					count++;
				}
			}
		}
		printf("%lld\n",count);
	}
	
	return 0;
}