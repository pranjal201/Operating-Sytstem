#include <pthread.h>
#include <stdio.h>
int size, buffer[100], no_of_samples_in_buffer;
int main()
{
pthread_t id1, id2, id3;
pthread_mutex_t buf_mutex, condition_mutex;
pthread_cond_t buf_full, buf_empty;
pthread_create(&id1, NULL, move_to_buffer, NULL);
pthread_create(&id2, NULL, write_into_file, NULL);
pthread_create(&id3, NULL, analysis, NULL);
pthread_join(id1, NULL);
pthread_join(id2, NULL);
pthread_join(id3, NULL);
pthread_exit(0);
}
void *move_to_buffer()
{
/* Repeat until all samples are received */
/* If no space in buffer, wait on buf_full */
/* Use buf_mutex to access the buffer, increment no. of samples */
/* Signal buf_empty */
pthread_exit(0);
}
void *write_into_file()
{
/* Repeat until all samples are written into the file */
/* If no data in buffer, wait on buf_empty */
/* Use buf_mutex to access the buffer, decrement no. of samples */
/* Signal buf_full */
pthread_exit(0);
}
void *analysis()
{
/* Repeat until all samples are analyzed */
/* Read a sample from the buffer and analyze it */
pthread_exit(0);
}
