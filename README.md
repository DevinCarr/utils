# utils
A collection of useful C/C++ classes and functions

## Usage
Currently the C++ files all require at least a C++11 compiler
and have been tested to work with `g++` and `clang`.

## Files

### C

### C++

`semaphore.h/cpp`: A basic semphore class

`bounded_queue.h`: A bounded lock-safe queue
- Requires: `semaphore.h/cpp`

`circular_buffer.h`: A circular stack that will always accept 
more elements and deleting ones off the end of the capacity.

## License
MIT - (view LICENSE for more information)
