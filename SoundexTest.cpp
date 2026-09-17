#include "Soundex.h"
#include "gmock/gmock.h"

using namespace testing;

class SoundexEncoding: public Test {
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWorld) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfThreeDigits) {
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
};

TEST_F(SoundexEncoding, ReplaceConstantsWithApproratedDigits) {
  ASSERT_THAT(soundex.encode("Ar"), Eq("A600"));
};

TEST_F(SoundexEncoding, UnknownDigits) {
  ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
};

TEST_F(SoundexEncoding, MultipleConstantsWithDigits) {
  ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
  ASSERT_THAT(soundex.encode("dcdlb").length(), Eq(4u));
}

