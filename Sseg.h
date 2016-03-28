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
#ifndef Sseg_included
#define Sseg_included

#include "Energia.h"

class Sseg 
{
public:
    Sseg(int a, int b, int c, int d, int e, int f, int g, int dp, int anode);
    void clear();
    void set(char val);
    void setChar(char val);

private:
    int m_a, m_b, m_c, m_d, m_e, m_f, m_g, m_dp, m_anode;
};

#endif
