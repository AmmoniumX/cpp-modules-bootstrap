export module HelloWorld:HelloImpl;

import std;

// `module HelloWorld:HelloImpl` defines a module *implementation* partition.
// That means that the partition may *never* be exported in the main module
// interface. It is only for internal use.
// `export module HelloWorld:HelloImpl` defines a module *interface* partition.
// The main difference is that
// interfaces *may* be exported in the main interface, and are guaranteed to be
// "reachable" to the exported BMI.
//
// The main confusion with module implementation partitions is that importing
// them within a module's "main interface" has the potential of introducing
// unspecified behavior if the interface's ABI depends on details of the
// implementation (such as a class needing to know the size of a struct defined
// within an implementation). Because of this reason, clang warns you when
// importing a private/implementation partition into an exported module
// interface.
//
// For more info see:
// https://chuanqixu9.github.io/c++/2025/12/30/C++20-Modules-Best-Practices.en.html#appendix-b-reasons-for-not-import-module-implementation-partition-units-in-module-interface-units

std::string get_hello() {
  // We still mark this 'export' so that the Primary Module (Hello.cppm)
  // can see and use it.
  return "Hello, C++ Module partitions!";
}
