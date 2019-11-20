- **#!/bin/bash ==> use bash to explain the following oders**

- **the # is explain syntax except the first # in #!/bin/bash** 

- **task lists:** 

    `crontab -e` 

`` means read oder betwen `` and the value of result of `` will input its ahead value and not have Spece
    ```shell
string=`whereis fish`
echo $string
```

- **"" means bash will explain value in ""** 

```shell
value=fish
echo "where is my $value"
echo "oh my ${value} fish"
```
- **position values:** 

    a position value only receive nine value

    ```shell
    $ bash a.sh aa bb cc dd ...
    #!/bin/bash
    echo $1
    echo $2
    echo $3
    ...
    ```

- **pre-define value:** 

    - $# ==> the number of position value in CLI
    
    - $* ==> the contents of position value 

    - $? ==> if last oder excute sucessfully, return 0, if fail, return not 0

    - $0 ==> show name of current oder


