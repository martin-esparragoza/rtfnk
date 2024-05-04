/**
 * @file socket.h
 * @brief Buffer read/write handler
 */

#ifndef INCLUDE_RTFNK_SOCKET_H_
#define INCLUDE_RTFNK_SOCKET_H_

#define FNK_SOCKET_MAXTYPES 256
#define FNK_SOCKET_MAXSOCKETS 64

// No enums, I'd like the control the type
#define FNK_SOCKET_ERRC_OK 0
#define FNK_SOCKET_ERRC_BIND_WOULDOVERFLOW 1
#define FNK_SOCKET_ERRC_RW_WOULDOVERFLOW 2

// TODO const char*
const char* fnk_socket_def_errcstr[] = { ///< Default error codes to string
    [FNK_SOCKET_ERRC_OK] = "Ok",
    [FNK_SOCKET_ERRC_BIND_WOULDOVERFLOW] = "No room in system to add new sockets",
    [FNK_SOCKET_ERRC_RW_WOULDOVERFLOW] = "Attempted to write/read outside buffer"
};

typedef struct fnk_socket {
    void const* writebuffer; ///< Information that is to be written
    void const* readbuffer; ///< Information that has been read and is stored
    unsigned writeposition; ///< This type might be too small... Change it if you so desire
    unsigned readposition;
    const unsigned char type; ///< Types can be defined by anything meaning that custom error codes can exist as well as custom update functions allowing for easier hardware writes
} fnk_socket_t;

const char* fnk_socket_errctostr(struct fnk_socket* self, unsigned char errc);

/**
 * @brief "Binds" the socket to the operating system
 * 
 * Gives the operating system a pointer to the socket so it can update it for you
 *
 * @param sock I'm just justifying the name. The socket isn't an owned object yet something something (bs bs bs..)
 */
unsigned char fnk_socket_bind(struct fnk_socket* sock);

/**
 * @brief Write content to buffer
 *
 * Used in native endianness
 *
 * @param self Socket
 * @param buf  Buffer to read from
 * @param len  # of bytes to read
 */
unsigned char fnk_socket_write(struct fnk_socket* self, void* buf, unsigned len);

/**
 * @brief Read content from buffer
 *
 * Used in native endianness
 *
 * @param self Socket
 * @param buf  Buffer to write to
 * @param len  # of bytes to write
 */
unsigned char fnk_socket_read(struct fnk_socket* self, void* buf, unsigned len);

/**
 * @brief Write content to buffer
 *
 * @param self   Socket
 * @param buf    Buffer to read from
 * @param len    # of bytes to read
 * @param little Little or big endian
 */
unsigned char fnk_socket_writee(struct fnk_socket* self, void* buf, unsigned len, _Bool little);

/**
 * @brief Read content from buffer
 *
 * @param self   Socket
 * @param buf    Buffer to write to
 * @param len    # of bytes to write
 * @param little Little or big endian
 */
unsigned char fnk_socket_reade(struct fnk_socket* self, void* buf, unsigned len, _Bool little);

#endif
