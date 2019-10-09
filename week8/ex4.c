#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    for (int i = 0; i < 10; i++) {
        char *a = malloc(10 * 1024 * 1024);
        memset(a, 0, 10 * 1024 * 1024);
        struct rusage *usage = malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, usage);
        printf("ru_ixrss: %ld, ru_idrss: %ld, ru_isrss: %ld, ru_minflt: %ld, ru_majflt: %ld\n", usage->ru_ixrss, usage->ru_idrss, usage->ru_isrss, usage->ru_minflt, usage->ru_majflt);
        sleep(1);
    }

    return 0;
}

/*
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 2888, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 5451, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 8014, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 10575, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 13135, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 15695, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 18255, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 20817, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 23378, ru_majflt: 0
ru_ixrss: 0, ru_idrss: 0, ru_isrss: 0, ru_minflt: 25938, ru_majflt: 0
*/