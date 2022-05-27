#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include<sstream>
#include <ostream>

struct Covek {
    int redbroj;
    std::string ime;
    float poeni;
    std::vector<Covek> sort(std::vector<Covek> covek_vec) {
        auto cmp = [](const Covek& c1, const Covek& c2) { return c1.poeni > c2.poeni; };
        std::sort(covek_vec.begin(), covek_vec.end(), cmp);
        return covek_vec;
    };
};

int main() {
    std::vector<Covek> luge;
    int i = 0;
    while (i < 7) {
        std::string p;
        Covek c;

        std::cout << "Vnesi reden broj: "; std::cin >> c.redbroj;
        std::cout << "Vnesi ime: "; std::cin >> c.ime;
        std::cout << "Vnesi poeni: "; std::cin >> p;

        c.poeni = std::stof(p);
        luge.push_back(c);
        i++;
        std::cout << std::endl;
    }
    std::cout << "Nesortirani:" << std::endl;
    for (auto itr : luge) {
        std::cout << itr.redbroj << " " << itr.ime << " " << itr.poeni << std::endl;
    }
    std::cout << std::endl;

    Covek c;
    luge = c.sort(luge);

    std::cout << "Sortirani:" << std::endl;
    for (auto itr : luge) {
        std::cout << itr.redbroj << " " << itr.ime << " " << itr.poeni << std::endl;
    }

    std::cout << std::endl;

    std::string br_idx, ime;
    std::cout << "Vnesi broj na indeks: "; std::cin >> br_idx;
    std::cout << "Vnesi ime: "; std::cin >> ime;


    std::string f_name = "./" + br_idx + "." + ime;
    std::ofstream file;
    file.open(f_name, std::ios_base::app);
    for (auto& itr : luge) file << itr.redbroj << " " << itr.ime << " " << itr.poeni << std::endl;
    file.close();

    return 0;
}