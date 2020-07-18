#pragma once

class Alive
{
public:
    inline Alive(int value, bool &isAlive) : value(value), m_isAlive(isAlive)
    {
        m_isAlive = true;
    }

    inline ~Alive()
    {
        m_isAlive = false;
    }

    int value;

private:
    bool &m_isAlive;
};
