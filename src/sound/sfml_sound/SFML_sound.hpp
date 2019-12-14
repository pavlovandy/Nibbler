// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SFML_sound.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/12/11 18:59:58 by apavlov           #+#    #+#             //
//   Updated: 2019/12/11 18:59:59 by apavlov          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NIBBLER_SFML_SOUND_HPP
# define NIBBLER_SFML_SOUND_HPP

# include "../ISoundLib.hpp"
# include <SFML/Audio.hpp>

class SFML_sound : public ISoundLib  {
public:
    SFML_sound();
    ~SFML_sound() override ;

    SFML_sound( const SFML_sound & ) = delete ;
    SFML_sound& operator=(const SFML_sound &) = delete ;

    void    playHappySound() override ;
    void    playSadSound() override ;
    void    increaseVolume() override ;
    void    decreaseVolume() override ;

private:
    sf::SoundBuffer happyBuff_;
    sf::SoundBuffer sadBuff_;
    sf::Sound   happy_;
    sf::Sound   sad_;
    float       volume_;

};

#endif
