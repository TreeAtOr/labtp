#include "Element.h"

Element::Element() : train(nullptr), next(nullptr), prev(nullptr) {}

Element::~Element() {
    delete train;
}