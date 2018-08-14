#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
//实现List列表的add,remmove以及.length操作；
template<class T>
class List {
private:
	T * data;
public:
	int count = 0;
	//向列表最后添加一个数据
	void add(T num) {
		count++;
		data = (T*)realloc(data, sizeof(T)*(count));
		data[count - 1] = num;
	}
	T operator[](int index) {
		return data[index];
	}
	//移除列表中的数据
	void remove(int index) {
		for (int i = index; i < count - 1; i++) {
			data[i] = data[i + 1];
		}
		data = (T*)realloc(data, sizeof(T)*(count - 1));
		count--;
	}
	void Clear() {
		if (count> 0) {
			data = NULL;
			count = 0;
		}
	}
};

class String {
private:
	char*data;
	bool ifEqual(int i, char *substr, int sublen) {
		for (int j = 0; j < sublen; j++) {
			if (substr[j] == data[i + j]) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
public:
	int length = 0;
	String(){}
	String(const char * str) {
		int i = 0;
		while (str[i] != '\0') {
			i++;
		}
		length = i;
		data = (char*)malloc(sizeof(char)*(length + 1));
		for (int i = 0; i < length + 1; i++) {
			data[i] = str[i];
		}
	}
	void operator=(const char * str) {
		int i = 0;
		while (str[i] != '\0') {
			i++;
		}
		length = i;
		if (data != NULL) {
			free(data);
		}
		data = (char*)malloc(sizeof(char)*(length + 1));
		for (int i = 0; i < length + 1; i++) {
			data[i] = str[i];
		}
	}
	void operator+=(String a) {
		data = (char*)realloc(data, length + a.length + 1);
		int index = 0;
		for (int i = length; i < length + a.length +1; i++) {
			data[i] = a.data[index++];
		}
		length = length + a.length;


	}
	String operator+(String a) {
		String c;
		c.data = (char*)realloc(data, length + a.length + 1);
		int index = 0;
		for (int i = length; i < length + a.length + 1; i++) {
			data[i] = a.data[index++];
		}
		c.length = length + a.length;
		return c;
	}
	friend ostream& operator<< (ostream &co,String t){
		cout << t.data;
		return co;
	}
	bool Contains(String subStr) {
		for (int i = 0; i < length; i++) {
			if (data[i] == subStr.data[0]) {
				for (int j = 0; j < subStr.length; j++) {
					if (ifEqual(i, subStr.data, subStr.length)) {
						return true;
					}
				}
			}
		}
		return false;
	}
	char operator[](int index){
		if (index < length&&index>0) {
			return data[index];
		}
		else {
			return false;
		}
	}
	String SubString(int start, int end) {
		String result;
		int len = end - start;
		if (start >= length) {
			result = "起始位置超出长度";
		}
		else if (start + len <= length) {
			char * substr = (char*)malloc(sizeof(char)*(len + 1));
			int index = 0;
			for (int i = start; i < length, index < len; i++, index++) {
				substr[index] = data[i];
			}
			substr[index] = '\0';
			result = substr;
		}
		else {
			result = "终点位置超出长度";
		}
		return result;
	}
	bool Equals(String a) {
		if (length == a.length) {
			for (int i = 0; i < length; i++) {
				if (data[i] == a.data[i]) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
		return true;
	}
	bool operator==(String a) {
		if (length == a.length) {
			for (int i = 0; i < length; i++) {
				if (data[i] == a.data[i]) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
		return true;
	}
	void Upper() {
		for (int i = 0; i < length; i++) {
			if (((int)data[i]) >= 97 && ((int)data[i]) <= 122) {
				data[i] -= 32;
			}
		}
	}
	void Lower() {
		for (int i = 0; i < length; i++) {
			if (((int)data[i]) >= 65 && ((int)data[i]) <= 90) {
				data[i] += 32;
			}
		}
	}
};
template <class t1, class t2>
class Dictionary {
public:
	t1 name;
	t2 value;
	Dictionary() {

	}
	Dictionary(t1 n, t2 v) {
		name = n;
		value = v;
	}

};
template<class t>
class Stack {
private:
	int length;
	t* data;
public :
	int top = 0;
	Stack(int l) {
		length = l;
		data = (t*)malloc(sizeof(t)*l);
	}
	void Push(t d) {
		if (top < length) {
			data[top++] = d;
		}
	}
	t Pop() {
		if (top > 0) {
			top--;
			return data[top];
		}
	}
	bool isFull() {
		if (top == length) {
			return true;
		}
		else {
			return false;
		}
	}
	void Clear() {
		if (top > 0) {
			top = 0;
		}
	}
};