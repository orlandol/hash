#include <stdio.h>

#include "keyarray.h"

/*
 *  Statistics list
 */

  DECLARE_STRING_KEYARRAY_TYPES( HashList, char* )

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

/*
 *  Test function
 */

  void RunTest( char* fileName, unsigned (*hashFunc)(char* ident) ) {
    FILE* wordFile = NULL;
    char curWord[64] = {};
    HashList* hashList = NULL;
    HashList* collisionList = NULL;
    unsigned line;
    unsigned column;

    wordFile = fopen(fileName, "rb");
    if( wordFile == NULL ) {
      printf( "  Error: Unable to open file '%s'\n", fileName );
      goto Cleanup;
    }

    while( feof(wordFile) == 0 ) {
      if( fgets(curWord, 64, wordFile) == NULL ) {
        break;
      }

      ///TODO: Add to collision list
    }

  Cleanup:
    if( wordFile ) {
      fclose( wordFile );
      wordFile = NULL;
    }
  }

/*
 *  Main program
 */

int main( int argc, char* argv[] ) {

  if( argc < 2 ) {
    printf( "\nUsage: hash file.ext\n" );
    return 1;
  }

  printf( "\nRunning Bit2Hash tests...\n" );
  RunTest( argv[1], Bit2Hash );

  return 0;
}
