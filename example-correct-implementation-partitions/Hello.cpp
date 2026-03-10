module;
#include <iostream>

module HelloWorld; // This file "is" part of HelloWorld
import :HelloImpl; // Private import is allowed here!

void say_hello() {
  // We can see get_internal_string() because we are in the same module
  std::cout << get_internal_string() << std::endl;
}
