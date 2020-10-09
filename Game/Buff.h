//
// Created by root on 10/2/20.
//

#ifndef DRAGONSLAYER_BUFF_H
#define DRAGONSLAYER_BUFF_H
#include <string>

using namespace std;


class Buff {

private:
    string name;
    string effect;
    string type;
    bool hidden;
    int turns;

public:

    void setName(string name);
    string getName();

    void setEffect(string effect);
    string getEffect();

    void setType(string type);
    string getType();

    void setHidden(bool hidden);
    bool isHidden();

    void setTurns(int turns);
    int getTurns();

    Buff(string name, string effect, string type, bool hidden, int turns);

    Buff();

    virtual ~Buff();

};


#endif //DRAGONSLAYER_BUFF_H
