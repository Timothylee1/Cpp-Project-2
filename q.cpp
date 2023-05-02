/*!*****************************************************************************
\File q.cpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Transitioning from C to C++
\Par Programming Lab #1
\Date 12-01-2022

\Brief
  This program takes a text file with a sequence of words containing a hidden 
  message and with the keywords, it decrypts the hidden message, and sends the
  secret message to the stdout. I/O functions of the C std lib is not allowed.
  This program utilizes a single function:
  
  - q
      Reads the contents of the given text file with the associated keywords
      to decrypt the hidden message and obtain the secret message. This 
      function searches for the keywords and obtains the word next to it as part
      of the secret message.
      e.g.
          text file contains: happy new year to everyone
          keywords: new to nullptr
          secret message: year everyone
*******************************************************************************/

#include <cstring>                                  //cpp string lib
#include <iostream>                                 
#include <fstream>                          
#include <cstdlib>                                  //for EXIT_SUCCESS

namespace hlp2 {

/*!*****************************************************************************
\brief
  Reads the contents of the given text file with the associated keywords to 
  decrypt the hidden message and obtain the secret message. This function 
  searches for the keywords and obtains the word next to it as part of the 
  secret message.

\param filename
  The name of the text file containing the hidden message.

\param key_words
  The key words used to decrypt the hidden message.

\param ifs
  The fstream variable for the file associated to filename.

\param check
  A boolean flag for detection of corresponding key word in hidden message. 

\param word
  Contains the string of a word in the filename.
*******************************************************************************/

void q(char const *filename, char const **key_words) {  

  //check if input file (ifs) can be opened
  std::fstream ifs(filename, std::ios_base::in);    //open file for reading
  if (!ifs.is_open()) {                             //check if 
    std::cout << "File " << filename << " not found.";
    EXIT_SUCCESS;                                   //exit program
  }
  bool check = false;                               
  std::string word;
  while (ifs >> word) {                             //while not eof
      for (int i = 0; *(key_words+i); i++) {        //iterates through to check if word == *key_words
        if (word == *(key_words+i)) {
          check = true;
          break;
        }
      }

      if (check) {                                  //word == *key_words
        ifs >> word;                                //collects next string
        std::cout << word << " ";
        check = false;                              //assigns check to false
      } 
      
  }  
  std::cout << "\n";
  ifs.close();                                      //close file
}

}
