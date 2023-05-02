/*!*****************************************************************************
\File q.hpp
\Author Timothy Lee Ke xin
\Par DP email: timothykexin.lee@digipen.edu.sg
\Par Course: RSE 1202
\Par Section: Transitioning from C to C++
\Par Programming Lab #1
\Date 12-01-2022

\Brief
  This header file contains the declaration of the function q. 
  
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

#ifndef Q_HPP_
#define Q_HPP_

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
*******************************************************************************/
  void q(char const* filename, char const **key_words);
}

#endif
