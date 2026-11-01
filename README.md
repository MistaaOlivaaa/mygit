# mygit

`mygit` is a small Git implementation written in C. The project gradually
recreates some of Git's internal concepts, including repository
initialization and the organization of the `.git` directory.

The project is currently under development. The only available command is
`init`.

## Current Features

The following command is available:

```text
mygit init
```

It creates an empty repository with the following structure:

```text
.git/
├── HEAD
├── objects/
└── refs/
    └── heads/
```

The `.git/HEAD` file points to the main branch:

```text
ref: refs/heads/main
```

The program displays an error if no command is provided or if the requested
command has not been implemented yet.

## Planned Features

The project interface is designed to support the following commands and
features:

- creating and reading Git objects;
- adding files with `add`;
- creating commits with `commit`;
- displaying the history with `log`;
- displaying the repository status with `status`;
- creating and switching branches;
- merging branches;
- `pull`, `push`, and `stash`.

These features are declared in `mygit.h`, but they have not all been
implemented or connected to `main` yet.

## Requirements

The project requires:

- a GCC-compatible C compiler;
- GNU Make when using the `Makefile` to build the project.

### Windows

On Windows, MSYS2 is a convenient way to install GCC and Make. In an
**MSYS2 UCRT64** terminal, install the required tools with:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc \
                    mingw-w64-ucrt-x86_64-make
```

The project can then be opened using its Windows path:

```bash
cd /c/Users/saadddd/Music/mygit
```

### Linux

On Debian or Ubuntu, install the required tools with:

```bash
sudo apt update
sudo apt install build-essential
```

## Building

From the project root, build the program with Make:

```bash
make
```

The generated binary is named `mygit` on Linux and may appear as `mygit.exe`
on Windows.

If `make` is not available, compile the project directly with GCC:

```bash
gcc main.c utils.c -Wall -Wextra -g -o mygit
```

On Windows, use:

```bash
gcc main.c utils.c -Wall -Wextra -g -o mygit.exe
```

## Usage

### Initialize a Repository

From the directory where the repository should be created, run the following
command.

On Linux or MSYS2:

```bash
./mygit init
```

In PowerShell:

```powershell
.\mygit.exe init
```

The command creates the `.git` directory and displays a confirmation message.

To verify the created structure on Linux or MSYS2:

```bash
find .git -print
```

In PowerShell:

```powershell
Get-ChildItem .git -Recurse
```

### Display the Minimal Usage Information

Running the program without a command displays its usage format:

```bash
./mygit
```

Expected output:

```text
usage: ./mygit <command> [args]
```

## Project Structure

```text
.
├── main.c
├── mygit.h
├── utils.c
└── Makefile
```

### `main.c`

Contains the program entry point and command dispatch logic. It currently
handles the `init` command.

### `mygit.h`

Contains the constants representing the repository's internal paths, the
sizes used for SHA-1 identifiers, and the declarations of the project's
functions.

### `utils.c`

Contains the utility functions currently used to:

- create a directory;
- read a file;
- write a file;
- convert a binary SHA-1 value to its hexadecimal representation.

The file also contains the functions planned for SHA-1 computation and Git
object management.

### `Makefile`

Describes how to build the project with GCC. The main targets are:

| Target | Description |
|---|---|
| `make` | Builds the program |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the binary |
| `make re` | Cleans and rebuilds the project |

## Current Limitations

- only the `init` command is accessible from the program;
- the commands declared in `mygit.h` have not all been implemented;
- the project does not yet replace the official Git program;
- complete index, tree, commit, and branch management still needs to be
  developed.

## Development

After modifying the source code, rebuild the project with:

```bash
make re
```

Then test repository initialization in a test directory to verify that the
`.git` directory is created correctly.
