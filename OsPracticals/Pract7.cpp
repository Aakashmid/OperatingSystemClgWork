#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int n, fd, fd1;
    char b[50];

    fd = open("filea.txt", O_RDONLY);               // Open source file
    n = read(fd, b, 15);                            // Read 15 bytes
    fd1 = open("filea", O_CREAT | O_WRONLY, 0642);  // Create/write destination
    write(fd1, b, n);                               // Write read content
    return 0;
}


