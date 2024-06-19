# Shsc C Interop
This library is a static library that includes headers and functions to help with C interop in Shsc.

## Compiling
To compile your library, run the following command:
```sh
gcc -c -o mycmodule.o mycmodule.c
gcc -shared -fPIC -o mycmodule.so mycmodule.o
```

See [`examples`](examples/) for an example of how to use this library.
