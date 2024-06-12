#include "sockserv.h"
#include "../../include/rtfnk/sockserv.h"
#include "socket.h"
#include "../util/flinkedlist.h"

void fnk_sockserv_init(struct fnk_sockserv* self) {
    util_flinkedlist_init(self->sockets, FNK_SOCKSRV_MAXSOCKETS);
    self->node = self->sockets;
}

void fnk_sockserv_bind(struct fnk_sockserv* self, struct fnk_socket* socket) {
    struct util_flinkedlist* node = util_flinkedlist_insert(self->node, (void *) socket);
    // BAD.
    if (!node)
        return false;
    self->node = socket->node = node;
    return true;
}

void fnk_sockserv_remove(struct fnk_sockserv* self, struct fnk_socket* socket) {
    util_flinkedlist_remove(self->node, socket->node);
}