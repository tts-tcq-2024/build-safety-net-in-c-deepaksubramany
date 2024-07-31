#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A020"); // 'X' maps to '2' and remaining is '0' for padding

    generateSoundex("BAX", soundex);
    ASSERT_STREQ(soundex, "B020"); // 'B' maps to '1', 'X' maps to '2', remaining '0'

    generateSoundex("CAX", soundex);
    ASSERT_STREQ(soundex, "C020"); // 'C' maps to '2', 'X' maps to '2', remaining '0'

    generateSoundex("DAX", soundex);
    ASSERT_STREQ(soundex, "D020"); // 'D' maps to '3', 'X' maps to '2', remaining '0'

    generateSoundex("MXY", soundex);
    ASSERT_STREQ(soundex, "M020"); // 'M' maps to '5', 'X' maps to '2', 'Y' is ignored

    generateSoundex("TAX", soundex);
    ASSERT_STREQ(soundex, "T020"); // 'T' maps to '3', 'X' maps to '2', remaining '0'

    generateSoundex("KAT", soundex);
    ASSERT_STREQ(soundex, "K030"); // 'K' maps to '2', 'T' maps to '3', remaining '0'
}
