**WHAT IS IT ABOUT?**

This is a 42 School project in Core curriculum, which requires to build a fuction named get_next_line (gnl) behaves like _fgets_ or _getline_ in standard library, involve reading lines from a file or input stream in a more flexible way than.

Function prototype: 
_char *get_next_line(int fd)_

The gnl is a pointer pointing to a character string, in this case 1 line in a file. 
It takes an _fd_ interger which is normally contained from an opened file: 
_int open(const char *pathname, int flags)_

**HOW TO USE IT?**
Placing gnl in an infinite loop, it walks you through the file line by line until the EOF (end of file) or from standard input from console.

**HOW IS IT BUILT?**
The logic behind: 
-> Read the n given bytes to a string 
-> From readed string get first line (until the newline '\n')
-> Before returning the line save the rest which not belong to 1.line 
-> Join the rest to it's real line at getting the next line. 
-> Repeat this logic till the EOF.

In building gnl some other selfbuilt funtions are utilized, they are placed in get_next_line_utils.c in the gnl reposity such as: 

_char	*ft_strjoin(char const *s1, char const *s2)_

_size_t	ft_strlen(const char *s)_

_void	*ft_memcpy(void *dst, const void *src, size_t n)_

_char	*ft_strdup(const char *s1)_

P/s: Sources Link: https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/ 
