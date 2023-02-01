#include "BitSet.h"
#include <iostream>


BitSet::BitSet(int index) {
	ptr = new unsigned long[(index + 31) / 32];	
}

BitSet::~BitSet() {
	delete[] ptr;
}

void BitSet::set(int n) {
	int index = n / 64;
	int pos = n % 64;
	ptr[index] |= (1 << pos);
}

void BitSet::reset(int n) {
	int index = n / 64;
	int pos = n % 64;
	if (ptr[index] & (1 << pos)) {
		ptr[index] ^= (1 << pos);
	}
}	
