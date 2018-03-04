// Kirubel Worede
// CSE_374
// 11/12/2015
// HW-5

#include "triemaker.h"

//Function declaretions
FILE* get_dictionary(int argc, char** argv);
TRIE_PTR make_node();
void make_tree(FILE* dictionary, TRIE_PTR first_node);
char* store_word(char* my_word);
int letter_to_level(char letter);

// Prompts the user for a file, checks it if readble and opens it.
FILE* get_dictionary(int argc, char** argv){
  if(argc<2){
    fprintf(stderr, "Please give the name of a dictorary.\nFormat is ...$./<dictionary filename>");
    exit(1);
  }
  FILE* dictionary = fopen(argv[1], "r");
  if(dictionary == NULL){
    fprintf(stderr, "Could not find dictionary fille.\n");
    exit(1);
  }
  return dictionary;
}

// Make link of tree nodes
void make_tree(FILE* dictionary, TRIE_PTR first_node){
  int level, k;
  char string[256];
  TRIE_PTR current_node;

  while(fscanf(dictionary, "%s", string)>0){//fscanf returns <0 when no more words
    current_node = first_node;
    for(k=0; k<strlen(string); k++){
      level = letter_to_level(string[k]);//which keypad number to attach next node
      if(current_node->next_node[level] == NULL){
        current_node->next_node[level] = make_node();
      }
      current_node = current_node->next_node[level];
    }
    if(current_node->node_word != NULL){
      while(current_node->next_node[HASH] != NULL){
        current_node = current_node->next_node[HASH];
      }
      current_node->next_node[HASH] = make_node();
      current_node = current_node->next_node[HASH];
    }
  current_node->node_word = store_word(string); 
  }
}

// Creat new nodes and allocates memory.
TRIE_PTR make_node(){
  int k;
  TRIE_PTR new_node = (TRIE_PTR) malloc(sizeof(TRIE_NODE));
  if(new_node == NULL){
    printf("could not get memory.\n");
    exit(1);// If we can not get enough memory from malloc, exit the program.
  }
  for(k=0;k<RANGE;k++){
    new_node->next_node[k] = NULL;
  }
  new_node->node_word = NULL;
  return new_node;
}

// Copy words to nodes
char* store_word(char* my_word){
  char* location = (char*) malloc(strlen(my_word)+1);
  if(location == NULL){
    printf("could not get word memory\n");
    exit(1);
  }
  strcpy(location, my_word);
  return location;
}

//Converts each char of a string to their apropriate level.
int letter_to_level(char letter){
    int level;
    switch(toupper(letter)){
        case 'A': case 'B': case 'C':
            level = 2;
        break;
        case 'D': case 'E': case 'F':
            level = 3;
	break;
		case 'G': case 'H': case 'I':
		     level = 4;
		     break;
		case 'J': case 'K': case 'L':
		     level = 5;
		     break;
		case 'M': case 'N': case 'O':
		     level = 6;
		     break;
		case 'P': case 'Q': case 'R': case 'S':
		     level = 7;
		     break;
		case 'T': case 'U': case 'V':
		     level = 8;
		     break;
		case 'W': case 'X': case 'Y': case 'Z':
		     level = 9;
		     break;		     
    }
    return level;       
}
