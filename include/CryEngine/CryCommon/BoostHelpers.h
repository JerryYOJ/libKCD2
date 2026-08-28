/*************************************************************************
Crytek Source File.
Copyright (C), Crytek Studios, 2001-2009.
-------------------------------------------------------------------------
Description: 
Helper macros/methods/classes for boost.
-------------------------------------------------------------------------
History:
- 02:07:2009: Created by Alex McCarthy
*************************************************************************/

#ifndef __BOOST_HELPERS_H__
#define __BOOST_HELPERS_H__

#if defined(XENON) && !defined(_XBOX)
    #define _XBOX
#endif

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <boost/enable_shared_from_this.hpp>

// boost/mem_fn.hpp lives in boost-bind, which this tree does not vcpkg.
// Nothing in the RE include graph uses boost::mem_fn.

#define DECLARE_BOOST_POINTERS(name) \
	typedef boost::shared_ptr<name> name##Ptr; \
	typedef boost::shared_ptr<const name> name##ConstPtr; \
	typedef boost::weak_ptr<name> name##WeakPtr; \
	typedef boost::weak_ptr<const name> name##ConstWeakPtr;

#endif // __BOOST_HELPERS_H__
