#include <iostream>
#include <memory>

class Game {
public:
    Game() { play(); }                       // calls a virtual step during construction
    void play() {
        initialize();
        startPlay();
        endPlay();
    }
    virtual ~Game() = default;
protected:
    virtual void initialize() = 0;
    virtual void startPlay()  = 0;
    virtual void endPlay()    = 0;
};

class Football : public Game {
protected:
    void initialize() override { std::cout << "Football initialized\n"; }
    void startPlay()  override { std::cout << "Football started\n"; }
    void endPlay()    override { std::cout << "Football finished\n"; }
};

int main() {
    auto game = std::make_unique<Football>();
}
