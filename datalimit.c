#include <stdio.h>

#include <sys/types.h>

#include <sys/resource.h>

#include <sys/time.h>

#include <errno.h>

int main( )

{

struct rlimit limit;

if( getrlimit( RLIMIT_DATA, &limit ) < 0 )

fprintf( stderr, “%s\n”, strerror(errno));

else

printf( “%-14s “, “RLIMIT_DATA” );

if( limit.rlim_cur == RLIM_INFINITY )

printf( ” (infinity) ” );

else

printf( “%10d ” , limit.rlim_cur );

if( limit.rlim_max == RLIM_INFINITY )

printf( ” ( infinity ) ” );

else

printf( “10Ld\n”, limit.rlim_max );

return 0;

}
