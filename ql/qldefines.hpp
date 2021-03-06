/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl
 Copyright (C) 2003, 2004, 2005, 2006, 2007 StatPro Italia srl
 Copyright (C) 2015 CompatibL

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file qldefines.hpp
    \brief Global definitions and compiler switches.
*/

#ifndef quantlib_defines_hpp
/* install-hook */
#define quantlib_defines_hpp


/* This allows one to include a given file at this point by
   passing it as a compiler define (e.g., -DQL_INCLUDE_FIRST=foo.hpp).

   The idea is to provide a hook for defining QL_REAL and at the
   same time including any necessary headers for the new type.
*/
#define INCLUDE_FILE(F) INCLUDE_FILE__(F)
#define INCLUDE_FILE_(F) #F
#ifdef QL_INCLUDE_FIRST
#    include INCLUDE_FILE(QL_INCLUDE_FIRST)
#endif
#undef INCLUDE_FILE_
#undef INCLUDE_FILE

/* Eventually these might go into userconfig.hpp.
   For the time being, we hard code them here.
   They can be overridden by passing the #define to the compiler.
*/
#ifndef QL_INTEGER
#    define QL_INTEGER int
#endif

#ifndef QL_BIG_INTEGER
#    define QL_BIG_INTEGER long
#endif

#ifndef QL_REAL
#   define QL_REAL double
#endif


/*! \defgroup macros QuantLib macros

    Global definitions and a few macros which help porting the
    code to different compilers.

    @{
*/

#if (defined(_DEBUG) || defined(DEBUG))
    #define QL_DEBUG
#endif

// On non-Visual Studio platforms, configuration is handled by CMake options
#ifndef _MSC_VER
#include <ql/config.hpp>
#else
#include <ql/userconfig.hpp>
#endif


// extra debug checks
#ifdef QL_DEBUG
    #ifndef QL_EXTRA_SAFETY_CHECKS
        #define QL_EXTRA_SAFETY_CHECKS
    #endif
#endif

// ensure that needed math constants are defined
#include <limits>
#include <ql/mathconstants.hpp>


/*! \defgroup limitMacros Numeric limits

    Some compilers do not give an implementation of
    <code>\<limits\></code> yet.  For the code to be portable
    these macros should be used instead of the corresponding method of
    <code>std::numeric_limits</code> or the corresponding macro
    defined in <code><limits.h></code>.

    @{
*/
/*! \def QL_MIN_INTEGER
    Defines the value of the largest representable negative integer value
*/
/*! \def QL_MAX_INTEGER
    Defines the value of the largest representable integer value
*/
/*! \def QL_MIN_REAL
    Defines the value of the largest representable negative
    floating-point value
*/
/*! \def QL_MIN_POSITIVE_REAL
    Defines the value of the smallest representable positive double value
*/
/*! \def QL_MAX_REAL
    Defines the value of the largest representable floating-point value
*/
/*! \def QL_EPSILON
    Defines the machine precision for operations over doubles
*/
// limits used as such
#define QL_MIN_INTEGER         ((std::numeric_limits<QL_INTEGER>::min)())
#define QL_MAX_INTEGER         ((std::numeric_limits<QL_INTEGER>::max)())
#define QL_MIN_REAL           -((std::numeric_limits<QL_REAL>::max)())
#define QL_MAX_REAL            ((std::numeric_limits<QL_REAL>::max)())
#define QL_MIN_POSITIVE_REAL   ((std::numeric_limits<QL_REAL>::min)())
#define QL_EPSILON             ((std::numeric_limits<QL_REAL>::epsilon)())
// specific values---these should fit into any Integer or Real
#define QL_NULL_INTEGER        ((std::numeric_limits<int>::max)())
#define QL_NULL_REAL           ((std::numeric_limits<float>::max)())
/*! @} */

/*! @}  */

//Visual Studio claims to support [[deprecated]] flag, but it really doesn't
#ifndef _MSC_VER
#define QL_DEPRECATED [[deprecated]]
#else
#define QL_DEPRECATED __declspec(deprecated)
#endif

#endif
