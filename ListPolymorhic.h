#ifndef LIST_H
#define LIST_H

typedef struct list_struct *list ;
extern list cons( void *head, list tail, int size ) ;
extern int length( list x_xs ) ;
extern void *head( list l ) ;
extern void *nth( list x_xs, int n ) ;
extern list tail( list l ) ;
extern list append( list xs, list ys, int size ) ;
extern list extra_filter( bool (*pred)( void *, void * ),
                        void * arg, list x_xs, int size );
#endif /* LIST_H */
