#include <iostream>

template<size_t N>
class MyBitset {
    static const size_t NUM_WORDS = (N + 31) / 32;// Number of 32-bit words needed to store N bits
    unsigned int data[NUM_WORDS] = {0};// Array to store the bits
public:
    // Default constructor (initialize all bits to 0)
    MyBitset() = default;

    // Constructor to initialize from an unsigned integer value
     explicit MyBitset(unsigned int);

    // Set the i-th bit to 1 (true) or 0 (false)
    void set(size_t , bool);


    // Get the value of the i-th bit
    [[nodiscard]] bool get(size_t ) const;

    // Count the number of set bits (1s) in the bitset
    [[nodiscard]] size_t count() const;

    // Flip all the bits (change 0 to 1 and vice versa)
    void flip();

    // Reset all bits to 0
    void reset();

    // Overload the bitwise AND operator '&'
    MyBitset<N> operator&(const MyBitset<N>&) const;

    // Overload the bitwise OR operator '|'
    MyBitset<N> operator|(const MyBitset<N>& other) const;

    // Overload the bitwise NOT operator '~'
    MyBitset<N> operator~() const;
};



