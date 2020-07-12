/**
 * @file mylibrary.h
 * @brief mylibrary library header file with main functions
 * @author Brecht Sanders
 *
 * This header file defines the functions needed for the basic library example
 */

#ifndef INCLUDED_MYLIBRARY_H
#define INCLUDED_MYLIBRARY_H

/*! \cond PRIVATE */
#if !defined(DLL_EXPORT_MYLIBRARY)
# if defined(_WIN32) && (defined(BUILD_MYLIBRARY_DLL) || defined(MYLIBRARY_EXPORTS))
#  define DLL_EXPORT_MYLIBRARY __declspec(dllexport)
# elif defined(_WIN32) && !defined(STATIC) && !defined(BUILD_MYLIBRARY_STATIC) && !defined(BUILD_MYLIBRARY)
#  define DLL_EXPORT_MYLIBRARY __declspec(dllimport)
# else
#  define DLL_EXPORT_MYLIBRARY
# endif
#endif
/*! \endcond */



/*! \brief version number constants
 * \sa     mylibrary_get_version()
 * \sa     mylibrary_get_version_string()
 * \name   MYLIBRARY_VERSION_*
 * \{
 */
/*! \brief major version number */
#define MYLIBRARY_VERSION_MAJOR 0
/*! \brief minor version number */
#define MYLIBRARY_VERSION_MINOR 0
/*! \brief micro version number */
#define MYLIBRARY_VERSION_MICRO 3
/*! @} */

/*! \brief packed version number */
#define MYLIBRARY_VERSION (MYLIBRARY_VERSION_MAJOR * 0x01000000 + MYLIBRARY_VERSION_MINOR * 0x00010000 + MYLIBRARY_VERSION_MICRO * 0x00000100)

/*! \cond PRIVATE */
#define MYLIBRARY_VERSION_STRINGIZE_(major, minor, micro) #major"."#minor"."#micro
#define MYLIBRARY_VERSION_STRINGIZE(major, minor, micro) MYLIBRARY_VERSION_STRINGIZE_(major, minor, micro)
/*! \endcond */

/*! \brief string with dotted version number \hideinitializer */
#define MYLIBRARY_VERSION_STRING MYLIBRARY_VERSION_STRINGIZE(MYLIBRARY_VERSION_MAJOR, MYLIBRARY_VERSION_MINOR, MYLIBRARY_VERSION_MICRO)

/*! \brief string with name of mylibrary library */
#define MYLIBRARY_NAME "mylibrary"

/*! \brief string with name and version of mylibrary library \hideinitializer */
#define MYLIBRARY_FULLNAME MYLIBRARY_NAME " " MYLIBRARY_VERSION_STRING



#ifdef __cplusplus
extern "C" {
#endif

/*! \brief get mylibrary library version string
 * \param  pmajor        pointer to integer that will receive major version number
 * \param  pminor        pointer to integer that will receive minor version number
 * \param  pmicro        pointer to integer that will receive micro version number
 * \sa     mylibrary_get_version_string()
 */
DLL_EXPORT_MYLIBRARY void mylibrary_get_version (int* pmajor, int* pminor, int* pmicro);

/*! \brief get mylibrary library version string
 * \return version string
 * \sa     mylibrary_get_version()
 */
DLL_EXPORT_MYLIBRARY const char* mylibrary_get_version_string ();

#ifdef __cplusplus
}
#endif

#endif
