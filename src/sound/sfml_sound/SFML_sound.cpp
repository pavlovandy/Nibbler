// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SFML_sound.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/12/11 18:59:44 by apavlov           #+#    #+#             //
//   Updated: 2019/12/11 18:59:45 by apavlov          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SFML_sound.hpp"

extern "C" {
    ISoundLib*	allocator( int , int ) {
        return new SFML_sound();
    }

    void				deallocator( ISoundLib* slib ) {
        delete slib;
    }
}

SFML_sound::SFML_sound() : volume_(50.f) {
    if (!happyBuff_.loadFromFile("resorces/sound/happy.wav"))
        throw std::runtime_error("Couldn't load happy sound");
    happy_.setBuffer(happyBuff_);
    if (!sadBuff_.loadFromFile("resorces/sound/death.wav"))
        throw std::runtime_error("Couldn't load sad sound");
    sad_.setBuffer(sadBuff_);

    sad_.setVolume(volume_);
    happy_.setVolume(volume_);
}

void    SFML_sound::playHappySound() {
    happy_.play();
}

void    SFML_sound::playSadSound() {
    sad_.play();
}

void    SFML_sound::increaseVolume() {
    if (volume_ + 5 <= 100) {
        volume_ += 5;
        sad_.setVolume(volume_);
        happy_.setVolume(volume_);
    }
}

void    SFML_sound::decreaseVolume() {
    if (volume_ - 5 >= 0) {
        volume_ -= 5;
        sad_.setVolume(volume_);
        happy_.setVolume(volume_);
    }
}

SFML_sound::~SFML_sound() {}
