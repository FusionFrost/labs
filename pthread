#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <time.h>

#define SIZE 5

void put_msg( char *title, time_t time_now) { 
	time(&time_now);    
   printf( "%s %s\t: pid=%lu, tid=%lu\n", 
           ctime(&time_now), title, getpid(), pthread_self() ); 
} 
void *test( void *in ) { 
   time_t time_n = (time_t)in; 
   time(&time_n); 
   put_msg( "pthread started", time_n ); 
   sleep( 5 );
   time(&time_n); 
   put_msg( "pthread finished", time_n ); 
   return NULL; 
} 

//static pthread_t tid[SIZE]; 
int main() { 
   pthread_t tid[SIZE]; 
   time_t time_now;
   int i; 
   time(&time_now);
   
   put_msg( "main started", time_now ); 
   for( i = 0; i < SIZE; i++ ) { 
      int status = pthread_create( &tid[ i ], NULL, test, (void*)&time_now );
         if( status != 0 ) perror( "pthread_create" ), exit( EXIT_FAILURE ); 
   }; 
   for( i = 0; i < SIZE; i++ )
      pthread_join( tid[ i ], NULL ); 
   time(&time_now);
   put_msg( "main finished", time_now ); 
   return( EXIT_SUCCESS ); 
} 
