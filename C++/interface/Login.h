#ifndef LOGIN_H
#define LOGIN_H

class Login {
public:
    virtual void fazerLogin() = 0; // Método puramente virtual
    virtual ~Login() = default;    // Destrutor virtual
};

#endif