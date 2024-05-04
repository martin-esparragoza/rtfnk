/**
 * @file socket.c
 * @brief Buffer read/write handler
 */

#include "../../include/rtfnk/socket.h"
#include "../util/flinkedlist.h"

extern const char* (* const fnk_socket_errctostr_table[FNK_SOCKET_MAXTYPES])(struct fnk_socket*, unsigned);
extern void(* const fnk_socket_update_table[FNK_SOCKET_MAXTYPES])(struct fnk_socket*); ///< If something messes up during updating, log it, but don't kill the socket
extern struct util_flinkedlist* node; // Available node for insertion

const char* fnk_socket_errctostr(struct fnk_socket* self, unsigned char errc) {
    if (errc < sizeof(fnk_socket_def_errcstr) / sizeof(fnk_socket_def_errcstr[0]))
        return fnk_socket_def_errcstr[errc];

    // Default errc not found. Ask the others
    return (*fnk_socket_errctostr_table[self->type])(self, errc);
}

unsigned char fnk_socket_bind(struct fnk_socket* sock) {
    struct util_flinkedlist* newnode = util_flinkedlist_insert(node, (void *) sock);
    if (newnode == 0)
        return FNK_SOCKET_ERRC_BIND_WOULDOVERFLOW;

    node = newnode;

    return FNK_SOCKET_ERRC_OK;
}

unsigned char fnk_socket_write(struct fnk_socket* self, void* buf, unsigned len) {
}

unsigned char fnk_socket_read(struct fnk_socket* self, void* buf, unsigned len);

unsigned char fnk_socket_writee(struct fnk_socket* self, void* buf, unsigned len, _Bool little);

unsigned char fnk_socket_reade(struct fnk_socket* self, void* buf, unsigned len, _Bool little);
