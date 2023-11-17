//
//  circular_buffer.cpp
//  data_structures
//
//  Created by Domen Gnezda on 10. 11. 2023.
//

#ifndef _CIRCULAR_BUFFER_H_
#define _CIRCULAR_BUFFER_H_

#include <iostream>

template<typename V>
class circular_buffer {

private:
	size_t max_size;
	size_t num_elements {0};
	V *buffer; // = new V[max_size];

public:
	// circular_buffer(const size_t &maximum_size);	// Constructor
	// circular_buffer(const circular_buffer &source); // Copy Constructor
	// circular_buffer(circular_buffer &&source);		// Move Constructor
	// ~circular_buffer();								// Destructor

	// circular_buffer &operator=(const circular_buffer &rhs);	// Copy assignment
	// circular_buffer &operator=(circular_buffer &&rhs);		// Move assignment

	// void add(V &value);
	// void _circulate();
	// void print() const;
	// size_t get_size() const;

	// Constructor
	circular_buffer(const size_t &maximum_size)
		: max_size{maximum_size} {
			buffer = new V[max_size];
		}

	// Copy Constructor
	circular_buffer(const circular_buffer &source) 
		: buffer{nullptr} {
			buffer = new V[source.get_size()];
			for (size_t i{0}; i < source.get_size(); ++i) {
				buffer[i] = source.buffer[i];
			}
		}

	// Move Constructor
	circular_buffer(circular_buffer &&source)
		: buffer{source.buffer} {
			source.buffer = nullptr;
	}


	// Destructor
	~circular_buffer() {
		delete [] this->buffer;
	}

	// Copy assignment
	circular_buffer &operator=(const circular_buffer &rhs) {
		if (this == &rhs)
			return *this;
		delete [] this->buffer;
		this->buffer = new V[rhs.get_size()];
		for (size_t i{0}; i < rhs.get_size(); ++i) {
			buffer[i] = rhs.buffer[i];
		}
		return *this;
	}

	// Move assignment
	circular_buffer &operator=(circular_buffer &&rhs) {
		if (this == &rhs)
			return *this;

		delete [] this->buffer;
		this->buffer = rhs.buffer;
		rhs.buffer = nullptr;
		return *this;
	}

	// Add value to buffer
	void add(V &value) {
		if (num_elements < max_size) {
			buffer[num_elements] = value;
			++num_elements;
		} else {
			_circulate();
			buffer[max_size - 1] = value;
		}
		std::cout << "circular_buffer after adding element: ";
		print();
	}

	// Helper function to circulate buffer
	void _circulate() {
		for (size_t i{0}; i < max_size - 1; ++i) {
			*(buffer + i) = *(buffer + (i + 1));
		}
	}

	// Print method
	void print() const {
		if (num_elements == 0) {
			std::cout << "circular_buffer[] is empty!" << std::endl;
		} else {
			std::cout << "circular_buffer[ ";

			for (size_t i{0}; i < num_elements; ++i) {
				std::cout << buffer[i] << " ";
			}

			std::cout << "] - {" << num_elements << "} elements in buffer." << std::endl;
		}
	}

	// Size getter
	void get_size() const {
		return this->max_size;
	}


};

#endif // _CIRCULAR_BUFFER_H_

