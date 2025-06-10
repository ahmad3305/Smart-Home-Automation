#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "mystr.h"
using namespace std;

class Account {
protected:
    Mystr id;
    Mystr username;
    Mystr password;
    Mystr name;
public:
    Account();
    Account(const Mystr& id, const Mystr& username, const Mystr& password, const Mystr& name);
    virtual ~Account();

    Mystr getId() const;
    Mystr getUsername() const;
    Mystr getName() const;
    void setPassword(const Mystr& newPassword);
    bool checkPassword(const Mystr& pass) const;
    virtual Mystr getRole() const;
};

#endif
