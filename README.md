# Shsc C Interop
This library is a static library that includes headers and functions to help with C interop in Shsc.

## Compiling this library

You'll need to have the following dependencies installed:
- `gcc` - the GNU C Compiler
- `make` - the build system
- `ld` - the linker
- `ar` - the archiver

Run `make` and the static library will be generated at `target/libshsc.a` (or `target/libshsc.lib` on Windows).

## Compile a shared library

To compile the `add.c` test library, run the following command:
```sh
gcc -shared -fPIC -o examples/add.so examples/add.c
LD_LIBRARY_PATH=$PWD/examples shsc examples/add.shsc
```

On windows, you can use the following command:
```sh
gcc -shared -fPIC -o examples/add.dll examples/add.c
shsc examples/add.shsc
```

See [`examples`](examples/) for an example of how to use this library.
