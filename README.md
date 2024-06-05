# `size_t` hash

A lighweight C library that offers a portable implementation of the Murmur3 hashing algorithm where the resulting hash is of type `size_t`. Inspired by [this implementation](https://github.com/PeterScott/murmur3).

## Usage

First, include the [`st-hash.h`](/lib/st-hash.h) and [`st-hash.c`](/lib/st-hash.c) files in your project, found in the [`lib`](/lib) directory. Then, compile them alongside your source files.

For usage examples, consult the [`demo.c`](/demo.c) and [`test.c`](/test.c) programs provided in the project.

Compile and execute them using these commands:

```bash
cc -o demo demo.c lib/st-hash.c 
./demo 

cc -o test test.c lib/st-hash.c 
./test 
```

## License

This project is licensed under the MIT License. See the [LICENSE](/LICENSE) file for details.