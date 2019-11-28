### an advantage usage of cat

- **heredoc** <++>

```sh
#!/bin/bash

value=ssssssucessful

cat << eof

    aaaaa${value}aaaaa
    aaaaa`echo -e "\033[30;47m${value}\033[0m"`aaaa
    aaaaaaaaaaaaaaaaaa

eof
```



