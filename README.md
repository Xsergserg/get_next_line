# gnl
 
Get_next_line function.

get_next_line(int filedescriptor, \*\*line)

Every function call add to \*\*line one line from file and return length of line, 0 if file is finished or -1 if error.

Function uses only malloc(), free(), read(), write(), open() and close() fuctions from c libraries, other functions are "handmade".
