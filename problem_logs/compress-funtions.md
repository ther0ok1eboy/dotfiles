### zip and unzip

**Some common parameters:**

| options             | explanation                                                                                          |
|---------------------|------------------------------------------------------------------------------------------------------|
| -d<store directory> | unzip to custom directory.                                                                           |
| -D                  | zip the file without directory.                                                                      |
| -F                  | try to fix broken file.                                                                              |
| -g                  | compress directory including have been compressed directory instead of create a new compressed file. |
| -m                  | after compressing, delete sourse file.                                                               |
| -q                  | not show the process of compressing.                                                                 |
| -r                  | recursion.                                                                                           |
| -S                  | compress directory including conceal files.                                                          |
    
**common use:** 

`$ zip -r -q zip-name $HOME/[your directory]` 

`$ zip -r -q zip-name *` if this file at your directory

`$ unzip zip-packages` unzip all files without directory (not recommend).

`$ unzip zip-packages -d my-dirctory` unzip all files into a directory named my-directory.

### unrar and rar

**Some common parameters:**

| options | explanation                      |
|---------|----------------------------------|
| -e      | extract files without dirctory   |
| -p      | print extract infomation         |
| -x      | extract files with complete path |

**common use:** 

`$ rar a c.rar *.c` compress all of C file under the current directory into a package named c.rar.

`$ unrar x c.rar` extract with full paths. 

### tar

**Some common parameters:**

| options | explanation                                       |
|---------|---------------------------------------------------|
| -c      | create new Archive                                |
| -x      | common compress                                   |
| -z      | compress with gzip                                |
| -v      | show compress process                             |
| -f      | use Archive name and it the last parameter        |
| -r      | compress file into a tail of exiting Archive file |

**common use:** 

`$ tar -cf c.tar *.c` compress all of C file under the current directory into a Archive named c.tar.

`$ tar -rf c.tar *.cpp` add all of CPP file under the current directory into a tail of exiting Archive file. 

`$ tar -czf c.tar.gz *.py` after compress an Archive file named c.tar, use `gzip` to compress this file named c.tar.gz. 

**some conclusions:**

| command          | easy usage        |
|------------------|-------------------|
| *.tar            | tar -xvf          |
| *.gz             | gzip -d & gunzip  |
| *.tar.gz & *.tgz | tar -xzf          |
| *.bz2            | bzip2 d & bunzip2 |
| *.tar.bz2        | tar -xjf          |
| *.rar            | unrar x           |
