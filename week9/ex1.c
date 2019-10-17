#include <stdio.h>

#define N 3

struct frame {
    unsigned int age    :8;
    unsigned int full   :1;
    unsigned int pageId :23;
};

struct frame frames[N];

int main() {
    for (int i = 0; i < N; i++) {
        frames[i].age = 0;
        frames[i].full = 0;
        frames[i].pageId = 0;
    }

    int hit = 0, miss = 0;

    FILE *in = fopen("my_input_inc.txt", "r");
    while (!feof(in)) {
        int pageId;
        fscanf(in, "%d", &pageId);
        int frameId = -1, target = 0;
        for (int i = 0; i < N; i++) {
            if (frames[i].full && frames[i].pageId == pageId) {
                frameId = i;
                break;
            }

            if (frames[i].full == 0) {
                target = i;
                break;
            } else if (frames[i].age < frames[target].age) {
                target = i;
            }
        }

        for (int i = 0; i < N; i++) {
            frames[i].age >>= 1;
        }

        if (frameId == -1) {
            //printf("Miss occurred for page %d, replacing frame %d with page %d with age %d\n", pageId, target, frames[target].pageId, frames[target].age);
            miss++;
            frames[target].age = 1 << 7;
            frames[target].pageId = pageId;
            frames[target].full = 1;
        } else {
            //printf("Hit occurred for page %d\n", pageId);
            hit++;
            frames[frameId].age += 1 << 7;
        }
    }

    printf("Hit / (Hit + Miss) = %lf\n", (double) hit / (hit + miss));
}

/*
N=10 : Hit / (Hit + Miss) = 0.010989
N=50 : Hit / (Hit + Miss) = 0.051948
N=100: Hit / (Hit + Miss) = 0.093906
*/