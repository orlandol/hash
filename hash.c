#include <stdio.h>

#include "keyarray.h"

/*
 *  Statistics list
 */

  DECLARE_STRING_KEYARRAY_TYPES( HashList, char* )

/*
 *  General declarations and functions
 */

  HashList* hashList = NULL;
  HashList* collisionList = NULL;

  unsigned line;
  unsigned column;

  char ReadChar( FILE* file ) {
    return 0;
  }

  void SkipComments( FILE* file ) {
  }

/*
 *  Bit-2 Hash (Draft)
 *
 *  Hash method using a look up table for each identifier character.
 *    Each look up table entry has two bits. Each bit overlaps with
 *    a different table entry. Ideally, no bits should overlap.
 *
 */

  const unsigned bit2Table[63] = {
  /* _ */
  /* a */
  /* z */
  /* A */
  /* Z */
  /* 0 */
  /* 9 */
  };

  unsigned Bit2Hash( char* ident ) {
    return 0;
  }

  void RunBit2Test( char* fileName ) {
  }

/*
 *  64K Value Hash (Draft)
 *
 *  Hash method which counts selected bits. 65536 bits are compressed
 *    down to 16-bits. Most frequent characters have a value of 1.
 *    Characters of average frequency have a value of 2. Characters of
 *    low frequency have a value of 3.
 *
 */

  const unsigned bit64kTable[63] = {
  /* _ */
  /* a */
  /* z */
  /* A */
  /* Z */
  /* 0 */
  /* 9 */
  };

  unsigned Bit64kHash( char* ident ) {
    return 0;
  }

  void RunBit64kTest( char* fileName ) {
  }

/*
 *  Weighted 64K Hash (Draft)
 *
 *  Hash method which keeps a count of characters, grouped by
 *    frequency of infrequent, average, and frequent. 65536 bits
 *    are compressed to 16-bits. Hash code is calculated as
 *    (infrequent * X) + (average * Y) + frequent.
 *
 */

  const unsigned weighted64kTable[63] = {
  /* _ */
  /* a */
  /* z */
  /* A */
  /* Z */
  /* 0 */
  /* 9 */
  };

  unsigned Weighted64kHash( char* ident ) {
    return 0;
  }

  void RunWeighted64kTest( char* fileName ) {
  }

/*
 *  TwoPassHash (Draft)
 *
 *  Hash method which counts characters, then calculates the hash
 *    value by combining each character count.
 *
 */

  const unsigned twoPassTable[63] = {
  /* _ */
  /* a */
  /* z */
  /* A */
  /* Z */
  /* 0 */
  /* 9 */
  };

  unsigned TwoPassHash( char* ident ) {
    return 0;
  }

  void RunTwoPassTest( char* fileName ) {
  }

/*
 *  Main program
 */

int main( int argc, char* argv[] ) {

  if( argc < 2 ) {
    printf( "\nUsage: hash file.ext\n" );
    return 1;
  }

  return 0;
}
