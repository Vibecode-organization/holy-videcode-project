#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
extern int csops(int, unsigned int, void *, size_t);
int main(void) {
    int fd = open("/tmp/ct_exec_canary.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd >= 0) {
        dprintf(fd, "pid=%d uid=%d euid=%d\n", getpid(), getuid(), geteuid());
        close(fd);
    }
    unsigned int st = 0;
    csops(getpid(), 0, &st, sizeof(st));
    printf("CTCANARY pid=%d uid=%d csflags=0x%x\n", getpid(), getuid(), st);
    sleep(30);
    return 0;
}
