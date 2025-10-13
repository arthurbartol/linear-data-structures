# linear-data-structures
A modular, generic implementation of classic linear data structures using C.

## Project Structure
```
linear_data_structures/
├── src/
│ ├── array.c / array.h
│ ├── stack.c / stack.h
│ ├── queue.c / queue.h
│ ├── linked_list.c / linked_list.h
│ └── double_linked_list.c / double_linked_list.h
│
├── tests/
│ ├── test_array.c
│ ├── test_stack.c
│ ├── test_queue.c
│ ├── test_linked_list.c
│ └── test_double_linked_list.c
│
├── build/ # Compiled binaries (created automatically)
└── Makefile # Build and test automation
```

## Build & Run
```bash
make clean
make
make run-tests
```
