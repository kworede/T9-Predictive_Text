// Kirubel Worede
// CSE_374
// 11/12/2015
// HW-5

#include "trie.h"

//Function declaretions
int main(int argc, char** argv);
FILE* get_dictionary(int argc, char** argv);
TRIE_PTR make_node();
void make_tree(FILE* dictionary, TRIE_PTR first_node);
int get_user_input(char* query_string);
void make_path(char* query_string, int word_length);
TRIE_PTR search(bool* found, int length, char* search_path, TRIE_PTR node);
void look_up_words(TRIE_PTR first_node);
void delete_trie(TRIE_PTR node);

//Reads dictionary file from the user and make function callings
int main(int argc, char** argv){
  TRIE_PTR first_node;
  FILE* dictionary;
  
  dictionary = get_dictionary(argc, argv);
  first_node = make_node();
  make_tree(dictionary, first_node);
  fclose(dictionary);
  look_up_words(first_node);
  delete_trie(first_node);
  
return 0;
}

// Take input numbers from the user and checks for the validity of the input digits
int get_user_input(char* query_string){
  int word_length;

  word_length = scanf("%255s", query_string);
  if(strcmp(query_string, "exit") == 0 || word_length == -1)
    return -1;
  word_length = strspn(query_string, GOOD_DIGITS);
  *(query_string + word_length) = 0;//cut off string after digits & #s
  return word_length;
}


//Changes a string of 2-9 and # characters into an (int) search path
void make_path(char* query_string, int word_length){
  int k;

  for (k = 0; k < word_length; k++) {
    query_string[k] = query_string[k] - '0';
    if (query_string[k] < 0)// only HASH is before '0' in ASCII 
      query_string[k] = HASH;//replace bad negative value with HASH value
  }
  return;
}

// Follow a path from current node, check new node exists, say if word found 
TRIE_PTR search(bool* found, int length, char* search_path, TRIE_PTR node){
  int k, next;

  *found = true;
  for (k = 0; k < length; k++) {
    next = ((int) search_path[k]);
    if (node->next_node[next] == NULL) {
      *found = false;
      break;
    }
    node = node->next_node[next];
  }
  if (node->node_word == NULL)
    *found = false;
  return node;
}

//Prompt uses for input, checks for exit, processes input, searches trie, prints (word|not found) message
void look_up_words(TRIE_PTR first_node){
  int word_length;
  char number_string[256];
  TRIE_PTR current_node;
  bool found = false, new_search;

  printf("enter any number of digits from 2-9, followed by \n"
	 "any number of copies of # and press <enter>\n"
	 "Type \"exit\" to quit\n");
  while (true) {
    word_length = get_user_input(number_string);
    if (word_length == -1)
      break; // -1 means user typed exit or CTRL-d
    new_search = isdigit(number_string[0]);
    if (new_search)
      current_node = first_node;
    make_path(number_string, word_length);
    current_node = search(&found, word_length, number_string, current_node);
    if (word_length == 0)
      printf(">");
    else if (found)
      printf("%s\n>", current_node->node_word);
    else if (new_search)
      printf("No word found.\n>");
    else
      printf("No more words found.\n\n>");
  }
}


// Follows nodes to their ends, then frees them and works back to current node
void delete_trie(TRIE_PTR node){
  int k;

  for (k=0; k<RANGE; k++) {
    if (node->next_node[k] != NULL) {
      delete_trie(node->next_node[k]);
    }
  }
  if (node->node_word != NULL) {
    free(node->node_word);
  }
  free(node);
  return;
}
