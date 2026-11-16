// helper — tiny payload executed by ctapp to test whether AMFI/CoreTrust
// accepts our crafted CMS signature.
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv) {
    const char *path = (argc > 1) ? argv[1] : "/tmp/ct_helper_ran";
    FILE *f = fopen(path, "w");
    if (f) { fprintf(f, "ran uid=%d pid=%d\n", getuid(), getpid()); fclose(f); }
    return 0;
}
