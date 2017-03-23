//
// Created by sauvau_m on 3/21/17.
//

#include "../include/UIComponent.hpp"

arcade::UIComponent::~UIComponent() {

}

arcade::UIComponent::UIComponent(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {

}

double arcade::UIComponent::getX() const {
    return x;
}

double arcade::UIComponent::getY() const {
    return y;
}

double arcade::UIComponent::getWidth() const {
    return width;
}

double arcade::UIComponent::getHeight() const {
    return height;
}

size_t arcade::UIComponent::getBackgroundId() const {
    return 0;
}

arcade::Color arcade::UIComponent::getBackgroundColor() const {
    return bgColor;
}

const std::string &arcade::UIComponent::getText() const {
    return text;
}

