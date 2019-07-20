// The MIT License (MIT)

// Copyright (c) 2013 lailongwei<lailongwei@126.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of 
// this software and associated documentation files (the "Software"), to deal in 
// the Software without restriction, including without limitation the rights to 
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
// the Software, and to permit persons to whom the Software is furnished to do so, 
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS 
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef __LLBC_CORE_OBJECT_POOL_OBJECT_MANIPULATOR_H__
#define __LLBC_CORE_OBJECT_POOL_OBJECT_MANIPULATOR_H__

#include "llbc/common/Common.h"

__LLBC_NS_BEGIN

/**
 * Pre-declare some classes.
 */
class LLBC_IObjectPoolInst;

__LLBC_NS_END

__LLBC_NS_BEGIN

/**
 * \brief The pool object manipulator.
 */
class LLBC_ObjectManipulator
{
public:
    /**
     * New object in giving memory.
     */
    template <typename ObjectType>
    static void New(void *mem);

    /**
     * Delete object.
     */
    template <typename ObjectType>
    static void Delete(void *obj);

    /**
     * Reset object.
     */
    template <typename ObjectType>
    static bool Reset(void *obj);

    #if LLBC_CFG_CORE_OBJECT_POOL_RESETOBJ_MATCH_clear
private:
    /**
     * Reset object, this method is called when object has clear():void function.
     */
    template <typename ObjectType, void (ObjectType::*)()>
    struct clearable_type;
    template <typename ObjectType>
    static bool ResetObj(void *obj, clearable_type<ObjectType, &ObjectType::clear> *);
    #endif // LLBC_CFG_CORE_OBJECT_POOL_RESETOBJ_MATCH_clear

    #if LLBC_CFG_CORE_OBJECT_POOL_RESETOBJ_MATCH_Clear
private:
    /**
     * Reset object, this method is called when object has Clear():void function.
     */
    template <typename ObjectType, void (ObjectType::*)()>
    struct Clearable_type;
    template <typename ObjectType>
    static bool ResetObj(void *obj, Clearable_type<ObjectType, &ObjectType::Clear> *);
    #endif // LLBC_CFG_CORE_OBJECT_POOL_RESETOBJ_MATCH_Clear

    #if LLBC_CFG_CORE_OBJECT_POOL_RESETOBJ_MATCH_reset
private:
    /**
     * Reset object, this method is called when object has reset():void function.
     */
    template <typename ObjectType, void (ObjectType::*)()>
    struct resetable_type;
    template <typename ObjectType>
    static bool ResetObj(void *obj, resetable_type<ObjectType, &ObjectType::reset> *);
    #endif // LLBC_CFG_CORE_OBJECT_POOL_RESETOBJ_MATCH_reset

    #if LLBC_CFG_CORE_OBJECT_POOL_RESETOBJ_MATCH_Reset
    /**
     * Reset object, this method is called when object has Reset():void function.
     */
    template <typename ObjectType, void (ObjectType::*)()>
    struct Resetable_type;
    template <typename ObjectType>
    static bool ResetObj(void *obj, Resetable_type<ObjectType, &ObjectType::Reset> *);
    #endif // LLBC_CFG_CORE_OBJECT_POOL_RESETOBJ_MATCH_Reset

private:
    /**
     * Reset object, default method.
     */
    template <typename ObjectType>
    static bool ResetObj(void *obj, ...);
};

__LLBC_NS_END

#include "llbc/core/objectpool/ObjectManipulatorImpl.h"

#endif // !__LLBC_CORE_OBJECT_POOL_OBJECT_MANIPULATOR_H__
