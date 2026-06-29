/* func_02051918 at 0x02051918
 *
 * Matched byte-for-byte with mwccarm 1.2/sp2p3 (arm9 main).
 */
typedef struct {
    unsigned char type;
    unsigned char arg;
    short pad;
    int value;
} Entry;

typedef struct {
    unsigned int count;
    Entry entries[1];
} Header;

extern Header *func_02050a84(unsigned int id);
extern int func_0205179c(unsigned int id, int flags, int arg2);
extern int func_020518dc(void *a, void *b);
extern int func_020516d4(unsigned int id, int flags, int arg2);
extern int func_020518a0(void *a, void *b);

int func_02051918(unsigned int id, void *param) {
    Header *h;
    unsigned int i;
    Entry *e;

    h = func_02050a84(id);
    if (h == 0) {
        return 0;
    }
    for (i = 0; i < h->count; i++) {
        e = &h->entries[i];
        switch (e->type) {
        case 0:
            if (func_0205179c(e->value, e->arg, (int)param) == 0) return 0;
            break;
        case 3:
            if (func_020518dc((void *)e->value, param) == 0) return 0;
            break;
        case 1:
            if (func_020516d4(e->value, e->arg, (int)param) == 0) return 0;
            break;
        case 2:
            if (func_020518a0((void *)e->value, param) == 0) return 0;
            break;
        }
    }
    return 1;
}