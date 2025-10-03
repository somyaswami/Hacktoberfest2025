#include <string>
#include <vector>
#include <algorithm> // For std::sort

class Solution_TwoPointer {
public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        // 1. Sort the spaces array. O(M log M).
        std::sort(spaces.begin(), spaces.end());
        
        // 2. Initialize the result string and reserve memory.
        std::string result = "";
        result.reserve(s.length() + spaces.size());
        
        // 3. Use a pointer for the spaces array.
        int space_ptr = 0;
        
        // 4. Iterate through the original string.
        for (int i = 0; i < s.length(); ++i) {
            
            // Check if the current index 'i' matches the next required space index.
            if (space_ptr < spaces.size() && i == spaces[space_ptr]) {
                result += ' ';
                space_ptr++; // Move to the next required space index
            }
            
            // Append the character itself.
            result += s[i];
        }
        
        return result;
    }
};
