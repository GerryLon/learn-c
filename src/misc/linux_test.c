#include "../common/common.h"
#include "linux_test.h"

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:        the pointer to the member.
 * @type:       the type of the container struct this is embedded in.
 * @member:     the name of the member within the struct.
 *
 * It takes three arguments – a pointer, type of the container,
 * and the name of the member the pointer refers to.
 * The macro will then expand to a new address pointing
 * to the container which accommodates the respective member.
 */
#define container_of(ptr, type, member) ({                  \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

#define container_of_noconst(ptr, type, member) ({      \
	(type *)( (char *)ptr - offsetof(type,member) );})

typedef struct Node {
    double d;
    int i;
} Node;

int test_classic_macro() {
	Node n = {
        .d = 3.14,
        .i = 6,
    };

    Node* pNode = NULL;
    // 成员i的偏移为一个double的长度, 以Node的定义为准
    assert(offsetof(Node, i) == sizeof(double));
    // d定义在Node中第一个位置, 所以偏移为0
    assert(offsetof(Node, d) == 0);
	// 事实上, 由于成员d偏移为0, 所以d的地址和n的地址一样
	assert(&n.d == &n);
	assert(&n.i == (char*)&n + sizeof(double));

    pNode = container_of(&n.i, Node, i);
    assert(pNode == &n);
    assert(pNode->i == 6);

    pNode = container_of_noconst(&n.i, Node, i);
    assert(pNode == &n);
    assert(pNode->i == 6);

    assert(&n.i - 2 == &n);
    // assert(&n.i - sizeof(double) == &n);

    // warning: initialization from incompatible pointer type [-Wincompatible-pointer-types]|
    // const typeof( ((type *)0)->member ) *__mptr = (ptr);
    // 上面const...这一句相当于将成员变量i对应类型,即int类型的指针赋值给ptmp, 所以类型不兼容
    char tmp = 'a';
    char* ptmp = &tmp;
    pNode = container_of(ptmp, Node, i);
    // assert(pNode == &n); // assert failed

    int num = 0;
    int* pnum = &num;
    // 没有warning, 因为成员变量i和num类型一样
    pNode = container_of(pnum, Node, i);
    // assert(pNode == &n); // assert failed
    return 0;
}


int test_linux() {
    test_classic_macro();
    return 0;
}
