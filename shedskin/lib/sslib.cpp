#include "builtin.hpp"

namespace __shedskin__ {

class_ *cl_class_, *cl_none, *cl_str_, *cl_int_, *cl_float_, *cl_complex, *cl_list, *cl_tuple, *cl_dict, *cl_set, *cl_object, *cl_rangeiter, *cl_xrange;

str *sp, *nl, *__fmt_s, *__fmt_H, *__fmt_d;
__GC_STRING ws, __fmtchars;
__GC_VECTOR(str *) __char_cache;

__ss_bool True;
__ss_bool False;

list<str *> *__join_cache, *__mod5_cache;
list<pyobj *> *__print_cache;

char __str_cache[4000];

#ifdef __SS_BIND
dict<void *, void *> *__ss_proxy;
#endif

void __init() {
    GC_INIT();
#ifdef __SS_BIND
    Py_Initialize();
    __ss_proxy = new dict<void *, void *>();
#endif

    cl_class_ = new class_ ("class_", 0, 0);
    cl_none = new class_("none", 1, 1);
    cl_str_ = new class_("str_", 2, 2);
    cl_int_ = new class_("int_", 3, 3);
    cl_float_ = new class_("float_", 4, 4);
    cl_list = new class_("list", 5, 5);
    cl_tuple = new class_("tuple", 6, 6);
    cl_dict = new class_("dict", 7, 7);
    cl_set = new class_("set", 8, 8);
    cl_object = new class_("object", 9, 9);
    cl_rangeiter = new class_("rangeiter", 10, 10);
    cl_complex = new class_("complex", 11, 11);
    cl_xrange = new class_("xrange", 12, 12);

    True.value = 1;
    False.value = 0;

    ws = " \n\r\t\f\v";
    __fmtchars = "#*-+ .0123456789hlL";
    sp = new str(" ");
    nl = new str("\n");
    __fmt_s = new str("%s");
    __fmt_H = new str("%H");
    __fmt_d = new str("%d");

    for(int i=0;i<256;i++) {
        char c = i;
        __char_cache.push_back(new str(&c, 1));
    }

    __join_cache = new list<str *>();
    __print_cache = new list<pyobj *>();
    __mod5_cache = new list<str *>();

   for(int i=0; i<1000; i++) {
       __str_cache[4*i] = '0' + (i % 10);
       __str_cache[4*i+1] = '0' + ((i/10) % 10);
       __str_cache[4*i+2] = '0' + ((i/100) % 10);
   }
}

}
