typedef struct queue_struct {
FILE * queue_stream ;
char_list queue_first ;
char_list queue_last ;
} * char_queue ;

#define queue_struct_size sizeof( struct queue_struct )


char_queue create( FILE * stream, int n ) {
char_queue q = malloc( queue_struct_size ) ;
if( q == NULL ) {
printf( "create: no space\n" ) ;
abort( ) ;
}
q->queue_stream= stream ;
q->queue_first = stream_to_list( stream, n ) ;
q->queue_last = find_last( q->queue_first ) ;
return q ;
}


char_list find_last( char_list current ) {
char_list previous = NULL ;
while( current != NULL ) {
previous = current ;
current = tail( current ) ;
}
return previous ;
}


char_list fetch( char_queue q ) {
return q->queue_first ;
}


void advance( char_queue q ) {
    char_list old, new;
int c = getc( q->queue_stream ) ;
if( c != EOF ) {
new = cons( c, NULL ) ; /* 1 */
q->queue_last->list_tail = new ; /* 2 */
q->queue_last = new ; /* 3 */
}
old = q->queue_first ; /* 4 */
q->queue_first = q->queue_first->list_tail ; /* 5 */
free( old ) ; /* 6 */
}

bool is_empty( char_queue q ) {
return q->queue_first == NULL ;
}


int word_count( char_list ws, char_queue ts ) {
int accu = 0 ;
while( ! is_empty( ts ) ) {
if( match( ws, fetch( ts ) ) ) {
accu++ ;
}
advance( ts ) ;
}
return accu ;
}


