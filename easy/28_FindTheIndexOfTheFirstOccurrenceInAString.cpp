#include <gtest/gtest.h>

#include <string>

class Solution {
public:
    bool checkSubstr(const std::string& needle, const std::string& haystack, int begin)
    {
      if(begin + needle.size() > haystack.size())
        return false;
      for(int i = 0; i < needle.size(); ++i)
      {
        if(haystack[begin + i] != needle[i])
          return false;
      }
      return true;
    }
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty())
          return -1;
        for (int i = 0; i < haystack.size(); ++i) {
          if(checkSubstr(needle, haystack, i))
            return i;
        }
        return -1;
    }
};

TEST(FindTheIndexOfTheFirstOccurrenceInAString, SimpleTest)
{
  Solution solution;
  EXPECT_EQ(solution.strStr("sadbutsad", "sad"), 0);
}