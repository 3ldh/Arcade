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

void arcade::UIComponent::setText(const std::string &text) {
    UIComponent::text = text;
}

void arcade::UIComponent::setBgColor(const arcade::Color &bgColor) {
    UIComponent::bgColor = bgColor;
}

bool arcade::UIComponent::hasSprite() const {
    return false;
}

void arcade::UIComponent::setClicked() {

}

arcade::Color arcade::UIComponent::getTextColor() const {
    return textColor;
}

void arcade::UIComponent::setTextColor(const arcade::Color &textColor) {
    UIComponent::textColor = textColor;
}

bool arcade::UIComponent::isHover() const {
    return hover;
}

void arcade::UIComponent::setHover(bool hover) {
    UIComponent::hover = hover;
}

bool arcade::UIComponent::isSelected() const {
    return selected;
}

void arcade::UIComponent::setSelected(bool selected) {
    UIComponent::selected = selected;
}

void arcade::UIComponent::toogle() {
    selected = !selected;
}
