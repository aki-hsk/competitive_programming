#include <bits/stdc++.h>
using namespace std;

int ld[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int y){
	return (y%4==0 && y%100!=0) || y%400==0;
}

int main(){
	int y,m,d;
	scanf("%d/%d/%d",&y,&m,&d);
	while(y % (m*d) != 0){
		if(d == ld[m-1]+(leap(y)&&m==2)){
			m++;
			d = 0;
		}
		if(m > 12) m = 1,y++;
		d++;
	}
	printf("%d/%02d/%02d\n",y,m,d);
	return 0;
}