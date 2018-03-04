// This script builds a program to implement T9 predictive text, a text input mode available on many cell phones and keypads. 
// Each number from 2-9 on the keypad represent three or four letters, the number 0 represents a space, and 1 represents a set of symbols such as { , . ! ? } etc. 
// The numbers from 2-9 represent letters as follows:

2 ABC 
3 DEF 
4 GHI 
5 JKL 
6 MNO
7 PQRS 
8 TUV 
9 WXYZ

// Since multiple letters map to a single number, many key sequences represent multiple words. 
// For example, the input 2665 represents "book" and "cool", among other possibilities.
// To translate from number sequences to words, we will use a data structure known as a trie. 
// A trie is a multiway branching structure (tree) that stores the prefixes of sequences. 
// As we travel down a path in the trie, we reach word sequences spelled out by the numbers along that path. 
// Classic trie data structures have edges labeled with letters to store prefixes of strings. //
// But for this application, we used a compressed trie that has only 10 possible branches at each node instead of 26, since the digits 0-9 represent the 26 letters, space and symbols. 
// Because of this, an extra layer of complexity is needed to figure out the string represented by a path.

// (Actually, for this application, each node only needs 8 possible children numbered 2-9, since digits 0 and 1 don't encode letters. 
// But writing the code might be easier if nodes have 10 children numbered 0-9, since then subtree number n corresponds to digit n. 


// For more information on the trie data structure, here is a link to the Wikipedia article.

 Technical Requirements
// Implement in C a program t9. The command

     t9 FILE
should read in a dictionary file (FILE) that contains a list of words. Translate each word in the dictionary into its numeric key sequence, 
then add the key sequence to your trie, with the word at the end of the path corresponding to the digits. 
If a word with the same numeric sequence already exists in the trie, add the new word to the trie as a link to a new node with an edge labeled '#' 
instead of one of the digits 2-9. (The words linked from a node by the '#' edges essentially form a linked list of words that have the same numeric code.)

For example, if the program reads the set of words "jello","rocks", and "socks" from the dictionary and adds it to an empty trie, the resulting trie 
should look like this:

![t9](https://user-images.githubusercontent.com/37035048/36951450-df7ece52-1fb8-11e8-92ea-acb1ab3ca9c3.PNG)


Once your program has read the dictionary and built the trie containing the words in it, it should start an interactive session. The user should be 
able to type numbers and the program should print out the word corresponding to the sequence of numbers entered. Your program should use the numbers 
typed by the user to traverse the trie that has already been created, retrieve the word, and print it to the screen. If the user then enters '#', 
the program should print the next word in the trie that has the same numeric value, and so forth. The user can also type a number followed by one or 
more '#' characters - this should print the same word that would be found by typing the number and individual '#' characters on separate input lines.

As an example, if we run the program using the above trie, an interactive session might look like this:
Enter "exit" to quit.
Enter Key Sequence (or "#" for next word):
> 76257
	'rocks'
Enter Key Sequence (or "#" for next word):
> #
	'socks'
Enter Key Sequence (or "#" for next word):
> 53556
	'jello'
Enter Key Sequence (or "#" for next word):
> #
    There are no more T9onyms

Enter Key Sequence (or "#" for next word):
> 76257#
	'socks'
Enter Key Sequence (or "#" for next word):
> 76257##
	There are no more T9onyms
>4423
	Not found in current dictionary.
>exit
The interactive session should terminate either when the user enters the word "exit" or when the end-of-file is reached on the interactive input (indicated by typing control-D on the keyboard).
