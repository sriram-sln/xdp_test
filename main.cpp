#include <sys/socket.h>

int main(int argc, char* argv[]) {
    int fd = socket(AF_XDP, SOCK_RAW, 0);

    static const int chunk_size = 4096;
    static const int chunk_count = 4096;
    static const int umem_len = chunk_size * chunk_count;
    unsigned char[chunk_count][chunk_size] umem = malloc(umem_len);

    return 0;
}