#include "circular_buffer.hpp"


int main() {
	circular_buffer<int> buf {10};

	buf.print();

	for (int i = 0; i < 21; ++i) {
		buf.add(i);
	}

	buf.print();

	return 0;
}