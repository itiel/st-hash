# `size_t` hash

A simple C implementation of the Murmur3 hashing algorithm with an output hash of type `size_t`. 

Inspired by [PeterScott](https://github.com/PeterScott)'s [implementation](https://github.com/PeterScott/murmur3).

## Usage

Include the [`st-hash.h`](/lib/st-hash.h) and [`st-hash.c`](/lib/st-hash.c) files in your project, found in the [`lib`](/lib) directory, then compile them with your source files.

For usage examples, consult the [`demo.c`](/demo.c) and [`test.c`](/test.c) programs provided in the project.

You can compile and execute them by using these commands:

```bash
cc -o demo demo.c lib/st-hash.c 
./demo 

cc -o test test.c lib/st-hash.c 
./test 
```

## License

This project is licensed under the MIT License. See the [LICENSE](/LICENSE) file for details.