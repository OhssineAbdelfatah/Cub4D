// #include<fcntl.h>
// #include<unistd.h>
// #include<stdio.h>

// int main()
// {
//     char *file = "file.txt";
//     char str1[5];
//     char str2[5];

//     int fd = open(file, O_RDONLY);
//     ssize_t r = read(fd, str1, 4);
//     str1[r] = 0;
//     printf ("str  : %s\n" , str1);

//     fd = open(file, O_RDONLY);
//     ssize_t rr = read(fd, str2, 4);
//     str2[rr] = 0;
//     printf ("str  : %s\n" , str2);
// }


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
    char str[5];
    char str2[5];

    int fd = open (text1, O_RDONLY);
    ssize_t r = read (fd, str, 5);
    str[r] = '\0';
    printf ("str : %s\n", str);
    
    // close(fd);
    int fd2 = open (text1, O_RDONLY);
    printf ("2nd fd2 %d\n", fd2);
    // if (fd2 == -1)
    //     perror("faild : ");
    ssize_t rr = read (fd2, str2, 5);
    str2[r] = '\0';
    printf ("str2 : %s\n", str2);
    printf ("r : %zd\n", r);
    printf ("rr : %zd\n", rr);
}
