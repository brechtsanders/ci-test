#include "mylibrary.h"
#include <stdio.h>
#include <stdlib.h>

#define VERSION2_STRINGIZE_(major, minor) #major"."#minor
#define VERSION2_STRINGIZE(major, minor) VERSION2_STRINGIZE_(major, minor)
#define VERSION3_STRINGIZE_(major, minor, micro) #major"."#minor"."#micro
#define VERSION3_STRINGIZE(major, minor, micro) VERSION3_STRINGIZE_(major, minor, micro)
#define VERSION4_STRINGIZE_(major, minor, micro, fix) #major"."#minor"."#micro"."#fix
#define VERSION4_STRINGIZE(major, minor, micro, fix) VERSION4_STRINGIZE_(major, minor, micro, fix)

const char* get_compiler ()
{
  //see also: https://sourceforge.net/p/predef/wiki/Compilers/
  return
# if defined(__GNUC__)
    "GCC "
#   if defined(__GNUC_PATCHLEVEL__)
      VERSION3_STRINGIZE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#   else
      VERSION2_STRINGIZE(__GNUC__, __GNUC_MINOR__)
#   endif
#   if defined(__MINGW64_VERSION_MAJOR)
      " (MinGW-w64 " VERSION2_STRINGIZE(__MINGW64_VERSION_MAJOR, __MINGW64_VERSION_MINOR)
#     if defined(__MINGW64__)
        " 64-bit"
#     else
        " 32-bit"
#     endif
        ")"
#   elif defined(__MINGW32_MAJOR_VERSION)
      " (MinGW32 " VERSION2_STRINGIZE(__MINGW32_MAJOR_VERSION, __MINGW32_MINOR_VERSION) ")"
#   endif
# elif defined(__clang__)
    "Clang " VERSION3_STRINGIZE(__clang_major__, __clang_minor__, __clang_patchlevel__)
#   if defined(__MINGW64_VERSION_MAJOR)
      " (MinGW-w64 " VERSION2_STRINGIZE(__MINGW64_VERSION_MAJOR, __MINGW64_VERSION_MINOR)
#     if defined(__MINGW64__)
        " 64-bit"
#     else
        " 32-bit"
#     endif
        ")"
#   elif defined(__MINGW32_MAJOR_VERSION)
      " (MinGW32 " VERSION2_STRINGIZE(__MINGW32_MAJOR_VERSION, __MINGW32_MINOR_VERSION) ")"
#   endif
# elif defined(_ACC_)
    "ACC"
# elif defined(__CMB__)
    "Altium MicroBlaze C"
# elif defined(__CHC__)
    "Altium C-to-Hardware"
# elif defined(__ACK__)
    "Amsterdam Compiler Kit"
# elif defined(__CC_ARM)
    "ARM Compiler"
# elif defined(__AZTEC_C__)
    "Aztec C"
# elif defined(__BORLANDC__)
    "Borland C++"
# elif defined(__CC65__)
    "CC65"
# elif defined(__COMO__)
    "Comeau C++"
# elif defined(__DECC)
    "Compaq C/C++"
# elif defined(__convexc__)
    "Convex C"
# elif defined(__COMPCERT__)
    "CompCert"
# elif defined(__COVERITY__)
    "Coverity C/C++ Static Analyzer"
# elif defined(_CRAYC)
    "Cray C"
# elif defined(__DCC__)
    "Diab C/C++"
# elif defined(_DICE)
    "DICE C"
# elif defined(__DMC__)
    "Digital Mars"
# elif defined(__SYSC__)
    "Dignus Systems/C++"
# elif defined(__DJGPP__)
    "DJGPP " VERSION2_STRINGIZE(__DJGPP__, __DJGPP_MINOR__)
# elif defined(__EDG__)
    "EDG C++ Frontend"
# elif defined(__PATHCC__)
    "EKOPath " VERSION3_STRINGIZE(__PATHCC__, __PATHCC_MINOR__, __PATHCC_PATCHLEVEL__)
# elif defined(__FCC_VERSION)
    "Fujitsu C++"
# elif defined(__ghs__)
    "Green Hill C/C++"
# elif defined(__HP_cc)
    "HP ANSI C"
# elif defined(__HP_aCC)
    "HP aC++"
# elif defined(__IAR_SYSTEMS_ICC__)
    "IAR C/C++"
# elif defined(__ibmxl__)
    "IBM XL C/C++ (Clang-based)" VERSION4_STRINGIZE(__ibmxl_version__, __ibmxl_release__, __ibmxl_modification__, __ibmxl_ptf_fix_level__)
# elif defined(__xlC__)
    "IBM XL C/C++ (legacy)"
# elif defined(__IBMC__)
    "IBM z/OS XL C/C++"
# elif defined(__IMAGECRAFT__)
    "ImageCraft C"
# elif defined(__INTEL_COMPILER)
    "Intel C/C++"
# elif defined(__KCC)
    "KAI C++"
# elif defined(__CA__) || defined(__KEIL__)
    "KEIL CARM"
# elif defined(__C166__)
    "KEIL C166"
# elif defined(__C51__) || defined(__CX51__)
    "KEIL C51"
# elif defined(__LCC__)
    "LCC"
# elif defined(__HIGHC__)
    "MetaWare High C/C++"
# elif defined(__MWERKS__) || defined(__CWCC__)
    "Metrowerks CodeWarrior"
# elif defined(_MSC_VER)
    "Microsoft Visual C++"
#   if _MSC_VER == 1910
      " 15.0"
#     if _MSC_FULL_VER == 191025017
        " (2017)"
#     endif
#   elif _MSC_VER == 1900
      " 14.0"
#     if (_MSC_FULL_VER == 190024210)
        " (2015 Update 3)"
#     elif (_MSC_FULL_VER == 190023918)
        " (2015 Update 2)"
#     elif (_MSC_FULL_VER == 190023506)
        " (2015 Update 1)"
#     elif (_MSC_FULL_VER == 190023026)
        " (2015)"
#     endif
#   elif _MSC_VER == 1800
      " 12.0 (2013)"
#   elif _MSC_VER == 1700
      " 11.0 (2012)"
#   elif _MSC_VER == 1600
      " 10.0"
#     if (_MSC_FULL_VER == 160040219)
        " (2010) SP1"
#     elif (_MSC_FULL_VER == 160030319)
        " (2010)"
#     endif
#   elif (_MSC_VER == 1500)
      " 9.0"
#     if (_MSC_FULL_VER == 150030729)
        " SP1"
#     elif (_MSC_FULL_VER == 150021022)
        " (2008)"
#     endif
#   elif _MSC_VER == 1400
      " 8.0 (2005)"
#   elif _MSC_VER == 1310
      " 7.1 (2003)"
#   elif _MSC_VER == 1300
      " 7.0"
#   elif _MSC_VER == 1200
      " 6.0"
#     if defined (_MSC_FULL_VER) && (_MSC_FULL_VER == 12008804)
        " SP6"
#     endif
#   elif _MSC_VER == 1100
      " 5.0"
#   elif _MSC_VER == 1020
      " 4.2"
#   elif _MSC_VER == 1000
      " 4.0"
#   elif _MSC_VER == 900
      " 3.0"
#   elif _MSC_VER == 800
      " 1.0"
#   endif
# elif defined(_MRI)
    "Microtec C/C++"
# elif defined(__NDPC__) || defined(__NDPX__)
    "Microway NDP C"
# elif defined(__sgi) || defined(sgi)
    "MIPSpro"
# elif defined(MIRACLE)
    "Miracle C"
# elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
    "MPW C++"
# elif defined(__CC_NORCROFT)
    "Norcroft C"
# elif defined(__NWCC__)
    "NWCC"
# elif defined(__OPEN64__) || defined(__OPENCC__)
    "Open64"
# elif defined( 	ORA_PROC)
    "Oracle Pro*C Precompiler"
# elif defined(__SUNPRO_C)
    "Oracle Solaris Studio"
# elif defined(__PACIFIC__)
    "Pacific C"
# elif defined(_PACC_VER)
    "Palm C/C++"
# elif defined(__POCC__)
    "Pelles C"
# elif defined(__PGI)
    "Portland Group C/C++"
# elif defined(__RENESAS__) || defined(__HITACHI__)
    "Renesas C/C++"
# elif defined(SASC) || defined(__SASC) || defined(__SASC__)
    "SAS/C"
# elif defined(_SCO_DS)
    "SCO OpenServer"
# elif defined(SDCC)
    "Small Device C Compiler"
# elif defined(__SNC__)
    "SN Compiler"
# elif defined(__VOSC__)
    "Stratus VOS C"
# elif defined(__SC__)
    "Symantec C++"
# elif defined(__TenDRA__)
    "TenDRA C/C++"
# elif defined(__TI_COMPILER_VERSION__) || defined(_TMS320C6X)
    "Texas Instruments C/C++ Compiler"
# elif defined(THINKC3) || defined(THINKC4)
    "THINK C"
#   if defined(THINKC4)
      " 4.x"
#   elif defined(THINKC3)
      " 3.x"
#   endif
# elif defined(__TINYC__)
    "Tiny C"
# elif defined(__TURBOC__)
    "Turbo C/C++"
# elif defined(_UCC)
    "Ultimate C/C++ " VERSION2_STRINGIZE(_MAJOR_REV, _MINOR_REV)
# elif defined(__USLC__)
    "USL C"
# elif defined(__VBCC__)
    "VBCC"
# elif defined(__WATCOMC__)
    "Watcom C++"
# elif defined(__ZTC__)
    "Zortech C++"
# elif defined(__llvm__)
    "LLVM"
# else
    NULL
# endif
  ;
}

int main()
{
  printf("Version: %s\n", mylibrary_get_version_string());
  const char* compiler = get_compiler();
  printf("Compiler: %s\n", (compiler ? compiler : "(unknown)"));
  return 0;
}
