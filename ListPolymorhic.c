

list extra_filter( bool (*pred)( void *, void * ),
                    void * arg, list x_xs, int size ) {
    if ( x_xs == NULL ) {
        return NULL ;
    } else {
        void * x = head( x_xs ) ;
        list xs = tail( x_xs ) ;
        if( pred( arg, x ) ) {
            return cons(x, extra_filter(pred,arg,xs,size), size);
        } else {
            return extra_filter( pred, arg, xs, size ) ;
        }
    }
}

void * head( list l ) {
    if( l == NULL ) {
        abort();
    }
    return l->list_head;
}

list tail( list l ) {
    if( l == NULL ) {
        abort() ;
    }
    return l->list_tail ;
}
