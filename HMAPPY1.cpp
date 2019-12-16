#include<iostream>
#include<stdlib.h>
#define MAX 100001
using namespace std;

long isRotate(long m1,long s1,long n){
	if(n-s1 < m1)
		return n-s1;
	return 0;
}

long maxOf(long a1,long a2,long a3){
	if(a1>=a2){
		if(a1>=a3){
			return a1;
		}
		else{
			return a3;
		}
	}
	else{
		if(a2>=a3){
			return a2;
		}
		else{
			return a3;
		}
	}
}

int main(){
	long i,n,q,k,arr[MAX],m1=-1,m2=-1,m3,s1=-1,s2=-1,s3=0,temp=0,l1,mx;
	string str1;
	char ch;
	cin >> n >> q>>k;
	for(i=0 ; i<n ; i++){
		cin >> arr[i];
	}
	
	/*
	cout<< "Array is: "<<endl;
	for(i=0 ; i<n ; i++){
		cout << arr[i];
	}
	cout<<endl;
	*/
	
	cin >> str1;
	
	temp=0;
	for(i=0 ; i<n ; i++){
		if(arr[i]==1){
			temp++;
			
		}
		else{
			if(temp >= m1){
				m2=m1;
				s2=s1;
				m1=temp;
				s1=i-temp;
			}
			else {
				if(temp > m2){
					m2=temp;
					s2=i-temp;
				}
			}
			temp=0;
		}
	}
	
	//cout << "m1: " << m1<<" s1: "<<s1 <<endl<<"m2: "<<m2<<" s2: "<<s2<<endl;
	
	temp=0;
	for(i=0 ; i<n ; i++){
		if(arr[i]==1)
			temp++;
		else
			break;
	}
	
	for(i=n-1 ; i>-1 ; i--){
		if(arr[i]==1)
			temp++;
		else{
			s3=i+1;
			//cout<<s3<<endl;
			break;
		}
	}
	
	//cout << "temp: "<<temp<<" s3: "<<s3<<endl;
	if(s3>=n)
		s3=0;
	if(s1!=s3){
		if(s1==0){
			m1=temp;
			s1=s3;
		}
		else{
			if(temp >= m1 ){
				m2=m1;
				s2=s1;
				m1=temp;
				s1=s3;
			}
			else if(temp > m2){
				m2=temp;
				s2=s3;
			}
		}
	}
	if(m1>n)
		m1=n;
	//cout<<"Final"<<endl;
	//cout << "m1: " << m1<<" s1: "<<s1 <<endl<<"m2: "<<m2<<" s2: "<<s2<<endl;
	
	for(i=0 ; i<=str1.size(); i++){
		ch = str1[i];
		//cout << ch<<endl;
		if(ch=='?'){
			l1 = isRotate(m1,s1,n);
			if(l1 && m1!=n){
				mx = maxOf(l1,m2,m1-l1);
			}
			else{
				mx = m1;
			}
			if(mx > k)
				mx = k;
			cout << mx << endl;
		}
		else if(ch=='!'){
			s1++;
			s2++;
			if(s1==n){
				s1=0;
			}
			if(s2==n){
				s2=0;
			}
		}
	}
	
	return 0;
}