/**
 * @file sockserv.h
 * @brief Socket server for driver processes
 * Only the functions (statically linked)
 */

#ifndef INCLUDE_RTFNK_SOCKSERVF_H_
#define INCLUDE_RTFNK_SOCKSERVF_H_

#include "types.h"
#include "include/rtfnk/sockservd.h"
#include "include/rtfnk/socketd.h"

/**
 * @brief Constructor
 */
void fnk_sockserv_init(struct fnk_sockserv* serv);

/**
 * @brief Convert errc to string
 *
 * @param errc Error code
 * @return String and if cannot find returns NULL
 */
const char* fnk_sockserv_errctostr(int errc);

/**
 * @brief To allocate the element
 */
size_t fnk_sockserv_sizeof();

/**
 * @brief Gets the next socket in queue (and puts it at the back)
 *
 * @param serv Server
 * @param socket Output
 */
int fnk_sockserv_getnextinqueue(struct fnk_sockserv* serv, struct fnk_socket** socket);

/**
 * @brief Adds the socket to the server
 */
void fnk_sockserv_bind(struct fnk_sockserv* serv, struct fnk_socket* socket);

/**
 * @brief Removes the socket from the server
 * The kernel will not clean your stuff up! Clean it up yourself or risk memory leakage!
 */
int fnk_sockserv_remove(struct fnk_sockserv* serv, struct fnk_socket* socket);

/**
 * @brief Server level reading of the write buffer
 *
 * @param dest Buffer to write into
 * @param len # of bytes to read
 */
int fnk_sockserv_readwritebuffer(struct fnk_socket* socket, void* dest, size_t len);

/**
 * @brief Server level writing to the read buffer
 *
 * @param dest Buffer to read from
 * @param len # of bytes to write
 */
int fnk_sockserv_writereadbuffer(struct fnk_socket* socket, const void* src, size_t len);

#endif