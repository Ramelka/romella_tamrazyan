#include <iostream>
#include <cmath>
using namespace std;

class RoundPeg {
    private:
        double _radius;
    public:
        RoundPeg() {
            _radius = 0.0;
        };

        RoundPeg(double _radius) {
            this->_radius = _radius;
        } 
        
        virtual double GetRadius() const {
            return this->_radius;
        }

        ~RoundPeg() {};
};

class SquarePeg {
    private:
        double _width;
    public:
        SquarePeg() {
            _width = 0.0;
        }

        SquarePeg(double _width) {
            this->_width = _width;
        }

        double GetWidth() const {
            return this->_width;
        }

        ~SquarePeg() {};
};

class RoundHole {
    private:
        double _radius;
    public:
        RoundHole() {
            _radius = 0.0;
        }

        RoundHole(double _radius) {
            this->_radius = _radius;
        }

        double GetRadius() const {
            return this->_radius;
        }

        bool Fits(RoundPeg *_round_peg) const {
            return GetRadius() >= _round_peg->GetRadius();
        }

        ~RoundHole() {};
};

class SquarePegAdapter:public RoundPeg {
    private:
        SquarePeg *_square_peg;
    public:
        SquarePegAdapter() {
            _square_peg = NULL;
        }
        SquarePegAdapter(SquarePeg *_square_peg) {
            this->_square_peg = _square_peg;
        }

        double GetRadius() const override {
            return _square_peg->GetWidth() * sqrt(2.0) / 2.0;
        }

        ~SquarePegAdapter() {};
};