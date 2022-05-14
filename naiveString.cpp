#include<iostream> 
#include <cstring>
using namespace std; 
  
void search(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == M) 
            cout << i << endl; 
    } 
} 

int main() 
{ 
    char txt[100]; 
    char pat[100]; 
    cin >> txt;
    cin >> pat;
    search(pat, txt); 
    return 0; 
} 
  


  #include<iostream>
using namespace std;

void naivePatternSearch(string mainString, string pattern, int array[], int *index) {
   int patLen = pattern.size();
   int strLen = mainString.size();

   for(int i = 0; i<=(strLen - patLen); i++) {
      int j;
      for(j = 0; j<patLen; j++) {      
         if(mainString[i+j] != pattern[j])
            break;
      }

      if(j == patLen) {   
         (*index)++;
         array[(*index)] = i;
      }
   }
}

int main() {
   string text;
   string pattern;
   cin >> text;
   cin >> pattern;
   int locArray[text.size()];
   int index = -1;
   naivePatternSearch(text, pattern, locArray, &index);

   for(int i = 0; i <= index; i++) {
      cout<<locArray[i]<<endl;
   }
}
