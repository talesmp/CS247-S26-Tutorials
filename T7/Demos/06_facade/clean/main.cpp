#include <iostream>
#include <memory>
#include <string>
#include <string_view>

class PopcornPopper { public: void on()  { std::cout << "Popper on\n"; }
                              void pop() { std::cout << "Popping corn\n"; } };
class Lights       { public: void dim(int p) { std::cout << "Lights dim to " << p << "%\n"; } };
class Projector    { public: void on()  { std::cout << "Projector on\n"; }
                              void wideScreen() { std::cout << "Projector in widescreen\n"; } };
class DvdPlayer    { public: void on()  { std::cout << "DVD on\n"; }
                              void play(std::string_view m) { std::cout << "Playing \"" << m << "\"\n"; } };

class HomeTheaterFacade {
    std::shared_ptr<PopcornPopper> popper;
    std::shared_ptr<Lights>        lights;
    std::shared_ptr<Projector>     projector;
    std::shared_ptr<DvdPlayer>     dvd;
public:
    HomeTheaterFacade(std::shared_ptr<PopcornPopper> pop, std::shared_ptr<Lights> l,
                      std::shared_ptr<Projector> pr, std::shared_ptr<DvdPlayer> d)
        : popper(std::move(pop)), lights(std::move(l)),
          projector(std::move(pr)), dvd(std::move(d)) {}

    void watchMovie(std::string_view movie) const {
        popper->on();
        popper->pop();
        lights->dim(10);
        projector->on();
        projector->wideScreen();
        dvd->on();
        dvd->play(movie);
    }
};

int main() {
    auto popper    = std::make_shared<PopcornPopper>();
    auto lights    = std::make_shared<Lights>();
    auto projector = std::make_shared<Projector>();
    auto dvd       = std::make_shared<DvdPlayer>();

    HomeTheaterFacade theater(popper, lights, projector, dvd);
    theater.watchMovie("I'm Still Here (2024)");
}
