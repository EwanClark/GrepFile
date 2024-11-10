# Build Instructions

`This project requires g++ for building.`

**Note**: The build output file is named `grepfile` by default. To change this, edit the last word on line 5 replacing `"grepfile"` with any name that suits your needs.

### Building  
`Ensure g++ is installed`

```bash
cd grepfile
g++ -Wall main.cpp -o grepfile
```
### Running

#### Usage from anywhere:
1. Move the built file into a directory in your `PATH` to use it globally with `"grepfile"`
2. Alternatively, run it directly using the full path:
`"/path/to/grepfile/build/grepfile"`

### How to Use

#### Help command:
```bash
grepfile --help

#### Normal usage:
grepfile -f [FileNameToSearch] -s "[TextToSearchFor]"
```