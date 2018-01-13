

/*

File bit_manipulation.c

Purpose :
contains helper functions for manipulating bits

* /



/************************************************************************/


// INCLUDE FILES
#include "bit_manipulation.h"


/************************************************************************/

//MACROS  / DEFINES


/************************************************************************/

// FUNCTION PROTOTYPES


/***************************************************/



//example of a testing function main();

#if 0

int mainTest(int argc, char *argv[])

{

	int rc = 0;		// return code

	short test = 0;
	short modified;
	int bitNum;		// bit number to be used

	test = 0;
	bitNum = 2;
	modified = test;
	flipBitShort(bitNum, &modified);
	printf("test_int=%d, flipping bit #=%d, answer should be=%d, test_modified=%d\n", test, bitNum, 4, modified);



	rc = isShortBitSet(modified, 3);
	printf("Bit 3 in %d should not be set.  Answer is %d \n", modified, rc);



	rc = isShortBitSet(modified, 2);
	printf("Bit 2 in %d should  be set.  Answer is %d \n", modified, rc);
       
	rc = countBits(63);
	printf("%d", rc);
	
    getchar();

	return(0);

}


#endif



/*************************************************************************************/

/* purpose: checks if bit i is set

input:
c - the character to be checked
bitNum - the bit number to be checked

return:
1 if the bit is set to 1
0 if the bit is not set (bit is 0)

*/



int isCharBitSet(char c, int bitNum)

{
    return ((c>>bitNum) & 1); // move to position of bit, compare value with & 1
}


/*************************************************************************************/



/* purpose: checks if bit i is set



input: 
num - the number to be checked
bitNum - the bit number to be checked 

return:
1 if the bit is set to 1
0 if the bit is not set (bit is 0)



*/

int isShortBitSet(short num, int bitNum)

{
    return ((num>>bitNum) & 1); // move to position of bit, compare value with & 1
}



/*************************************************************************************/

/* purpose: sets bit bitNum to 1 



input:
num - the address of the short integer
bitNum - the bit number to be checked

*/

void setShortBit(int bitNum, short *num)

{
    *num |= (1<<bitNum); // sets the short bit
}



/*************************************************************************************/


/* purpose: sets bit bitNum to 1

input:
c - address of character 
bitNum - the bit number to be checked

return:
1 if the bit is set to 1
0 if the bit is not set (bit is 0)

*/

void setCharBit(int bitNum, char *c)

{
    *c |= (1<<bitNum); // sets the char bit
}



/*************************************************************************************/


/*  count the number of bits in a short

input: 
num - a short interger

return
the number of bits that are set to 1 in num
*/


int countBits(short num)

{
    int numBits = 0;
    
	for (int i=0; i<sizeof(num)*8; i++) {
		if (((num>>i) & 1) == 1) numBits++;
    }
    return numBits;
}


/*************************************************************************************/

/* purpose:

flips bit i in num (set bit i to 1 if the bit is 0 or set bit i to 0 if the bit is 1)

input:
bitNum - the bit number to be flipped
num - address of the short integer

*/

void flipBitShort(int bitNum, short *num)

{
    *num ^= (1<<bitNum);
}


/*************************************************************************************/
















