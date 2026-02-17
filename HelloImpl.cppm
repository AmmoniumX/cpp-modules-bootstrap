module;
#include <string>

module HelloWorld:HelloImpl;
// Since we don't have "export" here, this makes it an "internal" partition, it cannot be 'export import'-ed

export std::string get_hello() {
  // We still mark this 'export' so that the Primary Module (Hello.cppm)
  // can see and use it.
  return "Hello, C++ Module partitions!";
}
