// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISoundLib.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/12/11 18:59:07 by apavlov           #+#    #+#             //
//   Updated: 2019/12/11 18:59:09 by apavlov          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NIBBLER_SOUNDLIB_HPP
#define NIBBLER_SOUNDLIB_HPP

class ISoundLib {
public:
    ISoundLib();
    virtual ~ISoundLib();
    virtual void    playHappySound() = 0;
    virtual void    playSadSound() = 0;
};

#endif
