/******************************************************************************
 *
 * Name: acenv.h - Generation environment specific items
 *       $Revision: 1.63 $
 *
 *****************************************************************************/

/******************************************************************************
 *
 * 1. Copyright Notice
 *
 * Some or all of this work - Copyright (c) 1999, Intel Corp.  All rights
 * reserved.
 *
 * 2. License
 *
 * 2.1. This is your license from Intel Corp. under its intellectual property
 * rights.  You may have additional license terms from the party that provided
 * you this software, covering your right to use that party's intellectual
 * property rights.
 *
 * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a
 * copy of the source code appearing in this file ("Covered Code") an
 * irrevocable, perpetual, worldwide license under Intel's copyrights in the
 * base code distributed originally by Intel ("Original Intel Code") to copy,
 * make derivatives, distribute, use and display any portion of the Covered
 * Code in any form, with the right to sublicense such rights; and
 *
 * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent
 * license (with the right to sublicense), under only those claims of Intel
 * patents that are infringed by the Original Intel Code, to make, use, sell,
 * offer to sell, and import the Covered Code and derivative works thereof
 * solely to the minimum extent necessary to exercise the above copyright
 * license, and in no event shall the patent license extend to any additions
 * to or modifications of the Original Intel Code.  No other license or right
 * is granted directly or by implication, estoppel or otherwise;
 *
 * The above copyright and patent license is granted only if the following
 * conditions are met:
 *
 * 3. Conditions
 *
 * 3.1. Redistribution of Source with Rights to Further Distribute Source.
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification with rights to further distribute source must include
 * the above Copyright Notice, the above License, this list of Conditions,
 * and the following Disclaimer and Export Compliance provision.  In addition,
 * Licensee must cause all Covered Code to which Licensee contributes to
 * contain a file documenting the changes Licensee made to create that Covered
 * Code and the date of any change.  Licensee must include in that file the
 * documentation of any changes made by any predecessor Licensee.  Licensee
 * must include a prominent statement that the modification is derived,
 * directly or indirectly, from Original Intel Code.
 *
 * 3.2. Redistribution of Source with no Rights to Further Distribute Source.
 * Redistribution of source code of any substantial portion of the Covered
 * Code or modification without rights to further distribute source must
 * include the following Disclaimer and Export Compliance provision in the
 * documentation and/or other materials provided with distribution.  In
 * addition, Licensee may not authorize further sublicense of source of any
 * portion of the Covered Code, and must include terms to the effect that the
 * license from Licensee to its licensee is limited to the intellectual
 * property embodied in the software Licensee provides to its licensee, and
 * not to intellectual property embodied in modifications its licensee may
 * make.
 *
 * 3.3. Redistribution of Executable. Redistribution in executable form of any
 * substantial portion of the Covered Code or modification must reproduce the
 * above Copyright Notice, and the following Disclaimer and Export Compliance
 * provision in the documentation and/or other materials provided with the
 * distribution.
 *
 * 3.4. Intel retains all right, title, and interest in and to the Original
 * Intel Code.
 *
 * 3.5. Neither the name Intel nor any other trademark owned or controlled by
 * Intel shall be used in advertising or otherwise to promote the sale, use or
 * other dealings in products derived from or relating to the Covered Code
 * without prior written authorization from Intel.
 *
 * 4. Disclaimer and Export Compliance
 *
 * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED
 * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE
 * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,
 * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY
 * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES
 * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR
 * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,
 * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY
 * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL
 * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS
 * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY
 * LIMITED REMEDY.
 *
 * 4.3. Licensee shall not export, either directly or indirectly, any of this
 * software or system incorporating such software without first obtaining any
 * required license or other approval from the U. S. Department of Commerce or
 * any other agency or department of the United States Government.  In the
 * event Licensee exports any such software from the United States or
 * re-exports any such software from a foreign destination, Licensee shall
 * ensure that the distribution and export/re-export of the software is in
 * compliance with all laws, regulations, orders, or other restrictions of the
 * U.S. Export Administration Regulations. Licensee agrees that neither it nor
 * any of its subsidiaries will export/re-export any technical data, process,
 * software, or service, directly or indirectly, to any country for which the
 * United States government or any agency thereof requires an export license,
 * other governmental approval, or letter of assurance, without first obtaining
 * such license, approval or letter.
 *
 *****************************************************************************/

