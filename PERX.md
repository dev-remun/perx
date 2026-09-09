
## perx

As stated in the [README](README.md) file, `perx` is a shell written in C inspired by the challenge of Codecrafters.

### Folder structure
```
perx
├── PERX.md
├── README.md
├── sample
│   ├── login
│   └── login.c
├── solutions
└── src
    ├── main.c
    ├── perx
    ├── perx_modules.h
    └── repl.c
```

* `/perx` - the root directory of the project
* `PERX.md` - the md file that contains the technical overview of perx
* `READ.md` - the md file that contains the purpose of perx and my motivation for creating it
* `/sample` - my practice playground folder that contains some of my C code and their exe files
* `login.c` - practice C code that tackles structs, strings, arrays, if-else, loops, and functions
* `login` - the executable file for `login.c`
* `/solutions` - the folder that contains the solutions for the problems in the Codecrafters guides
* `/src` - the folder that contains the source code for perx
* `main.c` - the entry point of perx
* `perx` - the executable file for `main.c`
* `perx_modules.h` - a header file that contains all the function prototypes for perx
* `repl.c` - an implementation of the read-evaluate-print-loop function defined in `perx_modules.h`