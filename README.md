## About

Second re-write of a variant of the UNIX shell to learn C, process management, pipes, and redirects. This is a project from an Operative System book I'm reading called: Operating Systems: Three Easy Pieces (OSTEP).

## Getting Started

### Compile

This project is entirely written in C, and compiled with gcc. 

To compile install `gcc`, clone the repo, and run `make` in the root of the project. If succesfull you should have a binary in `bin/mishell`

### Run

You can run the shell in two modes:

- Batch mode: passing a file with a list of commands to run in batch `bin/mishell batch.txt`
- Interpreter mode: running the shell with no arguments `bin/mishell`

## Roadmap

- [x] Simple configuration via .rc file
	- [x] Backgroung color
	- [x] Prompt color
	- [x] Path
	- [ ] Start sounds (annoying feature)
	- [x] Quote of the day
- [ ] Piping
- [ ] Output redirection
- [ ] Built-in commands: exit, cd, setpath
- [ ] Parallel command execution

## Acknowledgments

[Authors of Operating Systems: Three Easy Pieces.]() Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau, Arpaci-Dusseau Books, November, 2023 (Version 1.10) 

