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
gcc -Iinclude -shared -fPIC -o examples/add.so examples/add.c build/*-rel.o # -Ltarget -lshsc
shsc examples/add.shsc
```

On windows, you can use the following command:
```sh
gcc -Iinclude -shared -fPIC -o examples/add.dll examples/add.c build/*-rel.o # -Ltarget -lshsc
shsc examples/add.shsc
```

See [`examples`](examples/) for an example of how to use this library.

## Issue

Notice how `-Ltarget -lshsc` is commented out in the command above. In an ideal scenario, instead of including the `build/*-rel.o` files, we would link against the static library.

However, with present configuration, certain initialization functions that are present in the static library are not being included in the final shared library. This causes a runtime error when the shared library is loaded.

```
$ shsc examples/add.shsc
shsc: io:-1: failed to get symbol 'shsc_init_apifn_data'
    at io:libopen (io:-1)
    at main:loadfn (examples/add.shsc:2)
    at main:main (examples/add.shsc:12)
```

Here, the `shsc_init_apifn_data` function is not being included in the shared library. This is because the linker is not including the static library in the shared library.

It can be bypassed for now by using `build/*-rel.o` directly when compiling the shared library.
