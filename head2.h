#pragma once
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
void Sort(int data[], int length, int type);

//数组排序
//直接插入排序
void Sort(int data[], int length,int type) {
	if (type == 0) {//0代表正序，从小到大
		int flag = 0;
		for (int i = 1; i < length; i++) {
			if (data[i] < data[i - 1]) {
				flag = data[i];
				int j = i - 1;
				for (j; flag < data[j]; j--) {
					data[j + 1] = data[j];
				}
				data[j + 1] = flag;
			}
		}
	}
	else if (type == 1) {//倒序，从大到小
		int flag = 0;
		for (int i = 1; i < length; i++) {
			if (data[i] > data[i - 1]) {
				flag = data[i];
				int j = i - 1;
				for (j; flag > data[j] && j >= 0; j--) {
					data[j + 1] = data[j];
				}
				data[j + 1] = flag;
			}
		}
	}
}
template<class t>
void Reverse(t data[], int length)
{
	for (int i = 0; i <= length / 2; i++) {
		t tmp = data[i];
		data[i] = data[length - 1 - i];
		data[length - 1 - i] = tmp;
	}
}

template<class t>
double Average(t data[], int length) {
	double sum = 0;
	for (int i = 0; i< length; i++) {
		sum += data[i];
	}
	sum /= length;
	return sum;
}