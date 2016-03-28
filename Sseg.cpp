/*                 Sseg
 *             Dylan Wright
 *             dylan.wright@uky.edu
 *
 *  Energia Library for interfacing with 
 *  common anode seven segment display.
 *  
 *  Dylan Wright
 *  dylan.wright@uky.edu
 */
#include "Energia.h"
#include "Sseg.h"

Sseg::Sseg(int a, int b, int c, int d, int e, int f, int g, int dp, int anode) 
    : m_a(a)
    , m_b(b)
    , m_c(c)
    , m_d(d)
    , m_e(e)
    , m_f(f)
    , m_g(g)
    , m_dp(dp)
    , m_anode(anode)
{
    pinMode(m_a, OUTPUT);
    pinMode(m_b, OUTPUT);
    pinMode(m_c, OUTPUT);
    pinMode(m_d, OUTPUT);
    pinMode(m_e, OUTPUT);
    pinMode(m_f, OUTPUT);
    pinMode(m_g, OUTPUT);
    pinMode(m_dp, OUTPUT);
    pinMode(m_anode, OUTPUT);

    clear();
}

void Sseg::clear() 
{
    digitalWrite(m_anode, LOW);
}

void Sseg::set(char val) 
{
    digitalWrite(m_a, val % 2 ? LOW : HIGH);
    val = val / 2;
    digitalWrite(m_b, val % 2 ? LOW : HIGH);
    val = val / 2;
    digitalWrite(m_c, val % 2 ? LOW : HIGH);
    val = val / 2;
    digitalWrite(m_d, val % 2 ? LOW : HIGH);
    val = val / 2;
    digitalWrite(m_e, val % 2 ? LOW : HIGH);
    val = val / 2;
    digitalWrite(m_f, val % 2 ? LOW : HIGH);
    val = val / 2;
    digitalWrite(m_g, val % 2 ? LOW : HIGH);
    val = val / 2;
    digitalWrite(m_dp, val % 2 ? LOW : HIGH);
    val = val / 2;
    digitalWrite(m_anode, HIGH);
}

void Sseg::setChar(char val)
{
    char a,b,c,d,e,f,g,dp;
    a = b = c = d = e = f = g = dp = 0;
    switch (val) {
        case 48:
            a = b = c = d = e = f = 1;
            break;
        case 49:
            b = c = 1;
            break;
        case 50:
            a = b = d = e = g = 1;
            break;
        case 51:
            a = b = c = d = g = 1;
            break;
        case 52:
            b = c = f = g = 1;
            break;
        case 53:
            a = c = d = f = g = 1;
            break;
        case 54:
            a = c = d = e = f = g = 1;
            break;
        case 55:
            a = b = c = 1;
            break;
        case 56:
            a = b = c = d = e = f = g = 1;
            break;
        case 57:
            a = b = c = f = g = 1;
            break;
        default:
            a = b = c = d = e = f = g = dp = 1;
            break;
    }
    set(a + b*2 + c*4 + d*8 + e*16 + f*32 + g*64 + dp*128);
}
