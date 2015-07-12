/* Name of package */
#ifndef _CONFIG_H
#define _CONFIG_H

/* Name of package */
#define PACKAGE "memcached"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "patrick.galbraith@northscale.com"

/* Define to the full name of this package. */
#define PACKAGE_NAME "memcached"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "memcached 1.4.24"

/* Define to the full name and version of this package. */
#define PACKAGE_DESCRIPTION "memcached 1.4.24 is a high-performance, distributed memory object caching system, generic in nature, but intended for use in speeding up dynamic web applications by alleviating database load. Win32 port by Kronuz."

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "memcached"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.4.24"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "1.4.24"

/* machine is littleendian */
#define ENDIAN_LITTLE 1


/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* define to int if socklen_t not available */
/* #undef socklen_t */
/* Windows-specific includes */
#include <sys/types.h>
#include <sys/stat.h>
#include "win32.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <process.h>
#include "ntservice.h"

/*******************************/
/* HACKS to compile under UNIX */

#define S_ISSOCK(mode) 0
#define RLIMIT_CORE 4
#define RLIM_INFINITY ((unsigned long int) (-0UL))
#define RLIMIT_NOFILE 7

/* Create expected type and struct definitions */

typedef short int _uid_t;

struct passwd {
    char * pw_name;
    char * pw_passwd;
    _uid_t pw_uid;
    _uid_t pw_gid;
    char * pw_gecos;
    char * pw_dir;
    char * pw_shell;
};

struct sockaddr_un {
    unsigned short int sun_family;
    char sun_path[108];
};

struct rlimit {
    unsigned long int rlim_cur, rlim_max;
};

/* Function prototypes expected by UNIX code
 * - function definitions in dummy_defs.c
 */

int lstat(const char *path, struct stat *tstat);
int sigignore(int sig);
int getrlimit(int __resource, struct rlimit * __rlimits);
int setrlimit(int __resource, struct rlimit * __rlimits);
_uid_t getuid(void);
_uid_t geteuid(void);
struct passwd *getpwnam(const char *name);
int setuid(_uid_t uid);
int setgid(_uid_t gid);
#endif // _CONFIG_H
