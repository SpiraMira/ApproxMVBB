// ========================================================================================
//  ApproxMVBB 
//  Copyright (C) 2014 by Gabriel Nützi <nuetzig (at) imes (d0t) mavt (d0t) ethz (døt) ch>
//  
//  Licensed under GNU General Public License 3.0 or later. 
//  Some rights reserved. See COPYING, README.rst.
//
//  @license GPL-3.0 <http://www.gnu.org/licenses/gpl-3.0.html>
// ========================================================================================

#ifndef ApproxMVBB_GreatestCommonDivisor_hpp
#define ApproxMVBB_GreatestCommonDivisor_hpp
namespace ApproxMVBB{
    namespace MathFunctions {

        /** Greates common divisor */
        template<bool argsPositive = false,
                 typename T>
        typename std::enable_if<std::is_integral<T>::value,T >::type
        gcd2( T  a, T  b ) {

            if(!argsPositive) {
                a = std::abs( a );
                b = std::abs( b );
            }

            if( a == 0  ||  a == b ) {
                return  b;
            }
            if( b == 0 ) {
                return  a;
            }
            if( a > b ) {
                return  gcd2<true,T>( a % b, b );
            } else {
                return  gcd2<true,T>( a, b % a );
            }
        }

        /** Greates common divisor */
        template<bool argsPositive = false,
                 typename T>
        typename std::enable_if<std::is_integral<T>::value,T>::type
        gcd3( T  a, T  b, T  c ) {

            if(!argsPositive) {
                a = std::abs( a );
                b = std::abs( b );
                c = std::abs( c );
            }

            if   ( a == 0 )
                return  gcd2<true,T>( b, c );
            if   ( b == 0 )
                return  gcd2<true,T>( a, c );
            if   ( c == 0 )
                return  gcd2<true,T>( a, b );

            return  gcd2<true,T>( a, gcd2<true,T>( b, c ) );
        }
    }
};
#endif