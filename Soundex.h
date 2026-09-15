#ifndef Soundex_h
#define Soundex_h

#include <iostream>
#include <string>

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return zeroPad(head(word) + encodedDigits(word));
  }

private:
  std::string head(const std::string& word) const {
    return word.substr(0, 1);
  }

  // if word is 2 letter or above return 1 or else return empty
  std::string encodedDigits(const std::string& word) const {
    if (word.length() > 1) {
      return staticDigit(word[1]);
    };
    return "";
  }
  std::string staticDigit(char letter) const {
    std::unordered_map<char, std::string> dict {
      {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
      {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"},
      {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
      {'d', "3"}, {'t', "3"},
      {'l', "4"},
      {'m', "5"}, {'n', "5"},
      {'r', "6"}
    };

    return dict.find(letter)->second;
  }
  
  static const size_t MaxCodeLength{4};
  std::string zeroPad(const std::string& encoded) const {
    int zeroNeeded = MaxCodeLength - encoded.size();

    return encoded + std::string(zeroNeeded, '0');
  }

};

#endif
