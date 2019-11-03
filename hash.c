
#include <ctype.h>
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

  /*
   *  EARIOTNSLCUDPMHGBFYWKVXZJQ
   *
   *  Letter frequency from Robert Lewand's Cryptological Mathematics
   *    cited by Pavel Micka per Wikipedia - Letter Frequency
   *    https://en.wikipedia.org/wiki/Letter_frequency
   *
   */

  const unsigned bit2Table[256] = {
    /* 000 */ 0,
    /* 001 */ 0,
    /* 002 */ 0,
    /* 003 */ 0,
    /* 004 */ 0,
    /* 005 */ 0,
    /* 006 */ 0,
    /* 007 */ 0,
    /* 008 */ 0,
    /* 009 */ 0,
    /* 010 */ 0,
    /* 011 */ 0,
    /* 012 */ 0,
    /* 013 */ 0,
    /* 014 */ 0,
    /* 015 */ 0,
    /* 016 */ 0,
    /* 017 */ 0,
    /* 018 */ 0,
    /* 019 */ 0,
    /* 020 */ 0,
    /* 021 */ 0,
    /* 022 */ 0,
    /* 023 */ 0,
    /* 024 */ 0,
    /* 025 */ 0,
    /* 026 */ 0,
    /* 027 */ 0,
    /* 028 */ 0,
    /* 029 */ 0,
    /* 030 */ 0,
    /* 031 */ 0,
    /* ' ' */ 0,
    /* '!' */ 0,
    /* '"' */ 0,
    /* '#' */ 0,
    /* '$' */ 0,
    /* '%' */ 0,
    /* '&' */ 0,
    /* ''' */ 0,
    /* '(' */ 0,
    /* ')' */ 0,
    /* '*' */ 0,
    /* '+' */ 0,
    /* ',' */ 0,
    /* '-' */ 0,
    /* '.' */ 0,
    /* '/' */ 0,
    /* '0' */ 0,
    /* '1' */ 0,
    /* '2' */ 0,
    /* '3' */ 0,
    /* '4' */ 0,
    /* '5' */ 0,
    /* '6' */ 0,
    /* '7' */ 0,
    /* '8' */ 0,
    /* '9' */ 0,
    /* ':' */ 0,
    /* ';' */ 0,
    /* '<' */ 0,
    /* '=' */ 0,
    /* '>' */ 0,
    /* '?' */ 0,
    /* '@' */ 0,
    /* 'A' */ (1 << 4) | (1 << 2),
    /* 'B' */ 0,
    /* 'C' */ 0,
    /* 'D' */ 0,
    /* 'E' */ (1 << 3) | (1 << 1),
    /* 'F' */ 0,
    /* 'G' */ 0,
    /* 'H' */ 0,
    /* 'I' */ (1 << 2) | (1 << 1),
    /* 'J' */ 0,
    /* 'K' */ 0,
    /* 'L' */ 0,
    /* 'M' */ 0,
    /* 'N' */ (1 << 3) | (1 << 2),
    /* 'O' */ (1 << 4) | 1,
    /* 'P' */ 0,
    /* 'Q' */ 0,
    /* 'R' */ (1 << 3) | 1,
    /* 'S' */ (1 << 1) | 1,
    /* 'T' */ (1 << 4) | (1 << 1),
    /* 'U' */ 0,
    /* 'V' */ 0,
    /* 'W' */ 0,
    /* 'X' */ 0,
    /* 'Y' */ 0,
    /* 'Z' */ 0,
    /* '[' */ 0,
    /* '\' */ 0,
    /* ']' */ 0,
    /* '^' */ 0,
    /* '_' */ 0,
    /* '`' */ 0,
    /* 'a' */ 0,
    /* 'b' */ 0,
    /* 'c' */ 0,
    /* 'd' */ 0,
    /* 'e' */ 0,
    /* 'f' */ 0,
    /* 'g' */ 0,
    /* 'h' */ 0,
    /* 'i' */ 0,
    /* 'j' */ 0,
    /* 'k' */ 0,
    /* 'l' */ 0,
    /* 'm' */ 0,
    /* 'n' */ 0,
    /* 'o' */ 0,
    /* 'p' */ 0,
    /* 'q' */ 0,
    /* 'r' */ 0,
    /* 's' */ 0,
    /* 't' */ 0,
    /* 'u' */ 0,
    /* 'v' */ 0,
    /* 'w' */ 0,
    /* 'x' */ 0,
    /* 'y' */ 0,
    /* 'z' */ 0,
    /* '{' */ 0,
    /* '|' */ 0,
    /* '}' */ 0,
    /* '~' */ 0,
    /* 127 */ 0,
    /* 128 */ 0,
    /* 129 */ 0,
    /* 130 */ 0,
    /* 131 */ 0,
    /* 132 */ 0,
    /* 133 */ 0,
    /* 134 */ 0,
    /* 135 */ 0,
    /* 136 */ 0,
    /* 137 */ 0,
    /* 138 */ 0,
    /* 139 */ 0,
    /* 140 */ 0,
    /* 141 */ 0,
    /* 142 */ 0,
    /* 143 */ 0,
    /* 144 */ 0,
    /* 145 */ 0,
    /* 146 */ 0,
    /* 147 */ 0,
    /* 148 */ 0,
    /* 149 */ 0,
    /* 150 */ 0,
    /* 151 */ 0,
    /* 152 */ 0,
    /* 153 */ 0,
    /* 154 */ 0,
    /* 155 */ 0,
    /* 156 */ 0,
    /* 157 */ 0,
    /* 158 */ 0,
    /* 159 */ 0,
    /* 160 */ 0,
    /* 161 */ 0,
    /* 162 */ 0,
    /* 163 */ 0,
    /* 164 */ 0,
    /* 165 */ 0,
    /* 166 */ 0,
    /* 167 */ 0,
    /* 168 */ 0,
    /* 169 */ 0,
    /* 170 */ 0,
    /* 171 */ 0,
    /* 172 */ 0,
    /* 173 */ 0,
    /* 174 */ 0,
    /* 175 */ 0,
    /* 176 */ 0,
    /* 177 */ 0,
    /* 178 */ 0,
    /* 179 */ 0,
    /* 180 */ 0,
    /* 181 */ 0,
    /* 182 */ 0,
    /* 183 */ 0,
    /* 184 */ 0,
    /* 185 */ 0,
    /* 186 */ 0,
    /* 187 */ 0,
    /* 188 */ 0,
    /* 189 */ 0,
    /* 190 */ 0,
    /* 191 */ 0,
    /* 192 */ 0,
    /* 193 */ 0,
    /* 194 */ 0,
    /* 195 */ 0,
    /* 196 */ 0,
    /* 197 */ 0,
    /* 198 */ 0,
    /* 199 */ 0,
    /* 200 */ 0,
    /* 201 */ 0,
    /* 202 */ 0,
    /* 203 */ 0,
    /* 204 */ 0,
    /* 205 */ 0,
    /* 206 */ 0,
    /* 207 */ 0,
    /* 208 */ 0,
    /* 209 */ 0,
    /* 210 */ 0,
    /* 211 */ 0,
    /* 212 */ 0,
    /* 213 */ 0,
    /* 214 */ 0,
    /* 215 */ 0,
    /* 216 */ 0,
    /* 217 */ 0,
    /* 218 */ 0,
    /* 219 */ 0,
    /* 220 */ 0,
    /* 221 */ 0,
    /* 222 */ 0,
    /* 223 */ 0,
    /* 224 */ 0,
    /* 225 */ 0,
    /* 226 */ 0,
    /* 227 */ 0,
    /* 228 */ 0,
    /* 229 */ 0,
    /* 230 */ 0,
    /* 231 */ 0,
    /* 232 */ 0,
    /* 233 */ 0,
    /* 234 */ 0,
    /* 235 */ 0,
    /* 236 */ 0,
    /* 237 */ 0,
    /* 238 */ 0,
    /* 239 */ 0,
    /* 240 */ 0,
    /* 241 */ 0,
    /* 242 */ 0,
    /* 243 */ 0,
    /* 244 */ 0,
    /* 245 */ 0,
    /* 246 */ 0,
    /* 247 */ 0,
    /* 248 */ 0,
    /* 249 */ 0,
    /* 250 */ 0,
    /* 251 */ 0,
    /* 252 */ 0,
    /* 253 */ 0,
    /* 254 */ 0,
    /* 255 */ 0
  };

  unsigned Bit2Hash( char* ident ) {
    uint16_t hashCode = 0;

    while( *ident ) {
      if( ((*ident) == '_') || isalnum(*ident) ) {
        hashCode ^= bit2Table[(*ident) & 0xFF];
        hashCode = (hashCode << 5) | (hashCode >> 11);
        hashCode += 10141;
      }

      ident++;
    }

    return hashCode;
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
      printf( "%s, %u\n", curWord, Bit2Hash(curWord) );
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
