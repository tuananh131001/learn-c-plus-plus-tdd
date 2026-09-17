#ifndef Soundex_h
#define Soundex_h

#include <iostream>
#include <string>
#include <unordered_set>

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return zeroPad(head(word) + encodedDigits(word));
  }

private:
  static const size_t MaxCodeLength{4};

  std::string head(const std::string& word) const {
    return word.substr(0, 1);
  }

  // if word is 2 letter or above return 1 or else return empty
  // encodedDigits("Ar") -> 6
  std::string encodedDigits(const std::string& word) const {
    if (word.length() > 1) {
      std::string encodedDigits;

      for (char c : word) {
        if (isComplete(encodedDigits)) break;
        if(isVowels(c)) continue;

        encodedDigits += staticDigit(c);
      }

      return encodedDigits;
    };
    return "";
  }

  bool isComplete(std::string encodedString) const {
    return encodedString.length() == MaxCodeLength - 1;
  }

  bool isVowels(char c) const {
    std::unordered_set<char> vowelsDict{ 'a', 'e', 'i', 'o', 'u', 'y', 'h', 'w' };

    return vowelsDict.find(c) != vowelsDict.end(); // reach end not found
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

    auto digit = dict.find(letter);
    return digit == dict.end() ? "" : digit ->second;
  }
  
  std::string zeroPad(const std::string& encoded) const {
    int zeroNeeded = MaxCodeLength - encoded.size();

    return encoded + std::string(zeroNeeded, '0');
  }

};

#endif
