#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <inttypes.h>
#include <sys/time.h>

//  RETURNS THE CURRENT TIME, AS A NUMBER OF MILLISECONDS, IN A 64-bit INTEGER
int64_t milliseconds(void)
{
    struct timeval  now;

    gettimeofday( &now, NULL );       // timezone not required, so we pass NULL
    return ((int64_t)now.tv_sec * 1000) + now.tv_usec/1000;
}

void readfile(char filename[], int buffersize)
{
    int     ncalls  = 0;
    int64_t start   = milliseconds();

    int fd  = open(filename, O_RDONLY);
    ++ncalls;

    if(fd >= 0) {
        char buffer[buffersize];
        size_t  got;

        while((got = read(fd, buffer, sizeof(buffer))) > 0) {
            ++ncalls;
        }
        close(fd);
        ++ncalls;
    }

    printf("%i\t%i\n", buffersize, (int)(milliseconds() - start));
//    printf("%i\t%i\n", ncalls, (int)(milliseconds() - start));
}

void usage(char progname[])
{
    printf("Usage: %s filename buffersize\n", progname);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
//  ENSURE WE HAVE SUFFICIENT ARGUMENTS
    if(argc != 3) {
        usage(argv[0]);
    }

//  ENSURE THAT THE BUFFERSIZE IS MEANINGFUL
    int buffersize  = atoi(argv[2]);
    if(buffersize <= 0) {
        usage(argv[0]);
    }

//  PASS VALIDATED ARGUMENTS TO TEH FUNCTION WHICH DOES THE WORK
    readfile(argv[1], buffersize);

    return EXIT_SUCCESS;
}
