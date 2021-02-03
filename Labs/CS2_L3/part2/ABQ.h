#ifndef ABQ_H
#define ABQ_H
#include <iostream>
using namespace std;

template <typename T>
class ABQ
{
private:
	unsigned int capacity;
	unsigned int size;
	T *arr;
public:
	ABQ() {
		capacity = 1;
		size = 0;
		arr = new T[capacity];
	}

	~ABQ() {
		delete[] arr;
	}

	ABQ(int c) {
		capacity = c;
		size = 0;
		arr = new T[capacity];
	}

	unsigned int getSize() { return size; }
	unsigned int getMaxCapacity() { return capacity; }
	T* getData() { return arr; }

	ABQ(const ABQ &d) {
		capacity = d.capacity;
		size = d.size;
		arr = new T[capacity];

		for(int i = 0; i < ((int) size); i++) {
			arr[i] = d.arr[i];
		}
	}

	ABQ &operator=(const ABQ &d) {
		ABQ object;
		object.capacity = d.capacity;
		object.size = d.size;
		object.arr = new T[d.capacity];

		for(int i = 0; i < ((int) d.size); i++) {
			object.arr[i] = d.arr[i];
		}

		return object;
	}

	void enqueue(T data) {
		if(size == capacity) {
			capacity *= 2.0;

			T* enqueueArr = new T[capacity];

			for(int i = 0; i < ((int) size); i++) {
				enqueueArr[i] = arr[i];
			}

			delete[] arr;
			arr = enqueueArr;
		}

		arr[size] = data;
		size++;
	}

	T dequeue() {
		if(size == 0) {
			throw runtime_error("Runtime Error: Stack Empty!");
		}

		T object = arr[0];

		for(int i = 0; i < (int) size - 1; i++) {
			arr[i] = arr[i+1];
		}

		size--;

		double fillCapacity = (double) size / capacity;

		if (fillCapacity < 0.5) {
			capacity /= 2.0;

			T* dequeueArr = new T[capacity];

			for(int i = 0; i < ((int) size); i++) {
				dequeueArr[i] = arr[i];
			}

			delete[] arr;
			arr = dequeueArr;
		}

		return object;
	}

	T peek() {
		if(size == 0) {
			throw runtime_error("Runtime Error: Stack Empty!");
		}

		return arr[0];
	}
	
};

#endif