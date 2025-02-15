#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    mqd_t queue;
    struct mq_attr attrs;
    char *msg_ptr;
    ssize_t recvd;
    size_t i;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        return 1;
    }

    queue = mq_open(argv[1], O_RDONLY | O_CREAT , S_IRUSR | S_IWUSR, NULL); // NULL is for default attributes
    if (queue == (mqd_t)-1)
    {
        perror("mq_open");
        return 1;
    }

    if (mq_getattr(queue, &attrs) == -1)
    {
        perror("mq_getattr");
        mq_close(queue);
        return 1;
    }

    msg_ptr = calloc(1, attrs.mq_msgsize); // allocate memory for message
    if (msg_ptr == NULL)
    {
        perror("calloc for msg_ptr");
        mq_close(queue);
        return 1;
    }

    recvd = mq_receive(queue, msg_ptr, attrs.mq_msgsize, NULL); 
    if (recvd == -1)
    {
        perror("mq_receive");
        return 1;
    }
    printf("Received message in msg queue is:(%s)\n", msg_ptr);

}