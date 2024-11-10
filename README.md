In this building and manual we called the build file grepfile, you can change this by editing the last word on line 5 from "grepfile" to anything that fits your needs.

# Building
g++ needed.
cd grepfile
g++ -Wall main.cpp -o grepfile

# Running
usage from anywhere: 
put in a folder that is in the PATH and use {WhatYouCalledTheBuiltFile} from anywhere
specify file path:
use /dir/to/grepfile/build/grepfile to run the app.

# How to use
Help command:
grepfile --help

Normal usage:
grepfile -f {FileNameToSearch} -s "{WhatYouWantToSeachFor}"
