#include <cstdlib>
#include <cstring>
#include <sys/socket.h>

int main(int argc, char* argv[]) {
    int fd = socket(AF_XDP, SOCK_RAW, 0);

    static const int chunk_size = 4096;
    static const int chunk_count = 4096;
    static const int umem_len = chunk_size * chunk_count;
    unsigned char umem[chunk_count][chunk_size];

    if (!setsockopt(fd, SOL_XDP, XDP_UMEM_REG, &umem_reg, sizeof(umem_reg))) {
        std::cout << "Error!!!: " << std::strerror(errno) << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return 0;
}