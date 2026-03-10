module;
#include <string>

module HelloWorld:HelloImpl; // No 'export' = Implementation Partition

// This is visible ONLY to other files inside module HelloWorld
std::string get_internal_string() {
    return "Hello from a (pure) private partition!";
}
