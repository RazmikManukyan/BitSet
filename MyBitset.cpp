#include <iostream>

template<size_t N>
class MyBitset {
    static const size_t NUM_WORDS = (N + 31) / 32;// Number of 32-bit words needed to store N bits
    unsigned int data[NUM_WORDS] = {0};// Array to store the bits
public:
    // Default constructor (initialize all bits to 0)
    MyBitset() = default;

    // Constructor to initialize from an unsigned integer value
     explicit MyBitset(unsigned int value) {
        for(int i = 0; i < N; ++i) {
            set(i, value & 1);
            value >>= 1;
        }
    }

    // Set the i-th bit to 1 (true) or 0 (false)
    void set(size_t i, bool value) {
        if (i >= N) {
            return;
        }

        size_t wordIndex = i / 32;
        size_t bitIndex = i % 32;

        if(value) {
            data[wordIndex] |= (1u << bitIndex);// Set the bit to 1
        } else {
            data[wordIndex] &= ~(1u << bitIndex);// Set the bit to 0
        }
    }


    // Get the value of the i-th bit
    [[nodiscard]] bool get(size_t i) const {
        if (i >= N) {
            return false;
        }
        size_t wordIndex = i / 32;
        size_t bitIndex = i % 32;

        return (data[wordIndex] & (1u << bitIndex)) != 0;
    }

    // Count the number of set bits (1s) in the bitset
    [[nodiscard]] size_t count() const {
        size_t count = 0;
        for(int i = 0; i < NUM_WORDS; ++i) {
            unsigned int word = data[i];
            if(word != 0) {
                count += (word & 1);
                word >>= 1;
            }
        }
        return count;
    }

    // Flip all the bits (change 0 to 1 and vice versa)
    void flip() {
        for(int i = 0; i < NUM_WORDS; ++i) {
            data[i] = ~data[i];
        }
    }

    // Reset all bits to 0
    void reset() {
        for(int i = 0; i < NUM_WORDS; ++i) {
            data[i] = 0;
        }
    }
    // Overload the bitwise AND operator '&'
    MyBitset<N> operator&(const MyBitset<N>& other) const {
         MyBitset<N> result;
         for(int i = 0 ; i < NUM_WORDS; ++i) {
             result.data[i] = this->data[i] & other.data[i];
         }
         return result;
     }

    // Overload the bitwise OR operator '|'
    MyBitset<N> operator|(const MyBitset<N>& other) const {
         MyBitset<N> result;
         for(int i = 0; i < NUM_WORDS; ++i) {
             result.data[i] = this->data[i] | other.data[i];
         }
         return result;
     }

    // Overload the bitwise NOT operator '~'
    MyBitset<N> operator~() const {
         MyBitset<N> result;
         for(int i = 0; i < NUM_WORDS; ++i) {
             result.data[i] = ~this->data[i];
         }
         return result;
     }
};
