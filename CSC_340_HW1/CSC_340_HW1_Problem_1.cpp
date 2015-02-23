/**
 *  Name      : Word Frequency Counter
 *  Author    : Iain Raleigh
 *  Student ID: 915133718
 *  Email     : iraleigh@mail.sfsu.edu
 *  Compiler  : g++
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_LENGTH = 26;
const int ASCII_A = 65;
const int MAX_WORDCOUNT = 100;

struct Letter {
  char token;
  int freq;
}alphabet[ALPHABET_LENGTH];
struct Word {
  string token;
  int freq;
};
/**
 * @precondition  : Uninitialized alphabet array.
 * @postcondition : Initialized aplphabet array to hold letters A to Z.
 */
void createAlphabet(Letter arr[]);
/**
 * @precondition  : String containing upper and lower case letters, punctuation,
 *                  and unwanted symbols.
 * @postcondition : Returns a string in all uppercase and space delimited by
 *                  word
 */
string filter(string s);
/**
 * @precondition  : a filtered string (see filter())
 * @postcondition : the Letter (see Letter struct) of least occurance.
 */
Letter getLeastFreqLetter(string paragragh);
/**
 * @precondition  : A filtered string (see filter()) and a vector initialized in
 *                  the main function.
 * @postcondition : The Word (see Word struct) that occurs most.
 */
Word getMostFreqWord(string paragragh,vector<Word>& words_vec);
/**
 * @precondition  : A substring from a paragragh, and a vector.
 * @postcondition : The substring pushed to the back of that vector
 */
void addWordToVector(string current,vector<Word>& words_vec);
/**
 * @precondition  : A Word to be found to the vector
 * @postcondition : If the Word already exists, its position is returned. If
 *                  the word does not, then -1 is returned.
 */
int wordSearch(vector<Word>& words_vec, int size, string word);
/**
 * @precondition  : A vector of Words (see Word struct), that contains the words
 *                  and their associated frequencies.
 * @postcondition : Returns the Word with the highest Frequency value.
 */
Word mostFreq(vector<Word>& words_vec);
/**
 * @precondition  : A vector of Words (see Word struct), that contains the words
 *                  and their associated frequencies.
 * @postcondition : The vector printed using "cout" to list words and their
 *                  associated frequencies.
 */
void countWordFreq(vector<Word>& words_vec);

int main() {
  //declarations
  vector<Word> words_vec(0);
  string phrase;
  //initialization
  createAlphabet(alphabet);
  //user input
  cout << "Enter a phrase: ";
  getline(cin,phrase);
  phrase = filter(phrase);
  //output
  cout << "The least frequent letter  : " << getLeastFreqLetter(phrase).token << endl;
  cout << "The most frequent word     : " << getMostFreqWord(phrase,words_vec).token << endl;
  cout << "Frequency of all the words : " << endl;
  countWordFreq(words_vec);
  return 0;
}

string filter(string s){
  for (int i = 0; i<s.length();i++){
    if ((s.at(i) > 96) && (s.at(i) < 123)){ //if lowercase
      s.at(i) = s.at(i) - 32; //make uppercase
    } else if (((s.at(i) > 64) && (s.at(i) < 91)) || (s.at(i) == 32)) { //if uppercase
      s.at(i) = s.at(i); //keep
    } else { //if any other character in ASCII
      s.erase(i,1); //remove
    }
  }
  return s;
}
void createAlphabet(Letter arr[]){
  for (int i = 0; i < ALPHABET_LENGTH; i++) {
    arr[i].token = ASCII_A + i;
    arr[i].freq = 0;
  }
}
Letter getLeastFreqLetter(string paragragh){
  Letter min;
  min.token = '1';

  for (int i = 0; i<ALPHABET_LENGTH; i++){
    for (int j = 0; j<paragragh.length(); j++){
      if (alphabet[i].token == paragragh.at(j)){
        alphabet[i].freq++;
        if (min.token == '1') min = alphabet[i];
      }
    }
    if (alphabet[i].freq <= min.freq && alphabet[i].freq != 0)
      min = alphabet[i];
  }
  return min;
}
Word getMostFreqWord(string paragragh, vector<Word>& words_vec){
  int start = 0;
  size_t end = paragragh.find(" ");
  while (end != string::npos)
  {
    addWordToVector(paragragh.substr(start, end - start),words_vec);
    start = end + 1;
    end = paragragh.find(" ", start);
  }
  return mostFreq(words_vec);
}
void addWordToVector(string current,vector<Word>& words_vec){
  int position = wordSearch(words_vec,words_vec.size(),current);
  if (position/*915133718*/ != -1){
    words_vec.at(position).freq++;
  } else {
    Word newWord;
    newWord.token = current;
    newWord.freq = 1;
    words_vec.push_back(newWord);
  }
}
int wordSearch(vector<Word>& words_vec, int size, string word){
  int position = -1;
  for (int i=0; i<size;i++){
    if (words_vec.at(i).token == word){
      position = i;
    }
  }
  return position;
}
Word mostFreq(vector<Word>& words_vec){
  Word max = words_vec.at(0);
  for (int i = 1; i < words_vec.size(); i++){
    if (words_vec.at(i).freq > max.freq)
      max = words_vec.at(i);
  }
  return max;
}
void countWordFreq(vector<Word>& words_vec){
  for (int i = 0; i < words_vec.size(); i++){
    cout << "        " << words_vec.at(i).token << ": " << words_vec.at(i).freq << endl;
  }
}
