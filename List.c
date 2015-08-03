

typedef struct list_struct {
char list_head ;
struct list_struct * list_tail ;
} *char_list ;

#define list_struct_size sizeof( struct list_struct )
char_list cons( char head, char_list tail ) {
char_list l = malloc( list_struct_size ) ;
if( l == NULL ) {
printf( "cons: no space\n" ) ;
abort( ) ;
}
l->list_head = head ;
l->list_tail = tail ;
return l ;
}

char head( char_list l ) {
if( l == NULL ) {
abort() ;
}
return l->list_head ;
}

char_list list_hi( void ) {
char_list hi = cons( H, cons( i, NULL ) ) ;
return hi ;
}


int length( char_list x_xs ) {
if ( x_xs == NULL ) {
return 0 ;
} else {
return 1 + length( tail( x_xs ) ) ;
}
}


char nth( char_list x_xs, int n ) {
while( n != 0 ) {
x_xs = tail( x_xs ) ;
n-- ;
}
return head( x_xs ) ;
}


char_list append( char_list x_xs, char_list ys ) {
if( x_xs == NULL ) {
return ys ;
} else {
return cons( head( x_xs ),
append( tail( x_xs ), ys ) ) ;
}
}


char_list filter( bool (*pred)( char ), char_list x_xs ) {
if ( x_xs == NULL ) {
return NULL ;
} else {
char x = head( x_xs ) ;
char_list xs = tail( x_xs ) ;
if( pred( x ) ) {
return cons( x, filter( pred, xs ) ) ;
} else {
return filter( pred, xs ) ;
}
}
}

char_list map( char (*f)( char ), char_list x_xs ) {
if( x_xs == NULL ) {
return NULL ;
} else {
char x = head( x_xs ) ;
char_list xs = tail( x_xs ) ;
return cons( f( x ), map( f, xs ) ) ;
}
}

char_list copy( char_list x_xs ) {
if( x_xs == NULL ) {
return NULL ;
} else {
return cons( head( x_xs ), copy( tail( x_xs ) ) ) ;
}
}

char_list copy( char_list xs ) {
char_list accu = NULL ;
while( xs != NULL ) {
accu = append( accu, cons( head( xs ), NULL ) ) ;
xs = tail( xs ) ;
}
return accu ;
}

char_list copy( char_list xs ) {
char_list accu = NULL ;
char_list last ;
if( xs != NULL ) {
last = accu
= cons( head( xs ), NULL ) ;
xs = tail( xs ) ;
while( xs != NULL ) {
last = last->list_tail
= cons( head( xs ), NULL ) ;
xs = tail( xs ) ;
}
}
return accu ;
}

char_list copy( char_list xs ) {
char_list accu = NULL ;
char_list *last = &accu ;
while( xs != NULL ) {
char_list new = cons( head( xs ), NULL ) ;
*last = new ;
last = &new->list_tail ;
xs = tail( xs ) ;
}
return accu ;
}

char_list append( char_list xs,
char_list ys ) { /*added char_list ys*/
char_list accu = ys; /*replaced NULL by ys*/
char_list last ;
if( xs != NULL ) {
last = accu
= cons( head(xs), ys ) ; /*replaced NULL by ys*/
xs = tail( xs ) ;
while( xs != NULL ) {
last = last->list_tail
= cons( head(xs), ys ) ; /*replaced NULL by ys*/
xs = tail( xs ) ;
}
}
return accu ;
}

char_list array_to_list( char s [], int n ) {
int l = 0 ;
int u = n - 1 ;
char_list list = NULL ;
int i ;
for( i = u; i >= l; i-- ) {
list = cons( s[i], list ) ;
}
return list;
}

char * list_to_array( char_list xs ) {
int n = length( xs ) ;
char * array = malloc( n ) ;
int i = 0 ;
if( array == NULL ) {
printf( "list_to_array: no space\n" ) ;
abort( ) ;
}
while( xs != NULL ) {
array[i] = head( xs ) ;
i = i+1 ;
xs = tail( xs ) ;
}
return array;
}

char_list stream_to_list( FILE * stream ) {
int c = getc( stream ) ;
if( c == EOF ) {
return NULL ;
} else {
return cons( c, stream_to_list( stream ) ) ;
}
}


char_list stream_to_list( FILE * stream ) { /* name */
char_list accu = NULL ;
char_list last ;
int c; /* c declaration */
if( (c = getc(stream) ) != EOF ) { /* test on end */
last = accu
= cons( c, NULL ) ; /* c not head.. */
/* no statement here because getc side effects */
while( (c = getc(stream) ) != EOF ) { /* test on end */
last = last->list_tail
= cons( c, NULL ) ; /* c not head.. */
/* no statement here because getc side effects */
}
}
return accu ;
}
