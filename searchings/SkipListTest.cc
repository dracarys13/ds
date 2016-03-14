#include "SkipList.h"

int  main() {
    /* Key int, Valut int
    SkipList *sl = createSkipList();
    insert(sl, 1, 1 * 1);
    insert(sl, 2, 2 * 2);
    insert(sl, 3, 3 * 3);
    insert(sl, 4, 4 * 4);
    insert(sl, 5, 5 * 5);
    insert(sl, 6, 6 * 6);
    printSkipList(sl);
    Key key;
    Node *node;
    for (key = 0; key < 10; ++key) {
        node =  find(sl, key);
        if (NULL == node) {
            printf("cannot find %d\n", key);
        } else {
            printf("find:(%d,%d)\n", node->key, node->value);
        }
    }
    for (key = 0; key < 10; ++key) {
        remove(sl, key);
        printf("remove %d\n", key);
        printSkipList(sl);
    }
    destorySkipList(sl);
    */
    SkipList *sl = createSkipList();
    char *host[] = {"www.baidu.com", "www.sina.com", "www.google.com", "www.yahoo.com", "www.qq.com", "www.taobao.com"};
    char *ip[] = {"220.181.112.76", "121.14.1.189", "216.58.199.4", "116.214.12.74", "182.254.34.74", "58.67.149.253"};
    int len = sizeof(host) / sizeof(char *);
    for (int i = 0; i < len; ++i) {
        insert(sl, host[i], ip[i]);
    }
    printSkipList(sl);
    char *look[] = {"www.baidu.com", "www.sina.com", "www.google.com", "www.yahoo.com", "www.qq.com", "www.taobao.com", "www.cnn.com", "www.nba.com"};
    len = sizeof(look) / sizeof(char *);
    for (int i = 0; i < len; ++i) {
        Node *node =  find(sl, look[i]);
        if (NULL == node) {
            printf("cannot find %s\n", look[i]);
        } else {
            printf("find:(%s,%s)\n", node->key, node->value);
        }
    }
    for (int i = 0; i < len; ++i) {
        remove(sl, look[i]);
        printf("remove %s\n", look[i]);
        printSkipList(sl);
    }
    destorySkipList(sl);
    return 0;
}
