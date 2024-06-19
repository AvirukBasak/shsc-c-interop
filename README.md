# Shsc C Interop
This library is a static library that includes headers and functions to help with C interop in Shsc.

## Compiling
To compile the `add.c` test library, run the following command:
```sh
gcc -shared -fPIC -o examples/add.so examples/add.c
LD_LIBRARY_PATH=$PWD/examples shsc examples/add.shsc
```

See [`examples`](examples/) for an example of how to use this library.
