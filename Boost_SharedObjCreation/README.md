This example shows how to create a shared library that depends on Boost shared libraries.

I was getting an error `ld: symbol(s) not found for architecture x86_64`. The manual for ld states that

    -undefined : Specifies how undefined symbols are to be treated. Options are: error, warning, suppress, or dynamic_lookup.  The default is error.

    -flat_namespace : Alters how symbols are resolved at build time and runtime.  With -two_levelnamespace (the default), the linker only searches dylibs on the command line for symbols, and records in which dylib they were found.  With -flat_namespace, the linker searches all dylibs on the command line and all dylibs those original dylibs depend on. The linker does not record which dylib an external symbol came from, so at runtime dyld again searches all images and uses the first definition it finds.  In addition, any undefines in loaded flat_namespace dylibs must be resolvable at build time.