#ifndef __ACENV_H__
#define __ACENV_H__


/*
 * Configuration for ACPI Utilities
 */

#ifdef _ACPI_DUMP_APP
#define ACPI_DEBUG
#define ACPI_APPLICATION
#define ENABLE_DEBUGGER
#define ACPI_USE_SYSTEM_CLIBRARY
#define PARSER_ONLY
#endif

#ifdef _ACPI_EXEC_APP
#undef DEBUGGER_THREADING
#define DEBUGGER_THREADING      DEBUGGER_SINGLE_THREADED
#define ACPI_DEBUG
#define ACPI_APPLICATION
#define ENABLE_DEBUGGER
#define ACPI_USE_SYSTEM_CLIBRARY
#endif

#ifdef _ACPI_ASL_COMPILER
#define ACPI_DEBUG
#define ACPI_APPLICATION
#define ENABLE_DEBUGGER
#define ACPI_USE_SYSTEM_CLIBRARY
#endif


/*
 * Environment configuration.  The purpose of this file is to interface to the
 * local generation environment.
 *
 * 1) ACPI_USE_SYSTEM_CLIBRARY - Define this if linking to an actual C library.
 *      Otherwise, local versions of string/memory functions will be used.
 * 2) ACPI_USE_STANDARD_HEADERS - Define this if linking to a C library and
 *      the standard header files may be used.
 *
 * The ACPI subsystem only uses low level C library functions that do not call
 * operating system services and may therefore be inlined in the code.
 *
 * It may be necessary to tailor these include files to the target
 * generation environment.
 *
 *
 * Functions and constants used from each header:
 *
 * string.h:    memcpy
 *              memset
 *              strcat
 *              strcmp
 *              strcpy
 *              strlen
 *              strncmp
 *              strncat
 *              strncpy
 *
 * stdlib.h:    strtoul
 *
 * stdarg.h:    va_list
 *              va_arg
 *              va_start
 *              va_end
 *
 */

/*! [Begin] no source code translation */

#ifdef _LINUX
#include "aclinux.h"

#elif _AED_EFI
#include "acefi.h"

#elif WIN32
#include "acwin.h"

#elif __FreeBSD__
#include "acfreebsd.h"

#else

/* All other environments */

#define ACPI_USE_STANDARD_HEADERS

/* Name of host operating system (returned by the _OS_ namespace object) */

#define ACPI_OS_NAME         "Intel ACPI/CA Core Subsystem"

#endif


/*! [End] no source code translation !*/

/******************************************************************************
 *
 * C library configuration
 *
 *****************************************************************************/

#ifdef ACPI_USE_SYSTEM_CLIBRARY
/*
 * Use the standard C library headers.
 * We want to keep these to a minimum.
 *
 */

#ifdef ACPI_USE_STANDARD_HEADERS
/*
 * Use the standard headers from the standard locations
 */
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#endif /* ACPI_USE_STANDARD_HEADERS */

/*
 * We will be linking to the standard Clib functions
 */

#define STRSTR(s1,s2)   strstr((s1), (s2))
#define STRUPR(s)       strupr((s))
#define STRLEN(s)       strlen((s))
#define STRCPY(d,s)     strcpy((d), (s))
#define STRNCPY(d,s,n)  strncpy((d), (s), (n))
#define STRNCMP(d,s,n)  strncmp((d), (s), (n))
#define STRCMP(d,s)     strcmp((d), (s))
#define STRCAT(d,s)     strcat((d), (s))
#define STRNCAT(d,s,n)  strncat((d), (s), (n))
#define STRTOUL(d,s,n)  strtoul((d), (s), (n))
#define MEMCPY(d,s,n)   memcpy((d), (s), (n))
#define MEMSET(d,s,n)   memset((d), (s), (n))
#define TOUPPER         toupper
#define TOLOWER         tolower


