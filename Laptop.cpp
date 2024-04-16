#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <memory>

class Laptop;

class LaptopShop {
private:
    std::string laptopShop;
    std::vector<std::shared_ptr<Laptop>> laptops;
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dis{0, 10};

public:
    LaptopShop() = default;
    LaptopShop(const std::string& shopName) : laptopShop(shopName) {}

    std::string getLaptopShop() const {
        return laptopShop;
    }

    void setLaptopShop(const std::string& shopName) {
        laptopShop = shopName;
    }

    const std::vector<std::shared_ptr<Laptop>>& getLaptops() const {
        return laptops;
    }

    void loadData() {
        for (int i = 0; i < 10; i++) {
            auto l = std::make_shared<Laptop>();
            l->setLap_ID(i);
            std::string temp = (dis(gen) > 5) ? "Ryzen" : "Intel";
            l->setLap_processor(temp);
            laptops.push_back(l);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const LaptopShop& shop) {
        os << "Shop=[Shopname=" << shop.laptopShop << ",Laptops=[";
        for (const auto& lap : shop.laptops) {
            os << "{Lap_ID=" << lap->getLap_ID() << ", Lap_processor=" << lap->getLap_processor() << "}, ";
        }
        os << "]]";
        return os;
    }

    LaptopShop clone() const {
        LaptopShop shop;
        shop.setLaptopShop(laptopShop);
        for (const auto& l : laptops) {
            auto l_clone = std::make_shared<Laptop>();
            l_clone->setLap_ID(l->getLap_ID());
            l_clone->setLap_processor(l->getLap_processor());
            shop.laptops.push_back(l_clone);
        }
        return shop;
    }
};

class Laptop {
private:
    int Lap_ID;
    std::string Lap_processor;

public:
    int getLap_ID() const {
        return Lap_ID;
    }

    void setLap_ID(int id) {
        Lap_ID = id;
    }

    const std::string& getLap_processor() const {
        return Lap_processor;
    }

    void setLap_processor(const std::string& processor) {
        Lap_processor = processor;
    }
};

int main() {
    LaptopShop Ls("Ronaldo.Shop");
    Ls.loadData();
    std::cout << Ls << std::endl;

    LaptopShop Ls1 = Ls.clone();
    Ls.getLaptops().pop_back();
    Ls1.setLaptopShop("Messi");
    std::cout << Ls1 << std::endl;

    return 0;
}
