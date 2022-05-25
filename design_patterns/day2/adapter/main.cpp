#include "adapter.hpp"

int main() {

    RoundHole *hole = new RoundHole(4.0);
    RoundPeg *roundPeg = new RoundPeg(4.0);
    cout << hole->Fits(roundPeg) << endl;

    SquarePeg *smallSquarePeg = new SquarePeg(4.0);
    SquarePeg *largeSquarePeg = new SquarePeg(8.0);

    SquarePegAdapter *adapter1 = new SquarePegAdapter(smallSquarePeg);
    SquarePegAdapter *adapter2 = new SquarePegAdapter(largeSquarePeg);
    cout << hole->Fits(adapter1) << endl;
    cout << hole->Fits(adapter2) << endl;

    return 0;
}