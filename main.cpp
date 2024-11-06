#include <iostream>

std::vector<int> extractLowercaseAsciiCodes(const std::string &input, bool reverseResult) {
    std::vector<int> result;

    // extract all lowercase english alpha characters and put into result
    for (const unsigned char character: input) {
        if (character >= 'a' && character <= 'z') {
            result.push_back(character);
        }
    }

    // reverse the result if needed
    if (reverseResult) {
        std::reverse(result.begin(), result.end());
    }

    // result will be moved to caller, if compiler is C++11, which seems like a reasonable assumption
    return result;
}

void print(const std::string& test, const std::vector<int> &result) {
    std::cout << test << " ==> '";
    for (auto element: result) {
        std::cout << static_cast<char>(element);
    }
    std::cout << "' ==> [ ";

    for (auto element: result) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::vector<std::string> tests = {
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "Mixture Of caseS",
        "123abc456DEf4dg4GRW",
    };

    for (const auto& test: tests) {
        print(test, extractLowercaseAsciiCodes(test, false));
        print(test, extractLowercaseAsciiCodes(test, true));
        std::cout << std::endl;
    }

    return 0;
}
