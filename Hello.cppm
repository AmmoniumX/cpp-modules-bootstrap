module; 
// Global Module Fragment: The only place for traditional #include directives.
// This allows the module to use headers without "exporting" their macros or content.
#include <iostream>

export module HelloWorld;
// Module Declaration: Defines this file as the Primary Module Interface for 'HelloWorld'.
// Everything after this point belongs to the module's scope.

import :HelloImpl;
// Interface Partition Import: Imports the ':HelloImpl' partition.
// The 'export' prefix here is "transitive," meaning anyone who 'import HelloWorld'
// will also automatically get everything exported by ':HelloImpl'.

export void say_hello() {
    // Member of the module: Because this function is marked 'export', 
    // it is part of the public API.
    std::cout << get_hello() << std::endl; 
}