/******************************************************************************
 *
 * Not using native C library, use local implementations
 *
 *****************************************************************************/
#else

/*
 * Use local definitions of C library macros and functions
 * NOTE: The function implementations may not be as efficient
 * as an inline or assembly code implementation provided by a
 * native C library.
 */

#ifndef va_arg

#ifndef _VALIST
#define _VALIST
typedef char *va_list;
#endif /* _VALIST */

/*
 * Storage alignment properties
 */

#define  _AUPBND         (sizeof(int) - 1)
#define  _ADNBND         (sizeof(int) - 1)

/*
 * Variable argument list macro definitions
 */

#define _Bnd(X, bnd)    (((sizeof(X)) + (bnd)) & (~(bnd)))
#define va_arg(ap, T)  (*(T *)(((ap)+=((_Bnd(T, _AUPBND)))-(_Bnd(T,_ADNBND)))))
#define va_end(ap)      (void)0
#define va_start(ap, A) (void)((ap)=(((char*)&(A))+(_Bnd(A,_AUPBND))))

#endif /* va_arg */


#define STRSTR(s1,s2)    AcpiCmStrstr  ((s1), (s2))
#define STRUPR(s)        AcpiCmStrupr  ((s))
#define STRLEN(s)        AcpiCmStrlen  ((s))
#define STRCPY(d,s)      AcpiCmStrcpy  ((d), (s))
#define STRNCPY(d,s,n)   AcpiCmStrncpy ((d), (s), (n))
#define STRNCMP(d,s,n)   AcpiCmStrncmp ((d), (s), (n))
#define STRCMP(d,s)      AcpiCmStrcmp  ((d), (s))
#define STRCAT(d,s)      AcpiCmStrcat  ((d), (s))
#define STRNCAT(d,s,n)   AcpiCmStrncat ((d), (s), (n))
#define STRTOUL(d,s,n)   AcpiCmStrtoul ((d), (s),(n))
#define MEMCPY(d,s,n)    AcpiCmMemcpy  ((d), (s), (n))
#define MEMSET(d,v,n)    AcpiCmMemset  ((d), (v), (n))
#define TOUPPER          AcpiCmToUpper
#define TOLOWER          AcpiCmToLower

#endif /* ACPI_USE_SYSTEM_CLIBRARY */


/******************************************************************************
 *
 * Assembly code macros
 *
 *****************************************************************************/

/*
 * Handle platform- and compiler-specific assembly language differences.
 * These should already have been defined by the platform includes above.
 *
 * Notes:
 * 1) Interrupt 3 is used to break into a debugger
 * 2) Interrupts are turned off during ACPI register setup
 */

/* Unrecognized compiler, use defaults */
#ifndef ACPI_ASM_MACROS

#define ACPI_ASM_MACROS
#define causeinterrupt(level)
#define BREAKPOINT3
#define disable()
#define enable()
#define halt()
#define ACPI_ACQUIRE_GLOBAL_LOCK(GLptr, Acq)
#define ACPI_RELEASE_GLOBAL_LOCK(GLptr, Acq)

#endif /* ACPI_ASM_MACROS */


#ifdef ACPI_APPLICATION

/* Don't want software interrupts within a ring3 application */

#undef causeinterrupt
#undef BREAKPOINT3
#define causeinterrupt(level)
#define BREAKPOINT3
#endif


/******************************************************************************
 *
 * Compiler-specific
 *
 *****************************************************************************/

/* this has been moved to compiler-specific headers, which are included from the
   platform header. */



/* TBD: move this elsewhere! */

#ifdef __ia64__
/* Look at interim FADT to determine IO or memory mapped */
#define IoAddressSpace(flag)    (AcpiGbl_FADT->AddressSpace & flag)
#else
/* always IO space */
#define IoAddressSpace(flag)    (1)
#endif


#endif /* __ACENV_H__ */
