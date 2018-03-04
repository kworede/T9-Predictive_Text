// Kirubel Worede
// CSE_374
// 11/12/2015
// HW-5

#ifndef TRIE
#define TRIE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HASH 1
#define RANGE 10
#define GOOD_DIGITS "23456789#"

typedef struct trie_node *TRIE_PTR;

// Creats a new data type (TRIE_PTR)
typedef struct trie_node {
  TRIE_PTR next_node[RANGE];
  char* node_word ;
} TRIE_NODE;

#endif
