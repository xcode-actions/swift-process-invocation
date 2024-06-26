#ifndef exports_h
# define exports_h

/* Using the following would technically work to export execvpe directly (with a dummy C file),
 *  but it would also export the rest of unistd, which is already available through Glibc,
 *  thus creating conflicts when using Glibc stuff.
 * So instead we create an execvpe shim explicitly (spi_execvpe). */
//#define _GNU_SOURCE
//#include <unistd.h>

int spi_execvpe(const char *file, char *const argv[], char *const envp[]);

/* From stdlib.h w/ _GNU_SOURCE set to 500. */
char *spi_ptsname(int fd);

#endif /* exports_h */
