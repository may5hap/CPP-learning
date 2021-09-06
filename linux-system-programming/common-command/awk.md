# THIS MarkDown script is used to describe the usage of awk
## The base form
> awk 'condition1{action1} condition2{action2}...'

> awk '{printf $2 "\t" $4 "\n"}' test.txt
name	age
alice	10
bob	    11
jerry	11
zok	    12

> df -h | awk '{printf $5 "\n"}'
Use%
0%
1%
99%
2%
1%
0%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
100%
1%
100%
100%
100%
100%
1%
100%

## grep/cut/awk/printf pipeline
> df -h | grep "^tmpfs" | awk '{printf $5 "\n"}' | cut -d "%" -f 1
1
2
1
0
1
1