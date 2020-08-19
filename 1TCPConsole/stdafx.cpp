#include "stdafx.h"
void error(char* msg) {
	printf("%s\n", msg);
	exit(0);
}

//S=1+3+5+7+....+ (2n+1)\n
int TinhTonga(int n) {
	int i;
	int s = 0;
	for (i = 0; i <= n; ++i) 
		s = s + (2 * i + 1);
	return s;
}

//S=1*2 +2*3+...+n*(n+1)\n
int TinhTongb(int n) {
	int i, s = 0;
	for (i = 1; i <= n; ++i) {
		s = s + (i*(i + 1));
	}
	return s;
}

//S=1-2+3-4+...+(2n+1)\n
int TinhTongc(int n) {
	int i, s = 0;
	int t = -1;
	for ( i = 1; i <= 2*n+1; ++i)
	{
		t = t * -1;
		s = s + (t*i);
	}
	return s;
}

//S=a+b
int TinhTongd(int a, int b) {
	return a + b;
}

//tong lap phuong ( x3)
int TinhTonge(int a, int b) {
	return (a + b)*(a + b)*(a + b);
}

//Tong binh phuong
int TinhTongf(int a, int b) {
	return (a + b)*(a + b);
}

//S=1*2*3*....*n
int TinhTongg(int n) {
	int i , s = 1;
	for ( i = 1; i <=n; ++i)
	{
		s = s * i;
	}
	return s;
}

//S=1+2+3+...+n
int TinhTongh(int n) {
	int i, s = 0;
	for ( i = 1; i <=n; ++i)
	{
		s = s + i;
	}
	return s;
}