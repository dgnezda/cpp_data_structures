// 2. ADD OPERATOR[]? !!
// maybe "PEEK STREAM"
//
//  circular_buffer.cpp
//  data_structures
//
//  Created by Domen Gnezda on 10. 11. 2023.
//


#include <iostream>
using namespace std;


template<typename V>
class circular_buffer {
	size_t max_size {0};
	size_t num_elements {0};
	V *buffer = new V[max_size];

public:
	circular_buffer(const size_t &maximum_size)
	: max_size(maximum_size) 
	{}

	void add(V &value) {
		if (num_elements < max_size) {
			buffer[num_elements] = value;
			++num_elements;
		} else {
			_circulate();
			buffer[max_size - 1] = value;
		}
		cout << "Buffer after adding element: ";
		print();
	}

	void _circulate() {
		for (size_t i{0}; i < max_size - 1; ++i) {
			*(buffer + i) = *(buffer + (i + 1));
		}
	}

	void print() {
		if (num_elements == 0) {
			cout << "circular_buffer[] is empty!" << endl;
		} else {
			cout << "circular_buffer[ ";

			for (size_t i{0}; i < num_elements; ++i) {
				cout << buffer[i] << " ";
			}

			cout << "] - {" << num_elements << "} elements in buffer." << endl;
		}

	}

	~circular_buffer() {
		delete [] buffer;
	}

};

int main() {
	circular_buffer<int> buf {10};

	buf.print();

	for (int i = 0; i < 21; ++i) {
		buf.add(i);
	}

	buf.print();

	return 0;
}
