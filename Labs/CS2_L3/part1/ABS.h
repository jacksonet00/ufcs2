#ifndef ABS_H
#define ABS_H
#include <iostream>
using namespace std;

template <typename T>

class ABS {
private:
	unsigned int capacity;
	unsigned int size;
	T* arr;
public:
	ABS() {
		capacity = 1;
		size = 0;
		arr = new T[capacity];
	}

	~ABS() {
		delete[] arr;
	}

	ABS(int c) {
		capacity = c;
		size = 0;
		arr = new T[capacity];
	}

	unsigned int getSize() { return size; }
	unsigned int getMaxCapacity() { return capacity; }
	T* getData() { return arr; }

	ABS(const ABS &d) {
		capacity = d.capacity;
		size = d.size;
		arr = new T[capacity];

		for(int i = 0; i < (int) size; i++) {
			arr[i] = d.arr[i];
		}
	}

	ABS &operator=(const ABS& d) {
		ABS object;

		object.capacity = d.capacity;
		object.size = d.size;
		object.arr = new T[d.capacity];

		for(int i = 0; i < (int) d.size; i++) {
			object.arr[i] = d.arr[i];
		}

		return object;
	}

	void push(T data) {
		if(capacity == size) {
			capacity *= 2.0;

			T* pushArr = new T[capacity];

			for(int i = 0; i < (int) size; i++) {
				pushArr[i] = arr[i];
			}

			delete[] arr;
			arr = pushArr;
		}

		arr[size] = data;
		size++;
	}

	T pop() {
		if(size == 0) {
			throw runtime_error("Runtime Error: Stack Empty!");
		}

		T object = arr[size - 1];
		size--;

		double fillCapacity = (double) size / capacity;

		if(fillCapacity < 0.5) {
			capacity /= 2.0;

			T* popArr = new T[capacity];

			for(int i = 0; i < (int) size; i++) {
				popArr[i] = arr[i];
			}

			delete[] arr;
			arr = popArr;
		}

		return object;
	}

	T peek() {
		if(size == 0) {
			throw runtime_error("Runtime Error: Stack Empty!");
		}

		return arr[size - 1];
	}
};
#endif