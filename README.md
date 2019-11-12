# pa4
4 different sorting algorithms.

# To use
The executable performs two functions:
## Reads text from a file:
```
./a.exe <filename.txt>
```
If no filename is specified, `numbers.txt` will be assumed.

Note: the file must be formatted according:
```
<sorting id> // 0: bubble, 1: heap, 2: merge, 3: quick
<count>
1
2
3
...
```

## Times the sorting algorithms:
```
./a.exe test <count> <type>
```
This command allows you to specify _everything_ or _nothing_. Meaning that you can either follow the format above, or you can run the following:
```
./a.exe test
```
and the operations will run with default selections.

Note: `<type>` is currently limited to `random`, `increasing` and `decreasing`.
