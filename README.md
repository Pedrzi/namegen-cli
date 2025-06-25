# namegen-cli

A simple command-line tool to generate random names by combining an adjective, a noun, and a number.  
Useful for creating usernames, project names, or just for fun!

## Features

- Combines a random adjective and noun from text files
- Adds a random two-digit number at the end
- Customizable input files for adjectives and nouns
- Optional spacer/delimiter between words and number

## Usage

```sh
./namegen-cli [-a adjective_file] [-n noun_file] [-s spacer]
```

- `-a adjective_file` — Path to the adjectives file (default: `english-adjectives.txt`)
- `-n noun_file` — Path to the nouns file (default: `english-nouns.txt`)
- `-s spacer` — String to use as a spacer/delimiter (default: none)

**Example:**

```sh
./namegen-cli -a my-adjectives.txt -n my-nouns.txt -s "_"
```
Output:
```
Happy_Cat_42
```

## Building

Compile with gcc:

```sh
gcc -o namegen-cli main.c
```

## Files

- `main.c` — Source code
- `english-adjectives.txt` — Default adjectives list
- `english-nouns.txt` — Default nouns list

## License

MIT License

---

*Created for study and practice with C and command-line

