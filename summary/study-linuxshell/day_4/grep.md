## how to use grep 

- **grep "search contents" file-name** 

    - under file-name to find the row that include search contents

- **grep -c/-n "search contents" file-name** 

    - show how much row/then show contents

- **grep -i "Search Contents" file-name** 

    - ignore the uppuer and lower to search contents

- **grep -v "not include" file-name** 

    - find the contents that not include contents

- **grep -E "正则表达式"** 

    - ^linux: the row whose haed is linux

    - $linux: the row whose tail is linux

    - .: macth any single char

    - .+: macth any multi-char

    - .*: match zero or multi-char

    - [0-9a-z]: match any char betwen []

    - (linux)+: apeal more linux

    - (linux){3}: apeal three times 
  
    - ＼: ignore the spacial means of char

