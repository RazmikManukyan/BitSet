#ifndef BitSet_h
#define BitSet_h

class BitSet {
private:
	unsigned long* ptr;
public:
	BitSet(int);
	~BitSet();
	void set(int);
	void reset(int);
};

#endif
