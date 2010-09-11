#include "Vector4.hpp"

namespace __Vector4__ {

Vector4 *v;
str *__name__;


/**
class Vector4
*/

class_ *cl_Vector4;

void __init() {
    __name__ = new str("Vector4");

    cl_Vector4 = new class_("Vector4", 31, 31);
    v = (new Vector4());
}

} // module namespace

/* extension module glue */

extern "C" {
#include <Python.h>
#include <structmember.h>

namespace __Vector4__ { /* XXX */

/* class Vector4 */

typedef struct {
    PyObject_HEAD
    __Vector4__::Vector4 *__ss_object;
} Vector4Object;

static PyMemberDef Vector4Members[] = {
    {NULL}
};

static PyNumberMethods Vector4_as_number = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

static PyMethodDef Vector4Methods[] = {
    {NULL}
};

PyObject *Vector4New(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
    Vector4Object *self = (Vector4Object *)type->tp_alloc(type, 0);
    self->__ss_object = new __Vector4__::Vector4();
    self->__ss_object->__class__ = __Vector4__::cl_Vector4;
    __ss_proxy->__setitem__(self->__ss_object, self);
    return (PyObject *)self;
}

void Vector4Dealloc(Vector4Object *self) {
    self->ob_type->tp_free((PyObject *)self);
    __ss_proxy->__delitem__(self->__ss_object);
}

PyGetSetDef Vector4GetSet[] = {
    {NULL}
};

static PyTypeObject Vector4ObjectType = {
    PyObject_HEAD_INIT(NULL)
    0,              /* ob_size           */
    "Vector4.Vector4",        /* tp_name           */
    sizeof(Vector4Object), /* tp_basicsize      */
    0,              /* tp_itemsize       */
    (destructor)Vector4Dealloc, /* tp_dealloc        */
    0,              /* tp_print          */
    0,              /* tp_getattr        */
    0,              /* tp_setattr        */
    0,              /* tp_compare        */
    0,              /* tp_repr           */
    &Vector4_as_number,  /* tp_as_number      */
    0,              /* tp_as_sequence    */
    0,              /* tp_as_mapping     */
    0,              /* tp_hash           */
    0,              /* tp_call           */
    0,              /* tp_str            */
    0,              /* tp_getattro       */
    0,              /* tp_setattro       */
    0,              /* tp_as_buffer      */
    Py_TPFLAGS_DEFAULT, /* tp_flags          */
    0,              /* tp_doc            */
    0,              /* tp_traverse       */
    0,              /* tp_clear          */
    0,              /* tp_richcompare    */
    0,              /* tp_weaklistoffset */
    0,              /* tp_iter           */
    0,              /* tp_iternext       */
    Vector4Methods,      /* tp_methods        */
    Vector4Members,      /* tp_members        */
    Vector4GetSet,       /* tp_getset         */
    0,              /* tp_base           */
    0,              /* tp_dict           */
    0,              /* tp_descr_get      */
    0,              /* tp_descr_set      */
    0,              /* tp_dictoffset     */
    0,              /* tp_init           */
    0,              /* tp_alloc          */
    Vector4New,          /* tp_new            */
};

} // namespace Vector4

namespace __Vector4__ { /* XXX */

static PyNumberMethods Global_Vector4_as_number = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

static PyMethodDef Global_Vector4Methods[] = {
    {NULL}
};

PyMODINIT_FUNC initVector4(void) {
    printf("init v4\n");
//    __shedskin__::__init();
    __Vector4__::__init();

    PyObject *mod = Py_InitModule((char *)"Vector4", Global_Vector4Methods);
    if(!mod)
        return;

    if (PyType_Ready(&__Vector4__::Vector4ObjectType) < 0)
        return;

    PyModule_AddObject(mod, "Vector4", (PyObject *)&__Vector4__::Vector4ObjectType);

    PyModule_AddObject(mod, (char *)"v", __to_py(__Vector4__::v));

}

} // namespace __Vector4__

} // extern "C"
namespace __Vector4__ { /* XXX */

PyObject *Vector4::__to_py__() {
    if(__ss_proxy->has_key(this))
        return (PyObject *)(__ss_proxy->__getitem__(this));
    Vector4Object *self = (Vector4Object *)(Vector4ObjectType.tp_alloc(&Vector4ObjectType, 0));
    self->__ss_object = this;
    __ss_proxy->__setitem__(self->__ss_object, self);
    return (PyObject *)self;
}
}

namespace __shedskin__ { /* XXX */

template<> __Vector4__::Vector4 *__to_ss(PyObject *p) {
    if(p == Py_None) return NULL;
    if(PyObject_IsInstance(p, (PyObject *)&__Vector4__::Vector4ObjectType)!=1)
        throw new TypeError(new str("error in conversion to Shed Skin (Vector4 expected)"));
    return ((__Vector4__::Vector4Object *)p)->__ss_object;
}
}
