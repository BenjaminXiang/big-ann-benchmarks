#include <utils/dataset_io.h>

float* read_fbin(const char* filename, size_t& num, size_t& dim) {
    std::ifstream in(filename, std::ios::binary);
    if (!in.is_open()) {
        throw std::runtime_error("Cannot open file");
    }
    unsigned n, d;
    in.read((char*)&n, 4);
    in.read((char*)&d, 4);
    num = n;
    dim = d;
    size_t d_size = num*dim;
    float* data = new float[d_size];
    in.read((char*)data, d_size * sizeof(float));
    in.close();
    return data;
}