/*
* @Author: tlucanti
* @Date:   2022-03-27 17:22:08
* @Last Modified by:   tlucanti
* @Last Modified time: 2022-03-27 20:31:26
*/

#include <TLUnum.h>
#include <TLUmemory.h>
#include <TLUobjstack.h>
#include <TLUlexical.h>
#include <TLUbuiltin.h>

// --------------------------------- converter ---------------------------------
TLUobject   TLUnum(intmax_t a)
{
    _TLUnum  *obj = _TLUallocator(sizeof(_TLUnum));
    _TLUobjstack_add(TLUOBJ_NUM_TYPEID, obj);
    obj->number = a;
    return (TLUobject){ TLUOBJ_NUM_TYPEID, obj };
}

// ----------------------------------- copy ------------------------------------
__WUR
TLUobject   _TLU_num_copy(TLUobject _obj)
{
    _TLUnum *obj = _GET_NUM(_obj);
    return TLUnum(obj->number);
}

// ----------------------------------- hash ------------------------------------
__WUR
intmax_t   _TLU_hash_num(TLUobject _obj)
{
    _TLUnum *obj = _GET_NUM(_obj);
    return obj->number;
}

// ----------------------------------- iadd ------------------------------------
void _TLU_iadd_num2num(TLUobject _self, TLUobject _other)
{
    _TLUnum *self = _GET_NUM(_self);
    _TLUnum *other = _GET_NUM(_other);
    self->number += other->number;
}

// -------------------------------- str --------------------------------
__WUR
TLUobject _TLU_num2str(TLUobject _obj)
{
    _TLUnum *obj = _GET_NUM(_obj);
    char    buf[20];
    _TLUnum2s(obj->number, buf, 10, 0);
    return TLUstr(buf);
}
