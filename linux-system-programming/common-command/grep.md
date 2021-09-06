# THIS MarkDown file will introduce the usage of "grep"
## "grep" is used to find the line that contains the content you want:

> cat test.txt
ID  name    gender  age
1   alice   female  10
2   bob     male    11
3   jerry   female  11
4   zok     male    12

> grep "11" test.txt       // use "" for better
> 2   bob     male    11
> 3   jerry   female  11

> grep "1" test.txt        // can get lines that contain "1", note it is different with the lines that start with "1"(see next)
1   alice   female  10
2   bob     male    11
3   jerry   female  11
4   zok     male    12

## "grep" support regularized expression
## "^" is the begining of the line
> grep "^1" test.txt       // use ^, this is used to get lines that start with "1"
1   alice   female  10  

## "$" is the end of the line
> grep "1$" test.txt       // use $, this is used to get lines that end with "1"
2   bob     male    11
3   jerry   female  11

## "." can mathe with any one char, "*" means that the previous char can show up for any times(including 0)
> grep "^1.*$" test.txt    // .* meas any char or string
1   alice   female  10

## "[]" can be used to set the range, "\\{n\\}" means the previous char can show up for n times, "\\{m,n\\}" means the previous char can show up for m to n times. This is usually used to get the ip
> grep "[0-9]\\{1,3\\}.[0-9]\\{1,3\\}.[0-9]\\{1,3\\}.[0-9]\\{1,3\\}" test_.txt
alice   123.4.56.789    2021-9-5
elke    12.34.5.678     2021-09-05
bob     1.23.4.5        2021-09-5
bik     12.345.6.0      2021-9-05

## samely, we can get the date
> grep "[0-9]\\{1,4\\}-[0-9]\\{1,2\\}-[0-9]\\{1,2\\}" test_.txt
alice   123.4.56.789    2021-9-5
elke    12.34.5.678     2021-09-05
bob     1.23.4.5        2021-09-5
bik     12.345.6.0      2021-9-05

