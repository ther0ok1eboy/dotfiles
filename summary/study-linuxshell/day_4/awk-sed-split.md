## how to use awk and sed

- **awk '{print $0/$1}' file-name** 

    - print each column/first column base on file-name(default is take Space as split char)

- **awk -F% '{print $1"\t$3"}' file-name** 

    - base on % as split char to print the first row and third row


--------


- **sed -n '2'p file-name** 

    - print second row of file-name

- **sed -n '1,4'p file-name** 

    - print from first row to fourth row

- **sed -n '/fish'p file-name** 

    - print all rows that match with /fish

- **sed -n '1,/fish'p file-name** 

    - print all rows from first row to row that match /fish

- **sed '1,2'd** 

    - print all rows whiteout first and second row



--------



- **uniq -c file-name** 

    - print not repeat rows whose position is so close then print the numbers of repetition

- **uniq -d file-name** 

    - only print repeat rows


--------


- **sort file-name** 

    - base on alphabet' up to sort

- **sort -r file-name** 

    - base on alphabet' down to sort

- **cat file-name | sort -t: -k1** 


    - base on : as a split char and base on first column to sort(default base on Space to split each column)


--------



- **split -3 file-source file-destination** 

    - make file-source split with three parts into file-destination and appeal three new files
