#include "string.hpp"
#include <iostream>

int main() {
    std::cout << "=== String Class Demonstration ===\n\n";

    // 1. Constructors
    std::cout << "1. Constructors:\n";
    String empty;
    String hello("Hello");
    String world("World");
    String copy(hello);
    
    std::cout << "   empty: '" << empty << "' (size: " << empty.Size() << ")\n";
    std::cout << "   hello: '" << hello << "'\n";
    std::cout << "   world: '" << world << "'\n";
    std::cout << "   copy: '" << copy << "'\n\n";

    // 2. Assignment operator
    std::cout << "2. Assignment operator:\n";
    String assigned;
    assigned = world;
    std::cout << "   assigned = world: '" << assigned << "'\n\n";

    // 3. Concatenation
    std::cout << "3. Concatenation:\n";
    String helloWorld = hello + " " + world;
    std::cout << "   hello + \" \" + world: '" << helloWorld << "'\n";
    
    hello += " there";
    std::cout << "   hello += \" there\": '" << hello << "'\n\n";

    // 4. Repetition
    std::cout << "4. Repetition:\n";
    String stars = String("*") * 10;
    String abc = String("abc") * 3;
    std::cout << "   \"*\" * 10: '" << stars << "'\n";
    std::cout << "   \"abc\" * 3: '" << abc << "'\n\n";

    // 5. Comparison operators
    std::cout << "5. Comparison operators:\n";
    std::cout << "   hello == copy: " << (hello == copy) << "\n";
    std::cout << "   hello != world: " << (hello != world) << "\n";
    std::cout << "   hello < world: " << (hello < world) << "\n";
    std::cout << "   hello > world: " << (hello > world) << "\n\n";

    // 6. Character access
    std::cout << "6. Character access:\n";
    std::cout << "   hello[0]: '" << hello[0] << "'\n";
    hello[0] = 'h';
    std::cout << "   after hello[0] = 'h': '" << hello << "'\n\n";

    // 7. Find and Replace
    std::cout << "7. Find and Replace:\n";
    String sentence("The quick brown fox jumps over the lazy dog");
    std::cout << "   Original: '" << sentence << "'\n";
    
    size_t pos = sentence.Find("fox");
    std::cout << "   Find \"fox\": position " << pos << "\n";
    
    sentence.Replace('o', '0');
    std::cout << "   After replacing 'o' with '0': '" << sentence << "'\n\n";

    // 8. Trimming
    std::cout << "8. Trimming:\n";
    String padded("___padding___");
    std::cout << "   Original: '" << padded << "'\n";
    
    padded.RTrim('_');
    std::cout << "   After RTrim('_'): '" << padded << "'\n";
    
    padded.LTrim('_');
    std::cout << "   After LTrim('_'): '" << padded << "'\n\n";

    // 9. Empty check and size
    std::cout << "9. Empty check and size:\n";
    std::cout << "   empty.Empty(): " << empty.Empty() << "\n";
    std::cout << "   hello.Empty(): " << hello.Empty() << "\n";
    std::cout << "   hello.Size(): " << hello.Size() << "\n\n";

    // 10. Swap
    std::cout << "10. Swap:\n";
    String a("Apple");
    String b("Banana");
    std::cout << "   Before swap: a='" << a << "', b='" << b << "'\n";
    a.swap(b);
    std::cout << "   After swap: a='" << a << "', b='" << b << "'\n\n";

    std::cout << "=== Demonstration Complete ===\n";
    return 0;
}
