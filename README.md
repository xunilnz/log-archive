# Log Archive
This application is to help you backup log files from a server.

log-archive takes a directory as a parameter and creates a tar.gz archive of the specified directory. 
The tar.gz filename includes the date and time the program was run.

This is just one method of completing this task, in this case it is done in C. However a bash script could achieve the same thing quite easily.
 
## Compile

```
gcc log-archive.c -o log-archive
```

## Install

```
sudo mv ./log-archive /usr/local/bin/log-archive
```
## Usage
```
log-archive </directory/to/archive/> </directory/to/store/archive/>
```
