# THIS MarkDown script describes the usage of "sed"
## "sed" is used to CURD the data
> sed -option 'action' filename

## print the 2th line of test.txt
> sed -n '2p' test.txt
1   alice   female  10

## delete 2,3th line
> sed '2,3d' test.txt      
>> d for delete, note that this doesnot really delete the data
>> ID  name    gender  age
>> 3   jerry   female  11
>> 4   zok     male    12

> cat test.txt
>> ID  name    gender  age
>> 1   alice   female  10
>> 2   bob     male    11
>> 3   jerry   female  11
>> 4   zok     male    12

## append data
> sed '5 a  5   curry   male    20' test.txt
### or use i to insert
> sed '6 i  5    curry   male    20' test.txt
>> ID  name    gender  age
>> 1   alice   female  10
>> 2   bob     male    11
>> 3   jerry   female  11
>> 4   zok     male    12
>> 5   curry   male    20
### note that this does not really insert into the data. If you really want to insert into the data, use option -i
> cat test.txt
>> ID  name    gender  age
>> 1   alice   female  10
>> 2   bob     male    11
>> 3   jerry   female  11
>> 4   zok     male    12

> sed -i '5 a  5    curry   male    20' test.txt
>> ID  name    gender  age
>> 1   alice   female  10
>> 2   bob     male    11
>> 3   jerry   female  11
>> 4   zok     male    12
>> 5   curry   male    20

> cat test.txt
>> ID  name    gender  age
>> 1   alice   female  10
>> 2   bob     male    11
>> 3   jerry   female  11
>> 4   zok     male    12
>> 5   curry   male    20

## change the data
> sed -i '5c    10  durant  female 30' test.txt
>> ID  name    gender  age
>> 1   alice   female  10
>> 2   bob     male    11
>> 3   jerry   female  11
>> 10  durant  female  30