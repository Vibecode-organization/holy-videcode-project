// helper_dylib — payload loaded via dlopen to test AMFI/CoreTrust acceptance.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
__attribute__((constructor))
static void ct_init(void) {
    const char *p = getenv("CT_MARKER");
    if (p) {
        FILE *f = fopen(p, "w");
        if (f) { fprintf(f, "loaded uid=%d pid=%d\n", getuid(), getpid()); fclose(f); }
    }
}
int ct_ping(void) { return 0x1337; }
