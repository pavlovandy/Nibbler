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
    SFML_sound();
    ~SFML_sound() override ;
    void    playHappySound() override ;
    void    playSadSound() override ;
};

#endif
