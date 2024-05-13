#include <vector>
#include <string>

class Subbytes {
public:
    Subbytes(const std::vector<std::string>& blok);
    void wykonajOperacje();
    std::vector<std::string> getBlokPoSubbytes() const;
private:
    std::vector<std::string> blok;
    std::vector<std::string> blokPoSubbytes;
    static const std::string sBox[16][16]; // definicja S-Boxa
};
